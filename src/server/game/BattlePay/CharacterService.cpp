#include "BattlePayPackets.h"
#include "BattlePayMgr.h"
#include "BattlePayData.h"
#include "CharacterService.h"
#include "DatabaseEnv.h"
#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include <stdsoap2.h>
#include "QuestData.h"
#include <BattlenetHandler.cpp>
#include "SourceService.h"
#include "GameTables.h"
#include "Guild.h"
#include "GuildPackets.h"
#include "GuildMgr.h"
#include "CollectionMgr.h"
#include "Player.h"

CharacterService* CharacterService::instance()
{
    static CharacterService instance;
    return &instance;
}

void CharacterService::SetRename(Player* player)
{
    player->SetAtLoginFlag(AT_LOGIN_RENAME);

    auto stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_ADD_AT_LOGIN_FLAG);
    stmt->setUInt16(0, AT_LOGIN_RENAME);
    stmt->setUInt64(1, player->GetGUID().GetCounter());
    CharacterDatabase.Execute(stmt);
}

void CharacterService::ChangeFaction(Player* player)
{
    player->SetAtLoginFlag(AT_LOGIN_CHANGE_FACTION);

    auto stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_ADD_AT_LOGIN_FLAG);
    stmt->setUInt16(0, AT_LOGIN_CHANGE_FACTION);
    stmt->setUInt64(1, player->GetGUID().GetCounter());
    CharacterDatabase.Execute(stmt);
}

void CharacterService::ChangeRace(Player* player)
{
    player->SetAtLoginFlag(AT_LOGIN_CHANGE_RACE);

    auto stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_ADD_AT_LOGIN_FLAG);
    stmt->setUInt16(0, AT_LOGIN_CHANGE_RACE);
    stmt->setUInt64(1, player->GetGUID().GetCounter());
    CharacterDatabase.Execute(stmt);
}

void CharacterService::Customize(Player* player)
{
    player->SetAtLoginFlag(AT_LOGIN_CUSTOMIZE);

    auto stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_ADD_AT_LOGIN_FLAG);
    stmt->setUInt16(0, AT_LOGIN_CUSTOMIZE);
    stmt->setUInt64(1, player->GetGUID().GetCounter());
    CharacterDatabase.Execute(stmt);
}

void CharacterService::Boost(Player* player)
{
    player->GetSession()->AddAuthFlag(AT_AUTH_FLAG_20_LVL_UP);
}

void CharacterService::RestoreDeletedCharacter(WorldSession* session)
{
    session->AddAuthFlag(AT_AUTH_FLAG_RESTORE_DELETED_CHARACTER);
}

void CharacterService::UnlockMOPChallengeModeTransmog(Player* player)
{
	switch (player->getClass())
	{
	case CLASS_DEMON_HUNTER:
		// DH Can't see this product
		break;
	case CLASS_DRUID:
		player->GetCollectionMgr()->AddTransmogSet(1445);
		break;
	case CLASS_MONK:
		player->GetCollectionMgr()->AddTransmogSet(1442);
		break;
	case CLASS_WARLOCK:
		player->GetCollectionMgr()->AddTransmogSet(1437);
		break;
	case CLASS_SHAMAN:
		player->GetCollectionMgr()->AddTransmogSet(1438);
		break;
	case CLASS_DEATH_KNIGHT:
		player->GetCollectionMgr()->AddTransmogSet(1446);
		break;
	case CLASS_PRIEST:
		player->GetCollectionMgr()->AddTransmogSet(1440);
		break;
	case CLASS_ROGUE:
		player->GetCollectionMgr()->AddTransmogSet(1439);
		break;
	case CLASS_HUNTER:
		player->GetCollectionMgr()->AddTransmogSet(1444);
		break;
	case CLASS_PALADIN:
		player->GetCollectionMgr()->AddTransmogSet(1441);
		break;
	case CLASS_WARRIOR:
		player->GetCollectionMgr()->AddTransmogSet(1436);
		break;
	case CLASS_MAGE:
		player->GetCollectionMgr()->AddTransmogSet(1443);
		break;
	default:
		break;
	}
}

