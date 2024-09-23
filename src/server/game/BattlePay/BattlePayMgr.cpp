#include "Common.h"
#include "ObjectMgr.h"
#include "Chat.h"
#include "BattlePayMgr.h"
#include "WorldSession.h"
#include "Player.h"
#include "BattlePayData.h"
#include "DatabaseEnv.h"
#include "QuestData.h"
#include "LoginQueryHolder.h"
#include "ScriptMgr.h"
#include "AccountMgr.h"
#include "PetBattle.h"
#include "BattlePetData.h"
#include "CharacterService.h"
#include "CollectionMgr.h"
#include "Guild.h"
#include "GuildPackets.h"
#include "GuildMgr.h"

using namespace Battlepay;

BattlepayManager::BattlepayManager(WorldSession* session)
{
    _session = session;
    _walletName = "Battle Coins";
    _purchaseIDCount = 0;
    _distributionIDCount = 0;
    _isInGameStore = true;
}

BattlepayManager::~BattlepayManager() = default;

void BattlepayManager::RegisterStartPurchase(Purchase purchase)
{
    _actualTransaction = purchase;
}

uint64 BattlepayManager::GenerateNewPurchaseID()
{
    return uint64(0x1E77800000000000 | ++_purchaseIDCount);
}

uint64 BattlepayManager::GenerateNewDistributionId()
{
    return uint64(0x1E77800000000000 | ++_distributionIDCount);
}

Purchase* BattlepayManager::GetPurchase()
{
    return &_actualTransaction;
}

std::string const& BattlepayManager::GetDefaultWalletName() const
{
    return _walletName;
}

BattlePayCurrency BattlepayManager::GetShopCurrency() const
{
    /// @TODO: Move that to config files
    return Krw;
}

bool BattlepayManager::IsAvailable() const
{
    if (AccountMgr::IsPlayerAccount(_session->GetSecurity()))
        return true;

    return sWorld->getBoolConfig(CONFIG_PURCHASE_SHOP_ENABLED);
}

std::string Product::Serialize() const
{
    std::string res;
    res += "Expansion: " + std::to_string(CURRENT_EXPANSION);
    res += ", Type: " + std::to_string(WebsiteType);
    res += ", Quantity: " + std::to_string(1);
    res += ", IngameShop: " + std::to_string(1);
    res += ", CustomData: " + sScriptMgr->BattlePayGetCustomData(*this);

    uint32 idx = 0;
    for (auto const& itr : Items)
    {
        std::string iconName;
        if (auto itemTemplate = sObjectMgr->GetItemTemplate(itr.ItemID))
        {
            if (auto fileDataId = sDB2Manager.GetItemDIconFileDataId(itr.ItemID))
                iconName = std::to_string(fileDataId);

            switch (WebsiteType)
            {
            case Item:
                res += ", Item(ItemID: " + std::to_string(itr.ItemID) + ", Quality: " + std::to_string(itemTemplate->GetQuality()) + ", Icon: " + iconName + ")";
                break;
            case PackItems:
                res += ", Pack(Icon: " + iconName + ", ItemsEntry: " + std::to_string(itr.ItemID) + ", Num: " + std::to_string(idx) + ")";
                break;
            default:
                break;
            }
        }

        idx++;
    }

    return res;
}

void BattlepayManager::SavePurchase(Purchase * purchase)
{
    auto const& product = sBattlePayDataStore->GetProduct(purchase->ProductID);

    auto stm = CharacterDatabase.GetPreparedStatement(CHAR_INS_PURCHASE);
    stm->setUInt32(0, _session->GetAccountId());
    stm->setUInt32(1, realm.Id.Realm);
    stm->setUInt32(2, _session->GetPlayer() ? _session->GetPlayer()->GetGUIDLow() : 0);
    stm->setString(3, product.Serialize());
    stm->setUInt32(4, purchase->CurrentPrice);
    stm->setString(5, _session->GetRemoteAddress());

    _session->_queryProcessor.AddQuery(CharacterDatabase.AsyncQuery(stm).WithPreparedCallback([this](PreparedQueryResult result) -> void
        {
            OnPrepareStatementCallbackEvent(CallbackEvent::SavePurchase);
        }));
}

void BattlepayManager::OnPrepareStatementCallbackEvent(uint8 callbackEvent)
{
    switch (callbackEvent)
    {
    case CallbackEvent::SavePurchase:
        SendPointsBalance();
        break;
    default:
        break;
    }
}