void CharacterService::Gold20k(Player* player)
{
	player->ModifyMoney(200000000);
	player->SendCustomMessage("|cffff8000  20,000 gold has been added..");
}
void CharacterService::Gold50k(Player* player)
{
	player->ModifyMoney(500000000);
	player->SendCustomMessage("|cffff8000  50,000 gold has been added..");
}
void CharacterService::Gold100k(Player* player)
{
	player->ModifyMoney(1000000000);
	player->SendCustomMessage("|cffff8000  100,000 gold has been added..");
}
void CharacterService::Gold250k(Player* player)
{
	player->ModifyMoney(2500000000);
	player->SendCustomMessage("|cffff8000  250,000 gold have been added..");
}
void CharacterService::Gold500k(Player* player)
{
	player->ModifyMoney(5000000000);
	player->SendCustomMessage("|cffff8000  500,000 gold has been added..");
}
void CharacterService::Gold1000k(Player* player)
{
	player->ModifyMoney(10000000000);
	player->SendCustomMessage("|cffff8000  1,000,000 gold has been added..");
}

void CharacterService::ProfPriAlchemy(Player* player)
{
	if (player->HasSkill(SKILL_ALCHEMY))
	{
		player->GetSession()->SendNotification(EXISTING, LANG_UNIVERSAL, NULL);
		return;
	}
	if (PlayerAlreadyHasTwoProfessions(player))
	{
		player->GetSession()->SendNotification(ALREADY_KNOWN, LANG_UNIVERSAL, NULL);
		return;
	}
	else
		player->HasSkill(SKILL_ALCHEMY);
	CompleteLearnProfession(player, SKILL_ALCHEMY);
}
void CharacterService::ProfPriSastre(Player* player)
{
	if (player->HasSkill(SKILL_TAILORING))
	{
		player->GetSession()->SendNotification(EXISTING, LANG_UNIVERSAL, NULL);
		return;
	}
	if (PlayerAlreadyHasTwoProfessions(player))
	{
		player->GetSession()->SendNotification(ALREADY_KNOWN, LANG_UNIVERSAL, NULL);
		return;
	}
	else
		player->HasSkill(SKILL_TAILORING);
	CompleteLearnProfession(player, SKILL_TAILORING);
}
void CharacterService::ProfPriJoye(Player* player)
{
	if (player->HasSkill(SKILL_JEWELCRAFTING))
	{
		player->GetSession()->SendNotification(EXISTING, LANG_UNIVERSAL, NULL);
		return;
	}
	if (PlayerAlreadyHasTwoProfessions(player))
	{
		player->GetSession()->SendNotification(ALREADY_KNOWN, LANG_UNIVERSAL, NULL);
		return;
	}
	else
		player->HasSkill(SKILL_JEWELCRAFTING);
	CompleteLearnProfession(player, SKILL_JEWELCRAFTING);
}
void CharacterService::ProfPriHerre(Player* player)
{
	if (player->HasSkill(SKILL_BLACKSMITHING))
	{
		player->GetSession()->SendNotification(EXISTING, LANG_UNIVERSAL, NULL);
		return;
	}
	if (PlayerAlreadyHasTwoProfessions(player))
	{
		player->GetSession()->SendNotification(ALREADY_KNOWN, LANG_UNIVERSAL, NULL);
		return;
	}
	else
		player->HasSkill(SKILL_BLACKSMITHING);
	CompleteLearnProfession(player, SKILL_BLACKSMITHING);
}
void CharacterService::ProfPriPele(Player* player)
{
	if (player->HasSkill(SKILL_LEATHERWORKING))
	{
		player->GetSession()->SendNotification(EXISTING, LANG_UNIVERSAL, NULL);
		return;
	}
	if (PlayerAlreadyHasTwoProfessions(player))
	{
		player->GetSession()->SendNotification(ALREADY_KNOWN, LANG_UNIVERSAL, NULL);
		return;
	}
	else
		player->HasSkill(SKILL_LEATHERWORKING);
	CompleteLearnProfession(player, SKILL_LEATHERWORKING);

}
void CharacterService::ProfPriInge(Player* player)
{
	if (player->HasSkill(SKILL_ENGINEERING))
	{
		player->GetSession()->SendNotification(EXISTING, LANG_UNIVERSAL, NULL);
		return;
	}
	if (PlayerAlreadyHasTwoProfessions(player))
	{
		player->GetSession()->SendNotification(ALREADY_KNOWN, LANG_UNIVERSAL, NULL);
		return;
	}
	else
		player->HasSkill(SKILL_ENGINEERING);
	CompleteLearnProfession(player, SKILL_ENGINEERING);
}
void CharacterService::ProfPriInsc(Player* player)
{
	if (player->HasSkill(SKILL_INSCRIPTION))
	{
		player->GetSession()->SendNotification(EXISTING, LANG_UNIVERSAL, NULL);
		return;
	}
	if (PlayerAlreadyHasTwoProfessions(player))
	{
		player->GetSession()->SendNotification(ALREADY_KNOWN, LANG_UNIVERSAL, NULL);
		return;
	}
	else
		player->HasSkill(SKILL_INSCRIPTION);
	CompleteLearnProfession(player, SKILL_INSCRIPTION);
}
void CharacterService::ProfPriEncha(Player* player)
{
	if (player->HasSkill(SKILL_ENCHANTING))
	{
		player->GetSession()->SendNotification(EXISTING, LANG_UNIVERSAL, NULL);
		return;
	}
	if (PlayerAlreadyHasTwoProfessions(player))
	{
		player->GetSession()->SendNotification(ALREADY_KNOWN, LANG_UNIVERSAL, NULL);
		return;
	}
	else
		player->HasSkill(SKILL_ENCHANTING);
	CompleteLearnProfession(player, SKILL_ENCHANTING);
}
void CharacterService::ProfPriDesu(Player* player)
{
	if (player->HasSkill(SKILL_SKINNING))
	{
		player->GetSession()->SendNotification(EXISTING, LANG_UNIVERSAL, NULL);
		return;
	}
	if (PlayerAlreadyHasTwoProfessions(player))
	{
		player->GetSession()->SendNotification(ALREADY_KNOWN, LANG_UNIVERSAL, NULL);
		return;
	}
	else
		player->HasSkill(SKILL_SKINNING);
	CompleteLearnProfession(player, SKILL_SKINNING);
}
void CharacterService::ProfPriMing(Player* player)
{
	if (player->HasSkill(SKILL_MINING))
	{
		player->GetSession()->SendNotification(EXISTING, LANG_UNIVERSAL, NULL);
		return;
	}
	if (PlayerAlreadyHasTwoProfessions(player))
	{
		player->GetSession()->SendNotification(ALREADY_KNOWN, LANG_UNIVERSAL, NULL);
		return;
	}
	else
		player->HasSkill(SKILL_MINING);
	CompleteLearnProfession(player, SKILL_MINING);
}
void CharacterService::ProfPriHerb(Player* player, WorldSession* session)
{
	Battlepay::PaymentFailed;
	Battlepay::PurchaseDenied;
	Battlepay::Purchase purchase;
	if (player->HasSkill(SKILL_HERBALISM))
	{
		player->SendCustomMessage(GetCustomMessage(Battlepay::CustomMessage::StoreBuyFailed));
		Battlepay::Error::PurchaseDenied;
		player->GetSession()->SendNotification(EXISTING, LANG_UNIVERSAL, NULL);
		return;
	}
	if (PlayerAlreadyHasTwoProfessions(player))
	{
		Battlepay::Error::PurchaseDenied;
		player->SendCustomMessage(GetCustomMessage(Battlepay::CustomMessage::StoreBuyFailed));
		player->GetSession()->SendNotification(ALREADY_KNOWN, LANG_UNIVERSAL, NULL);
		return;
	}
	else
		player->HasSkill(SKILL_HERBALISM);
	CompleteLearnProfession(player, SKILL_HERBALISM);
}