void BattlepayManager::ProcessDelivery(Purchase * purchase)
{
    // _existProducts.insert
    auto player = _session->GetPlayer(); // atm only ingame shop -_-

    auto const* product = sBattlePayDataStore->GetProduct(purchase->ProductID);
    if (!product)
        return;

    switch (product->WebsiteType)
    {
    case Battlepay::Item:
        for (auto const& itr : product->Items)
            if (player)
            {
                // Check if the item is heirloom we unlock in collectionmgr instead of adding it
                if (HeirloomEntry const* heirloom = sDB2Manager.FindHeirloom(itr.ItemID))
                {
                    player->GetCollectionMgr()->AddHeirloom(heirloom->ItemID, 0);

                    // We also upgrade it to 110lvl cuz we are cool
                    player->GetCollectionMgr()->UpgradeHeirloom(heirloom->ItemID, heirloom->UpgradeItemID[2]);
                }
                else
                    player->AddItem(itr.ItemID, itr.Quantity);
            }
        break;
    case Battlepay::BattlePet:
        if (player)
            for (auto const& itr : product->Items)
                player->AddBattlePetByCreatureId(itr.ItemID, true, true);
        break;
    case Rename:
        if (player)
            sCharacterService->SetRename(player);
        break;
    case Faction:
        if (player)
            sCharacterService->ChangeFaction(player);
        break;
    case DeletedCharacter:
        sCharacterService->RestoreDeletedCharacter(_session);
        break;
    case Customization:
        if (player)
            sCharacterService->Customize(player);
        break;
    case AppareanceArtifact:
        if (player)
            sCharacterService->AppareanceArtifact(player);
        break;
    case Race:
        if (player)
            sCharacterService->ChangeRace(player);
        break;
    case CategoryGold:
        if (player)

            break;
    
    case CharacterBoost:
    {
        if (_session->HasAuthFlag(AT_AUTH_FLAG_20_LVL_UP)) //@send error?
            break;

        //SendBattlePayDistribution(purchase->ProductID, DistributionStatus::BATTLE_PAY_DIST_STATUS_AVAILABLE, 1);

        /* if (player)
           sCharacterService->Boost(player);
        break;
		*/
    }
    //case Gold:
    //    break;
    //case Category:
    //    break;
    //case Battlepay::Spell:
    //    break;
    //case Currency:
    //    break;
    case Gold1:
        if (player)
            sCharacterService->Gold20k(player);
        break;
    case Gold2:
        if (player)
            sCharacterService->Gold50k(player);
        break;
    case Gold3:
        if (player)
            sCharacterService->Gold100k(player);
        break;
    case Gold4:
        if (player)
            sCharacterService->Gold250k(player);
        break;
    case Gold5:
        if (player)
            sCharacterService->Gold500k(player);
        break;
    case Gold6:
        if (player)
            sCharacterService->Gold1000k(player);
        break;
    case ProfPriAlchemy:
        if (player)
            sCharacterService->ProfPriAlchemy(player);
        break;
    case ProfPriSastre:
        if (player)
            sCharacterService->ProfPriSastre(player);
        break;
    case ProfPriJoye:
        if (player)
            sCharacterService->ProfPriJoye(player);
        break;
    case ProfPriHerre:
        if (player)
            sCharacterService->ProfPriHerre(player);
        break;
    case ProfPriPele:
        if (player)
            sCharacterService->ProfPriPele(player);
        break;
    case ProfPriInge:
        if (player)
            sCharacterService->ProfPriInge(player);
        break;
    case ProfPriInsc:
        if (player)
            sCharacterService->ProfPriInsc(player);
        break;
    case ProfPriEncha:
        if (player)
            sCharacterService->ProfPriEncha(player);
        break;
    case ProfPriDesu:
        if (player)
            sCharacterService->ProfPriDesu(player);
        break;
    case ProfPriMing:
        if (player)
            sCharacterService->ProfPriMing(player);
        break;
    case ProfPriHerb:
        if (player)
            sCharacterService->ProfPriHerb(player, _session);
        break;
    case ProfSecCoci:
        if (player)
            sCharacterService->ProfSecCoci(player);
        break;
    case ProfSecArque:
        if (player)
            sCharacterService->ProfSecArque(player);
        break;
    case ProfSecPrau:
        if (player)
            sCharacterService->ProfSecPrau(player);
        break;
    case ProfSecFish:
        if (player)
            sCharacterService->ProfSecFish(player);
        break;
    case RepClassic:
        if (player)
            sCharacterService->RepClassic(player);
        break;
    case RepBurnig:
        if (player)
            sCharacterService->RepBurnig(player);
        break;
    case RepTLK:
        if (player)
            sCharacterService->RepTLK(player);
        break;
    case RepCata:
        if (player)
            sCharacterService->RepCata(player);
        break;
    case RepPanda:
        if (player)
            sCharacterService->RepPanda(player);
        break;
    case RepDraenor:
        if (player)
            sCharacterService->RepDraenor(player);
        break;
    case RepLegion:
        if (player)
            sCharacterService->RepLegion(player);
        break;
    case Unbinall:
        if (player)
            sCharacterService->Unbinall(player);
        break;
    case RacesAlliedHighmountainTauren:
        if (player)
            sCharacterService->RacesAlliedHighmountainTauren(player);
        break;

    case RacesAlliedNightborne:
        if (player)
            sCharacterService->RacesAlliedNightborne(player);
        break;

    case RacesAlliedVoidElf:
        if (player)
            sCharacterService->RacesAlliedVoidElf(player);
        break;

    case RacesAlliedLighForgedDraenei:
        if (player)
            sCharacterService->RacesAlliedLighForgedDraenei(player);
        break;
  
    case GuildRename:
    {
        if (!product.ScriptName.compare("battlepay_service_guildrename"));
        {
            Guild* guild = player->GetGuild();
            if (!guild)
            {
                Guild::SendCommandResult(player->GetSession(), GUILD_PROMOTE_SS, ERR_GUILD_PLAYER_NOT_IN_GUILD);
                return;
            }

            if (guild->GetLeaderGUID() != player->GetGUID())
            {
                Guild::SendCommandResult(player->GetSession(), GUILD_PROMOTE_SS, ERR_GUILD_PERMISSIONS);
                return;
            }

            guild->SetRename(true);
        }
    }
    break;
   	case MOPChallengeModeTransmog:
		if (player)
			sCharacterService->UnlockMOPChallengeModeTransmog(player);
		break;

	case WODChallengeModeTransmog:
		if (player)
			for (uint32 tmogid : WODChallengeTransmogIDs)
			{
				if (!player->GetCollectionMgr()->HasTransmog(tmogid))
					player->GetCollectionMgr()->AddTransmog(tmogid, 0);
			}
		break;

	case WarglaivesOfAzzinothTransmog:
		if (player)
		{
			player->CompletedAchievement(sAchievementStore.LookupEntry(11869));
			player->GetCollectionMgr()->AddTransmogSet(1347);
		}
		break;

	case HeritageHighmountainTauren:
		if (player)
			player->GetCollectionMgr()->AddTransmogSet(1522);
		break;

	case HeritageLightforgedDraenei:
		if (player)
			player->GetCollectionMgr()->AddTransmogSet(1525);
		break;

	case HeritageNightborne:
		if (player)
			player->GetCollectionMgr()->AddTransmogSet(1523);
		break;

	case HeritageVoidElf:
		if (player)
			player->GetCollectionMgr()->AddTransmogSet(1524);
		break;
		//case PremadeCharacter:
		//    break;
		//case RealmTransfer:
		//    break;
		//case ExpansionTransfer:
		//    break;
		//case Premium:
		//    break;
		//case PackItems:
		//    break;
		//case ItemProfession:
		//    break;	
		//case Transmogrification:
		//    break;
		//case CategoryProfession:
		//    break;
		//case CategoryPremade:
		//    break;
		//case ItemMount:
		//    break;
		//case CategoryCharacterManagement:
		//    break;
		//case CategoryRealmTransfer:
		//    break;
		//case CategoryExpansionTransfer:
		//    break;
    case Gold:
    {
        if (!player)
            break;

        if (!product.ScriptName.compare("battlepay_nethershard_1k"))
        {
            player->ModifyCurrency(1226, 1000);
            break;
        }
        else if (!product.ScriptName.compare("battlepay_resources_1k"))
        {
            player->ModifyCurrency(1220, 1000);
            break;
        }
        else if (!product.ScriptName.compare("battlepay_supplies_1k"))
        {
            player->ModifyCurrency(1342, 1000);
            break;
        }
        else if (!product.ScriptName.compare("battlepay_badge_1k"))
        {
            player->ModifyCurrency(1166, 1000);
            break;
        }
        else if (!product.ScriptName.compare("battlepay_garrison_200"))
        {
            player->ModifyCurrency(824, 200);
            break;
        }
        else if (!product.ScriptName.compare("battlepay_crystal_5k"))
        {
            player->ModifyCurrency(823, 5000);
            break;
        }
        else if (!product.ScriptName.compare("battlepay_timeless_5k"))
        {
            player->ModifyCurrency(777, 5000);
            break;
        }
        else if (!product.ScriptName.compare("battlepay_argunite_2k"))
        {
            player->ModifyCurrency(1508, 2000);
            break;
        }
        else if (!product.ScriptName.compare("battlepay_sightless_1k"))
        {
            player->ModifyCurrency(1149, 1000);
            break;
        }
        else if (!product.ScriptName.compare("battlepay_echoes of battle_1k"))
        {
            player->ModifyCurrency(1356, 100);
            break;
        }
        else if (!product.ScriptName.compare("battlepay_echoes of domination_1k"))
        {
            player->ModifyCurrency(1357, 100);
            break;
        }
        else if (!product.ScriptName.compare("battlepay_essence_1k"))
        {
            player->ModifyCurrency(1533, 1000);
            break;
        }
        else if (!product.ScriptName.compare("goblin_hunter"))
        {
            player->AddItem(3000203, 1);
            break;
        }
        else if (!product.ScriptName.compare("goblin_warrior"))
        {
            player->AddItem(3000202, 1);
            break;
        }
        else if (!product.ScriptName.compare("goblin_fist"))
        {
            player->AddItem(3000204, 1);
            break;
        }
        else if (!product.ScriptName.compare("goblin_grit"))
        {
            player->AddItem(3000205, 1);
            break;
        }
        else if (!product.ScriptName.compare("wod_pathfinder"))
        {
            player->learnSpell(191645, true);
            break;
        }
        else if (!product.ScriptName.compare("legion_pathfinder"))
        {
            player->learnSpell(226342, true);
            player->learnSpell(233368, true);
            break;
        }
    }
    break;
    //case Level:
    //    break;
    //case PremadeCharacter:
    //    break;
    //case RealmTransfer:
    //    break;
    //case ExpansionTransfer:
    //    break;
    //case Premium:
    //    break;
    //case PackItems:
    //    break;
    //case ItemProfession:
    //    break;
    //case Transmogrification:
    //    break;
    //case CategoryProfession:
    //    break;
    //case CategoryPremade:
    //    break;
    //case ItemMount:
    //    break;
    //case CategoryCharacterManagement:
    //    break;
    //case CategoryRealmTransfer:
    //    break;
    //case CategoryExpansionTransfer:
    //    break;
    //case CategoryGold:
    //   break;
    default:
        break;
    }

    if (!product->ScriptName.empty())
        sScriptMgr->OnBattlePayProductDelivery(_session, product);

    if (!IsInGameStore())
    {
        auto flags = player->GetAtLoginFlags();
        _session->SendCharacterEnum(false, flags, player->GetGUID().GetCounter());
        _session->LogoutPlayer(false);
    }
}


void BattlepayManager::OnPaymentSucess(uint32 newBalance)
{
    auto player = _session->GetPlayer();
    if (!player)
        return;

    std::ostringstream data;
    data << newBalance;
    player->SendCustomMessage(GetCustomMessage(CustomMessage::StoreBalance), data);
}

bool BattlepayManager::AlreadyOwnProduct(uint32 itemId) const
{
    //if (_existProducts.find(productId) != _existProducts.end())
    //    return turue;

    auto const& player = _session->GetPlayer();
    if (player)
    {
        auto itemTemplate = sObjectMgr->GetItemTemplate(itemId);
        if (!itemTemplate)
            return true;

        for (auto itr : itemTemplate->Effects)
            if (itr->TriggerType == ITEM_SPELLTRIGGER_LEARN_SPELL_ID && player->HasSpell(itr->SpellID))
                return true;

        if (player->GetCollectionMgr()->HasToy(itemId))
            return true;
    }

    return false;
}

auto GroupFilterForSession = [](uint32 groupId) -> bool
{
    switch (groupId)
    {
    case ProductGroups::Mount:
    case ProductGroups::Pets:
    case ProductGroups::Services:
    case ProductGroups::Boosts:
    case ProductGroups::Heirlooms:
        return true;
    default:
        return false;
    }
};