void CharacterService::ProfSecCoci(Player* player)
{
	player->HasSkill(SKILL_COOKING);
	CompleteLearnProfession(player, SKILL_COOKING);
	player->GetSession()->SendNotification("|cff00FF00You have learned Cooking with all its recipes and reached the maximum level.");
}
void CharacterService::ProfSecPrau(Player* player)
{
	player->HasSkill(SKILL_FIRST_AID);
	CompleteLearnProfession(player, SKILL_FIRST_AID);
	player->GetSession()->SendNotification("|cff00FF00You have learned First Aid with all its recipes and reached the maximum level.");
}
void CharacterService::ProfSecArque(Player* player)
{
	player->learnSpell(80836, false);
	player->learnSpell(89129, false);
	player->learnSpell(89723, false);
	player->learnSpell(89724, false);
	player->learnSpell(89725, false);
	player->learnSpell(89726, false);
	player->learnSpell(89727, false);
	player->learnSpell(110394, false);
	player->learnSpell(158763, false);
	player->learnSpell(201709, false);
	CompleteLearnProfession(player, SKILL_ARCHAEOLOGY);
	player->GetSession()->SendNotification("|cff00FF00You have learned Archeology with all its recipes and reached the maximum level.");
}
void CharacterService::ProfSecFish(Player* player)
{
	player->learnSpell(7733, false);
	player->learnSpell(7734, false);
	player->learnSpell(18249, false);
	player->learnSpell(19889, false);
	player->learnSpell(33100, false);
	player->learnSpell(51293, false);
	player->learnSpell(88869, false);
	player->learnSpell(110412, false);
	player->learnSpell(158744, false);
	player->learnSpell(210829, false);
	player->HasSkill(SKILL_FISHING);
	CompleteLearnProfession(player, SKILL_FISHING);
	player->GetSession()->SendNotification("|cff00FF00You have learned Fishing with all its recipes and have reached the maximum level.");
}
// Restart Raids and Dungeons
void CharacterService::Unbinall(Player* player)
{
	for (uint8 i = 0; i < MAX_DIFFICULTY; ++i)
	{
		Player::BoundInstancesMap& binds = player->GetBoundInstances(Difficulty(i));
		for (Player::BoundInstancesMap::iterator itr = binds.begin(); itr != binds.end();)
		{
			InstanceSave* save = itr->second.save;
			if (itr->first != player->GetMapId())
				player->UnbindInstance(itr, Difficulty(i));
			else
				++itr;
		}
	}
	player->GetSession()->SendNotification("|cff00FF00 All dungeons and raids have been restarted.");
}