auto BattlepayManager::ProductFilter(Product product) -> bool
{
    auto player = _session->GetPlayer();
    if (!player)
    {
        switch (product.WebsiteType)
        {
        case Battlepay::BattlePet:
        case Rename:
        case Faction:
        case DeletedCharacter:
        case Customization:
        case Race:
        case CharacterBoost:
            //case Category:
            //    break;
            //case Battlepay::Spell:
            //    break;
            //case Currency:
            //    break;
            //case GuildRename:
            //    break;
            //case Gold:
            //    break;
            //case Level:
            //    break;
        case PremadeCharacter:
            //    break;
            //case RealmTransfer:
            //    break;
            //case ExpansionTransfer:
            //    break;
        case Premium:
            //    break;
            //case PackItems:
            //    break;
            //case ItemProfession:
            //    break;
            //case Transmogrification:
            //    break;
            //case CategoryProfession:
            //    break;
            //case CategoryPremade:
            //    break;
        case ItemMount:
            //    break;
            //case CategoryCharacterManagement:
            //    break;
            //case CategoryRealmTransfer:
            //    break;
            //case CategoryExpansionTransfer:
            //    break;
            //case CategoryGold:
            //    break;
            return true;
        default:
            return false;
        }
    }

    if (product.ClassMask && (player->getClassMask() & product.ClassMask) == 0)
        return false;

    for (auto& itr : product.Items)
    {
        if (AlreadyOwnProduct(itr.ItemID))
            return false;

        if (auto itemTemplate = sObjectMgr->GetItemTemplate(itr.ItemID))
        {
            if (itemTemplate->AllowableClass && (itemTemplate->AllowableClass & player->getClassMask()) == 0)
                return false;

            if (itemTemplate->AllowableRace && (itemTemplate->AllowableRace & player->getRaceMask()) == 0)
                return false;

            if (itemTemplate->GetMinFactionID() && uint32(player->GetReputationRank(itemTemplate->GetMinFactionID())) < itemTemplate->GetMinReputation())
                return false;

            for (auto effectData : itemTemplate->Effects)
            {
                if (effectData->SpellID != 0 && effectData->TriggerType == ITEM_SPELLTRIGGER_LEARN_SPELL_ID)
                {
                    if (auto spellInfo = sSpellMgr->GetSpellInfo(effectData->SpellID))
                    {
                        if (spellInfo->HasAttribute(SPELL_ATTR7_HORDE_ONLY) && (player->getRaceMask() & RACEMASK_HORDE) == 0)
                            return false;

                        if (spellInfo->HasAttribute(SPELL_ATTR7_ALLIANCE_ONLY) && (player->getRaceMask() & RACEMASK_ALLIANCE) == 0)
                            return false;
                    }
                }
            }
        }
    }

    return true;
};

void BattlepayManager::SendProductList()
{
    WorldPackets::BattlePay::ProductListResponse response;
    if (!IsAvailable())
    {
        response.Result = ProductListResult::LockUnk1;
        _session->SendPacket(response.Write());
        return;
    }

    auto const& player = _session->GetPlayer();
    auto const& localeIndex = _session->GetSessionDbLocaleIndex();

    response.Result = ProductListResult::Available;
    response.ProductList.CurrencyID = GetShopCurrency();

    for (auto& itr : sBattlePayDataStore->GetProductGroups())
    {
        if (!player && !GroupFilterForSession(itr.GroupID))
            continue;

        WorldPackets::BattlePay::BattlePayProductGroup pGroup;
        pGroup.GroupID = itr.GroupID;
        pGroup.IconFileDataID = itr.IconFileDataID;
        pGroup.Ordering = itr.Ordering;
        pGroup.UnkInt = 0;
        pGroup.IsAvailableDescription = "";
        pGroup.DisplayType = itr.DisplayType;

        auto name = itr.Name;
        if (auto productLocale = sBattlePayDataStore->GetProductGroupLocale(itr.GroupID))
            ObjectMgr::GetLocaleString(productLocale->Name, localeIndex, name);
        pGroup.Name = name;
        response.ProductList.ProductGroup.emplace_back(pGroup);
    }

    for (auto const& itr : sBattlePayDataStore->GetShopEntries())
    {
        if (!player && !GroupFilterForSession(itr.GroupID))
            continue;

        WorldPackets::BattlePay::BattlePayShopEntry sEntry;
        sEntry.EntryID = itr.EntryID;
        sEntry.GroupID = itr.GroupID;
        sEntry.ProductID = itr.ProductID;
        sEntry.Ordering = itr.Ordering;
        sEntry.VasServiceType = itr.Flags;
        sEntry.StoreDeliveryType = itr.BannerType;

        auto data = WriteDisplayInfo(itr.DisplayInfoID, localeIndex);
        if (std::get<0>(data))
        {
            sEntry.DisplayInfo = boost::in_place();
            sEntry.DisplayInfo = std::get<1>(data);
        }

        response.ProductList.Shop.emplace_back(sEntry);
    }

    for (auto const& itr : sBattlePayDataStore->GetProducts())
    {
        auto const& product = itr.second;
        if (!ProductFilter(product))
            continue;

        if (!player && !GroupFilterForSession(sBattlePayDataStore->GetProductGroupId(product.ProductID)))
            continue;

        WorldPackets::BattlePay::ProductInfoStruct pInfo;
        pInfo.NormalPriceFixedPoint = product.NormalPriceFixedPoint * g_CurrencyPrecision;
        pInfo.CurrentPriceFixedPoint = product.CurrentPriceFixedPoint * g_CurrencyPrecision;
        pInfo.ProductID = product.ProductID;
        pInfo.ChoiceType = product.ChoiceType;
        pInfo.ProductIDs.emplace_back(product.ProductID);
        //std::vector<uint32> UnkInts;
        pInfo.UnkInt2 = 47; // 2 ?

        auto dataPI = WriteDisplayInfo(product.DisplayInfoID, localeIndex);
        if (std::get<0>(dataPI))
        {
            pInfo.DisplayInfo = boost::in_place();
            pInfo.DisplayInfo = std::get<1>(dataPI);
        }

        response.ProductList.ProductInfo.emplace_back(pInfo);

        WorldPackets::BattlePay::BattlePayProduct pProduct;
        pProduct.ProductID = product.ProductID;
        pProduct.Flags = product.Flags;
        pProduct.Type = product.Type;
        //pProduct.UnkBits Optional<uint16> ;
        //pProduct.UnkInt1 = 0;
        //pProduct.DisplayId = 0;
        //pProduct.ItemId = 0;
        //pProduct.UnkInt4 = 0;
        //pProduct.UnkInt5 = 0;
        //pProduct.UnkString = "";
        //pProduct.UnkBit = false;

        for (auto& item : product.Items)
        {
            WorldPackets::BattlePay::ProductItem pItem;
            pItem.ID = item.ID;
            pItem.ItemID = product.Items.size() > 1 ? 0 : item.ItemID; ///< Disable tooltip for packs (client handle only one tooltip).
            pItem.Quantity = item.Quantity;
            //pItem.UnkInt1 = 0;
            //pItem.UnkInt2 = 0;
            //pItem.UnkByte = 0;
            pItem.HasPet = AlreadyOwnProduct(item.ItemID);
            pItem.PetResult = item.PetResult;

            auto dataP = WriteDisplayInfo(item.DisplayInfoID, localeIndex);
            if (std::get<0>(dataP))
            {
                pItem.DisplayInfo = boost::in_place();
                pItem.DisplayInfo = std::get<1>(dataP);
            }

            pProduct.Items.emplace_back(pItem);
        }

        auto dataP = WriteDisplayInfo(product.DisplayInfoID, localeIndex);
        if (std::get<0>(dataP))
        {
            pProduct.DisplayInfo = boost::in_place();
            pProduct.DisplayInfo = std::get<1>(dataP);
        }

        response.ProductList.Product.emplace_back(pProduct);
    }

    _session->SendPacket(response.Write());
}