void CharacterService::RacesAlliedHighmountainTauren(Player* player)
{
	player->CompletedAchievement(sAchievementStore.LookupEntry(10059)); 
	player->CompletedAchievement(sAchievementStore.LookupEntry(12245));
	player->learnSpell(258060, false);
}

void CharacterService::RacesAlliedNightborne(Player* player)
{
	player->CompletedAchievement(sAchievementStore.LookupEntry(11340)); 
	player->CompletedAchievement(sAchievementStore.LookupEntry(12244));
	player->learnSpell(258845, false);
}

void CharacterService::RacesAlliedVoidElf(Player* player)
{
	player->CompletedAchievement(sAchievementStore.LookupEntry(12066)); 
	player->CompletedAchievement(sAchievementStore.LookupEntry(12242));
	player->learnSpell(259202, false);
}

void CharacterService::RacesAlliedLighForgedDraenei(Player* player)
{
	player->CompletedAchievement(sAchievementStore.LookupEntry(12066)); 
	player->CompletedAchievement(sAchievementStore.LookupEntry(12243));
	player->learnSpell(258022, false);
}

void CharacterService::RepClassic(Player* player)
{
	player->SetReputation(21, 42000);
	player->SetReputation(576, 42000);
	player->SetReputation(87, 42000);
	player->SetReputation(92, 42000);
	player->SetReputation(93, 42000);
	player->SetReputation(609, 42000);
	player->SetReputation(529, 42000);
	player->SetReputation(909, 42000);
	player->SetReputation(369, 42000);
	player->SetReputation(59, 42000);
	player->SetReputation(910, 42000);
	player->SetReputation(349, 42000);
	player->SetReputation(809, 42000);
	player->SetReputation(749, 42000);
	player->SetReputation(270, 42000);
	player->SetReputation(470, 42000);
	player->SetReputation(577, 42000);
	player->SetReputation(70, 42000);
	player->SetReputation(1357, 42000);
	player->SetReputation(1975, 42000);

	if (player->GetTeam() == ALLIANCE)
	{
		player->SetReputation(890, 42000);
		player->SetReputation(1691, 42000);
		player->SetReputation(1419, 42000);
		player->SetReputation(69, 42000);
		player->SetReputation(930, 42000);
		player->SetReputation(47, 42000);
		player->SetReputation(1134, 42000);
		player->SetReputation(54, 42000);
		player->SetReputation(730, 42000);
		player->SetReputation(509, 42000);
		player->SetReputation(1353, 42000);
		player->SetReputation(72, 42000);
		player->SetReputation(589, 42000);
	}
	else // Repu Horde
	{
		player->SetReputation(1690, 42000);
		player->SetReputation(1374, 42000);
		player->SetReputation(1133, 42000);
		player->SetReputation(81, 42000);
		player->SetReputation(729, 42000);
		player->SetReputation(68, 42000);
		player->SetReputation(889, 42000);
		player->SetReputation(510, 42000);
		player->SetReputation(911, 42000);
		player->SetReputation(76, 42000);
		player->SetReputation(1352, 42000);
		player->SetReputation(530, 42000);
	}
	player->GetSession()->SendNotification("|cff00FF00All the Classic Reputations have been increased.!");
	return;
}
void CharacterService::RepBurnig(Player* player)
{
	player->SetReputation(1015, 42000);
	player->SetReputation(1011, 42000);
	player->SetReputation(933, 42000);
	player->SetReputation(967, 42000);
	player->SetReputation(970, 42000);
	player->SetReputation(942, 42000);
	player->SetReputation(1031, 42000);
	player->SetReputation(1012, 42000);
	player->SetReputation(990, 42000);
	player->SetReputation(932, 42000);
	player->SetReputation(934, 42000);
	player->SetReputation(935, 42000);
	player->SetReputation(1077, 42000);
	player->SetReputation(1038, 42000);
	player->SetReputation(989, 42000);

	if (player->GetTeam() == ALLIANCE)
	{
		player->SetReputation(946, 42000);
		player->SetReputation(978, 42000);
	}
	else // Repu Horde
	{
		player->SetReputation(941, 42000);
		player->SetReputation(947, 42000);
		player->SetReputation(922, 42000);
	}
	player->GetSession()->SendNotification("|cff00FF00All Burning Crusade Reputations have been increased.!");
	return;
}
void CharacterService::RepTLK(Player* player)
{
	player->SetReputation(1242, 42000);
	player->SetReputation(1376, 42000);
	player->SetReputation(1387, 42000);
	player->SetReputation(1135, 42000);
	player->SetReputation(1158, 42000);
	player->SetReputation(1173, 42000);
	player->SetReputation(1171, 42000);
	player->SetReputation(1204, 42000);
	if (player->GetTeam() == ALLIANCE)
	{
		player->SetReputation(1177, 42000);
		player->SetReputation(1174, 42000);
	}
	else // Repu Horde
	{
		player->SetReputation(1172, 42000);
		player->SetReputation(1178, 42000);
	}
	player->SetReputation(529, 42000);
	player->GetSession()->SendNotification("|cff00FF00All The Lich King Reputations increased!");
	return;
}
void CharacterService::RepCata(Player* player)
{
	player->SetReputation(1091, 42000);
	player->SetReputation(1098, 42000);
	player->SetReputation(1106, 42000);
	player->SetReputation(1156, 42000);
	player->SetReputation(1090, 42000);
	player->SetReputation(1119, 42000);
	player->SetReputation(1073, 42000);
	player->SetReputation(1105, 42000);
	player->SetReputation(1104, 42000);

	if (player->GetTeam() == ALLIANCE)
	{
		player->SetReputation(1094, 42000);
		player->SetReputation(1050, 42000);
		player->SetReputation(1068, 42000);
		player->SetReputation(1126, 42000);
		player->SetReputation(1037, 42000);
	}
	else // Repu Horde
	{
		player->SetReputation(1052, 42000);
		player->SetReputation(1067, 42000);
		player->SetReputation(1124, 42000);
		player->SetReputation(1064, 42000);
		player->SetReputation(1085, 42000);
	}
	player->GetSession()->SendNotification("|cff00FF00All Cataclysm Reputations have been increased.!");
	return;
}
void CharacterService::RepPanda(Player* player)
{
	player->SetReputation(1216, 42000);
	player->SetReputation(1435, 42000);
	player->SetReputation(1277, 42000);
	player->SetReputation(1359, 42000);
	player->SetReputation(1275, 42000);
	player->SetReputation(1492, 42000);
	player->SetReputation(1281, 42000);
	player->SetReputation(1283, 42000);
	player->SetReputation(1279, 42000);
	player->SetReputation(1273, 42000);
	player->SetReputation(1341, 42000);
	player->SetReputation(1345, 42000);
	player->SetReputation(1337, 42000);
	player->SetReputation(1272, 42000);
	player->SetReputation(1351, 42000);
	player->SetReputation(1302, 42000);
	player->SetReputation(1269, 42000);
	player->SetReputation(1358, 42000);
	player->SetReputation(1271, 42000);
	player->SetReputation(1282, 42000);
	player->SetReputation(1440, 42000);
	player->SetReputation(1270, 42000);
	player->SetReputation(1278, 42000);
	player->SetReputation(1280, 42000);
	player->SetReputation(1276, 42000);

	if (player->GetTeam() == ALLIANCE)
	{
		player->SetReputation(1242, 42000);
		player->SetReputation(1376, 42000);
		player->SetReputation(1387, 42000);

	}
	else // Repu Horde
	{
		player->SetReputation(1388, 42000);
		player->SetReputation(1228, 42000);
		player->SetReputation(1375, 42000);
	}
	player->GetSession()->SendNotification("|cff00FF00All Pandaria Reputations have been increased.!");
	return;
}
void CharacterService::RepDraenor(Player* player)
{
	player->SetReputation(1850, 42000);
	player->SetReputation(1515, 42000);
	player->SetReputation(1520, 42000);
	player->SetReputation(1732, 42000);
	player->SetReputation(1735, 42000);
	player->SetReputation(1741, 42000);
	player->SetReputation(1849, 42000);
	player->SetReputation(1737, 42000);
	player->SetReputation(1711, 42000);
	player->SetReputation(1736, 42000);
	// Repu Alianza
	if (player->GetTeam() == ALLIANCE)
	{
		player->SetReputation(1731, 42000);
		player->SetReputation(1710, 42000);
		player->SetReputation(1738, 42000);
		player->SetReputation(1733, 42000);
		player->SetReputation(1847, 42000);
		player->SetReputation(1682, 42000);
	}
	else // Repu Horde
	{
		player->SetReputation(1740, 42000);
		player->SetReputation(1681, 42000);
		player->SetReputation(1445, 42000);
		player->SetReputation(1708, 42000);
		player->SetReputation(1848, 42000);
		player->SetReputation(1739, 42000);
	}
	player->GetSession()->SendNotification("|cff00FF00All Draenor Reputations have been increased.!");
	return;
}
void CharacterService::RepLegion(Player* player)
{
	player->SetReputation(1919, 42000);
	player->SetReputation(1859, 42000);
	player->SetReputation(1900, 42000);
	player->SetReputation(1899, 42000);
	player->SetReputation(1989, 42000);
	player->SetReputation(1947, 42000);
	player->SetReputation(1894, 42000);
	player->SetReputation(1984, 42000);
	player->SetReputation(1862, 42000);
	player->SetReputation(1861, 42000);
	player->SetReputation(1860, 42000);
	player->SetReputation(1815, 42000);
	player->SetReputation(1883, 42000);
	player->SetReputation(1828, 42000);
	player->SetReputation(1948, 42000);
	player->SetReputation(2018, 42000);
	player->SetReputation(1888, 42000);
	player->SetReputation(2045, 42000);
	player->SetReputation(2170, 42000);
	player->SetReputation(2165, 42000);
	player->GetSession()->SendNotification("|cff00FF00 All Legion Reputations have been increased.!");
	return;
}