std::tuple<bool, WorldPackets::BattlePay::ProductDisplayInfo> BattlepayManager::WriteDisplayInfo(uint32 displayInfoID, LocaleConstant localeIndex, uint32 productId /*= 0*/)
{
    auto GeneratePackDescription = [localeIndex](Product const* product) -> std::string
    {
        auto getQualityColor = [](uint32 quality) -> std::string
        {
            switch (quality)
            {
            case ITEM_QUALITY_POOR:
                return "|cff9d9d9d";
            case ITEM_QUALITY_NORMAL:
                return "|cffffffff";
            case ITEM_QUALITY_UNCOMMON:
                return "|cff1eff00";
            case ITEM_QUALITY_RARE:
                return "|cff0070dd";
            case ITEM_QUALITY_EPIC:
                return "|cffa335ee";
            case ITEM_QUALITY_LEGENDARY:
                return "|cffff8000";
            case ITEM_QUALITY_ARTIFACT:
                return "|cffe5cc80";
            case ITEM_QUALITY_HEIRLOOM:
                return "|cffe5cc80";
            default:
                return "|cffe5cc80";
            }
        };

        std::string res;
        for (auto itr : product->Items)
            if (auto itemTemplate = sObjectMgr->GetItemTemplate(itr.ItemID))
                res += getQualityColor(itemTemplate->GetQuality()) + itemTemplate->GetName()->Get(localeIndex) + "\n";
        return res;
    };

    auto info = WorldPackets::BattlePay::ProductDisplayInfo();
    if (!displayInfoID)
        return std::make_tuple(false, info);

    auto displayInfo = sBattlePayDataStore->GetDisplayInfo(displayInfoID);
    if (!displayInfo)
        return std::make_tuple(false, info);

    auto displayLocale = sBattlePayDataStore->GetDisplayInfoLocale(displayInfoID);

    info.Name1 = displayInfo->Name1;
    if (displayLocale)
        ObjectMgr::GetLocaleString(displayLocale->Name1, localeIndex, info.Name1);

    info.Name2 = displayInfo->Name2;
    if (displayLocale)
        ObjectMgr::GetLocaleString(displayLocale->Name2, localeIndex, info.Name2);

    info.Name3 = displayInfo->Name3;
    if (productId)
    {
        auto product = sBattlePayDataStore->GetProduct(productId);
        if (!product->Items.empty())
            info.Name3 = GeneratePackDescription(product);
    }
    else if (displayLocale)
        ObjectMgr::GetLocaleString(displayLocale->Name3, localeIndex, info.Name3);

    info.Name4 = displayInfo->Name4;
    if (displayLocale)
        ObjectMgr::GetLocaleString(displayLocale->Name4, localeIndex, info.Name4);

    if (displayInfo->CreatureDisplayInfoID != 0)
        info.CreatureDisplayInfoID = displayInfo->CreatureDisplayInfoID;

    if (auto visualsId = displayInfo->VisualsId)
    {
        if (auto visuals = sBattlePayDataStore->GetDisplayInfoVisuals(displayInfoID))
        {
            info.VisualsId = displayInfo->VisualsId;

            for (auto const& itr : *visuals)
            {
                WorldPackets::BattlePay::ProductDisplayVisualData visual;
                visual.DisplayId = itr.DisplayId;
                visual.VisualId = itr.VisualId;
                visual.ProductName = itr.ProductName;
                info.Visuals.emplace_back(visual);
            }
        }
    }

    if (displayInfo->Flags != 0)
        info.Flags = displayInfo->Flags;

    //Optional<uint32> UnkInt1;
    //Optional<uint32> UnkInt2;
    //Optional<uint32> UnkInt3;

    return std::make_tuple(true, info);
}

void BattlepayManager::SendPointsBalance()
{
    auto player = _session->GetPlayer();

    if (!player)
        return;

    ChatHandler(player->GetSession()).PSendSysMessage("|cff7ebff1 | Account: (%u) %s | Credits: %u |", player->GetSession()->GetAccountId(), player->GetSession()->GetAccountName().c_str(), player->GetDonateTokens());
}

void BattlepayManager::SendBattlePayDistribution(uint32 productId, uint8 status, uint64 distributionId, ObjectGuid targetGuid)
{
    WorldPackets::BattlePay::DistributionUpdate distributionBattlePay;
    auto product = sBattlePayDataStore->GetProduct(productId);
    if (!product || !product->ProductID)
        return;

    auto const& localeIndex = _session->GetSessionDbLocaleIndex();
    distributionBattlePay.DistributionObject.DistributionID = distributionId;
    distributionBattlePay.DistributionObject.Status = status;
    distributionBattlePay.DistributionObject.ProductID = productId;
    distributionBattlePay.DistributionObject.Revoked = false; // not needed for us

    if (!targetGuid.IsEmpty())
    {
        distributionBattlePay.DistributionObject.TargetPlayer = targetGuid;
        distributionBattlePay.DistributionObject.TargetVirtualRealm = GetVirtualRealmAddress();
        distributionBattlePay.DistributionObject.TargetNativeRealm = GetVirtualRealmAddress();
    }

    WorldPackets::BattlePay::BattlePayProduct productData;

    for (auto const& item : product->Items)
    {
        WorldPackets::BattlePay::ProductItem productItem;

        auto dataP = WriteDisplayInfo(item.DisplayInfoID, localeIndex);
        if (std::get<0>(dataP))
        {
            productItem.DisplayInfo = boost::in_place();
            productItem.DisplayInfo = std::get<1>(dataP);
        }

        productItem.PetResult = item.PetResult;
        productItem.ID = item.ID;
        productItem.ItemID = item.ItemID;
        productItem.Quantity = item.Quantity;
        productItem.UnkInt1 = item.DisplayInfoID;
        productItem.UnkInt2 = 0;
        productItem.PetResult = 0;;
        productItem.HasPet = item.HasPet;
        productData.Items.emplace_back(productItem);
    }

    auto dataP = WriteDisplayInfo(product->DisplayInfoID, localeIndex);
    if (std::get<0>(dataP))
    {
        productData.DisplayInfo = boost::in_place();
        productData.DisplayInfo = std::get<1>(dataP);
    }

    //productData.UnkBits       Optional<uint16> ;
    productData.ProductID = product->ProductID;
    productData.Flags = product->Flags;
    productData.UnkInt1 = 0;
    productData.DisplayId = product->DisplayInfoID;
    productData.ItemId = 0;
    productData.UnkInt4 = 0;
    productData.UnkInt5 = 0;
    productData.UnkString = "";
    productData.Type = 0;
    productData.UnkBit = false;
    distributionBattlePay.DistributionObject.Product = std::move(productData);
    _session->SendPacket(distributionBattlePay.Write());
}