void CharacterService::AppareanceArtifact(Player* player)
{
	player->CompletedAchievement(sAchievementStore.LookupEntry(10460));
	player->CompletedAchievement(sAchievementStore.LookupEntry(11165));
	player->CompletedAchievement(sAchievementStore.LookupEntry(10743));
	player->CompletedAchievement(sAchievementStore.LookupEntry(10748));
	player->CompletedAchievement(sAchievementStore.LookupEntry(11163));
	player->CompletedAchievement(sAchievementStore.LookupEntry(11160));
	player->CompletedAchievement(sAchievementStore.LookupEntry(10747));
	player->CompletedAchievement(sAchievementStore.LookupEntry(10602));
	player->CompletedAchievement(sAchievementStore.LookupEntry(10853));
	player->CompletedAchievement(sAchievementStore.LookupEntry(11144));
	player->CompletedAchievement(sAchievementStore.LookupEntry(10746));
	player->CompletedAchievement(sAchievementStore.LookupEntry(10461));
	player->CompletedAchievement(sAchievementStore.LookupEntry(10460));
	player->CompletedAchievement(sAchievementStore.LookupEntry(10459));
	player->CompletedAchievement(sAchievementStore.LookupEntry(11162));
	if (player->GetTeam() == ALLIANCE)
	{
		// Alianza
		player->CompletedAchievement(sAchievementStore.LookupEntry(10749));
		player->CompletedAchievement(sAchievementStore.LookupEntry(10743));
		player->CompletedAchievement(sAchievementStore.LookupEntry(11165));
		player->CompletedAchievement(sAchievementStore.LookupEntry(11167));
		player->CompletedAchievement(sAchievementStore.LookupEntry(11169));
	}
	else // Horda
	{
		player->CompletedAchievement(sAchievementStore.LookupEntry(11170));
		player->CompletedAchievement(sAchievementStore.LookupEntry(11168));
		player->CompletedAchievement(sAchievementStore.LookupEntry(11166));
		player->CompletedAchievement(sAchievementStore.LookupEntry(10745));
		player->CompletedAchievement(sAchievementStore.LookupEntry(11173));
	}
	player->SendCustomMessage("|cffff8000  New Appearances Unlocked..");
}