void BattlepayManager::AssignDistributionToCharacter(ObjectGuid const& targetCharGuid, uint64 distributionId, uint32 productId, uint16 specId, uint16 choiceId)
{
    WorldPackets::BattlePay::UpgradeStarted upgrade;
    upgrade.CharacterGUID = targetCharGuid;
    _session->SendPacket(upgrade.Write());

    WorldPackets::BattlePay::BattlePayStartDistributionAssignToTargetResponse assignResponse;
    assignResponse.DistributionID = distributionId;
    assignResponse.unkint1 = 0;
    assignResponse.unkint2 = 0;
    _session->SendPacket(upgrade.Write());

    auto purchase = GetPurchase();
    purchase->Status = DistributionStatus::BATTLE_PAY_DIST_STATUS_ADD_TO_PROCESS;

    SendBattlePayDistribution(productId, purchase->Status, distributionId, targetCharGuid);
}

void BattlepayManager::Update(uint32 diff)
{
    auto& data = _actualTransaction;
    auto product = sBattlePayDataStore->GetProduct(data.ProductID);
    if (!product)
        return;

    switch (data.Status)
    {
    case DistributionStatus::BATTLE_PAY_DIST_STATUS_ADD_TO_PROCESS:
    {
        switch (product->WebsiteType)
        {
        case CharacterBoost:
        {
            auto const& player = ObjectAccessor::GetObjectInOrOutOfWorld(data.TargetCharacter, static_cast<Player*>(nullptr));
            if (!player)
                break;

            WorldPackets::BattlePay::BattlePayCharacterUpgradeQueued responseQueued;
            responseQueued.EquipmentItems = sDB2Manager.GetItemLoadOutItemsByClassID(player->getClass(), 3)[0];
            responseQueued.Character = data.TargetCharacter;
            _session->SendPacket(responseQueued.Write());

            data.Status = DistributionStatus::BATTLE_PAY_DIST_STATUS_PROCESS_COMPLETE;
            SendBattlePayDistribution(data.ProductID, data.Status, data.DistributionId, data.TargetCharacter);
            break;
        }
        default:
            break;
        }
        break;
    }
    case DistributionStatus::BATTLE_PAY_DIST_STATUS_PROCESS_COMPLETE: //send SMSG_BATTLE_PAY_VAS_PURCHASE_STARTED
    {
        switch (product->WebsiteType)
        {
        case CharacterBoost:
        {
            data.Status = DistributionStatus::BATTLE_PAY_DIST_STATUS_FINISHED;
            SendBattlePayDistribution(data.ProductID, data.Status, data.DistributionId, data.TargetCharacter);
            break;
        }
        default:
            break;
        }
        break;
    }
    case DistributionStatus::BATTLE_PAY_DIST_STATUS_FINISHED:
    {
        switch (product->WebsiteType)
        {
        case CharacterBoost:
            SendBattlePayDistribution(data.ProductID, data.Status, data.DistributionId, data.TargetCharacter);
            break;
        default:
            break;
        }
        break;
    }
    case DistributionStatus::BATTLE_PAY_DIST_STATUS_AVAILABLE:
    case DistributionStatus::BATTLE_PAY_DIST_STATUS_NONE:
    default:
        break;
    }
}