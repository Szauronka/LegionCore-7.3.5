/*
 * Copyright (C) 2011 TrintiyCore <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include <boost/regex.hpp>
#include "DB2HotfixGenerator.h"
#include "DB2Stores.h"
#include "Common.h"
#include "DB2LoadInfo.h"
#include "DatabaseEnv.h"
#include "ObjectMgr.h"

DB2Storage<AchievementEntry>                    sAchievementStore("Achievement.db2", AchievementLoadInfo::Instance());
DB2Storage<AdventureJournalEntry>               sAdventureJournalStore("AdventureJournal.db2", AdventureJournalLoadInfo::Instance());
DB2Storage<AdventureMapPOIEntry>                sAdventureMapPOIStore("AdventureMapPOI.db2", AdventureMapPOILoadInfo::Instance());
DB2Storage<AnimKitEntry>                        sAnimKitStore("AnimKit.db2", AnimKitLoadInfo::Instance());
DB2Storage<AreaGroupMemberEntry>                sAreaGroupMemberStore("AreaGroupMember.db2", AreaGroupMemberLoadInfo::Instance());
DB2Storage<AreaTableEntry>                      sAreaTableStore("AreaTable.db2", AreaTableLoadInfo::Instance());
DB2Storage<AreaTriggerEntry>                    sAreaTriggerStore("AreaTrigger.db2", AreaTriggerLoadInfo::Instance());
DB2Storage<ArmorLocationEntry>                  sArmorLocationStore("ArmorLocation.db2", ArmorLocationLoadInfo::Instance());
DB2Storage<ArtifactEntry>                       sArtifactStore("Artifact.db2", ArtifactLoadInfo::Instance());
DB2Storage<ArtifactAppearanceEntry>             sArtifactAppearanceStore("ArtifactAppearance.db2", ArtifactAppearanceLoadInfo::Instance());
DB2Storage<ArtifactAppearanceSetEntry>          sArtifactAppearanceSetStore("ArtifactAppearanceSet.db2", ArtifactAppearanceSetLoadInfo::Instance());
DB2Storage<ArtifactCategoryEntry>               sArtifactCategoryStore("ArtifactCategory.db2", ArtifactCategoryLoadInfo::Instance());
DB2Storage<ArtifactPowerEntry>                  sArtifactPowerStore("ArtifactPower.db2", ArtifactPowerLoadInfo::Instance());
DB2Storage<ArtifactPowerLinkEntry>              sArtifactPowerLinkStore("ArtifactPowerLink.db2", ArtifactPowerLinkLoadInfo::Instance());
DB2Storage<ArtifactPowerPickerEntry>            sArtifactPowerPickerStore("ArtifactPowerPicker.db2", ArtifactPowerPickerLoadInfo::Instance());
DB2Storage<ArtifactPowerRankEntry>              sArtifactPowerRankStore("ArtifactPowerRank.db2", ArtifactPowerRankLoadInfo::Instance());
DB2Storage<ArtifactQuestXPEntry>                sArtifactQuestXPStore("ArtifactQuestXP.db2", ArtifactQuestXpLoadInfo::Instance());
DB2Storage<ArtifactUnlockEntry>                 sArtifactUnlockStore("ArtifactUnlock.db2", ArtifactUnlockLoadInfo::Instance());
DB2Storage<AuctionHouseEntry>                   sAuctionHouseStore("AuctionHouse.db2", AuctionHouseLoadInfo::Instance());
DB2Storage<BankBagSlotPricesEntry>              sBankBagSlotPricesStore("BankBagSlotPrices.db2", BankBagSlotPricesLoadInfo::Instance());
DB2Storage<BannedAddonsEntry>                   sBannedAddOnsStore("BannedAddons.db2", BannedAddonsLoadInfo::Instance());
DB2Storage<BarberShopStyleEntry>                sBarberShopStyleStore("BarberShopStyle.db2", BarberShopStyleLoadInfo::Instance());
DB2Storage<BattlemasterListEntry>               sBattlemasterListStore("BattlemasterList.db2", BattlemasterListLoadInfo::Instance());
DB2Storage<BattlePetAbilityEntry>               sBattlePetAbilityStore("BattlePetAbility.db2", BattlePetAbilityLoadInfo::Instance());
DB2Storage<BattlePetAbilityEffectEntry>         sBattlePetAbilityEffectStore("BattlePetAbilityEffect.db2", BattlePetAbilityEffectLoadInfo::Instance());
DB2Storage<BattlePetAbilityStateEntry>          sBattlePetAbilityStateStore("BattlePetAbilityState.db2", BattlePetAbilityStateLoadInfo::Instance());
DB2Storage<BattlePetAbilityTurnEntry>           sBattlePetAbilityTurnStore("BattlePetAbilityTurn.db2", BattlePetAbilityTurnLoadInfo::Instance());
DB2Storage<BattlePetBreedQualityEntry>          sBattlePetBreedQualityStore("BattlePetBreedQuality.db2", BattlePetBreedQualityLoadInfo::Instance());
DB2Storage<BattlePetBreedStateEntry>            sBattlePetBreedStateStore("BattlePetBreedState.db2", BattlePetBreedStateLoadInfo::Instance());
DB2Storage<BattlePetEffectPropertiesEntry>      sBattlePetEffectPropertiesStore("BattlePetEffectProperties.db2", BattlePetEffectPropertiesLoadInfo::Instance());
DB2Storage<BattlePetSpeciesEntry>               sBattlePetSpeciesStore("BattlePetSpecies.db2", BattlePetSpeciesLoadInfo::Instance());
DB2Storage<BattlePetSpeciesStateEntry>          sBattlePetSpeciesStateStore("BattlePetSpeciesState.db2", BattlePetSpeciesStateLoadInfo::Instance());
DB2Storage<BattlePetSpeciesXAbilityEntry>       sBattlePetSpeciesXAbilityStore("BattlePetSpeciesXAbility.db2", BattlePetSpeciesXAbilityLoadInfo::Instance());
DB2Storage<BattlePetStateEntry>                 sBattlePetStateStore("BattlePetState.db2", BattlePetStateLoadInfo::Instance());
DB2Storage<BroadcastTextEntry>                  sBroadcastTextStore("BroadcastText.db2", BroadcastTextLoadInfo::Instance());
DB2Storage<CharacterFacialHairStylesEntry>      sCharacterFacialHairStylesStore("CharacterFacialHairStyles.db2", CharacterFacialHairStylesLoadInfo::Instance());
DB2Storage<CharacterLoadoutEntry>               sCharacterLoadoutStore("CharacterLoadout.db2", CharacterLoadoutLoadInfo::Instance());
DB2Storage<CharacterLoadoutItemEntry>           sCharacterLoadoutItemStore("CharacterLoadoutItem.db2", CharacterLoadoutItemLoadInfo::Instance());
DB2Storage<CharBaseSectionEntry>                sCharBaseSectionStore("CharBaseSection.db2", CharBaseSectionLoadInfo::Instance());
DB2Storage<CharSectionsEntry>                   sCharSectionsStore("CharSections.db2", CharSectionsLoadInfo::Instance());
DB2Storage<CharShipmentEntry>                   sCharShipmentStore("CharShipment.db2", CharShipmentLoadInfo::Instance());
DB2Storage<CharShipmentContainerEntry>          sCharShipmentContainerStore("CharShipmentContainer.db2", CharShipmentContainerLoadInfo::Instance());
DB2Storage<CharStartOutfitEntry>                sCharStartOutfitStore("CharStartOutfit.db2", CharStartOutfitLoadInfo::Instance());
DB2Storage<CharTitlesEntry>                     sCharTitlesStore("CharTitles.db2", CharTitlesLoadInfo::Instance());
DB2Storage<ChatChannelsEntry>                   sChatChannelsStore("ChatChannels.db2", ChatChannelsLoadInfo::Instance());
DB2Storage<ChrClassesEntry>                     sChrClassesStore("ChrClasses.db2", ChrClassesLoadInfo::Instance());
DB2Storage<ChrClassesXPowerTypesEntry>          sChrClassesXPowerTypesStore("ChrClassesXPowerTypes.db2", ChrClassesXPowerTypesLoadInfo::Instance());
DB2Storage<ChrRacesEntry>                       sChrRacesStore("ChrRaces.db2", ChrRacesLoadInfo::Instance());
DB2Storage<ChrSpecializationEntry>              sChrSpecializationStore("ChrSpecialization.db2", ChrSpecializationLoadInfo::Instance());
DB2Storage<ContributionEntry>                   sContributionStore("Contribution.db2", ContributionLoadInfo::Instance());
DB2Storage<ConversationLineEntry>               sConversationLineStore("ConversationLine.db2", ConversationLineLoadInfo::Instance());
DB2Storage<CreatureDifficultyEntry>             sCreatureDifficultyStore("CreatureDifficulty.db2", CreatureDifficultyLoadInfo::Instance());
DB2Storage<CreatureDisplayInfoEntry>            sCreatureDisplayInfoStore("CreatureDisplayInfo.db2", CreatureDisplayInfoLoadInfo::Instance());
DB2Storage<CreatureDisplayInfoExtraEntry>       sCreatureDisplayInfoExtraStore("CreatureDisplayInfoExtra.db2", CreatureDisplayInfoExtraLoadInfo::Instance());
DB2Storage<CreatureFamilyEntry>                 sCreatureFamilyStore("CreatureFamily.db2", CreatureFamilyLoadInfo::Instance());
DB2Storage<CreatureModelDataEntry>              sCreatureModelDataStore("CreatureModelData.db2", CreatureModelDataLoadInfo::Instance());
DB2Storage<CreatureTypeEntry>                   sCreatureTypeStore("CreatureType.db2", CreatureTypeLoadInfo::Instance());
DB2Storage<CreatureXContributionEntry>          sCreatureXContributionStore("CreatureXContribution.db2", CreatureXContributionLoadInfo::Instance());
DB2Storage<CriteriaEntry>                       sCriteriaStore("Criteria.db2", CriteriaLoadInfo::Instance());
DB2Storage<CriteriaTreeEntry>                   sCriteriaTreeStore("CriteriaTree.db2", CriteriaTreeLoadInfo::Instance());
DB2Storage<CurrencyTypesEntry>                  sCurrencyTypesStore("CurrencyTypes.db2", CurrencyTypesLoadInfo::Instance());
DB2Storage<CurveEntry>                          sCurveStore("Curve.db2", CurveLoadInfo::Instance());
DB2Storage<CurvePointEntry>                     sCurvePointStore("CurvePoint.db2", CurvePointLoadInfo::Instance());
DB2Storage<DestructibleModelDataEntry>          sDestructibleModelDataStore("DestructibleModelData.db2", DestructibleModelDataLoadInfo::Instance());
DB2Storage<DifficultyEntry>                     sDifficultyStore("Difficulty.db2", DifficultyLoadInfo::Instance());
DB2Storage<DungeonEncounterEntry>               sDungeonEncounterStore("DungeonEncounter.db2", DungeonEncounterLoadInfo::Instance());
DB2Storage<DurabilityCostsEntry>                sDurabilityCostsStore("DurabilityCosts.db2", DurabilityCostsLoadInfo::Instance());
DB2Storage<DurabilityQualityEntry>              sDurabilityQualityStore("DurabilityQuality.db2", DurabilityQualityLoadInfo::Instance());
DB2Storage<EmotesEntry>                         sEmotesStore("Emotes.db2", EmotesLoadInfo::Instance());
DB2Storage<EmotesTextEntry>                     sEmotesTextStore("EmotesText.db2", EmotesTextLoadInfo::Instance());
DB2Storage<FactionEntry>                        sFactionStore("Faction.db2", FactionLoadInfo::Instance());
DB2Storage<FactionTemplateEntry>                sFactionTemplateStore("FactionTemplate.db2", FactionTemplateLoadInfo::Instance());
DB2Storage<FriendshipRepReactionEntry>          sFriendshipRepReactionStore("FriendshipRepReaction.db2", FriendshipRepReactionLoadInfo::Instance());
DB2Storage<FriendshipReputationEntry>           sFriendshipReputationStore("FriendshipReputation.db2", FriendshipReputationLoadInfo::Instance());
DB2Storage<GameObjectArtKitEntry>               sGameObjectArtKitStore("GameObjectArtKit.db2", GameobjectArtKitLoadInfo::Instance());
DB2Storage<GameObjectDisplayInfoEntry>          sGameObjectDisplayInfoStore("GameObjectDisplayInfo.db2", GameobjectDisplayInfoLoadInfo::Instance());
DB2Storage<GameObjectsEntry>                    sGameObjectsStore("GameObjects.db2", GameobjectsLoadInfo::Instance());
DB2Storage<GarrAbilityEntry>                    sGarrAbilityStore("GarrAbility.db2", GarrAbilityLoadInfo::Instance());
DB2Storage<GarrAbilityCategoryEntry>            sGarrAbilityCategoryStore("GarrAbilityCategory.db2", GarrAbilityCategoryLoadInfo::Instance());
DB2Storage<GarrAbilityEffectEntry>              sGarrAbilityEffectStore("GarrAbilityEffect.db2", GarrAbilityEffectLoadInfo::Instance());
DB2Storage<GarrBuildingEntry>                   sGarrBuildingStore("GarrBuilding.db2", GarrBuildingLoadInfo::Instance());
DB2Storage<GarrBuildingDoodadSetEntry>          sGarrBuildingDoodadSetStore("GarrBuildingDoodadSet.db2", GarrBuildingDoodadSetLoadInfo::Instance());
DB2Storage<GarrBuildingPlotInstEntry>           sGarrBuildingPlotInstStore("GarrBuildingPlotInst.db2", GarrBuildingPlotInstLoadInfo::Instance());
DB2Storage<GarrClassSpecEntry>                  sGarrClassSpecStore("GarrClassSpec.db2", GarrClassSpecLoadInfo::Instance());
DB2Storage<GarrEncounterEntry>                  sGarrEncounterStore("GarrEncounter.db2", GarrEncounterLoadInfo::Instance());
DB2Storage<GarrEncounterSetXEncounterEntry>     sGarrEncounterSetXEncounterStore("GarrEncounterSetXEncounter.db2", GarrEncounterSetXEncounterLoadInfo::Instance());
DB2Storage<GarrEncounterXMechanicEntry>         sGarrEncounterXMechanicStore("GarrEncounterXMechanic.db2", GarrEncounterXMechanicLoadInfo::Instance());
DB2Storage<GarrFollItemSetMemberEntry>          sGarrFollItemSetMemberStore("GarrFollItemSetMember.db2", GarrFollItemSetMemberLoadInfo::Instance());
DB2Storage<GarrFollowerEntry>                   sGarrFollowerStore("GarrFollower.db2", GarrFollowerLoadInfo::Instance());
DB2Storage<GarrFollowerLevelXPEntry>            sGarrFollowerLevelXPStore("GarrFollowerLevelXP.db2", GarrFollowerLevelXPLoadInfo::Instance());
DB2Storage<GarrFollowerQualityEntry>            sGarrFollowerQualityStore("GarrFollowerQuality.db2", GarrFollowerQualityLoadInfo::Instance());
DB2Storage<GarrFollowerSetXFollowerEntry>       sGarrFollowerSetXFollowerStore("GarrFollowerSetXFollower.db2", GarrFollowerSetXFollowerLoadInfo::Instance());
DB2Storage<GarrFollowerTypeEntry>               sGarrFollowerTypeStore("GarrFollowerType.db2", GarrFollowerTypeLoadInfo::Instance());
DB2Storage<GarrFollowerXAbilityEntry>           sGarrFollowerXAbilityStore("GarrFollowerXAbility.db2", GarrFollowerXAbilityLoadInfo::Instance());
DB2Storage<GarrFollSupportSpellEntry>           sGarrFollSupportSpellStore("GarrFollSupportSpell.db2", GarrFollSupportSpellLoadInfo::Instance());
DB2Storage<GarrItemLevelUpgradeDataEntry>       sGarrItemLevelUpgradeDataStore("GarrItemLevelUpgradeData.db2", GarrItemLevelUpgradeDataLoadInfo::Instance());
DB2Storage<GarrMechanicEntry>                   sGarrMechanicStore("GarrMechanic.db2", GarrMechanicLoadInfo::Instance());
DB2Storage<GarrMechanicSetXMechanicEntry>       sGarrMechanicSetXMechanicStore("GarrMechanicSetXMechanic.db2", GarrMechanicSetXMechanicLoadInfo::Instance());
DB2Storage<GarrMechanicTypeEntry>               sGarrMechanicTypeStore("GarrMechanicType.db2", GarrMechanicTypeLoadInfo::Instance());
DB2Storage<GarrMissionEntry>                    sGarrMissionStore("GarrMission.db2", GarrMissionLoadInfo::Instance());
DB2Storage<GarrMissionTypeEntry>                sGarrMissionTypeStore("GarrMissionType.db2", GarrMissionTypeLoadInfo::Instance());
DB2Storage<GarrMissionXEncounterEntry>          sGarrMissionXEncounterStore("GarrMissionXEncounter.db2", GarrMissionXEncounterLoadInfo::Instance());
DB2Storage<GarrMissionXFollowerEntry>           sGarrMissionXFollowerStore("GarrMissionXFollower.db2", GarrMissionXFollowerLoadInfo::Instance());
DB2Storage<GarrMssnBonusAbilityEntry>           sGarrMssnBonusAbilityStore("GarrMssnBonusAbility.db2", GarrMssnBonusAbilityLoadInfo::Instance());
DB2Storage<GarrPlotEntry>                       sGarrPlotStore("GarrPlot.db2", GarrPlotLoadInfo::Instance());
DB2Storage<GarrPlotBuildingEntry>               sGarrPlotBuildingStore("GarrPlotBuilding.db2", GarrPlotBuildingLoadInfo::Instance());
DB2Storage<GarrPlotInstanceEntry>               sGarrPlotInstanceStore("GarrPlotInstance.db2", GarrPlotInstanceLoadInfo::Instance());
DB2Storage<GarrSiteLevelEntry>                  sGarrSiteLevelStore("GarrSiteLevel.db2", GarrSiteLevelLoadInfo::Instance());
DB2Storage<GarrSiteLevelPlotInstEntry>          sGarrSiteLevelPlotInstStore("GarrSiteLevelPlotInst.db2", GarrSiteLevelPlotInstLoadInfo::Instance());
DB2Storage<GarrSpecializationEntry>             sGarrSpecializationStore("GarrSpecialization.db2", GarrSpecializationLoadInfo::Instance());
DB2Storage<GarrTalentEntry>                     sGarrTalentStore("GarrTalent.db2", GarrTalentLoadInfo::Instance());
DB2Storage<GarrTalentTreeEntry>                 sGarrTalentTreeStore("GarrTalentTree.db2", GarrTalentTreeLoadInfo::Instance());
DB2Storage<GarrTypeEntry>                       sGarrTypeStore("GarrType.db2", GarrTypeLoadInfo::Instance());
DB2Storage<GemPropertiesEntry>                  sGemPropertiesStore("GemProperties.db2", GemPropertiesLoadInfo::Instance());
DB2Storage<GlyphBindableSpellEntry>             sGlyphBindableSpellStore("GlyphBindableSpell.db2", GlyphBindableSpellLoadInfo::Instance());
DB2Storage<GlyphPropertiesEntry>                sGlyphPropertiesStore("GlyphProperties.db2", GlyphPropertiesLoadInfo::Instance());
DB2Storage<GlyphRequiredSpecEntry>              sGlyphRequiredSpecStore("GlyphRequiredSpec.db2", GlyphRequiredSpecLoadInfo::Instance());
DB2Storage<GroupFinderActivityEntry>            sGroupFinderActivityStore("GroupFinderActivity.db2", GroupFinderActivityLoadInfo::Instance());
DB2Storage<GroupFinderActivityGrpEntry>         sGroupFinderActivityGrpStore("GroupFinderActivityGrp.db2", GroupFinderActivityGrpLoadInfo::Instance());
DB2Storage<GroupFinderCategoryEntry>            sGroupFinderCategoryStore("GroupFinderCategory.db2", GroupFinderCategoryLoadInfo::Instance());
DB2Storage<GuildColorBackgroundEntry>           sGuildColorBackgroundStore("GuildColorBackground.db2", GuildColorBackgroundLoadInfo::Instance());
DB2Storage<GuildColorBorderEntry>               sGuildColorBorderStore("GuildColorBorder.db2", GuildColorBorderLoadInfo::Instance());
DB2Storage<GuildColorEmblemEntry>               sGuildColorEmblemStore("GuildColorEmblem.db2", GuildColorEmblemLoadInfo::Instance());
DB2Storage<GuildPerkSpellsEntry>                sGuildPerkSpellsStore("GuildPerkSpells.db2", GuildPerkSpellsLoadInfo::Instance());
DB2Storage<HeirloomEntry>                       sHeirloomStore("Heirloom.db2", HeirloomLoadInfo::Instance());
DB2Storage<HolidayNamesEntry>                   sHolidayNamesStore("HolidayNames.db2", HolidayNamesLoadInfo::Instance());
DB2Storage<HolidaysEntry>                       sHolidaysStore("Holidays.db2", HolidaysLoadInfo::Instance());
DB2Storage<ImportPriceArmorEntry>               sImportPriceArmorStore("ImportPriceArmor.db2", ImportPriceArmorLoadInfo::Instance());
DB2Storage<ImportPriceQualityEntry>             sImportPriceQualityStore("ImportPriceQuality.db2", ImportPriceQualityLoadInfo::Instance());
DB2Storage<ImportPriceShieldEntry>              sImportPriceShieldStore("ImportPriceShield.db2", ImportPriceShieldLoadInfo::Instance());
DB2Storage<ImportPriceWeaponEntry>              sImportPriceWeaponStore("ImportPriceWeapon.db2", ImportPriceWeaponLoadInfo::Instance());
DB2Storage<ItemEntry>                           sItemStore("Item.db2", ItemLoadInfo::Instance());
DB2Storage<ItemAppearanceEntry>                 sItemAppearanceStore("ItemAppearance.db2", ItemAppearanceLoadInfo::Instance());
DB2Storage<ItemArmorQualityEntry>               sItemArmorQualityStore("ItemArmorQuality.db2", ItemArmorQualityLoadInfo::Instance());
DB2Storage<ItemArmorShieldEntry>                sItemArmorShieldStore("ItemArmorShield.db2", ItemArmorShieldLoadInfo::Instance());
DB2Storage<ItemArmorTotalEntry>                 sItemArmorTotalStore("ItemArmorTotal.db2", ItemArmorTotalLoadInfo::Instance());
DB2Storage<ItemBonusEntry>                      sItemBonusStore("ItemBonus.db2", ItemBonusLoadInfo::Instance());
DB2Storage<ItemBonusListLevelDeltaEntry>        sItemBonusListLevelDeltaStore("ItemBonusListLevelDelta.db2", ItemBonusListLevelDeltaLoadInfo::Instance());
DB2Storage<ItemBonusTreeNodeEntry>              sItemBonusTreeNodeStore("ItemBonusTreeNode.db2", ItemBonusTreeNodeLoadInfo::Instance());
DB2Storage<ItemChildEquipmentEntry>             sItemChildEquipmentStore("ItemChildEquipment.db2", ItemChildEquipmentLoadInfo::Instance());
DB2Storage<ItemClassEntry>                      sItemClassStore("ItemClass.db2", ItemClassLoadInfo::Instance());
DB2Storage<ItemCurrencyCostEntry>               sItemCurrencyCostStore("ItemCurrencyCost.db2", ItemCurrencyCostLoadInfo::Instance());
DB2Storage<ItemDamageAmmoEntry>                 sItemDamageAmmoStore("ItemDamageAmmo.db2", ItemDamageAmmoLoadInfo::Instance());
DB2Storage<ItemDamageOneHandEntry>              sItemDamageOneHandStore("ItemDamageOneHand.db2", ItemDamageOneHandLoadInfo::Instance());
DB2Storage<ItemDamageOneHandCasterEntry>        sItemDamageOneHandCasterStore("ItemDamageOneHandCaster.db2", ItemDamageOneHandCasterLoadInfo::Instance());
DB2Storage<ItemDamageTwoHandEntry>              sItemDamageTwoHandStore("ItemDamageTwoHand.db2", ItemDamageTwoHandLoadInfo::Instance());
DB2Storage<ItemDamageTwoHandCasterEntry>        sItemDamageTwoHandCasterStore("ItemDamageTwoHandCaster.db2", ItemDamageTwoHandCasterLoadInfo::Instance());
DB2Storage<ItemDisenchantLootEntry>             sItemDisenchantLootStore("ItemDisenchantLoot.db2", ItemDisenchantLootLoadInfo::Instance());
DB2Storage<ItemEffectEntry>                     sItemEffectStore("ItemEffect.db2", ItemEffectLoadInfo::Instance());
DB2Storage<ItemExtendedCostEntry>               sItemExtendedCostStore("ItemExtendedCost.db2", ItemExtendedCostLoadInfo::Instance());
DB2Storage<ItemLevelSelectorEntry>              sItemLevelSelectorStore("ItemLevelSelector.db2", ItemLevelSelectorLoadInfo::Instance());
DB2Storage<ItemLevelSelectorQualityEntry>       sItemLevelSelectorQualityStore("ItemLevelSelectorQuality.db2", ItemLevelSelectorQualityLoadInfo::Instance());
DB2Storage<ItemLevelSelectorQualitySetEntry>    sItemLevelSelectorQualitySetStore("ItemLevelSelectorQualitySet.db2", ItemLevelSelectorQualitySetLoadInfo::Instance());
DB2Storage<ItemLimitCategoryEntry>              sItemLimitCategoryStore("ItemLimitCategory.db2", ItemLimitCategoryLoadInfo::Instance());
DB2Storage<ItemLimitCategoryConditionEntry>     sItemLimitCategoryConditionStore("ItemLimitCategoryCondition.db2", ItemLimitCategoryConditionLoadInfo::Instance());
DB2Storage<ItemModifiedAppearanceEntry>         sItemModifiedAppearanceStore("ItemModifiedAppearance.db2", ItemModifiedAppearanceLoadInfo::Instance());
DB2Storage<ItemPriceBaseEntry>                  sItemPriceBaseStore("ItemPriceBase.db2", ItemPriceBaseLoadInfo::Instance());
DB2Storage<ItemRandomPropertiesEntry>           sItemRandomPropertiesStore("ItemRandomProperties.db2", ItemRandomPropertiesLoadInfo::Instance());
DB2Storage<ItemRandomSuffixEntry>               sItemRandomSuffixStore("ItemRandomSuffix.db2", ItemRandomSuffixLoadInfo::Instance());
DB2Storage<ItemSetEntry>                        sItemSetStore("ItemSet.db2", ItemSetLoadInfo::Instance());
DB2Storage<ItemSetSpellEntry>                   sItemSetSpellStore("ItemSetSpell.db2", ItemSetSpellLoadInfo::Instance());
DB2Storage<ItemSparseEntry>                     sItemSparseStore("ItemSparse.db2", ItemSparseLoadInfo::Instance());
DB2Storage<ItemSpecEntry>                       sItemSpecStore("ItemSpec.db2", ItemSpecLoadInfo::Instance());
DB2Storage<ItemSpecOverrideEntry>               sItemSpecOverrideStore("ItemSpecOverride.db2", ItemSpecOverrideLoadInfo::Instance());
DB2Storage<ItemUpgradeEntry>                    sItemUpgradeStore("ItemUpgrade.db2", ItemUpgradeLoadInfo::Instance());
DB2Storage<ItemXBonusTreeEntry>                 sItemXBonusTreeStore("ItemXBonusTree.db2", ItemXBonusTreeLoadInfo::Instance());
DB2Storage<JournalEncounterEntry>               sJournalEncounterStore("JournalEncounter.db2", JournalEncounterLoadInfo::Instance());
DB2Storage<JournalEncounterCreatureEntry>       sJournalEncounterCreatureStore("JournalEncounterCreature.db2", JournalEncounterCreatureLoadInfo::Instance());
DB2Storage<JournalEncounterItemEntry>           sJournalEncounterItemStore("JournalEncounterItem.db2", JournalEncounterItemLoadInfo::Instance());
DB2Storage<JournalInstanceEntry>                sJournalInstanceStore("JournalInstance.db2", JournalInstanceLoadInfo::Instance());
DB2Storage<KeychainEntry>                       sKeyChainStore("Keychain.db2", KeychainLoadInfo::Instance());
DB2Storage<LanguageWordsEntry>                  sLanguageWordsStore("LanguageWords.db2", LanguageWordsLoadInfo::Instance());
DB2Storage<LFGDungeonsEntry>                    sLfgDungeonsStore("LFGDungeons.db2", LfgDungeonsLoadInfo::Instance());
DB2Storage<LFGRoleRequirementEntry>             sLfgRoleRequirementStore("LFGRoleRequirement.db2", LfgRoleRequirementLoadInfo::Instance());
DB2Storage<LightEntry>                          sLightStore("Light.db2", LightLoadInfo::Instance());
DB2Storage<LiquidTypeEntry>                     sLiquidTypeStore("LiquidType.db2", LiquidTypeLoadInfo::Instance());
DB2Storage<LockEntry>                           sLockStore("Lock.db2", LockLoadInfo::Instance());
DB2Storage<MailTemplateEntry>                   sMailTemplateStore("MailTemplate.db2", MailTemplateLoadInfo::Instance());
DB2Storage<ManagedWorldStateEntry>              sManagedWorldStateStore("ManagedWorldState.db2", ManagedWorldStateLoadInfo::Instance());
DB2Storage<ManagedWorldStateBuffEntry>          sManagedWorldStateBuffStore("ManagedWorldStateBuff.db2", ManagedWorldStateBuffLoadInfo::Instance());
DB2Storage<ManagedWorldStateInputEntry>         sManagedWorldStateInputStore("ManagedWorldStateInput.db2", ManagedWorldStateInputLoadInfo::Instance());
DB2Storage<MapEntry>                            sMapStore("Map.db2", MapLoadInfo::Instance());
DB2Storage<MapChallengeModeEntry>               sMapChallengeModeStore("MapChallengeMode.db2", MapChallengeModeLoadInfo::Instance());
DB2Storage<MapDifficultyEntry>                  sMapDifficultyStore("MapDifficulty.db2", MapDifficultyLoadInfo::Instance());
DB2Storage<MapDifficultyXConditionEntry>        sMapDifficultyXConditionStore("MapDifficultyXCondition.db2", MapDifficultyXConditionLoadInfo::Instance());
DB2Storage<ModifierTreeEntry>                   sModifierTreeStore("ModifierTree.db2", ModifierTreeLoadInfo::Instance());
DB2Storage<MountEntry>                          sMountStore("Mount.db2", MountLoadInfo::Instance());
DB2Storage<MountCapabilityEntry>                sMountCapabilityStore("MountCapability.db2", MountCapabilityLoadInfo::Instance());
DB2Storage<MountTypeXCapabilityEntry>           sMountTypeXCapabilityStore("MountTypeXCapability.db2", MountTypeXCapabilityLoadInfo::Instance());
DB2Storage<MountXDisplayEntry>                  sMountXDisplayStore("MountXDisplay.db2", MountXDisplayLoadInfo::Instance());
DB2Storage<MovieEntry>                          sMovieStore("Movie.db2", MovieLoadInfo::Instance());
DB2Storage<NameGenEntry>                        sNameGenStore("NameGen.db2", NameGenLoadInfo::Instance());
DB2Storage<NamesProfanityEntry>                 sNamesProfanityStore("NamesProfanity.db2", NamesProfanityLoadInfo::Instance());
DB2Storage<NamesReservedEntry>                  sNamesReservedStore("NamesReserved.db2", NamesReservedLoadInfo::Instance());
DB2Storage<NamesReservedLocaleEntry>            sNamesReservedLocaleStore("NamesReservedLocale.db2", NamesReservedLocaleLoadInfo::Instance());
DB2Storage<OverrideSpellDataEntry>              sOverrideSpellDataStore("OverrideSpellData.db2", OverrideSpellDataLoadInfo::Instance());
DB2Storage<ParagonReputationEntry>              sParagonReputationStore("ParagonReputation.db2", ParagonReputationLoadInfo::Instance());
DB2Storage<PhaseEntry>                          sPhaseStore("Phase.db2", PhaseLoadInfo::Instance());
DB2Storage<PhaseXPhaseGroupEntry>               sPhaseXPhaseGroupStore("PhaseXPhaseGroup.db2", PhaseXPhaseGroupLoadInfo::Instance());
DB2Storage<PlayerConditionEntry>                sPlayerConditionStore("PlayerCondition.db2", PlayerConditionLoadInfo::Instance());
DB2Storage<PowerDisplayEntry>                   sPowerDisplayStore("PowerDisplay.db2", PowerDisplayLoadInfo::Instance());
DB2Storage<PowerTypeEntry>                      sPowerTypeStore("PowerType.db2", PowerTypeLoadInfo::Instance());
DB2Storage<PrestigeLevelInfoEntry>              sPrestigeLevelInfoStore("PrestigeLevelInfo.db2", PrestigeLevelInfoLoadInfo::Instance());
DB2Storage<PVPDifficultyEntry>                  sPvpDifficultyStore("PVPDifficulty.db2", PvpDifficultyLoadInfo::Instance());
DB2Storage<PVPItemEntry>                        sPvpItemStore("PVPItem.db2", PvpItemLoadInfo::Instance());
DB2Storage<PvpRewardEntry>                      sPvpRewardStore("PvpReward.db2", PvpRewardLoadInfo::Instance());
DB2Storage<PvpScalingEffectEntry>               sPvpScalingEffectStore("PvpScalingEffect.db2", PvpScalingEffectLoadInfo::Instance());
DB2Storage<PvpScalingEffectTypeEntry>           sPvpScalingEffectTypeStore("PvpScalingEffectType.db2", PvpScalingEffectTypeLoadInfo::Instance());
DB2Storage<PvpTalentEntry>                      sPvpTalentStore("PvpTalent.db2", PvpTalentLoadInfo::Instance());
DB2Storage<PvpTalentUnlockEntry>                sPvpTalentUnlockStore("PvpTalentUnlock.db2", PvpTalentUnlockLoadInfo::Instance());
DB2Storage<QuestFactionRewardEntry>             sQuestFactionRewardStore("QuestFactionReward.db2", QuestFactionRewardLoadInfo::Instance());
DB2Storage<QuestLineEntry>                      sQuestLineStore("QuestLine.db2", QuestLineLoadInfo::Instance());
DB2Storage<QuestLineXQuestEntry>                sQuestLineXQuestStore("QuestLineXQuest.db2", QuestLineXQuestLoadInfo::Instance());
DB2Storage<QuestMoneyRewardEntry>               sQuestMoneyRewardStore("QuestMoneyReward.db2", QuestMoneyRewardLoadInfo::Instance());
DB2Storage<QuestObjectiveEntry>                 sQuestObjectiveStore("QuestObjective.db2", QuestObjectiveLoadInfo::Instance());
DB2Storage<QuestPackageItemEntry>               sQuestPackageItemStore("QuestPackageItem.db2", QuestPackageItemLoadInfo::Instance());
DB2Storage<QuestPOIBlobEntry>                   sQuestPOIBlobStore("QuestPOIBlob.db2", QuestPOIBlobLoadInfo::Instance());
DB2Storage<QuestPOIPointEntry>                  sQuestPOIPointStore("QuestPOIPoint.db2", QuestPOIPointLoadInfo::Instance());
DB2Storage<QuestSortEntry>                      sQuestSortStore("QuestSort.db2", QuestSortLoadInfo::Instance());
DB2Storage<QuestV2Entry>                        sQuestV2Store("QuestV2.db2", QuestV2LoadInfo::Instance());
DB2Storage<QuestV2CliTaskEntry>                 sQuestV2CliTaskStore("QuestV2CliTask.db2", QuestV2CliTaskLoadInfo::Instance());
DB2Storage<QuestXPEntry>                        sQuestXPStore("QuestXP.db2", QuestXpLoadInfo::Instance());
DB2Storage<RandPropPointsEntry>                 sRandPropPointsStore("RandPropPoints.db2", RandPropPointsLoadInfo::Instance());
DB2Storage<RelicSlotTierRequirementEntry>       sRelicSlotTierRequirementStore("RelicSlotTierRequirement.db2", RelicSlotTierRequirementLoadInfo::Instance());
DB2Storage<RelicTalentEntry>                    sRelicTalentStore("RelicTalent.db2", RelicTalentLoadInfo::Instance());
DB2Storage<ResearchBranchEntry>                 sResearchBranchStore("ResearchBranch.db2", ResearchBranchLoadInfo::Instance());
DB2Storage<ResearchProjectEntry>                sResearchProjectStore("ResearchProject.db2", ResearchProjectLoadInfo::Instance());
DB2Storage<ResearchSiteEntry>                   sResearchSiteStore("ResearchSite.db2", ResearchSiteLoadInfo::Instance());
DB2Storage<RewardPackEntry>                     sRewardPackStore("RewardPack.db2", RewardPackLoadInfo::Instance());
DB2Storage<RewardPackXCurrencyTypeEntry>        sRewardPackXCurrencyTypeStore("RewardPackXCurrencyType.db2", RewardPackXCurrencyTypeLoadInfo::Instance());
DB2Storage<RewardPackXItemEntry>                sRewardPackXItemStore("RewardPackXItem.db2", RewardPackXItemLoadInfo::Instance());
DB2Storage<RulesetItemUpgradeEntry>             sRulesetItemUpgradeStore("RulesetItemUpgrade.db2", RulesetItemUpgradeLoadInfo::Instance());
DB2Storage<SandboxScalingEntry>                 sSandboxScalingStore("SandboxScaling.db2", SandboxScalingLoadInfo::Instance());
DB2Storage<ScalingStatDistributionEntry>        sScalingStatDistributionStore("ScalingStatDistribution.db2", ScalingStatDistributionLoadInfo::Instance());
DB2Storage<ScenarioEntry>                       sScenarioStore("Scenario.db2", ScenarioLoadInfo::Instance());
DB2Storage<ScenarioStepEntry>                   sScenarioStepStore("ScenarioStep.db2", ScenarioStepLoadInfo::Instance());
DB2Storage<SkillLineEntry>                      sSkillLineStore("SkillLine.db2", SkillLineLoadInfo::Instance());
DB2Storage<SkillLineAbilityEntry>               sSkillLineAbilityStore("SkillLineAbility.db2", SkillLineAbilityLoadInfo::Instance());
DB2Storage<SkillRaceClassInfoEntry>             sSkillRaceClassInfoStore("SkillRaceClassInfo.db2", SkillRaceClassInfoLoadInfo::Instance());
DB2Storage<SoundKitEntry>                       sSoundKitStore("SoundKit.db2", SoundKitLoadInfo::Instance());
DB2Storage<SpecializationSpellsEntry>           sSpecializationSpellsStore("SpecializationSpells.db2", SpecializationSpellsLoadInfo::Instance());
DB2Storage<SpellEntry>                          sSpellStore("Spell.db2", SpellLoadInfo::Instance());
DB2Storage<SpellAuraOptionsEntry>               sSpellAuraOptionsStore("SpellAuraOptions.db2", SpellAuraOptionsLoadInfo::Instance());
DB2Storage<SpellAuraRestrictionsEntry>          sSpellAuraRestrictionsStore("SpellAuraRestrictions.db2", SpellAuraRestrictionsLoadInfo::Instance());
DB2Storage<SpellCastingRequirementsEntry>       sSpellCastingRequirementsStore("SpellCastingRequirements.db2", SpellCastingRequirementsLoadInfo::Instance());
DB2Storage<SpellCastTimesEntry>                 sSpellCastTimesStore("SpellCastTimes.db2", SpellCastTimesLoadInfo::Instance());
DB2Storage<SpellCategoriesEntry>                sSpellCategoriesStore("SpellCategories.db2", SpellCategoriesLoadInfo::Instance());
DB2Storage<SpellCategoryEntry>                  sSpellCategoryStore("SpellCategory.db2", SpellCategoryLoadInfo::Instance());
DB2Storage<SpellClassOptionsEntry>              sSpellClassOptionsStore("SpellClassOptions.db2", SpellClassOptionsLoadInfo::Instance());
DB2Storage<SpellCooldownsEntry>                 sSpellCooldownsStore("SpellCooldowns.db2", SpellCooldownsLoadInfo::Instance());
DB2Storage<SpellDurationEntry>                  sSpellDurationStore("SpellDuration.db2", SpellDurationLoadInfo::Instance());
DB2Storage<SpellEffectEntry>                    sSpellEffectStore("SpellEffect.db2", SpellEffectLoadInfo::Instance());
DB2Storage<SpellEquippedItemsEntry>             sSpellEquippedItemsStore("SpellEquippedItems.db2", SpellEquippedItemsLoadInfo::Instance());
DB2Storage<SpellFocusObjectEntry>               sSpellFocusObjectStore("SpellFocusObject.db2", SpellFocusObjectLoadInfo::Instance());
DB2Storage<SpellInterruptsEntry>                sSpellInterruptsStore("SpellInterrupts.db2", SpellInterruptsLoadInfo::Instance());
DB2Storage<SpellItemEnchantmentEntry>           sSpellItemEnchantmentStore("SpellItemEnchantment.db2", SpellItemEnchantmentLoadInfo::Instance());
DB2Storage<SpellItemEnchantmentConditionEntry>  sSpellItemEnchantmentConditionStore("SpellItemEnchantmentCondition.db2", SpellItemEnchantmentConditionLoadInfo::Instance());
DB2Storage<SpellLearnSpellEntry>                sSpellLearnSpellStore("SpellLearnSpell.db2", SpellLearnSpellLoadInfo::Instance());
DB2Storage<SpellLevelsEntry>                    sSpellLevelsStore("SpellLevels.db2", SpellLevelsLoadInfo::Instance());
DB2Storage<SpellMiscEntry>                      sSpellMiscStore("SpellMisc.db2", SpellMiscLoadInfo::Instance());
DB2Storage<SpellPowerEntry>                     sSpellPowerStore("SpellPower.db2", SpellPowerLoadInfo::Instance());
DB2Storage<SpellPowerDifficultyEntry>           sSpellPowerDifficultyStore("SpellPowerDifficulty.db2", SpellPowerDifficultyLoadInfo::Instance());
DB2Storage<SpellProcsPerMinuteEntry>            sSpellProcsPerMinuteStore("SpellProcsPerMinute.db2", SpellProcsPerMinuteLoadInfo::Instance());
DB2Storage<SpellProcsPerMinuteModEntry>         sSpellProcsPerMinuteModStore("SpellProcsPerMinuteMod.db2", SpellProcsPerMinuteModLoadInfo::Instance());
DB2Storage<SpellRadiusEntry>                    sSpellRadiusStore("SpellRadius.db2", SpellRadiusLoadInfo::Instance());
DB2Storage<SpellRangeEntry>                     sSpellRangeStore("SpellRange.db2", SpellRangeLoadInfo::Instance());
DB2Storage<SpellReagentsEntry>                  sSpellReagentsStore("SpellReagents.db2", SpellReagentsLoadInfo::Instance());
DB2Storage<SpellReagentsCurrencyEntry>          sSpellReagentsCurrencyStore("SpellReagentsCurrency.db2", SpellReagentsCurrencyLoadInfo::Instance());
DB2Storage<SpellScalingEntry>                   sSpellScalingStore("SpellScaling.db2", SpellScalingLoadInfo::Instance());
DB2Storage<SpellShapeshiftEntry>                sSpellShapeshiftStore("SpellShapeshift.db2", SpellShapeshiftLoadInfo::Instance());
DB2Storage<SpellShapeshiftFormEntry>            sSpellShapeshiftFormStore("SpellShapeshiftForm.db2", SpellShapeshiftFormLoadInfo::Instance());
DB2Storage<SpellTargetRestrictionsEntry>        sSpellTargetRestrictionsStore("SpellTargetRestrictions.db2", SpellTargetRestrictionsLoadInfo::Instance());
DB2Storage<SpellTotemsEntry>                    sSpellTotemsStore("SpellTotems.db2", SpellTotemsLoadInfo::Instance());
DB2Storage<SpellXSpellVisualEntry>              sSpellXSpellVisualStore("SpellXSpellVisual.db2", SpellXSpellVisualLoadInfo::Instance());
DB2Storage<SummonPropertiesEntry>               sSummonPropertiesStore("SummonProperties.db2", SummonPropertiesLoadInfo::Instance());
DB2Storage<TactKeyEntry>                        sTactKeyStore("TactKey.db2", TactKeyLoadInfo::Instance());
DB2Storage<TalentEntry>                         sTalentStore("Talent.db2", TalentLoadInfo::Instance());
DB2Storage<TaxiNodesEntry>                      sTaxiNodesStore("TaxiNodes.db2", TaxiNodesLoadInfo::Instance());
DB2Storage<TaxiPathEntry>                       sTaxiPathStore("TaxiPath.db2", TaxiPathLoadInfo::Instance());
DB2Storage<TaxiPathNodeEntry>                   sTaxiPathNodeStore("TaxiPathNode.db2", TaxiPathNodeLoadInfo::Instance());
DB2Storage<TotemCategoryEntry>                  sTotemCategoryStore("TotemCategory.db2", TotemCategoryLoadInfo::Instance());
DB2Storage<ToyEntry>                            sToyStore("Toy.db2", ToyLoadInfo::Instance());
DB2Storage<TransmogHolidayEntry>                sTransmogHolidayStore("TransmogHoliday.db2", TransmogHolidayLoadInfo::Instance());
DB2Storage<TransmogSetEntry>                    sTransmogSetStore("TransmogSet.db2", TransmogSetLoadInfo::Instance());
DB2Storage<TransmogSetGroupEntry>               sTransmogSetGroupStore("TransmogSetGroup.db2", TransmogSetGroupLoadInfo::Instance());
DB2Storage<TransmogSetItemEntry>                sTransmogSetItemStore("TransmogSetItem.db2", TransmogSetItemLoadInfo::Instance());
DB2Storage<TransportAnimationEntry>             sTransportAnimationStore("TransportAnimation.db2", TransportAnimationLoadInfo::Instance());
DB2Storage<TransportRotationEntry>              sTransportRotationStore("TransportRotation.db2", TransportRotationLoadInfo::Instance());
DB2Storage<UnitPowerBarEntry>                   sUnitPowerBarStore("UnitPowerBar.db2", UnitPowerBarLoadInfo::Instance());
DB2Storage<VehicleEntry>                        sVehicleStore("Vehicle.db2", VehicleLoadInfo::Instance());
DB2Storage<VehicleSeatEntry>                    sVehicleSeatStore("VehicleSeat.db2", VehicleSeatLoadInfo::Instance());
DB2Storage<VignetteEntry>                       sVignetteStore("Vignette.db2", VignetteLoadInfo::Instance());
DB2Storage<WMOAreaTableEntry>                   sWMOAreaTableStore("WMOAreaTable.db2", WmoAreaTableLoadInfo::Instance());
DB2Storage<WorldEffectEntry>                    sWorldEffectStore("WorldEffect.db2", WorldEffectLoadInfo::Instance());
DB2Storage<WorldMapAreaEntry>                   sWorldMapAreaStore("WorldMapArea.db2", WorldMapAreaLoadInfo::Instance());
DB2Storage<WorldMapOverlayEntry>                sWorldMapOverlayStore("WorldMapOverlay.db2", WorldMapOverlayLoadInfo::Instance());
DB2Storage<WorldMapTransformsEntry>             sWorldMapTransformsStore("WorldMapTransforms.db2", WorldMapTransformsLoadInfo::Instance());
DB2Storage<WorldSafeLocsEntry>                  sWorldSafeLocsStore("WorldSafeLocs.db2", WorldSafeLocsLoadInfo::Instance());
DB2Storage<WorldStateExpressionEntry>           sWorldStateExpressionStore("WorldStateExpression.db2", WorldStateExpressionLoadInfo::Instance());
DB2Storage<WorldStateUIEntry>                   sWorldStateUIStore("WorldStateUI.db2", WorldStateUILoadInfo::Instance());



TaxiMask                                        sTaxiNodesMask;
std::vector<uint8>                              sTaxiNodesMaskV;
TaxiMask                                        sOldContinentsNodesMask;
TaxiMask                                        sHordeTaxiNodesMask;
TaxiMask                                        sAllianceTaxiNodesMask;
TaxiPathSetBySource                             sTaxiPathSetBySource;
TaxiPathNodesByPath                             sTaxiPathNodesByPath;

DEFINE_DB2_SET_COMPARATOR(ChrClassesXPowerTypesEntry)

struct ItemLevelSelectorQualityEntryComparator
{
    bool operator()(ItemLevelSelectorQualityEntry const* left, ItemLevelSelectorQualityEntry const* right) const { return Compare(left, right); }
    bool operator()(ItemLevelSelectorQualityEntry const* left, ItemQualities quality) const { return left->Quality < quality; }
    static bool Compare(ItemLevelSelectorQualityEntry const* left, ItemLevelSelectorQualityEntry const* right);
};

typedef std::map<uint32 /*hash*/, DB2StorageBase*> StorageMap;
typedef std::unordered_map<uint32 /*curveID*/, std::vector<CurvePointEntry const*>> CurvePointsContainer;
typedef std::vector<ItemXBonusTreeEntry const*> ItemXBonusTreeContainer;
typedef std::unordered_map<uint32 /*bonusListId*/, DB2Manager::ItemBonusList> ItemBonusListContainer;
typedef std::unordered_map<int16, uint32> ItemBonusListLevelDeltaContainer;
typedef std::unordered_multimap<uint32 /*itemId*/, uint32 /*bonusTreeId*/> ItemToBonusTreeContainer;
typedef std::unordered_map<uint32 /*bonusTreeId*/, std::set<uint32 /*itemId*/>> BonusToItemTreeContainer;
typedef std::vector<std::vector<ItemModifiedAppearanceEntry const*>> ItemModifiedAppearanceByItemContainer;
typedef std::unordered_map<uint32 /*itemId*/, std::vector<uint32>> ItemToTransmogVector;
typedef std::unordered_map<uint32, std::set<ItemBonusTreeNodeEntry const*>> ItemBonusTreeContainer;
typedef std::unordered_map<uint32, std::vector<ItemSpecOverrideEntry const*>> ItemSpecOverridesContainer;
typedef std::unordered_map<uint32, MountEntry const*> MountContainer;
typedef std::set<MountTypeXCapabilityEntry const*, DB2Manager::MountTypeXCapabilityEntryComparator> MountTypeXCapabilitySet;
typedef std::unordered_map<uint32, DB2Manager::MountTypeXCapabilitySet> MountCapabilitiesByTypeContainer;
typedef std::unordered_map<uint32, DB2Manager::MountXDisplayContainer> MountDisplaysCointainer;
typedef std::unordered_map<uint32 /*areaGroupId*/, std::vector<uint32/*areaId*/>> AreaGroupMemberContainer;
typedef std::unordered_map<uint32 /*areaId*/, std::vector<uint32/*areaGroupId*/>> AreaMemberGroupContainer;
typedef std::unordered_map<uint32, MapChallengeModeEntry const*> MapChallengeModeEntryContainer;
typedef std::vector<uint32 /*MapID*/> MapChallengeModeListContainer;
typedef std::vector<double> MapChallengeWeightListContainer;
typedef std::unordered_map<uint32, uint32> RulesetItemUpgradeContainer;
typedef std::unordered_map<uint32, std::vector<QuestPackageItemEntry const*>> QuestPackageItemContainer;
typedef std::unordered_set<uint32> ToyItemIdsContainer;
typedef std::unordered_map<uint32, HeirloomEntry const*> HeirloomItemsContainer;
typedef std::unordered_map<uint32, AchievementEntry const*> AchievementParentContainer;
typedef std::map<uint32 /*CharacterLoadoutID*/, std::vector<uint32>> CharacterLoadoutItemContainer;
typedef std::unordered_map<uint32, uint8> CharacterLoadoutDataContainer;
typedef std::unordered_map<uint8 /*ClassID*/, CharacterLoadoutDataContainer> CharacterLoadoutContainer;
typedef std::unordered_map<uint32 /*Parent*/, std::vector<CriteriaTreeEntry const*>> CriteriaTreeContainer;
typedef std::unordered_map<uint32, std::list<uint32>> ItemSpecsContainer;
typedef std::unordered_map<uint32, std::vector<ModifierTreeEntry const*>> ModifierTreeContainer;
typedef std::unordered_map<uint32, std::array<std::vector<NameGenEntry const*>, 2>> NameGenContainer;
typedef std::array<std::vector<boost::wregex>, MAX_LOCALES + 1> NameValidationRegexContainer;
typedef std::unordered_multimap<uint32, SkillRaceClassInfoEntry const*> SkillRaceClassInfoContainer;
typedef std::unordered_map<uint32, std::vector<SpecializationSpellsEntry const*>> SpecializationSpellsBySpecContainer;
typedef std::unordered_map<uint32, std::vector<SpellProcsPerMinuteModEntry const*>> SpellProcsPerMinuteModContainer;
typedef std::unordered_map<uint32, std::set<SpellTargetRestrictionsEntry const*>> SpellRestrictionDiffContainer;
typedef std::unordered_map<uint32, uint32> RevertLearnSpellContainer;
typedef std::unordered_map<uint32, uint32> ReversTriggerSpellContainer;
typedef std::unordered_map<uint16, SpellEffectEntry const*> SpellEffectsMap;
struct SpellEffectDiff { SpellEffectsMap effects; };
typedef std::vector<SpellEffectDiff> SpellEffectDiffContainer;
typedef std::vector<SpellEffect> SpellEffectContainer;
typedef ChrSpecializationEntry const* ChrSpecializationByIndexContainer[MAX_CLASSES + 1][MAX_SPECIALIZATIONS];
typedef std::unordered_map<uint32, ChrSpecializationEntry const*> ChrSpecialzationByClassContainer;
typedef std::map<uint32, AreaTableEntry const*> AreaEntryContainer;
typedef std::map<uint32, DungeonEncounterEntry const*> DungeonEncounterByDisplayIDContainer;
typedef std::unordered_map<uint32, std::vector<QuestLineXQuestEntry const*>> QuestsByQuestLineContainer; 
typedef std::map<WMOAreaTableTripple, WMOAreaTableEntry const*> WMOAreaInfoByTrippleContainer;
typedef std::vector<PvpTalentEntry const*> PvPTalentsByPositionContainer[MAX_CLASSES][MAX_TALENT_TIERS][MAX_TALENT_COLUMNS];
typedef std::map<uint32, PvpTalentEntry const*> PvpTalentBySpellIDContainer;
typedef std::multimap<uint32 /*BuildingTypeID*/, GarrBuildingEntry const*> GarrBuildingTypeMap;
typedef std::unordered_map<uint16, std::vector<ArtifactAppearanceSetEntry const*>> ArtifactAppearanceSetContainer;
typedef std::unordered_map<uint16, std::vector<ArtifactAppearanceEntry const*>> SetToArtifactAppearanceContainer;
typedef std::unordered_map<uint32, std::unordered_set<uint32>> ArtifactPowerLinksContainer;
typedef std::unordered_map<uint16, std::vector<ArtifactPowerEntry const*>> ArtifactPowerContainer;
typedef std::unordered_map<std::pair<uint32, uint8>, ArtifactPowerRankEntry const*> ArtifactPowerRanksContainer;
typedef std::unordered_map<uint32 /*itemId*/, ItemChildEquipmentEntry const*> ItemChildEquipmentContainer;
typedef std::array<ItemClassEntry const*, 19> ItemClassByOldEnumContainer;
typedef std::unordered_map<uint32, std::vector<ItemLimitCategoryConditionEntry const*>> ItemLimitCategoryConditionContainer;
typedef std::unordered_map<uint8, PowerTypeEntry const*> PowerTypeContainer;
typedef std::unordered_map<uint32 /*glyphPropertiesId*/, std::vector<uint32>> GlyphBindableSpellsContainer;
typedef std::unordered_map<uint32 /*glyphPropertiesId*/, std::vector<uint32>> GlyphRequiredSpecsContainer;
typedef std::unordered_map<uint16, WorldMapAreaEntry const*> WorldMapAreaContainer;
typedef std::unordered_map<uint16, std::vector<uint16>> WorldMapZoneContainer;
typedef std::unordered_map<std::pair<uint16 /*honorLevel*/, uint8 /*prestigeLevel*/>, uint32 /*rewardPackID*/> PvpRewardPackByHonorLevelContainer;
typedef std::unordered_map<uint32 /*rewardPackID*/, RewardPackXItemEntry const*> RewardPackXItemContainer;
typedef std::unordered_map<uint32 /*rewardPackID*/, RewardPackXCurrencyTypeEntry const*> RewardPackXCurrencyTypeContainer;
typedef std::vector</*specID*/ std::vector<float /*Scalar*/>> PvpScalingEffectContainer;
typedef std::map<uint32 /*mapID*/, uint32 /*encounterID*/> EncounterIdByMapIDContainer;
typedef std::map<uint32 /*encounterID*/, std::vector<uint32> /*bossIDs*/> JournalLootIDsByEncounterIDContainer;
typedef std::map<uint32 /*encounterID*/, std::vector<uint32 /*itemIDs*/>> InstanceLootItemIDsByEncounterIDContainer;
typedef std::unordered_map<uint32 /*ArtifactID*/, ArtifactUnlockEntry const*> ArtifactToUnlockContainer;
typedef std::unordered_map<uint32, ParagonReputationEntry const*> ParagonReputationContainer;
typedef std::vector<BattlePetSpeciesEntry const*> BattlePetSpeciesContainer;
typedef std::vector<BattlePetSpeciesEntry const*> CreatureToSpeciesContainer;
typedef std::unordered_map<uint32 /*SpellID*/, SkillLineAbilityEntry const*> SpellToSkillContainer;
typedef std::unordered_map<uint32 /*SpellID*/, BattlePetSpeciesEntry const*> SpellToSpeciesContainer;
typedef std::unordered_map<int16 /*MapID*/, std::unordered_map<uint8 /*DifficultyID*/, LFGDungeonsEntry const*>> LFGDungeonsContainer;
typedef std::unordered_map<uint16 /*MaxLevel*/, std::unordered_map<uint8 /*MinLevel*/, uint32>> SandboxScalingContainer;
typedef std::set<ItemLevelSelectorQualityEntry const*, ItemLevelSelectorQualityEntryComparator> ItemLevelSelectorQualities;

namespace
{
    StorageMap _stores;
    std::map<uint64, int32> _hotfixData;

    CurvePointsContainer _curvePoints;
    ItemBonusListContainer _itemBonusLists;
    ItemBonusListLevelDeltaContainer _itemLevelDeltaToBonusListContainer;
    ItemBonusTreeContainer _itemBonusTrees;
    ItemModifiedAppearanceByItemContainer _itemModifiedAppearancesByItem;
    ItemToTransmogVector _itemToTransmogByItem;
    ItemToBonusTreeContainer _itemToBonusTree;
    BonusToItemTreeContainer _bonusToItemTree;
    ItemSpecOverridesContainer _itemSpecOverrides;
    MountContainer _mountsBySpellId;
    MountCapabilitiesByTypeContainer _mountCapabilitiesByType;
    std::list<uint32> _gameObjectsList;
    std::map<uint32 /*landID*/, DB2Manager::LanguageWordsContainer> _languageWordsMap;
    AreaGroupMemberContainer _areaGroupMembers;
    AreaMemberGroupContainer _areaMemberGroups;
    RulesetItemUpgradeContainer _rulesetItemUpgrade;
    QuestPackageItemContainer _questPackages;
    ToyItemIdsContainer _toys;
    HeirloomItemsContainer _heirlooms;
    std::map<std::tuple<uint8 /*level*/, uint8 /*typeID*/>, uint32 /*nextLevelXP*/> _garrFollowerLevelXP;
    std::map<std::tuple<uint8 /*quality*/, uint8 /*typeID*/>, uint32 /*nextQualityXP*/> _garrFollowerQualityXP;
    AchievementParentContainer _achievementParentList;
    CharacterLoadoutItemContainer _characterLoadoutItem;
    CharacterLoadoutContainer _characterLoadout;
    CriteriaTreeContainer _criteriaTree;
    ModifierTreeContainer _modifierTree;
    NameGenContainer _nameGenData;
    NameValidationRegexContainer _nameValidators;
    SkillRaceClassInfoContainer _skillRaceClassInfoBySkill;
    SpecializationSpellsBySpecContainer _specializationSpellsBySpec;
    SpellProcsPerMinuteModContainer _spellProcsPerMinuteMods;
    SpellRestrictionDiffContainer _spellRestrictionDiff;
    RevertLearnSpellContainer _revertLearnSpell;
    ReversTriggerSpellContainer _reversTriggerSpellList;
    SpellEffectDiffContainer _spellEffectDiff;
    SpellEffectContainer _spellEffectMap;
    ChrSpecializationByIndexContainer _chrSpecializationByIndex;
    ChrSpecialzationByClassContainer _defaultChrSpecializationsByClass;
    DB2Manager::PetFamilySpellsContainer _petFamilySpells;
    uint32 _powersByClass[MAX_CLASSES][MAX_POWERS];
    AreaEntryContainer _areaEntry;
    DungeonEncounterByDisplayIDContainer _dungeonEncounterByDisplayID;
    QuestsByQuestLineContainer _questsByQuestLine;
    std::set<std::tuple<uint8, uint8, uint32>> _characterFacialHairStyles;
    std::multimap<std::tuple<uint8, uint8, CharBaseSectionVariation>, CharSectionsEntry const*> _charSections;
    DB2Manager::FactionTeamContainer _factionTeam;
    ParagonReputationContainer _paragonFaction;
    ParagonReputationContainer _paragonQuest;
    WMOAreaInfoByTrippleContainer _WMOAreaInfoByTripple;
    uint32 _pvpTalentUnlock[MAX_PVP_TALENT_TIERS][MAX_TALENT_COLUMNS];
    ArtifactPowerRanksContainer _artifactPowerRanks;
    GlyphBindableSpellsContainer _glyphBindableSpells;
    GlyphRequiredSpecsContainer _glyphRequiredSpecs;
    WorldMapAreaContainer _worldMapArea;
    WorldMapZoneContainer _worldMapZone;
    MapChallengeModeEntryContainer _mapChallengeModeEntrybyMap;
    MapChallengeModeListContainer _challengeModeMaps;
    MapChallengeWeightListContainer _challengeWeightMaps;
    PvPTalentsByPositionContainer _pvpTalentByPos;
    PvpTalentBySpellIDContainer _pvpTalentBySpellID;
    PvpRewardPackByHonorLevelContainer _rewardPackByHonorLevel;
    RewardPackXItemContainer _rewardPackXItem;
    RewardPackXCurrencyTypeContainer _rewardPackXCurrency;
    DB2Manager::GarrAbilityEffectContainer _garrAbilityEffectContainer;
    MountDisplaysCointainer _mountDisplays;
    PvpScalingEffectContainer _pvpScalingEffectsBySpecID;
    EncounterIdByMapIDContainer _encounterIdByMapID;
    JournalLootIDsByEncounterIDContainer _journalLootIDsByEncounterID;
    InstanceLootItemIDsByEncounterIDContainer _instanceLootItemIDsByEncounterID;
    DB2Manager::GarrTalentClassMap _garClassMap;
    PowerTypeContainer _powerTypeContainer;
    std::unordered_map<uint32, std::vector<TransmogSetEntry const*>> _transmogSetsByItemModifiedAppearance;
    std::unordered_map<uint32, std::vector<TransmogSetItemEntry const*>> _transmogSetItemsByTransmogSet;
    std::unordered_set<uint32> _itemsWithCurrencyCost;
    std::unordered_map<uint32 /*itemLevelSelectorQualitySetId*/, ItemLevelSelectorQualities> _itemLevelQualitySelectorQualities;
    ItemClassByOldEnumContainer _itemClassByOldEnum;
    ItemLimitCategoryConditionContainer _itemCategoryConditions;
    GarrBuildingTypeMap _buldingTypeConteiner;
    ArtifactAppearanceSetContainer _artifactAppearanceSetConteiner;
    SetToArtifactAppearanceContainer _setToArtifactAppearanceContainer;
    ArtifactPowerLinksContainer _artifactPowerLinks;
    ArtifactPowerContainer _artifactPowerContainer;
    ItemChildEquipmentContainer _itemChildEquipment;
    ArtifactToUnlockContainer _artifactToUnlockContainer;
    DB2Manager::XContainer _xEncounter;
    DB2Manager::XContainer _xMechanic;
    std::unordered_map<uint32, std::set<uint32>> _phasesByGroup;
    BattlePetSpeciesContainer _battlePetSpeciesContainer;
    CreatureToSpeciesContainer _creatureToSpeciesContainer;
    SpellToSkillContainer _spellToSkillContainer;
    SpellToSpeciesContainer _spellToSpeciesContainer;
    std::unordered_map<uint32, uint32> _spellMiscBySpellIDContainer;
    LFGDungeonsContainer _lfgdungeonsContainer;
    std::unordered_map<std::pair<uint32, uint32>, uint32> _LFGRoleRequirementCondition;
    SandboxScalingContainer _sandboxScalingContainer;
    DB2Manager::MapDifficultyContainer _mapDifficulty;
    std::unordered_map<uint32, uint32> _mapDifficultyCondition;
    std::unordered_map<uint32, uint32> _hostileSpellVisualIdContainer;
    std::unordered_map<uint32, bool> _isChildItem;
    std::unordered_map<uint32, MapEntry const*> _mapEntryContainer;
}

typedef std::vector<std::string> DB2StoreProblemList;

template<class T, template<class> class DB2>
inline void LoadDB2(uint32& availableDb2Locales, DB2StoreProblemList& errlist, StorageMap& stores, DB2StorageBase* storage, std::string const& db2Path, uint32 defaultLocale, DB2<T> const& /*hint*/)
{
    // validate structure
    DB2LoadInfo const* loadInfo = storage->GetLoadInfo();
    {
        std::string clientMetaString, ourMetaString;
        for (std::size_t i = 0; i < loadInfo->Meta->FieldCount; ++i)
            for (std::size_t j = 0; j < loadInfo->Meta->ArraySizes[i]; ++j)
                clientMetaString += loadInfo->Meta->Types[i];

        for (std::size_t i = loadInfo->Meta->HasIndexFieldInData() ? 0 : 1; i < loadInfo->FieldCount; ++i)
            ourMetaString += char(std::tolower(loadInfo->Fields[i].Type));

        ASSERT(clientMetaString == ourMetaString,
            "%s C++ structure fields %s do not match generated types from the client %s",
            storage->GetFileName().c_str(), ourMetaString.c_str(), clientMetaString.c_str());

        // compatibility format and C++ structure sizes
        ASSERT(loadInfo->Meta->GetRecordSize() == sizeof(T),
            "Size of '%s' set by format string (%u) not equal size of C++ structure (" SZFMTD ").",
            storage->GetFileName().c_str(), loadInfo->Meta->GetRecordSize(), sizeof(T));
    }

    if (storage->Load(db2Path + localeNames[defaultLocale] + '/', defaultLocale))
    {
        storage->LoadFromDB();
        // LoadFromDB() always loads strings into enUS locale, other locales are expected to have data in corresponding _locale tables
        // so we need to make additional call to load that data in case said locale is set as default by worldserver.conf (and we do not want to load all this data from .db2 file again)
        if (defaultLocale != LOCALE_enUS)
            storage->LoadStringsFromDB(defaultLocale);

        for (uint32 i = 0; i < TOTAL_LOCALES; ++i)
        {
            if (defaultLocale == i || i == LOCALE_none)
                continue;

            if (availableDb2Locales & (1 << i))
                if (!storage->LoadStringsFrom((db2Path + localeNames[i] + '/'), i))
                    availableDb2Locales &= ~(1 << i);             // mark as not available for speedup next checks

            storage->LoadStringsFromDB(i);
        }
    }
    else
    {
        // sort problematic db2 to (1) non compatible and (2) nonexistent
        if (FILE* f = fopen((db2Path + localeNames[defaultLocale] + '/' + storage->GetFileName()).c_str(), "rb"))
        {
            std::ostringstream stream;
            stream << storage->GetFileName() << " exists, and has " << storage->GetFieldCount() << " field(s) (expected " << loadInfo->Meta->FieldCount
                << "). Extracted file might be from wrong client version.";
            std::string buf = stream.str();
            errlist.push_back(buf);
            fclose(f);
        }
        else
            errlist.push_back(storage->GetFileName());
    }

    stores[storage->GetTableHash()] = storage;
}

DB2Manager& DB2Manager::Instance()
{
    static DB2Manager instance;
    return instance;
}

void DB2Manager::LoadStores(std::string const& dataPath, uint32 defaultLocale)
{
    uint32 oldMSTime = getMSTime();

    std::string db2Path = dataPath + "dbc/";

    DB2StoreProblemList bad_db2_files;
    uint32 availableDb2Locales = 0xFFF;

    std::vector<DB2StorageBase*> storages{};

#define LOAD_DB2(store) LoadDB2(availableDb2Locales, bad_db2_files, _stores, &store, db2Path, defaultLocale, store)

    LOAD_DB2(sAchievementStore);
    LOAD_DB2(sAdventureJournalStore);
    LOAD_DB2(sAdventureMapPOIStore);
    LOAD_DB2(sAnimKitStore);
    LOAD_DB2(sAreaGroupMemberStore);
    LOAD_DB2(sAreaTableStore);
    LOAD_DB2(sAreaTriggerStore);
    LOAD_DB2(sArmorLocationStore);
    LOAD_DB2(sArtifactStore);
    LOAD_DB2(sArtifactAppearanceStore);
    LOAD_DB2(sArtifactAppearanceSetStore);
    LOAD_DB2(sArtifactCategoryStore);
    LOAD_DB2(sArtifactPowerStore);
    LOAD_DB2(sArtifactPowerLinkStore);
    LOAD_DB2(sArtifactPowerPickerStore);
    LOAD_DB2(sArtifactPowerRankStore);
    LOAD_DB2(sArtifactQuestXPStore);
    LOAD_DB2(sArtifactUnlockStore);
    LOAD_DB2(sAuctionHouseStore);
    LOAD_DB2(sBankBagSlotPricesStore);
    LOAD_DB2(sBannedAddOnsStore);
    LOAD_DB2(sBarberShopStyleStore);
    LOAD_DB2(sBattlemasterListStore);
    LOAD_DB2(sBattlePetAbilityStore);
    LOAD_DB2(sBattlePetAbilityEffectStore);
    LOAD_DB2(sBattlePetAbilityStateStore);
    LOAD_DB2(sBattlePetAbilityTurnStore);
    LOAD_DB2(sBattlePetBreedQualityStore);
    LOAD_DB2(sBattlePetBreedStateStore);
    LOAD_DB2(sBattlePetEffectPropertiesStore);
    LOAD_DB2(sBattlePetSpeciesStore);
    LOAD_DB2(sBattlePetSpeciesStateStore);
    LOAD_DB2(sBattlePetSpeciesXAbilityStore);
    LOAD_DB2(sBattlePetStateStore);
    LOAD_DB2(sBroadcastTextStore);
    LOAD_DB2(sCharacterFacialHairStylesStore);
    LOAD_DB2(sCharacterLoadoutStore);
    LOAD_DB2(sCharacterLoadoutItemStore);
    LOAD_DB2(sCharBaseSectionStore);
    LOAD_DB2(sCharSectionsStore);
    LOAD_DB2(sCharShipmentStore);
    LOAD_DB2(sCharShipmentContainerStore);
    LOAD_DB2(sCharStartOutfitStore);
    LOAD_DB2(sCharTitlesStore);
    LOAD_DB2(sChatChannelsStore);
    LOAD_DB2(sChrClassesStore);
    LOAD_DB2(sChrClassesXPowerTypesStore);
    LOAD_DB2(sChrRacesStore);
    LOAD_DB2(sChrSpecializationStore);
    LOAD_DB2(sContributionStore);
    LOAD_DB2(sConversationLineStore);
    LOAD_DB2(sCreatureDifficultyStore);
    LOAD_DB2(sCreatureDisplayInfoStore);
    LOAD_DB2(sCreatureDisplayInfoExtraStore);
    LOAD_DB2(sCreatureFamilyStore);
    LOAD_DB2(sCreatureModelDataStore);
    LOAD_DB2(sCreatureTypeStore);
    LOAD_DB2(sCreatureXContributionStore);
    LOAD_DB2(sCriteriaStore);
    LOAD_DB2(sCriteriaTreeStore);
    LOAD_DB2(sCurrencyTypesStore);
    LOAD_DB2(sCurveStore);
    LOAD_DB2(sCurvePointStore);
    LOAD_DB2(sDestructibleModelDataStore);
    LOAD_DB2(sDifficultyStore);
    LOAD_DB2(sDungeonEncounterStore);
    LOAD_DB2(sDurabilityCostsStore);
    LOAD_DB2(sDurabilityQualityStore);
    LOAD_DB2(sEmotesStore);
    LOAD_DB2(sEmotesTextStore);
    LOAD_DB2(sFactionStore);
    LOAD_DB2(sFactionTemplateStore);
    LOAD_DB2(sFriendshipRepReactionStore);
    LOAD_DB2(sFriendshipReputationStore);
    LOAD_DB2(sGameObjectArtKitStore);
    LOAD_DB2(sGameObjectDisplayInfoStore);
    LOAD_DB2(sGameObjectsStore);
    LOAD_DB2(sGarrAbilityStore);
    LOAD_DB2(sGarrAbilityCategoryStore);
    LOAD_DB2(sGarrAbilityEffectStore);
    LOAD_DB2(sGarrBuildingStore);
    LOAD_DB2(sGarrBuildingDoodadSetStore);
    LOAD_DB2(sGarrBuildingPlotInstStore);
    LOAD_DB2(sGarrClassSpecStore);
    LOAD_DB2(sGarrEncounterStore);
    LOAD_DB2(sGarrEncounterSetXEncounterStore);
    LOAD_DB2(sGarrEncounterXMechanicStore);
    LOAD_DB2(sGarrFollItemSetMemberStore);
    LOAD_DB2(sGarrFollowerStore);
    LOAD_DB2(sGarrFollowerLevelXPStore);
    LOAD_DB2(sGarrFollowerQualityStore);
    LOAD_DB2(sGarrFollowerSetXFollowerStore);
    LOAD_DB2(sGarrFollowerTypeStore);
    LOAD_DB2(sGarrFollowerXAbilityStore);
    LOAD_DB2(sGarrFollSupportSpellStore);
    LOAD_DB2(sGarrItemLevelUpgradeDataStore);
    LOAD_DB2(sGarrMechanicStore);
    LOAD_DB2(sGarrMechanicSetXMechanicStore);
    LOAD_DB2(sGarrMechanicTypeStore);
    LOAD_DB2(sGarrMissionStore);
    LOAD_DB2(sGarrMissionTypeStore);
    LOAD_DB2(sGarrMissionXEncounterStore);
    LOAD_DB2(sGarrMissionXFollowerStore);
    LOAD_DB2(sGarrMssnBonusAbilityStore);
    LOAD_DB2(sGarrPlotStore);
    LOAD_DB2(sGarrPlotBuildingStore);
    LOAD_DB2(sGarrPlotInstanceStore);
    LOAD_DB2(sGarrSiteLevelStore);
    LOAD_DB2(sGarrSiteLevelPlotInstStore);
    LOAD_DB2(sGarrSpecializationStore);
    LOAD_DB2(sGarrTalentStore);
    LOAD_DB2(sGarrTalentTreeStore);
    LOAD_DB2(sGarrTypeStore);
    LOAD_DB2(sGemPropertiesStore);
    LOAD_DB2(sGlyphBindableSpellStore);
    LOAD_DB2(sGlyphPropertiesStore);
    LOAD_DB2(sGlyphRequiredSpecStore);
    LOAD_DB2(sGroupFinderActivityStore);
    LOAD_DB2(sGroupFinderActivityGrpStore);
    LOAD_DB2(sGroupFinderCategoryStore);
    LOAD_DB2(sGuildColorBackgroundStore);
    LOAD_DB2(sGuildColorBorderStore);
    LOAD_DB2(sGuildColorEmblemStore);
    LOAD_DB2(sGuildPerkSpellsStore);
    LOAD_DB2(sHeirloomStore);
    LOAD_DB2(sHolidayNamesStore);
    LOAD_DB2(sHolidaysStore);
    LOAD_DB2(sImportPriceArmorStore);
    LOAD_DB2(sImportPriceQualityStore);
    LOAD_DB2(sImportPriceShieldStore);
    LOAD_DB2(sImportPriceWeaponStore);
    LOAD_DB2(sItemStore);
    LOAD_DB2(sItemAppearanceStore);
    LOAD_DB2(sItemArmorQualityStore);
    LOAD_DB2(sItemArmorShieldStore);
    LOAD_DB2(sItemArmorTotalStore);
    LOAD_DB2(sItemBonusStore);
    LOAD_DB2(sItemBonusListLevelDeltaStore);
    LOAD_DB2(sItemBonusTreeNodeStore);
    LOAD_DB2(sItemChildEquipmentStore);
    LOAD_DB2(sItemClassStore);
    LOAD_DB2(sItemCurrencyCostStore);
    LOAD_DB2(sItemDamageAmmoStore);
    LOAD_DB2(sItemDamageOneHandStore);
    LOAD_DB2(sItemDamageOneHandCasterStore);
    LOAD_DB2(sItemDamageTwoHandStore);
    LOAD_DB2(sItemDamageTwoHandCasterStore);
    LOAD_DB2(sItemDisenchantLootStore);
    LOAD_DB2(sItemEffectStore);
    LOAD_DB2(sItemExtendedCostStore);
    LOAD_DB2(sItemLevelSelectorStore);
    LOAD_DB2(sItemLevelSelectorQualityStore);
    LOAD_DB2(sItemLevelSelectorQualitySetStore);
    LOAD_DB2(sItemLimitCategoryStore);
    LOAD_DB2(sItemLimitCategoryConditionStore);
    LOAD_DB2(sItemModifiedAppearanceStore);
    LOAD_DB2(sItemPriceBaseStore);
    LOAD_DB2(sItemRandomPropertiesStore);
    LOAD_DB2(sItemRandomSuffixStore);
    LOAD_DB2(sItemSetStore);
    LOAD_DB2(sItemSetSpellStore);
    LOAD_DB2(sItemSparseStore);
    LOAD_DB2(sItemSpecStore);
    LOAD_DB2(sItemSpecOverrideStore);
    LOAD_DB2(sItemUpgradeStore);
    LOAD_DB2(sItemXBonusTreeStore);
    LOAD_DB2(sJournalEncounterStore);
    LOAD_DB2(sJournalEncounterCreatureStore);
    LOAD_DB2(sJournalEncounterItemStore);
    LOAD_DB2(sJournalInstanceStore);
    LOAD_DB2(sKeyChainStore);
    LOAD_DB2(sLanguageWordsStore);
    LOAD_DB2(sLfgDungeonsStore);
    LOAD_DB2(sLfgRoleRequirementStore);
    LOAD_DB2(sLightStore);
    LOAD_DB2(sLockStore);
    LOAD_DB2(sMailTemplateStore);
    LOAD_DB2(sManagedWorldStateStore);
    LOAD_DB2(sManagedWorldStateBuffStore);
    LOAD_DB2(sManagedWorldStateInputStore);
    LOAD_DB2(sMapStore);
    LOAD_DB2(sMapChallengeModeStore);
    LOAD_DB2(sMapDifficultyStore);
    LOAD_DB2(sMapDifficultyXConditionStore);
    LOAD_DB2(sModifierTreeStore);
    LOAD_DB2(sMountStore);
    LOAD_DB2(sMountCapabilityStore);
    LOAD_DB2(sMountTypeXCapabilityStore);
    LOAD_DB2(sMountXDisplayStore);
    LOAD_DB2(sMovieStore);
    LOAD_DB2(sNameGenStore);
    LOAD_DB2(sNamesProfanityStore); 
    LOAD_DB2(sNamesReservedStore); 
    LOAD_DB2(sNamesReservedLocaleStore); 
    LOAD_DB2(sOverrideSpellDataStore);
    LOAD_DB2(sParagonReputationStore);
    LOAD_DB2(sPhaseStore);
    LOAD_DB2(sPhaseXPhaseGroupStore);
    LOAD_DB2(sPlayerConditionStore);
    LOAD_DB2(sPowerDisplayStore);
    LOAD_DB2(sPowerTypeStore);
    LOAD_DB2(sPrestigeLevelInfoStore);
    LOAD_DB2(sPvpDifficultyStore);
    LOAD_DB2(sPvpItemStore);
    LOAD_DB2(sPvpRewardStore);
    LOAD_DB2(sPvpScalingEffectStore);
    LOAD_DB2(sPvpScalingEffectTypeStore);
    LOAD_DB2(sPvpTalentStore);
    LOAD_DB2(sPvpTalentUnlockStore);
    LOAD_DB2(sQuestFactionRewardStore);
    LOAD_DB2(sQuestLineStore);
    LOAD_DB2(sQuestLineXQuestStore);
    LOAD_DB2(sQuestMoneyRewardStore);
    LOAD_DB2(sQuestObjectiveStore);
    LOAD_DB2(sQuestPackageItemStore);
    LOAD_DB2(sQuestPOIBlobStore);
    LOAD_DB2(sQuestPOIPointStore);
    LOAD_DB2(sQuestSortStore);
    LOAD_DB2(sQuestV2Store);
    LOAD_DB2(sQuestV2CliTaskStore);
    LOAD_DB2(sQuestXPStore);
    LOAD_DB2(sRandPropPointsStore);
    LOAD_DB2(sRelicSlotTierRequirementStore);
    LOAD_DB2(sRelicTalentStore);
    LOAD_DB2(sResearchBranchStore);
    LOAD_DB2(sResearchProjectStore);
    LOAD_DB2(sResearchSiteStore);
    LOAD_DB2(sRewardPackStore);
    LOAD_DB2(sRewardPackXCurrencyTypeStore);
    LOAD_DB2(sRewardPackXItemStore);
    LOAD_DB2(sRulesetItemUpgradeStore);
    LOAD_DB2(sSandboxScalingStore);
    LOAD_DB2(sScalingStatDistributionStore);
    LOAD_DB2(sScenarioStore);
    LOAD_DB2(sScenarioStepStore);
    LOAD_DB2(sSkillLineStore);
    LOAD_DB2(sSkillLineAbilityStore);
    LOAD_DB2(sSkillRaceClassInfoStore);
    LOAD_DB2(sSoundKitStore);
    LOAD_DB2(sSpecializationSpellsStore);
    LOAD_DB2(sSpellStore);
    LOAD_DB2(sSpellAuraOptionsStore);
    LOAD_DB2(sSpellAuraRestrictionsStore);
    LOAD_DB2(sSpellCastingRequirementsStore);
    LOAD_DB2(sSpellCastTimesStore);
    LOAD_DB2(sSpellCategoriesStore);
    LOAD_DB2(sSpellCategoryStore);
    LOAD_DB2(sSpellClassOptionsStore);
    LOAD_DB2(sSpellCooldownsStore);
    LOAD_DB2(sSpellDurationStore);
    LOAD_DB2(sSpellEffectStore);
    LOAD_DB2(sSpellEquippedItemsStore);
    LOAD_DB2(sSpellFocusObjectStore);
    LOAD_DB2(sSpellInterruptsStore);
    LOAD_DB2(sSpellItemEnchantmentStore);
    LOAD_DB2(sSpellItemEnchantmentConditionStore);
    LOAD_DB2(sSpellLearnSpellStore);
    LOAD_DB2(sSpellLevelsStore);
    LOAD_DB2(sSpellMiscStore);
    LOAD_DB2(sSpellPowerStore);
    LOAD_DB2(sSpellPowerDifficultyStore);
    LOAD_DB2(sSpellProcsPerMinuteStore);
    LOAD_DB2(sSpellProcsPerMinuteModStore);
    LOAD_DB2(sSpellRadiusStore);
    LOAD_DB2(sSpellRangeStore);
    LOAD_DB2(sSpellReagentsStore);
    LOAD_DB2(sSpellReagentsCurrencyStore);
    LOAD_DB2(sSpellScalingStore);
    LOAD_DB2(sSpellShapeshiftStore);
    LOAD_DB2(sSpellShapeshiftFormStore);
    LOAD_DB2(sSpellTargetRestrictionsStore);
    LOAD_DB2(sSpellTotemsStore);
    LOAD_DB2(sSpellXSpellVisualStore);
    LOAD_DB2(sSummonPropertiesStore);
    LOAD_DB2(sTactKeyStore);
    LOAD_DB2(sTalentStore);
    LOAD_DB2(sTaxiNodesStore);
    LOAD_DB2(sTaxiPathStore);
    LOAD_DB2(sTaxiPathNodeStore);
    LOAD_DB2(sTotemCategoryStore);
    LOAD_DB2(sToyStore);
    LOAD_DB2(sTransmogHolidayStore);
    LOAD_DB2(sTransmogSetStore);
    LOAD_DB2(sTransmogSetGroupStore);
    LOAD_DB2(sTransmogSetItemStore);
    LOAD_DB2(sTransportAnimationStore);
    LOAD_DB2(sTransportRotationStore);
    LOAD_DB2(sUnitPowerBarStore);
    LOAD_DB2(sVehicleStore);
    LOAD_DB2(sVehicleSeatStore);
    LOAD_DB2(sVignetteStore);
    LOAD_DB2(sWMOAreaTableStore);
    LOAD_DB2(sWorldEffectStore);
    LOAD_DB2(sWorldMapAreaStore);
    LOAD_DB2(sWorldMapOverlayStore);
    LOAD_DB2(sWorldMapTransformsStore);
    LOAD_DB2(sWorldSafeLocsStore);
    LOAD_DB2(sWorldStateExpressionStore);
    LOAD_DB2(sWorldStateUIStore);
   

    // error checks
    if (bad_db2_files.size() == _stores.size())
    {
        TC_LOG_ERROR(LOG_FILTER_GENERAL, "\nIncorrect DataDir value in worldserver.conf or ALL required *.db2 files (" SZFMTD ") not found by path: %sdbc/%s/", _stores.size(), dataPath.c_str(), localeNames[defaultLocale]);
        exit(1);
    }
    if (!bad_db2_files.empty())
    {
        std::string str;
        for (auto const& bad_db2_file : bad_db2_files)
            str += bad_db2_file + "\n";

        TC_LOG_ERROR(LOG_FILTER_GENERAL, "\nSome required *.db2 files (%u from " SZFMTD ") not found or not compatible:\n%s", bad_db2_files.size(), _stores.size(), str.c_str());
        exit(1);
    }

    // Check loaded DB2 files proper version
    if (!sAreaTableStore.LookupEntry(9531) ||                // last area added in 7.3.5 (25996)
        !sCharTitlesStore.LookupEntry(522) ||                // last char title added in 7.3.5 (25996)
        !sGemPropertiesStore.LookupEntry(3632) ||            // last gem property added in 7.3.5 (25996)
        !sItemStore.LookupEntry(157831) ||                   // last item added in 7.3.5 (25996)
        !sItemExtendedCostStore.LookupEntry(6300) ||         // last item extended cost added in 7.3.5 (25996)
        !sMapStore.LookupEntry(1903) ||                      // last map added in 7.3.5 (25996)
        !sSpellStore.LookupEntry(263166))                    // last spell added in 7.3.5 (25996)
    {
        TC_LOG_ERROR(LOG_FILTER_GENERAL, "You have _outdated_ DB2 files. Please extract correct versions from current using client.");
        exit(1);
    }


    InitDB2CustomStores();

    TC_LOG_INFO(LOG_FILTER_SERVER_LOADING, ">> Initialized " SZFMTD " DB2 data stores in %u ms", _stores.size(), GetMSTimeDiffToNow(oldMSTime));
}

void DB2Manager::InitDB2CustomStores()
{
    ASSERT(BATTLE_PET_SPECIES_MAX_ID >= sBattlePetSpeciesStore.GetNumRows(),
        "BATTLE_PET_SPECIES_MAX_ID (%d) must be equal to or greater than %u", BATTLE_PET_SPECIES_MAX_ID, sBattlePetSpeciesStore.GetNumRows());

    ASSERT(PVP_SCALING_EFFECT_MAX >= sPvpScalingEffectTypeStore.GetNumRows(), "In PvpScalingEffectTypes.db2 exist new rows %u", sPvpScalingEffectTypeStore.GetNumRows());

    for (AreaTableEntry const* area : sAreaTableStore)
        _areaEntry.insert(std::make_pair(area->ID, area));

    for (LanguageWordsEntry const* entry : sLanguageWordsStore)
        _languageWordsMap[entry->LanguageID][strlen(entry->Word->Str[sObjectMgr->GetDBCLocaleIndex()])].push_back(entry->Word->Str[sObjectMgr->GetDBCLocaleIndex()]);

    for (ToyEntry const* toy : sToyStore)
        _toys.insert(toy->ItemID);

    for (HeirloomEntry const* heirloom : sHeirloomStore)
        _heirlooms[heirloom->ItemID] = heirloom;

    for (AreaGroupMemberEntry const* areaGroupMember : sAreaGroupMemberStore)
    {
        _areaGroupMembers[areaGroupMember->AreaGroupID].push_back(areaGroupMember->AreaID);
        _areaMemberGroups[areaGroupMember->AreaID].push_back(areaGroupMember->AreaGroupID);
    }

    for (GlyphBindableSpellEntry const* glyphBindableSpell : sGlyphBindableSpellStore)
        _glyphBindableSpells[glyphBindableSpell->GlyphPropertiesID].push_back(glyphBindableSpell->SpellID);

    for (GlyphRequiredSpecEntry const* glyphRequiredSpec : sGlyphRequiredSpecStore)
        _glyphRequiredSpecs[glyphRequiredSpec->GlyphPropertiesID].push_back(glyphRequiredSpec->ChrSpecializationID);

    for (ItemBonusEntry const* bonus : sItemBonusStore)
        _itemBonusLists[bonus->ParentItemBonusListID].push_back(bonus);

    for (ItemBonusTreeNodeEntry const* bonusTreeNode : sItemBonusTreeNodeStore)
        _itemBonusTrees[bonusTreeNode->BonusTreeID].insert(bonusTreeNode);

    for (ItemBonusListLevelDeltaEntry const* itemBonusListLevelDelta : sItemBonusListLevelDeltaStore)
        _itemLevelDeltaToBonusListContainer[itemBonusListLevelDelta->ItemLevelDelta] = itemBonusListLevelDelta->ID;

    for (ItemCurrencyCostEntry const* itemCurrencyCost : sItemCurrencyCostStore)
        _itemsWithCurrencyCost.insert(itemCurrencyCost->ItemID);

    for (ItemLevelSelectorQualityEntry const* itemLevelSelectorQuality : sItemLevelSelectorQualityStore)
        _itemLevelQualitySelectorQualities[itemLevelSelectorQuality->ItemLevelSelectorQualitySetID].insert(itemLevelSelectorQuality);

    for (auto condition : sItemLimitCategoryConditionStore)
         _itemCategoryConditions[condition->ParentItemLimitCategoryID].push_back(condition);

    for (ItemModifiedAppearanceEntry const* appearanceMod : sItemModifiedAppearanceStore)
    {
        _itemToTransmogByItem[appearanceMod->ItemID].push_back(appearanceMod->ID);

        if (_itemModifiedAppearancesByItem.size() <= appearanceMod->ItemID)
            _itemModifiedAppearancesByItem.resize(appearanceMod->ItemID + 1);
        if (_itemModifiedAppearancesByItem[appearanceMod->ItemID].size() <= appearanceMod->ItemAppearanceModifierID)
            _itemModifiedAppearancesByItem[appearanceMod->ItemID].resize(appearanceMod->ItemAppearanceModifierID + 1);

        _itemModifiedAppearancesByItem[appearanceMod->ItemID][appearanceMod->ItemAppearanceModifierID] = appearanceMod;
    }

    for (CurvePointEntry const* curvePoint : sCurvePointStore)
        if (sCurveStore.LookupEntry(curvePoint->CurveID))
            _curvePoints[curvePoint->CurveID].push_back(curvePoint);

    for (auto & curvePoint : _curvePoints)
        std::sort(curvePoint.second.begin(), curvePoint.second.end(), [](CurvePointEntry const* point1, CurvePointEntry const* point2) { return point1->OrderIndex < point2->OrderIndex; });

    for (MountEntry const* mount : sMountStore)
    {
        _mountsBySpellId[mount->SourceSpellID] = mount;
        if (mount->SourceSpellID == 37015)  // hack for fly custom
            _mountsBySpellId[215545] = mount;
        if (mount->SourceSpellID == 6898)  // hack for ground custom
            _mountsBySpellId[165974] = mount;
        if (mount->SourceSpellID == 28828) // hack for quest mount
            _mountsBySpellId[218964] = mount;
    }

    for (MountTypeXCapabilityEntry const* mount : sMountTypeXCapabilityStore)
        _mountCapabilitiesByType[mount->MountTypeID].insert(mount);

    for (MountXDisplayEntry const* mountDisplay : sMountXDisplayStore)
        _mountDisplays[mountDisplay->MountID].push_back(mountDisplay);

    _pvpScalingEffectsBySpecID.resize(MAX_SPECS);
    for (uint16 i = 0; i < MAX_SPECS; ++i)
    {
        _pvpScalingEffectsBySpecID[i].resize(PVP_SCALING_EFFECT_MAX);
        for (uint16 j = 0; j < PVP_SCALING_EFFECT_MAX; ++j)
            _pvpScalingEffectsBySpecID[i][j] = 0.0f;
    }

    for (PvpScalingEffectEntry const* entry : sPvpScalingEffectStore)
        _pvpScalingEffectsBySpecID[entry->SpecializationID][entry->PvpScalingEffectTypeID] = entry->Value;

    for (MapChallengeModeEntry const* entry : sMapChallengeModeStore)
    {
        _mapChallengeModeEntrybyMap[entry->MapID] = entry;
        if (entry->Flags != 2)
        {
            _challengeModeMaps.emplace_back(entry->ID);
            _challengeWeightMaps.emplace_back(GetChallngeWeight(entry->MapID));
        }
    }

    for (ItemXBonusTreeEntry const* itemBonusTreeAssignment : sItemXBonusTreeStore)
    {
        _itemToBonusTree.insert({ itemBonusTreeAssignment->ItemID, itemBonusTreeAssignment->ItemBonusTreeID });
        _bonusToItemTree[itemBonusTreeAssignment->ItemBonusTreeID].insert(itemBonusTreeAssignment->ItemID);
    }

    for (QuestPackageItemEntry const* questPackageItem : sQuestPackageItemStore)
        _questPackages[questPackageItem->PackageID].push_back(questPackageItem);

    for (GameObjectsEntry const* store : sGameObjectsStore)
        _gameObjectsList.push_back(store->ID);

    for (RulesetItemUpgradeEntry const* rulesetItemUpgrade : sRulesetItemUpgradeStore)
        _rulesetItemUpgrade[rulesetItemUpgrade->ItemID] = rulesetItemUpgrade->ItemUpgradeID;

    for (TaxiPathEntry const* entry : sTaxiPathStore)
        sTaxiPathSetBySource[entry->FromTaxiNode][entry->ToTaxiNode] = TaxiPathBySourceAndDestination(entry->ID, entry->Cost);

    uint32 pathCount = sTaxiPathStore.GetNumRows();

    // Calculate path nodes count
    std::vector<uint32> pathLength;
    pathLength.resize(pathCount);                           // 0 and some other indexes not used
    for (TaxiPathNodeEntry const* entry : sTaxiPathNodeStore)
        if (static_cast<uint8>(pathLength[entry->PathID]) < entry->NodeIndex + 1)
            pathLength[entry->PathID] = entry->NodeIndex + 1;

    // Set path length
    sTaxiPathNodesByPath.resize(pathCount);                 // 0 and some other indexes not used
    for (size_t i = 0; i < sTaxiPathNodesByPath.size(); ++i)
        sTaxiPathNodesByPath[i].resize(pathLength[i]);

    // fill data
    for (TaxiPathNodeEntry const* entry : sTaxiPathNodeStore)
        sTaxiPathNodesByPath[entry->PathID][entry->NodeIndex] = entry;

    // Initialize global taxinodes mask
    // include existed nodes that have at least single not spell base (scripted) path
    {
        if (sTaxiNodesStore.GetNumRows())
        {
             ASSERT(TaxiMaskSize >= ((sTaxiNodesStore.GetNumRows() - 1) / 8) + 1,
             "TaxiMaskSize is not large enough to contain all taxi nodes! (current value %d, required %d)",
             TaxiMaskSize, uint32(((sTaxiNodesStore.GetNumRows() - 1) / 8) + 1));
        }

        sTaxiNodesMaskV.resize(TaxiMaskSize, 0);
        sTaxiNodesMask.fill(0);
        sOldContinentsNodesMask.fill(0);
        sHordeTaxiNodesMask.fill(0);
        sAllianceTaxiNodesMask.fill(0);
        for (TaxiNodesEntry const* node : sTaxiNodesStore)
        {
            if (node->ID == 1985 || node->ID == 1986 || node->ID == 1987)
                const_cast<TaxiNodesEntry*>(node)->Flags |= TAXI_NODE_FLAG_ALLIANCE | TAXI_NODE_FLAG_HORDE;

            if (!(node->Flags & (TAXI_NODE_FLAG_ALLIANCE | TAXI_NODE_FLAG_HORDE)))
                continue;

            // valid taxi network node
            auto field = static_cast<uint16>((node->ID - 1) / 8);
            uint32 submask = 1 << ((node->ID - 1) % 8);

            sTaxiNodesMask[field] |= submask;
            sTaxiNodesMaskV[field] |= submask;
            if (node->Flags & TAXI_NODE_FLAG_HORDE)
                sHordeTaxiNodesMask[field] |= submask;
            if (node->Flags & TAXI_NODE_FLAG_ALLIANCE)
                sAllianceTaxiNodesMask[field] |= submask;

            uint32 nodeMap;
            DeterminaAlternateMapPosition(node->ContinentID, node->Pos.X, node->Pos.Y, node->Pos.Z, &nodeMap);
            if (nodeMap < 2)
                sOldContinentsNodesMask[field] |= submask;
        }
    }

    for (AchievementEntry const* store : sAchievementStore)
        if (store->CriteriaTree)
            _achievementParentList[store->CriteriaTree] = store;

    for (CharacterLoadoutItemEntry const* LoadOutItem : sCharacterLoadoutItemStore)
        _characterLoadoutItem[LoadOutItem->CharacterLoadoutID].push_back(LoadOutItem->ItemID);

    for (CharacterLoadoutEntry const* entry : sCharacterLoadoutStore)
        _characterLoadout[entry->ChrClassID].insert(std::make_pair(entry->ID, entry->Purpose));

    for (CriteriaTreeEntry const* ct : sCriteriaTreeStore)
        if (ct->Parent)
            _criteriaTree[ct->Parent].push_back(ct);

    for (GameObjectDisplayInfoEntry const* info : sGameObjectDisplayInfoStore)
    {
        if (info->GeoBoxMax.X < info->GeoBoxMin.X)
            std::swap(*const_cast<float*>(&info->GeoBoxMax.X), *const_cast<float*>(&info->GeoBoxMin.X));

        if (info->GeoBoxMax.Y < info->GeoBoxMin.Y)
            std::swap(*const_cast<float*>(&info->GeoBoxMax.Y), *const_cast<float*>(&info->GeoBoxMin.Y));

        if (info->GeoBoxMax.Z < info->GeoBoxMin.Z)
            std::swap(*const_cast<float*>(&info->GeoBoxMax.Z), *const_cast<float*>(&info->GeoBoxMin.Z));
    }

    for (ItemSetSpellEntry const* itemSetSpell : sItemSetSpellStore)
        _itemSetSpells[itemSetSpell->ItemSetID].push_back(itemSetSpell);

    for (ItemSpecOverrideEntry const* entry : sItemSpecOverrideStore)
        _itemSpecOverrides[entry->ItemID].push_back(entry);

    for (ModifierTreeEntry const* mt : sModifierTreeStore)
        if (mt->Parent)
            _modifierTree[mt->Parent].push_back(mt);

    for (NameGenEntry const* entry : sNameGenStore)
        _nameGenData[entry->RaceID][entry->Sex].push_back(entry);

    for (NamesProfanityEntry const* namesProfanity : sNamesProfanityStore)
    {
        ASSERT(namesProfanity->Language < MAX_LOCALES || namesProfanity->Language == -1);
        std::wstring name;
        ASSERT(Utf8toWStr(namesProfanity->Name, name));
        if (namesProfanity->Language != -1)
            _nameValidators[namesProfanity->Language].emplace_back(name, boost::regex::icase | boost::regex::optimize);
        else
        {
            for (uint32 i = 0; i < MAX_LOCALES; ++i)
            {
                if (i == LOCALE_none)
                    continue;

                _nameValidators[i].emplace_back(name, boost::regex::icase | boost::regex::optimize);
            }
        }
    }

    for (NamesReservedLocaleEntry const* namesReserved : sNamesReservedLocaleStore)
    {
        ASSERT(!(namesReserved->LocaleMask & ~((1u << TOTAL_LOCALES) - 1)));
		std::wstring name;
        ASSERT(Utf8toWStr(namesReserved->Name, name));
        _nameValidators[MAX_LOCALES].emplace_back(name, boost::regex::icase | boost::regex::optimize);
    }

    for (NamesReservedLocaleEntry const* namesReserved : sNamesReservedLocaleStore)
    {
        ASSERT(!(namesReserved->LocaleMask & ~((1 << MAX_LOCALES) - 1)));
        std::wstring name;
        ASSERT(Utf8toWStr(namesReserved->Name, name));
        for (uint32 i = 0; i < MAX_LOCALES; ++i)
        {
            if (i == LOCALE_none)
                continue;

            if (namesReserved->LocaleMask & (1 << i))
                _nameValidators[i].emplace_back(name, boost::regex::icase | boost::regex::optimize);
        }
    }

    for (ResearchSiteEntry const* rs : sResearchSiteStore)
    {
        if (!rs->IsValid())
            continue;

        ResearchSiteData& data = _researchSiteDataMap[rs->ID];
        data.entry = rs;
        for (QuestPOIPointEntry const* poi : sQuestPOIPointStore)
            if (poi->ID == rs->QuestPoiBlobID)
                data.points.push_back(ResearchPOIPoint(poi->X, poi->Y));

        if (data.points.empty())
            TC_LOG_DEBUG(LOG_FILTER_SERVER_LOADING, "Research siteID %u QuestPoiBlobId %u MapID %u has 0 points points in DB2!", rs->ID, rs->QuestPoiBlobID, rs->MapID);
    }

    for (ResearchProjectEntry const* rp : sResearchProjectStore)
        if (rp->IsVaid())
            _researchProjectContainer.insert(rp);

    for (TransportAnimationEntry const* entry : sTransportAnimationStore)
        _transportAnimationsByEntry[entry->TransportID][entry->TimeIndex] = entry;

    for (SkillRaceClassInfoEntry const* entry : sSkillRaceClassInfoStore)
        if (sSkillLineStore.LookupEntry(entry->SkillID))
            _skillRaceClassInfoBySkill.emplace(entry->SkillID, entry);

    for (SpecializationSpellsEntry const* specSpells : sSpecializationSpellsStore)
        _specializationSpellsBySpec[specSpells->SpecID].push_back(specSpells);

    for (SpellCategoriesEntry const* spell : sSpellCategoriesStore)
    {
        if (spell && spell->Category)
            _spellCategory[spell->Category].insert(spell->SpellID);
    }

    for (SpellProcsPerMinuteModEntry const* ppmMod : sSpellProcsPerMinuteModStore)
        _spellProcsPerMinuteMods[ppmMod->SpellProcsPerMinuteID].push_back(ppmMod);

    for (SpellTargetRestrictionsEntry const* restriction : sSpellTargetRestrictionsStore)
        _spellRestrictionDiff[restriction->SpellID].insert(restriction);

    _spellEffectDiff.resize(sSpellEffectStore.GetNumRows() + 1);
    _spellEffectMap.resize(sSpellEffectStore.GetNumRows() + 1);

    for (SpellEffectEntry const* spellEffect : sSpellEffectStore)
    {
        ASSERT(spellEffect->EffectIndex < MAX_SPELL_EFFECTS, "MAX_SPELL_EFFECTS must be at least %u", spellEffect->EffectIndex + 1);
        ASSERT(spellEffect->Effect < TOTAL_SPELL_EFFECTS, "TOTAL_SPELL_EFFECTS must be at least %u", spellEffect->Effect + 1);
        ASSERT(spellEffect->EffectAura < TOTAL_AURAS, "TOTAL_AURAS must be at least %u", spellEffect->EffectAura + 1);
        ASSERT(spellEffect->ImplicitTarget[0] < TOTAL_SPELL_TARGETS, "TOTAL_SPELL_TARGETS must be at least %u", spellEffect->ImplicitTarget[0] + 1);
        ASSERT(spellEffect->ImplicitTarget[1] < TOTAL_SPELL_TARGETS, "TOTAL_SPELL_TARGETS must be at least %u", spellEffect->ImplicitTarget[1] + 1);

        if (spellEffect->DifficultyID)
            _spellEffectDiff[spellEffect->SpellID].effects[MAKE_PAIR16(spellEffect->EffectIndex, spellEffect->DifficultyID)] = spellEffect;
        else
            _spellEffectMap[spellEffect->SpellID].effects[spellEffect->EffectIndex] = spellEffect;

        if (spellEffect->Effect == SPELL_EFFECT_LEARN_SPELL)
            _revertLearnSpell[spellEffect->EffectTriggerSpell] = spellEffect->SpellID;

        if (spellEffect->EffectTriggerSpell)
            _reversTriggerSpellList[spellEffect->EffectTriggerSpell] = spellEffect->SpellID;
    }

    memset(_chrSpecializationByIndex, 0, sizeof _chrSpecializationByIndex);
    for (ChrSpecializationEntry const* chrSpec : sChrSpecializationStore)
    {
        ASSERT(chrSpec->ClassID < MAX_CLASSES);
        ASSERT(chrSpec->OrderIndex < MAX_SPECIALIZATIONS);

        uint32 storageIndex = chrSpec->ClassID;
        if (chrSpec->Flags & CHR_SPECIALIZATION_FLAG_PET_OVERRIDE_SPEC)
        {
            ASSERT(!chrSpec->ClassID);
            storageIndex = PET_SPEC_OVERRIDE_CLASS_INDEX;
        }

        _chrSpecializationByIndex[storageIndex][chrSpec->OrderIndex] = chrSpec;
        if (chrSpec->Flags & CHR_SPECIALIZATION_FLAG_RECOMMENDED)
            _defaultChrSpecializationsByClass[chrSpec->ClassID] = chrSpec;
    }

    for (PVPDifficultyEntry const* entry : sPvpDifficultyStore)
    {
        if (entry->RangeIndex >= MS::Battlegrounds::MaxBrackets)
            ASSERT(false && "Need update MS::Battlegrounds::MaxBrackets by db2 data");
    }

    {
        std::set<ChrClassesXPowerTypesEntry const*, ChrClassesXPowerTypesEntryComparator> powers;
        for (ChrClassesXPowerTypesEntry const* power : sChrClassesXPowerTypesStore)
            powers.insert(power);

        for (auto & powersByClass : _powersByClass)
            for (auto & power : powersByClass)
                power = MAX_POWERS;

        for (ChrClassesXPowerTypesEntry const* power : powers)
        {
            uint32 index = 0;
            for (uint32 j = 0; j < MAX_POWERS; ++j)
                if (_powersByClass[power->ClassID][j] != MAX_POWERS)
                    ++index;

            ASSERT(power->PowerType < MAX_POWERS);
            _powersByClass[power->ClassID][power->PowerType] = index;
        }
    }

    for (DungeonEncounterEntry const* store : sDungeonEncounterStore)
        if (store->CreatureDisplayID)
            _dungeonEncounterByDisplayID[store->CreatureDisplayID] = store;

    for (MapDifficultyEntry const* entry : sMapDifficultyStore)
        _mapDifficulty[entry->MapID][entry->DifficultyID] = entry;

    for (auto const& entry : sMapDifficultyXConditionStore)
        _mapDifficultyCondition[entry->MapDifficultyId] = entry->PlayerConditionID;

    for (auto const& spellMiscEntry : sSpellMiscStore)
        _spellMiscBySpellIDContainer[spellMiscEntry->SpellID] = spellMiscEntry->ID;

    for (SkillLineAbilityEntry const* skillLine : sSkillLineAbilityStore)
    {
        if (skillLine->SkillLine >= _skillLineAbilityContainer.size())
            _skillLineAbilityContainer.resize(skillLine->SkillLine + 1);
        _skillLineAbilityContainer[skillLine->SkillLine].push_back(skillLine);

        _spellToSkillContainer[skillLine->Spell] = skillLine;

        SpellMiscEntry const* spellMisc = sSpellMiscStore.LookupEntry(GetSpellMisc(skillLine->Spell));
        if (!spellMisc)
            continue;

        if (spellMisc->Attributes[0] & SPELL_ATTR0_PASSIVE)
            for (CreatureFamilyEntry const* cFamily : sCreatureFamilyStore)
            {
                if (skillLine->SkillLine != cFamily->SkillLine[0] && (!cFamily->SkillLine[1] || skillLine->SkillLine != cFamily->SkillLine[1]))
                    continue;

                if (skillLine->AcquireMethod != SKILL_LINE_ABILITY_LEARNED_ON_SKILL_LEARN)
                    continue;

                _petFamilySpells[cFamily->ID].insert(skillLine->Spell);
            }
    }

    for (QuestLineXQuestEntry const* entry : sQuestLineXQuestStore)
        _questsByQuestLine[entry->QuestLineID].push_back(entry);

    for (auto & itr : _questsByQuestLine)
        std::sort(itr.second.begin(), itr.second.end(), [](QuestLineXQuestEntry const* entry1, QuestLineXQuestEntry const* entry2) { return entry1->OrderIndex < entry2->OrderIndex; });

    for (CharacterFacialHairStylesEntry const* characterFacialStyle : sCharacterFacialHairStylesStore)
        _characterFacialHairStyles.emplace(characterFacialStyle->RaceID, characterFacialStyle->SexID, characterFacialStyle->VariationID);

    std::array<CharBaseSectionVariation, SECTION_TYPE_MAX> sectionToBase = { {} };
    for (auto charBaseSection : sCharBaseSectionStore)
    {
        ASSERT(charBaseSection->ResolutionVariationEnum < SECTION_TYPE_MAX, "SECTION_TYPE_MAX (%d) must be equal to or greater than %u", uint32(SECTION_TYPE_MAX), uint32(charBaseSection->ResolutionVariationEnum + 1));
        ASSERT(charBaseSection->VariationEnum < AsUnderlyingType(CharBaseSectionVariation::Count), "CharBaseSectionVariation::Count %u must be equal to or greater than %u", uint32(CharBaseSectionVariation::Count), uint32(charBaseSection->VariationEnum + 1));

        sectionToBase[charBaseSection->ResolutionVariationEnum] = static_cast<CharBaseSectionVariation>(charBaseSection->VariationEnum);
    }

    std::map<std::tuple<uint8, uint8, CharBaseSectionVariation>, std::set<std::pair<uint8, uint8>>> addedSections;
    for (auto charSection : sCharSectionsStore)
    {
        ASSERT(charSection->BaseSection < SECTION_TYPE_MAX, "SECTION_TYPE_MAX (%d) must be equal to or greater than %u", AsUnderlyingType(SECTION_TYPE_MAX), uint32(charSection->BaseSection + 1));

        std::tuple<uint8, uint8, CharBaseSectionVariation> sectionKey{ charSection->RaceID, charSection->SexID, sectionToBase[charSection->BaseSection] };
        std::pair<uint8, uint8> sectionCombination{ charSection->VariationIndex, charSection->ColorIndex };
        if (addedSections[sectionKey].count(sectionCombination))
            continue;

        addedSections[sectionKey].insert(sectionCombination);
        _charSections.insert({ sectionKey, charSection });
    }

    for (FactionEntry const* faction : sFactionStore)
        if (faction->ParentFactionID)
            _factionTeam[faction->ParentFactionID].push_back(faction->ID);

    for (ParagonReputationEntry const* paragonReputation : sParagonReputationStore)
    {
        _paragonFaction[paragonReputation->FactionID] = paragonReputation;
        _paragonQuest[paragonReputation->QuestID] = paragonReputation;
    }

    for (TalentEntry const* talentInfo : sTalentStore)
        if (talentInfo->ClassID < MAX_CLASSES && talentInfo->TierID < MAX_TALENT_TIERS && talentInfo->ColumnIndex < MAX_TALENT_COLUMNS)
            _talentByPos[talentInfo->ClassID][talentInfo->TierID][talentInfo->ColumnIndex].push_back(talentInfo);

    for (PvpTalentEntry const* talentInfo : sPvpTalentStore)
        if (talentInfo->ClassID < MAX_CLASSES && talentInfo->TierID < MAX_TALENT_TIERS && talentInfo->ColumnIndex < MAX_TALENT_COLUMNS)
        {
            _pvpTalentByPos[talentInfo->ClassID][talentInfo->TierID][talentInfo->ColumnIndex].push_back(talentInfo);
            _pvpTalentBySpellID[talentInfo->SpellID] = talentInfo;
        }

    for (WMOAreaTableEntry const* wmoAreaTableEntry : sWMOAreaTableStore)
        _WMOAreaInfoByTripple.insert(std::make_pair(WMOAreaTableTripple(wmoAreaTableEntry->WmoID, wmoAreaTableEntry->NameSetID, wmoAreaTableEntry->WmoGroupID), wmoAreaTableEntry));

    for (PvpTalentUnlockEntry const* talentUnlock : sPvpTalentUnlockStore)
        _pvpTalentUnlock[talentUnlock->TierID][talentUnlock->ColumnIndex] = talentUnlock->HonorLevel;

    for (ArtifactAppearanceSetEntry const* entry : sArtifactAppearanceSetStore)
        _artifactAppearanceSetConteiner[entry->ArtifactID].push_back(entry);

    for (ArtifactAppearanceEntry const* entry : sArtifactAppearanceStore)
        _setToArtifactAppearanceContainer[entry->ArtifactAppearanceSetID].push_back(entry);

    for (ArtifactPowerLinkEntry const* artifactPowerLink : sArtifactPowerLinkStore)
    {
        _artifactPowerLinks[artifactPowerLink->PowerA].insert(artifactPowerLink->PowerB);
        _artifactPowerLinks[artifactPowerLink->PowerB].insert(artifactPowerLink->PowerA);
    }

    for (ArtifactPowerEntry const* entry : sArtifactPowerStore)
        _artifactPowerContainer[entry->ArtifactID].push_back(entry);

    for (ArtifactPowerRankEntry const* artifactPowerRank : sArtifactPowerRankStore)
        _artifactPowerRanks[std::pair<uint32, uint8>(artifactPowerRank->ArtifactPowerID, artifactPowerRank->RankIndex)] = artifactPowerRank;


    for (ItemChildEquipmentEntry const* itemChildEquipment : sItemChildEquipmentStore)
    {
        ASSERT(_itemChildEquipment.find(itemChildEquipment->ItemID) == _itemChildEquipment.end(), "Item must have max 1 child item.");
        _itemChildEquipment[itemChildEquipment->ItemID] = itemChildEquipment;
        _isChildItem[itemChildEquipment->ChildItemID] = true;
    }

    for (ItemClassEntry const* itemClass : sItemClassStore)
    {
        ASSERT(itemClass->OldEnumValue < _itemClassByOldEnum.size());
        ASSERT(!_itemClassByOldEnum[itemClass->OldEnumValue]);
        _itemClassByOldEnum[itemClass->OldEnumValue] = itemClass;
    }

    for (TransmogSetItemEntry const* transmogSetItem : sTransmogSetItemStore)
    {
        auto set = sTransmogSetStore.LookupEntry(transmogSetItem->TransmogSetID);
        if (!set)
            continue;

        _transmogSetsByItemModifiedAppearance[transmogSetItem->ItemModifiedAppearanceID].push_back(set);
        _transmogSetItemsByTransmogSet[transmogSetItem->TransmogSetID].push_back(transmogSetItem);
    }

    for (PowerTypeEntry const* entry : sPowerTypeStore)
        _powerTypeContainer[entry->PowerTypeEnum] = entry;

    for (SummonPropertiesEntry const* entry : sSummonPropertiesStore)
        if (entry->Slot > 127)
            const_cast<SummonPropertiesEntry*>(entry)->Slot -= 256;

    for (WorldMapAreaEntry const* entry : sWorldMapAreaStore)
    {
        _worldMapArea[entry->AreaID] = entry;
        if (entry->MapID >= 0 && entry->MapID < 2000) // Prevent -1
            _worldMapZone[entry->MapID].push_back(entry->AreaID);
    }

    for (PvpRewardEntry const* entry : sPvpRewardStore)
        _rewardPackByHonorLevel[std::make_pair(entry->HonorLevel, entry->PrestigeLevel)] = entry->RewardPackID;

    for (RewardPackXItemEntry const* entry : sRewardPackXItemStore)
        _rewardPackXItem[entry->RewardPackID] = entry;

    for (RewardPackXCurrencyTypeEntry const* entry : sRewardPackXCurrencyTypeStore)
         _rewardPackXCurrency[entry->RewardPackID] = entry;

    for (auto const& journalEntry : sJournalEncounterStore)
        _journalLootIDsByEncounterID[journalEntry->JournalInstanceID].emplace_back(journalEntry->ID);

    for (auto const& journalEncounterItemEntry : sJournalEncounterItemStore)
        _instanceLootItemIDsByEncounterID[journalEncounterItemEntry->JournalEncounterID].emplace_back(journalEncounterItemEntry->ItemID);

    for (ArtifactUnlockEntry const* entry : sArtifactUnlockStore)
        _artifactToUnlockContainer[entry->ArtifactID] = entry;

     for (WorldStateExpressionEntry const* entry : sWorldStateExpressionStore) // Need for convert WorldStateExpressionID -> WorldStateID
         entry->Eval(NULL);

    for (PhaseXPhaseGroupEntry const* group : sPhaseXPhaseGroupStore)
        if (PhaseEntry const* phase = sPhaseStore.LookupEntry(group->PhaseID))
            _phasesByGroup[group->PhaseGroupID].insert(phase->ID);

    _battlePetSpeciesContainer.resize(sBattlePetSpeciesStore.GetNumRows(), nullptr);
    for (auto const& bps : sBattlePetSpeciesStore)
    {
        _battlePetSpeciesContainer[bps->ID] = bps;
        _spellToSpeciesContainer[bps->SummonSpellID] = bps;

        if (bps->CreatureID >= _creatureToSpeciesContainer.size())
            _creatureToSpeciesContainer.resize(bps->CreatureID + 1, nullptr);
        _creatureToSpeciesContainer[bps->CreatureID] = bps;
    }

    for (GarrFollowerLevelXPEntry const* entry : sGarrFollowerLevelXPStore)
        _garrFollowerLevelXP[std::make_tuple(entry->FollowerLevel, entry->GarrFollowerTypeID)] = entry->XpToNextLevel;

    for (GarrFollowerQualityEntry const* entry : sGarrFollowerQualityStore)
        _garrFollowerQualityXP[std::make_tuple(entry->Quality, entry->GarrFollowerTypeID)] = entry->XpToNextQuality;

    for (CharShipmentEntry const* entry : sCharShipmentStore)
        _charShipmentConteiner.insert(std::make_pair(entry->ContainerID, entry));

    for (GarrBuildingEntry const* entry : sGarrBuildingStore)
        _buldingTypeConteiner.insert(std::make_pair(entry->BuildingType, entry));

    for (GarrTalentEntry const* entry : sGarrTalentStore)
        if (GarrTalentTreeEntry const* tree = sGarrTalentTreeStore.LookupEntry(entry->ID))
            _garClassMap[tree->ClassID][entry->Tier][entry->UiOrder] = entry;

    for (GarrMissionEntry const* entry : sGarrMissionStore)
        _garrMissionsMap[entry->GarrTypeID].push_back(entry);

    for (GarrAbilityEffectEntry const* entry : sGarrAbilityEffectStore)
        _garrAbilityEffectContainer[entry->GarrAbilityID].insert(entry);

    for (GarrMechanicSetXMechanicEntry const* entry : sGarrMechanicSetXMechanicStore)
        _xMechanic[entry->GarrMechanicSetId].insert(entry->GarrMechanicID);

    for (GarrEncounterSetXEncounterEntry const* entry : sGarrEncounterSetXEncounterStore)
        _xEncounter[entry->xEncounter].insert(entry->Encounter);

    for (LFGDungeonsEntry const* entry : sLfgDungeonsStore)
        _lfgdungeonsContainer[entry->MapID][entry->DifficultyID] = entry;

    for (auto const& entry : sLfgRoleRequirementStore)
        _LFGRoleRequirementCondition[std::make_pair(entry->LfgDungeonsId, entry->RoleType)] = entry->PlayerConditionID;

    for (SandboxScalingEntry const* entry : sSandboxScalingStore)
        _sandboxScalingContainer[entry->MaxLevel][entry->MinLevel] = entry->ID;

    

    for (MapEntry const* entry : sMapStore)
        _mapEntryContainer[entry->ID] = entry;
}

DB2StorageBase const* DB2Manager::GetStorage(uint32 type)
{
    return Trinity::Containers::MapGetValuePtr(_stores, type);
}

void DB2Manager::LoadingExtraHotfixData()
{
    DB2HotfixGenerator<AchievementEntry> achHotfixes(sAchievementStore);
    achHotfixes.ApplyHotfix(4539, [](AchievementEntry* achievement) // Once Bitten, Twice Shy (10 player) - Icecrown Citadel Correct map requirement (currently has Ulduar)
    {
        achievement->InstanceID = 631;
    });

    uint8 activeSeason = sWorld->getIntConfig(CONFIG_PVP_ACTIVE_SEASON);

    DB2HotfixGenerator<ItemSparseEntry> itemSparseHotfixes(sItemSparseStore);
    for (auto const& itr : sItemSparseStore)
    {
        if (sWorld->getBoolConfig(CONFIG_PVP_LEVEL_ENABLE) && activeSeason != 6 && activeSeason != 7)
        {
            if ((legionPvpItem[activeSeason][0] && itr->ItemNameDescriptionID == legionPvpItem[activeSeason][0]) || (legionPvpItem[activeSeason][1] && itr->ItemNameDescriptionID == legionPvpItem[activeSeason][1])) // Legion Season
            {
                itemSparseHotfixes.ApplyHotfix(itr->ID, [](ItemSparseEntry* entry)
                {
                    entry->Flags[2] |= ITEM_FLAG3_OBLITERATABLE;
                }, true);
            }
        }

        if (sWorld->getIntConfig(CONFIG_OBLITERUM_LEVEL_START))
        {
            switch(itr->ID)
            {
                case 123910:
                case 126995:
                case 127019:
                case 127020:
                case 127033:
                case 127034:
                case 128884:
                case 128900:
                case 123911:
                case 123912:
                case 123913:
                case 123914:
                case 123915:
                case 123916:
                case 123917:
                case 126996:
                case 126997:
                case 126998:
                case 126999:
                case 127000:
                case 127001:
                case 127002:
                case 127842:
                case 128705:
                case 128709:
                case 128710:
                case 128711:
                case 128885:
                case 128886:
                case 128887:
                case 128888:
                case 128889:
                case 128890:
                case 128891:
                case 128901:
                case 128902:
                case 128903:
                case 128904:
                case 128905:
                case 128906:
                case 128907:
                case 132504:
                case 132505:
                case 132506:
                case 132507:
                case 130229:
                case 130231:
                case 136713:
                case 130230:
                case 130244:
                case 130238:
                case 130239:
                case 130240:
                case 130233:
                case 130237:
                case 130242:
                case 130234:
                case 130236:
                case 130241:
                case 130235:
                case 130243:
                    itemSparseHotfixes.ApplyHotfix(itr->ID, [](ItemSparseEntry* entry)
                    {
                        entry->ItemLevel = sWorld->getIntConfig(CONFIG_OBLITERUM_LEVEL_START);
                    }, true);
                    break;
            }
        }
    }

    DB2HotfixGenerator<PlayerConditionEntry> playerConditionHotfixes(sPlayerConditionStore);
    for (auto const& itr : sPlayerConditionStore)
    {
        // Fix visual bug for unlock ArtifactAppearance
        if (itr->ID == 42299)
        {
            playerConditionHotfixes.ApplyHotfix(itr->ID, [](PlayerConditionEntry* entry)
            {
                entry->PrevQuestID[2] = 0;
                entry->PrevQuestLogic = 0;
            }, true);
        }
        if (itr->ID == 44176)
        {
            playerConditionHotfixes.ApplyHotfix(itr->ID, [](PlayerConditionEntry* entry)
            {
                entry->PrevQuestID[0] = 45910;
                entry->ModifierTreeID = 0;
            }, true);
        }
        if (itr->ID == 50389 || itr->ID == 44158 ||
            itr->ID == 50405 || itr->ID == 44692 ||
            itr->ID == 50408 || itr->ID == 44177 ||
            itr->ID == 50401 || itr->ID == 44688 ||
            itr->ID == 50397 || itr->ID == 44699)
        {
            playerConditionHotfixes.ApplyHotfix(itr->ID, [](PlayerConditionEntry* entry)
            {
                entry->PrevQuestID[0] = 45904;
                entry->ModifierTreeID = 0;
            }, true);
        }
        if (itr->ID == 44166 || itr->ID == 50382 ||
            itr->ID == 44176 || itr->ID == 50387 ||
            itr->ID == 44680 || itr->ID == 50391 ||
            itr->ID == 44697 || itr->ID == 50400 ||
            itr->ID == 44703 || itr->ID == 50407)
        {
            playerConditionHotfixes.ApplyHotfix(itr->ID, [](PlayerConditionEntry* entry)
            {
                entry->PrevQuestID[0] = 45910;
                entry->ModifierTreeID = 0;
            }, true);
        }
        if (itr->ID == 44540 || itr->ID == 50377 ||
            itr->ID == 44678 || itr->ID == 50381 ||
            itr->ID == 44682 || itr->ID == 50384 ||
            itr->ID == 44685 || itr->ID == 50392 ||
            itr->ID == 44695 || itr->ID == 50396 ||
            itr->ID == 44701 || itr->ID == 50412)
        {
            playerConditionHotfixes.ApplyHotfix(itr->ID, [](PlayerConditionEntry* entry)
            {
                entry->PrevQuestID[0] = 45905;
                entry->ModifierTreeID = 0;
            }, true);
        }
        if (itr->ID == 44683 || itr->ID == 50385 ||
            itr->ID == 44686 || itr->ID == 50393 ||
            itr->ID == 44694 || itr->ID == 50395 ||
            itr->ID == 44696 || itr->ID == 50399 ||
            itr->ID == 44698 || itr->ID == 50406)
        {
            playerConditionHotfixes.ApplyHotfix(itr->ID, [](PlayerConditionEntry* entry)
            {
                entry->PrevQuestID[0] = 45906;
                entry->ModifierTreeID = 0;
            }, true);
        }
        if (itr->ID == 44162 || itr->ID == 50379 ||
            itr->ID == 44542 || itr->ID == 50383 ||
            itr->ID == 44681 || itr->ID == 50390 ||
            itr->ID == 44689 || itr->ID == 50402 ||
            itr->ID == 44691 || itr->ID == 50404 ||
            itr->ID == 44693 || itr->ID == 50411)
        {
            playerConditionHotfixes.ApplyHotfix(itr->ID, [](PlayerConditionEntry* entry)
            {
                entry->PrevQuestID[0] = 45902;
                entry->ModifierTreeID = 0;
            }, true);
        }
        if (itr->ID == 44178 || itr->ID == 50386 ||
            itr->ID == 44684 || itr->ID == 50394 ||
            itr->ID == 44687 || itr->ID == 50398 ||
            itr->ID == 44702 || itr->ID == 50409)
        {
            playerConditionHotfixes.ApplyHotfix(itr->ID, [](PlayerConditionEntry* entry)
            {
                entry->PrevQuestID[0] = 45909;
                entry->ModifierTreeID = 0;
            }, true);
        }
        if (itr->ID == 44541 || itr->ID == 50378 ||
            itr->ID == 44679 || itr->ID == 50380 ||
            itr->ID == 44690 || itr->ID == 50388 ||
            itr->ID == 44700 || itr->ID == 50403 ||
            itr->ID == 44704 || itr->ID == 50410)
        {
            playerConditionHotfixes.ApplyHotfix(itr->ID, [](PlayerConditionEntry* entry)
            {
                entry->PrevQuestID[0] = 45908;
                entry->ModifierTreeID = 0;
            }, true);
        }
    }
}

void DB2Manager::LoadHotfixData()
{
    auto oldMSTime = getMSTime();

    LoadingExtraHotfixData();

    auto result = HotfixDatabase.Query("SELECT Id, TableHash, RecordId, Deleted FROM hotfix_data ORDER BY Id");
    if (!result)
    {
        TC_LOG_INFO(LOG_FILTER_SERVER_LOADING, ">> Loaded 0 hotfix info entries.");
        return;
    }

    uint32 count = 0;

    std::map<std::pair<uint32, int32>, bool> deletedRecords;

    do
    {
        auto fields = result->Fetch();
        auto id = fields[0].GetUInt32();
        auto tableHash = fields[1].GetUInt32();
        auto recordId = fields[2].GetInt32();
        auto deleted = fields[3].GetBool();
        if (_stores.find(tableHash) == _stores.end())
        {
            TC_LOG_INFO(LOG_FILTER_SQL, "Table `hotfix_data` references unknown DB2 store by hash 0x%X in hotfix id %d", tableHash, id);
            continue;
        }

        _maxHotfixId = std::max(_maxHotfixId, id);
        _hotfixData[MAKE_PAIR64(id, tableHash)] = recordId;
        deletedRecords[std::make_pair(tableHash, recordId)] = deleted;
        ++count;
    } while (result->NextRow());

    for (auto & deletedRecord : deletedRecords)
        if (deletedRecord.second)
            if (auto store = Trinity::Containers::MapGetValuePtr(_stores, deletedRecord.first.first))
                store->EraseRecord(deletedRecord.first.second);

    TC_LOG_INFO(LOG_FILTER_SERVER_LOADING, ">> Loaded %u hotfix records in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void DB2Manager::InsertNewHotfix(uint32 tableHash, uint32 recordId)
{
    _hotfixData[MAKE_PAIR64(++_maxHotfixId, tableHash)] = recordId;
}

std::map<uint64, int32> const& DB2Manager::GetHotfixData()
{
    return _hotfixData;
}

std::vector<uint32> DB2Manager::GetAreasForGroup(uint32 areaGroupId)
{
    auto itr = _areaGroupMembers.find(areaGroupId);
    if (itr != _areaGroupMembers.end())
        return itr->second;

    return {};
}

std::vector<uint32> DB2Manager::GetGroupsForArea(uint32 areaId)
{
    auto itr = _areaMemberGroups.find(areaId);
    if (itr != _areaMemberGroups.end())
        return itr->second;

    return {};
}

bool DB2Manager::IsInArea(uint32 objectAreaId, uint32 areaId)
{
    do
    {
        if (objectAreaId == areaId)
            return true;

        auto objectArea = sAreaTableStore.LookupEntry(objectAreaId);
        if (!objectArea)
            break;

        objectAreaId = objectArea->ParentAreaID;
    } while (objectAreaId);

    return false;
}

std::list<uint32> DB2Manager::GetGameObjectsList()
{
    return _gameObjectsList;
}

uint32 DB2Manager::GetRulesetItemUpgrade(uint32 itemId) const
{
    auto itr = _rulesetItemUpgrade.find(itemId);
    if (itr != _rulesetItemUpgrade.end())
        return itr->second;

    return 0;
}

enum class CurveInterpolationMode : uint8
{
    Linear = 0,
    Cosine = 1,
    CatmullRom = 2,
    Bezier3 = 3,
    Bezier4 = 4,
    Bezier = 5,
    Constant = 6,
};

static CurveInterpolationMode DetermineCurveType(CurveEntry const* curve, std::vector<CurvePointEntry const*> const& points)
{
    switch (curve->Type)
    {
        case 1:
            return points.size() < 4 ? CurveInterpolationMode::Cosine : CurveInterpolationMode::CatmullRom;
        case 2:
        {
            switch (points.size())
            {
                case 1:
                    return CurveInterpolationMode::Constant;
                case 2:
                    return CurveInterpolationMode::Linear;
                case 3:
                    return CurveInterpolationMode::Bezier3;
                case 4:
                    return CurveInterpolationMode::Bezier4;
                default:
                    break;
            }
            return CurveInterpolationMode::Bezier;
        }
        case 3:
            return CurveInterpolationMode::Cosine;
        default:
            break;
    }

    return points.size() != 1 ? CurveInterpolationMode::Linear : CurveInterpolationMode::Constant;
}

float DB2Manager::GetCurveValueAt(uint32 curveId, float x) const
{
    auto itr = _curvePoints.find(curveId);
    if (itr == _curvePoints.end())
        return 0.0f;

    CurveEntry const* curve = sCurveStore.AssertEntry(curveId);
    std::vector<CurvePointEntry const*> const& points = itr->second;
    if (points.empty())
        return 0.0f;

    switch (DetermineCurveType(curve, points))
    {
        case CurveInterpolationMode::Linear:
        {
            std::size_t pointIndex = 0;
            while (pointIndex < points.size() && points[pointIndex]->Pos.X <= x)
                ++pointIndex;

            if (!pointIndex)
                return points[0]->Pos.Y;

            if (pointIndex >= points.size())
                return points.back()->Pos.Y;

            float xDiff = points[pointIndex]->Pos.X - points[pointIndex - 1]->Pos.X;
            if (xDiff == 0.0)
                return points[pointIndex]->Pos.Y;

            return (((x - points[pointIndex - 1]->Pos.X) / xDiff) * (points[pointIndex]->Pos.Y - points[pointIndex - 1]->Pos.Y)) + points[pointIndex - 1]->Pos.Y;
        }
        case CurveInterpolationMode::Cosine:
        {
            std::size_t pointIndex = 0;
            while (pointIndex < points.size() && points[pointIndex]->Pos.X <= x)
                ++pointIndex;

            if (!pointIndex)
                return points[0]->Pos.Y;

            if (pointIndex >= points.size())
                return points.back()->Pos.Y;

            float xDiff = points[pointIndex]->Pos.X - points[pointIndex - 1]->Pos.X;
            if (xDiff == 0.0)
                return points[pointIndex]->Pos.Y;

            return ((points[pointIndex]->Pos.Y - points[pointIndex - 1]->Pos.Y) * (1.0f - std::cos((x - points[pointIndex - 1]->Pos.X) / xDiff * float(M_PI))) * 0.5f) + points[pointIndex - 1]->Pos.Y;
        }
        case CurveInterpolationMode::CatmullRom:
        {
            std::size_t pointIndex = 1;
            while (pointIndex < points.size() && points[pointIndex]->Pos.X <= x)
                ++pointIndex;

            if (pointIndex == 1)
                return points[1]->Pos.Y;

            if (pointIndex >= points.size() - 1)
                return points[points.size() - 2]->Pos.Y;

            float xDiff = points[pointIndex]->Pos.X - points[pointIndex - 1]->Pos.X;
            if (xDiff == 0.0)
                return points[pointIndex]->Pos.Y;

            float mu = (x - points[pointIndex - 1]->Pos.X) / xDiff;
            float a0 = -0.5f * points[pointIndex - 2]->Pos.Y + 1.5f * points[pointIndex - 1]->Pos.Y - 1.5f * points[pointIndex]->Pos.Y + 0.5f * points[pointIndex + 1]->Pos.Y;
            float a1 = points[pointIndex - 2]->Pos.Y - 2.5f * points[pointIndex - 1]->Pos.Y + 2.0f * points[pointIndex]->Pos.Y - 0.5f * points[pointIndex + 1]->Pos.Y;
            float a2 = -0.5f * points[pointIndex - 2]->Pos.Y + 0.5f * points[pointIndex]->Pos.Y;
            float a3 = points[pointIndex - 1]->Pos.Y;

            return a0 * mu * mu * mu + a1 * mu * mu + a2 * mu + a3;
        }
        case CurveInterpolationMode::Bezier3:
        {
            float xDiff = points[2]->Pos.X - points[0]->Pos.X;
            if (xDiff == 0.0)
                return points[1]->Pos.Y;

            float mu = (x - points[0]->Pos.X) / xDiff;
            return ((1.0f - mu) * (1.0f - mu) * points[0]->Pos.Y) + (1.0f - mu) * 2.0f * mu * points[1]->Pos.Y + mu * mu * points[2]->Pos.Y;
        }
        case CurveInterpolationMode::Bezier4:
        {
            float xDiff = points[3]->Pos.X - points[0]->Pos.X;
            if (xDiff == 0.0)
                return points[1]->Pos.Y;

            float mu = (x - points[0]->Pos.X) / xDiff;
            return (1.0f - mu) * (1.0f - mu) * (1.0f - mu) * points[0]->Pos.Y + 3.0f * mu * (1.0f - mu) * (1.0f - mu) * points[1]->Pos.Y + 3.0f * mu * mu * (1.0f - mu) * points[2]->Pos.Y + mu * mu * mu * points[3]->Pos.Y;
        }
        case CurveInterpolationMode::Bezier:
        {
            float xDiff = points.back()->Pos.X - points[0]->Pos.X;
            if (xDiff == 0.0f)
                return points.back()->Pos.Y;

            std::vector<float> tmp(points.size());
            for (std::size_t i = 0; i < points.size(); ++i)
                tmp[i] = points[i]->Pos.Y;

            float mu = (x - points[0]->Pos.X) / xDiff;
            int32 i = int32(points.size()) - 1;
            int32 k = 0;
            while (i > 0)
            {
                for (k = 0; k < i; ++k)
                    tmp[k] = tmp[k] + mu * (tmp[k + 1] - tmp[k]);

                --i;
            }
            return tmp[0];
        }
        case CurveInterpolationMode::Constant:
            return points[0]->Pos.Y;
        default:
            break;
    }

    return 0.0f;
}

uint32 DB2Manager::GetItemDisplayId(uint32 itemId, uint32 appearanceModId) const
{
    if (ItemModifiedAppearanceEntry const* modifiedAppearance = GetItemModifiedAppearance(itemId, appearanceModId))
        if (ItemAppearanceEntry const* itemAppearance = sItemAppearanceStore.LookupEntry(modifiedAppearance->ItemAppearanceID))
            return itemAppearance->ItemDisplayInfoID;

    return 0;
}

uint32 DB2Manager::GetItemDIconFileDataId(uint32 itemId, uint32 appearanceModId) const
{
    if (auto modifiedAppearance = GetItemModifiedAppearance(itemId, appearanceModId))
        if (auto itemAppearance = sItemAppearanceStore.LookupEntry(modifiedAppearance->ItemAppearanceID))
            return itemAppearance->DefaultIconFileDataID;

    return 0;
}

std::vector<ItemLimitCategoryConditionEntry const*> const* DB2Manager::GetItemLimitCategoryConditions(uint32 categoryId) const
{
    return Trinity::Containers::MapGetValuePtr(_itemCategoryConditions, categoryId);
}

ItemModifiedAppearanceEntry const* DB2Manager::GetItemModifiedAppearance(uint32 itemId, uint32 appearanceModId) const
{
    if (_itemModifiedAppearancesByItem.size() <= itemId || _itemModifiedAppearancesByItem[itemId].empty())
        return nullptr;

    if (appearanceModId)
    {
        if (_itemModifiedAppearancesByItem[itemId].size() > appearanceModId)
            if (_itemModifiedAppearancesByItem[itemId][appearanceModId])
                return _itemModifiedAppearancesByItem[itemId][appearanceModId];
    }

    // Fall back to unmodified appearance
    return _itemModifiedAppearancesByItem[itemId][0];
}

ItemModifiedAppearanceEntry const* DB2Manager::GetDefaultItemModifiedAppearance(uint32 itemId) const
{
    if (_itemModifiedAppearancesByItem.size() <= itemId || _itemModifiedAppearancesByItem[itemId].empty())
        return nullptr;

    return _itemModifiedAppearancesByItem[itemId][0];
}

uint32 DB2Manager::GetTransmogId(uint32 itemId, uint8 appearanceModId) const
{
    if (!itemId)
        return 0;

    if (auto modifiedAppearance = GetItemModifiedAppearance(itemId, appearanceModId))
        return modifiedAppearance->ID;

    return 0;
}

std::vector<uint32> DB2Manager::GetAllTransmogsByItemId(uint32 itemId) const
{
    if (!itemId)
        return {};

    auto itr = _itemToTransmogByItem.find(itemId);
    if (itr != _itemToTransmogByItem.end())
        return itr->second;

    return {};
}

DB2Manager::ItemBonusList const* DB2Manager::GetItemBonusList(uint32 bonusListId) const
{
    return Trinity::Containers::MapGetValuePtr(_itemBonusLists, bonusListId);
}

uint32 DB2Manager::GetItemBonusListForItemLevelDelta(int16 delta) const
{
    auto itr = _itemLevelDeltaToBonusListContainer.find(delta);
    if (itr != _itemLevelDeltaToBonusListContainer.end())
        return itr->second;

    return 0;
}

DB2Manager::LanguageWordsContainer const* DB2Manager::GetLanguageWordMap(uint32 langID)
{
    return Trinity::Containers::MapGetValuePtr(_languageWordsMap, langID);
}

StringVector const* DB2Manager::GetLanguageWordsBySize(uint32 langID, uint32 size)
{
    if (auto wordMap = GetLanguageWordMap(langID))
        return Trinity::Containers::MapGetValuePtr(*wordMap, size);

    return nullptr;
}

std::vector<QuestPackageItemEntry const*> const* DB2Manager::GetQuestPackageItems(uint32 questPackageID) const
{
    return Trinity::Containers::MapGetValuePtr(_questPackages, questPackageID);
}

MountEntry const* DB2Manager::GetMount(uint32 spellId) const
{
    return Trinity::Containers::MapGetValuePtr(_mountsBySpellId, spellId);
}

MountEntry const* DB2Manager::GetMountById(uint32 id)
{
    return sMountStore.LookupEntry(id);
}

std::vector<uint32> DB2Manager::GetItemBonusTree(uint32 itemId, uint32 itemBonusTreeMod, uint32& itemLevel) const
{
    std::vector<uint32> bonusListIDs;

    auto const* proto = sItemSparseStore.LookupEntry(itemId);
    if (!proto)
        return bonusListIDs;

    auto itemIdRange = _itemToBonusTree.equal_range(itemId);
    if (itemIdRange.first == itemIdRange.second)
        return bonusListIDs;

    for (auto itemTreeItr = itemIdRange.first; itemTreeItr != itemIdRange.second; ++itemTreeItr)
    {
        auto treeItr = _itemBonusTrees.find(itemTreeItr->second);
        if (treeItr == _itemBonusTrees.end())
            continue;

        for (auto bonusTreeNode : treeItr->second)
        {
            if (bonusTreeNode->ItemContext != itemBonusTreeMod)
                continue;

            if (bonusTreeNode->ChildItemBonusListID)
                bonusListIDs.emplace_back(bonusTreeNode->ChildItemBonusListID);
            else if (bonusTreeNode->ChildItemLevelSelectorID)
            {
                auto selector = sItemLevelSelectorStore.LookupEntry(bonusTreeNode->ChildItemLevelSelectorID);
                if (!selector)
                    continue;

                itemLevel = selector->MinItemLevel;

                int16 delta = int16(selector->MinItemLevel) - proto->ItemLevel;

                if (auto bonus = GetItemBonusListForItemLevelDelta(delta))
                    bonusListIDs.emplace_back(bonus);

                if (auto selectorQualitySet = sItemLevelSelectorQualitySetStore.LookupEntry(selector->ItemLevelSelectorQualitySetID))
                {
                    auto itemSelectorQualities = _itemLevelQualitySelectorQualities.find(selector->ItemLevelSelectorQualitySetID);
                    if (itemSelectorQualities != _itemLevelQualitySelectorQualities.end())
                    {
                        auto quality = ITEM_QUALITY_UNCOMMON;
                        if (selector->MinItemLevel >= selectorQualitySet->IlvlEpic)
                            quality = ITEM_QUALITY_EPIC;
                        else if (selector->MinItemLevel >= selectorQualitySet->IlvlRare)
                            quality = ITEM_QUALITY_RARE;

                        auto itemSelectorQuality = std::lower_bound(itemSelectorQualities->second.begin(), itemSelectorQualities->second.end(), quality, ItemLevelSelectorQualityEntryComparator{});
                        if (itemSelectorQuality != itemSelectorQualities->second.end())
                            bonusListIDs.emplace_back((*itemSelectorQuality)->QualityItemBonusListID);
                    }
                }
            }
        }
    }

    return bonusListIDs;
}

bool ItemLevelSelectorQualityEntryComparator::Compare(ItemLevelSelectorQualityEntry const* left, ItemLevelSelectorQualityEntry const* right)
{
    return left->Quality > right->Quality;
}

std::set<uint32> const* DB2Manager::GetItemsByBonusTree(uint32 itemBonusTreeMod) const
{
    return Trinity::Containers::MapGetValuePtr(_bonusToItemTree, itemBonusTreeMod);
}

std::set<ItemBonusTreeNodeEntry const*> const* DB2Manager::GetItemBonusSet(uint32 itemBonusTree) const
{
    return Trinity::Containers::MapGetValuePtr(_itemBonusTrees, itemBonusTree);
}

HeirloomEntry const* DB2Manager::GetHeirloomByItemId(uint32 itemId) const
{
    return Trinity::Containers::MapGetValuePtr(_heirlooms, itemId);
}

HeirloomEntry const* DB2Manager::FindHeirloom(uint32 itemId) const
{
    for (auto heirloom : _heirlooms)
        if (heirloom.first == itemId
            || heirloom.second->LegacyItemID == itemId
            || heirloom.second->LegacyUpgradedItemID == itemId
            || heirloom.second->UpgradeItemID[0] == itemId
            || heirloom.second->UpgradeItemID[1] == itemId
            || heirloom.second->UpgradeItemID[2] == itemId 
            || heirloom.second->UpgradeItemID[3] == itemId)
            return heirloom.second;

    return nullptr;
}

bool DB2Manager::IsToyItem(uint32 toy) const
{
    return _toys.count(toy) > 0;
}

ResearchPOIPoint::ResearchPOIPoint() : x(0), y(0)
{
}

ResearchPOIPoint::ResearchPOIPoint(int32 _x, int32 _y) : x(_x), y(_y)
{
}

DigSitePosition::DigSitePosition() : x(0.0f), y(0.0f)
{
}

DigSitePosition::DigSitePosition(float _x, float _y) : x(_x), y(_y)
{
}

ResearchSiteData::ResearchSiteData() : entry(nullptr), find_id{ 0 }, zone(0), branch_id(0), level(0xFF)
{
}

SpellEffect::SpellEffect()
{
    for (auto & effect : effects)
        effect = nullptr;
}

WMOAreaTableTripple::WMOAreaTableTripple(int32 r, int32 a, int32 g) : groupId(g), rootId(r), adtId(a)
{
}

bool WMOAreaTableTripple::operator<(const WMOAreaTableTripple& b) const
{
    return memcmp(this, &b, sizeof(WMOAreaTableTripple)) < 0;
}

bool DB2Manager::MountTypeXCapabilityEntryComparator::Compare(MountTypeXCapabilityEntry const* left, MountTypeXCapabilityEntry const* right)
{
    if (left->MountTypeID == right->MountTypeID)
        return left->OrderIndex < right->OrderIndex;

    return left->ID < right->ID;
}

DB2Manager::MountTypeXCapabilitySet const* DB2Manager::GetMountCapabilities(uint32 mountType) const
{
    return Trinity::Containers::MapGetValuePtr(_mountCapabilitiesByType, mountType);
}

uint32 DB2Manager::GetXPForNextFollowerLevel(uint32 level, uint8 followerTypeID)
{
    auto const& it = _garrFollowerLevelXP.find(std::make_tuple(level, followerTypeID));
    if (it != _garrFollowerLevelXP.end())
        return it->second;

    return 0;
}

uint32 DB2Manager::GetXPForNextFollowerQuality(uint32 quality, uint8 followerTypeID)
{
    auto const& it = _garrFollowerQualityXP.find(std::make_tuple(quality, followerTypeID));
    if (it != _garrFollowerQualityXP.end())
        return it->second;

    return 0;
}

uint8 DB2Manager::GetNextFollowerQuality(uint32 quality, uint8 followerTypeID)
{
    uint8 currentOrderID = 0;
    for (auto entry : sGarrFollowerQualityStore)
    {
        if (entry->GarrFollowerTypeID != followerTypeID)
            continue;

        if (entry->Quality != quality)
            continue;

        currentOrderID = entry->TraitCount;
    }

    for (auto entry : sGarrFollowerQualityStore)
    {
        if (entry->GarrFollowerTypeID != followerTypeID)
            continue;

        if (entry->Quality != quality)
            continue;

        if (entry->TraitCount > currentOrderID)
            continue;

        return entry->Quality;
    }

    return 0;
}

char const* DB2Manager::GetBroadcastTextValue(BroadcastTextEntry const* broadcastText, LocaleConstant locale /*= DEFAULT_LOCALE*/, uint8 gender /*= GENDER_MALE*/, bool forceGender /*= false*/)
{
    if (gender == GENDER_FEMALE && (forceGender || broadcastText->Text1->Str[DEFAULT_LOCALE][0] != '\0'))
    {
        if (broadcastText->Text1->Str[locale][0] != '\0')
            return broadcastText->Text1->Str[locale];

        return broadcastText->Text1->Str[DEFAULT_LOCALE];
    }

    if (broadcastText->Text->Str[locale][0] != '\0')
        return broadcastText->Text->Str[locale];

    return broadcastText->Text->Str[DEFAULT_LOCALE];
}

AchievementEntry const* DB2Manager::GetsAchievementByTreeList(uint32 criteriaTree)
{
    return Trinity::Containers::MapGetValuePtr(_achievementParentList, criteriaTree);
}

std::array<std::vector<uint32>, 2> DB2Manager::GetItemLoadOutItemsByClassID(uint32 classID, uint8 type /*= 0*/)
{
    std::array<std::vector<uint32>, 2> _array;

    auto itr = _characterLoadout.find(classID);
    if (itr == _characterLoadout.end())
        return _array;

    for (auto const& v : itr->second)
        if (v.second == type)
        {
            auto itr2 = _characterLoadoutItem.find(v.first);
            if (itr2 != _characterLoadoutItem.end())
                for (uint32 item : itr2->second)
                    _array[0].emplace_back(item);
        }

    return _array;
}

std::vector<uint32> DB2Manager::GetLowestIdItemLoadOutItemsBy(uint32 classID, uint8 type)
{
    auto itr = _characterLoadout.find(classID);
    if (itr == _characterLoadout.end())
        return std::vector<uint32>();

    uint32 smallest = std::numeric_limits<uint32>::max();
    for (auto const& v : itr->second)
        if (v.second == type)
            if (v.first < smallest)
                smallest = v.first;

    return _characterLoadoutItem.count(smallest) ? _characterLoadoutItem[smallest] : std::vector<uint32>();
}

std::vector<CriteriaTreeEntry const*> const* DB2Manager::GetCriteriaTreeList(uint32 parent)
{
    return Trinity::Containers::MapGetValuePtr(_criteriaTree, parent);
}

std::vector<ModifierTreeEntry const*> const* DB2Manager::GetModifierTreeList(uint32 parent)
{
    return Trinity::Containers::MapGetValuePtr(_modifierTree, parent);
}

std::string DB2Manager::GetNameGenEntry(uint8 race, uint8 gender) const
{
    ASSERT(gender < GENDER_NONE);
    auto ritr = _nameGenData.find(race);
    if (ritr == _nameGenData.end())
        return "";

    if (ritr->second[gender].empty())
        return "";

    return Trinity::Containers::SelectRandomContainerElement(ritr->second[gender])->Name;
}

ResponseCodes DB2Manager::ValidateName(std::wstring const& name, LocaleConstant locale) const
{
    for (boost::wregex const& regex : _nameValidators[locale])
        if (boost::regex_search(name, regex))
            return CHAR_NAME_PROFANE;

    for (boost::wregex const& regex : _nameValidators[MAX_LOCALES])
        if (boost::regex_search(name, regex))
            return CHAR_NAME_RESERVED;

    return CHAR_NAME_SUCCESS;
}

uint32 DB2Manager::GetQuestUniqueBitFlag(uint32 questID)
{
    if (QuestV2Entry const* v2 = sQuestV2Store.LookupEntry(questID))
        return v2->UniqueBitFlag;

    return 0;
}

ResearchSiteEntry const* DB2Manager::GetResearchSiteEntryById(uint32 id)
{
    ResearchSiteDataMap::const_iterator itr = _researchSiteDataMap.find(id);
    if (itr != _researchSiteDataMap.end())
        return itr->second.entry;

    return nullptr;
}

void DB2Manager::DeterminaAlternateMapPosition(uint32 mapId, float x, float y, float z, uint32* newMapId /*= nullptr*/, DBCPosition2D* newPos /*= nullptr*/)
{
    ASSERT(newMapId || newPos);
    WorldMapTransformsEntry const* transformation = nullptr;
    for (WorldMapTransformsEntry const* transform : sWorldMapTransformsStore)
    {
        if (transform->MapID != mapId)
            continue;

        if (transform->RegionMin.X > x || transform->RegionMax.X < x)
            continue;
        if (transform->RegionMin.Y > y || transform->RegionMax.Y < y)
            continue;
        if (transform->RegionMin.Z > z || transform->RegionMax.Z < z)
            continue;

        transformation = transform;
        break;
    }

    if (!transformation)
    {
        if (newMapId)
            *newMapId = mapId;

        if (newPos)
        {
            newPos->X = x;
            newPos->Y = y;
        }
        return;
    }

    if (newMapId)
        *newMapId = transformation->NewMapID;

    if (!newPos)
        return;

    if (transformation->RegionScale > 0.0f && transformation->RegionScale < 1.0f)
    {
        x = (x - transformation->RegionMin.X) * transformation->RegionScale + transformation->RegionMin.X;
        y = (y - transformation->RegionMin.Y) * transformation->RegionScale + transformation->RegionMin.Y;
    }

    newPos->X = x + transformation->RegionOffset.X;
    newPos->Y = y + transformation->RegionOffset.Y;
}

bool DB2Manager::IsTotemCategoryCompatiableWith(uint32 itemTotemCategoryId, uint32 requiredTotemCategoryId)
{
    if (!requiredTotemCategoryId)
        return true;

    if (!itemTotemCategoryId)
        return false;

    TotemCategoryEntry const* itemEntry = sTotemCategoryStore.LookupEntry(itemTotemCategoryId);
    if (!itemEntry)
        return false;

    TotemCategoryEntry const* reqEntry = sTotemCategoryStore.LookupEntry(requiredTotemCategoryId);
    if (!reqEntry)
        return false;

    if (itemEntry->TotemCategoryType != reqEntry->TotemCategoryType)
        return false;

    return (itemEntry->TotemCategoryMask & reqEntry->TotemCategoryMask) == reqEntry->TotemCategoryMask;
}

SkillRaceClassInfoEntry const* DB2Manager::GetSkillRaceClassInfo(uint32 skill, uint8 race, uint8 class_)
{
    auto bounds = _skillRaceClassInfoBySkill.equal_range(skill);
    for (auto itr = bounds.first; itr != bounds.second; ++itr)
    {
        if (itr->second->RaceMask && !(itr->second->RaceMask & (UI64LIT(1) << (race - 1))))
            continue;
        if (itr->second->ClassMask && !(itr->second->ClassMask & (1 << (class_ - 1))))
            continue;

        return itr->second;
    }

    return nullptr;
}

std::vector<SpecializationSpellsEntry const*> const* DB2Manager::GetSpecializationSpells(uint32 specId)
{
    return Trinity::Containers::MapGetValuePtr(_specializationSpellsBySpec, specId);
}

std::vector<SpellProcsPerMinuteModEntry const*> DB2Manager::GetSpellProcsPerMinuteMods(uint32 spellprocsPerMinuteId) const
{
    auto itr = _spellProcsPerMinuteMods.find(spellprocsPerMinuteId);
    if (itr != _spellProcsPerMinuteMods.end())
        return itr->second;

    return {};
}

SpellTargetRestrictionsEntry const* DB2Manager::GetSpellTargetRestrioctions(uint32 spellId, uint16 difficulty)
{
    SpellRestrictionDiffContainer::const_iterator itr = _spellRestrictionDiff.find(spellId);
    if (itr != _spellRestrictionDiff.end())
        for (auto const& v : itr->second)
        {
            if (v->DifficultyID != difficulty && difficulty == DIFFICULTY_MYTHIC_KEYSTONE)
                difficulty = DIFFICULTY_MYTHIC_DUNGEON;

            if (v->DifficultyID == difficulty)
                return v;
        }
    return nullptr;
}

uint32 DB2Manager::GetLearnSpell(uint32 trigerSpell)
{
    RevertLearnSpellContainer::const_iterator itr = _revertLearnSpell.find(trigerSpell);
    if (itr != _revertLearnSpell.end())
        return itr->second;

    return 0;
}

uint32 DB2Manager::GetSpellByTrigger(uint32 trigerSpell)
{
    ReversTriggerSpellContainer::const_iterator itr = _reversTriggerSpellList.find(trigerSpell);
    if (itr != _reversTriggerSpellList.end())
        return itr->second;

    return 0;
}

SpellEffectEntry const* DB2Manager::GetSpellEffectEntry(uint32 spellId, uint32 effect, uint8 difficulty)
{
    if (difficulty)
    {
        SpellEffectsMap const* effects = &_spellEffectDiff[spellId].effects;
        auto itrsecond = effects->find(MAKE_PAIR16(effect, difficulty));
        if (itrsecond != effects->end())
            return itrsecond->second;
    }
    else
        return _spellEffectMap[spellId].effects[effect];

    return nullptr;
}

std::set<uint32> const* DB2Manager::GetSpellCategory(uint32 category)
{
    return Trinity::Containers::MapGetValuePtr(_spellCategory, category);
}

std::vector<ItemSpecOverrideEntry const*> const* DB2Manager::GetItemSpecOverrides(uint32 itemId) const
{
    return Trinity::Containers::MapGetValuePtr(_itemSpecOverrides, itemId);
}

PVPDifficultyEntry const* DB2Manager::GetBattlegroundBracketByLevel(uint32 mapID, uint32 level)
{
    PVPDifficultyEntry const* maxEntry = nullptr;
    for (PVPDifficultyEntry const* entry : sPvpDifficultyStore)
    {
        if (entry->MapID != mapID || entry->MinLevel > level)
            continue;

        if (entry->MaxLevel >= level)
            return entry;

        if (!maxEntry || maxEntry->MaxLevel < entry->MaxLevel)
            maxEntry = entry;
    }

    return maxEntry;
}

PVPDifficultyEntry const* DB2Manager::GetBattlegroundBracketById(uint32 mapID, uint8 id)
{
    for (PVPDifficultyEntry const* entry : sPvpDifficultyStore)
        if (entry->MapID == mapID && entry->RangeIndex == id)
            return entry;

    return nullptr;
}

ChrSpecializationEntry const* DB2Manager::GetChrSpecializationByIndex(uint8 classID, uint32 index)
{
    return _chrSpecializationByIndex[classID][index];
}

ChrSpecializationEntry const* DB2Manager::GetDefaultChrSpecializationForClass(uint32 class_) const
{
    return Trinity::Containers::MapGetValuePtr(_defaultChrSpecializationsByClass, class_);
}

DB2Manager::PetFamilySpellsSet const* DB2Manager::GetPetFamilySpells(uint32 family)
{
    return Trinity::Containers::MapGetValuePtr(_petFamilySpells, family);
}

bool ChrClassesXPowerTypesEntryComparator::Compare(ChrClassesXPowerTypesEntry const* left, ChrClassesXPowerTypesEntry const* right)
{
    if (left->ClassID != right->ClassID)
        return left->ClassID < right->ClassID;

    return left->PowerType < right->PowerType;
}

uint32 DB2Manager::GetPowerIndexByClass(uint32 powerType, uint32 classId) const
{
    return _powersByClass[classId][powerType];
}

AreaTableEntry const* DB2Manager::FindAreaEntry(uint32 area)
{
    return Trinity::Containers::MapGetValuePtr(_areaEntry, area);
}

uint32 DB2Manager::GetParentZoneOrSelf(uint32 zone)
{
    AreaTableEntry const* area = FindAreaEntry(zone);
    if (!area)
        return zone;

    return area->ParentAreaID ? area->ParentAreaID : zone;
}

char const* DB2Manager::GetPetName(uint32 petfamily, LocaleConstant localeConstant)
{
    if (!petfamily)
        return nullptr;

    if (auto petFamily = sCreatureFamilyStore.LookupEntry(petfamily))
        return petFamily->Name->Str[localeConstant][0] != '\0' ? petFamily->Name->Str[localeConstant] : nullptr;
    return nullptr;
}

DungeonEncounterEntry const* DB2Manager::GetDungeonEncounterByDisplayID(uint32 displayID)
{
    return Trinity::Containers::MapGetValuePtr(_dungeonEncounterByDisplayID, displayID);
}

MapDifficultyEntry const* DB2Manager::GetDownscaledMapDifficultyData(uint32 mapId, Difficulty &difficulty)
{
    DifficultyEntry const* diffEntry = sDifficultyStore.LookupEntry(difficulty);
    if (!diffEntry)
        return GetDefaultMapDifficulty(mapId);

    uint32 tmpDiff = difficulty;
    MapDifficultyEntry const* mapDiff = GetMapDifficultyData(mapId, Difficulty(tmpDiff));
    while (!mapDiff)
    {
        tmpDiff = diffEntry->FallbackDifficultyID;
        diffEntry = sDifficultyStore.LookupEntry(tmpDiff);
        if (!diffEntry)
            return GetDefaultMapDifficulty(mapId);

        mapDiff = GetMapDifficultyData(mapId, Difficulty(tmpDiff)); // we are 10 normal or 25 normal
    }

    difficulty = Difficulty(tmpDiff);
    return mapDiff;
}

MapDifficultyEntry const* DB2Manager::GetDefaultMapDifficulty(uint32 mapID)
{
    auto itr = _mapDifficulty.find(mapID);
    if (itr == _mapDifficulty.end())
        return nullptr;

    if (itr->second.empty())
        return nullptr;

    for (auto& p : itr->second)
    {
        DifficultyEntry const* difficulty = sDifficultyStore.LookupEntry(p.first);
        if (!difficulty)
            continue;

        if (difficulty->ID == DIFFICULTY_40)
            return p.second;

        if (difficulty->Flags & DIFFICULTY_FLAG_DEFAULT)
            return p.second;
    }

    return itr->second.begin()->second;
}

MapDifficultyEntry const* DB2Manager::GetMapDifficultyData(uint32 mapId, Difficulty difficulty)
{
    auto itr = _mapDifficulty.find(mapId);
    if (itr == _mapDifficulty.end())
        return nullptr;

    return Trinity::Containers::MapGetValuePtr(itr->second, difficulty);
}

DB2Manager::MapDifficultyContainer DB2Manager::GetAllMapsDifficultyes()
{
    return _mapDifficulty;
}

uint32 DB2Manager::GetPlayerConditionForMapDifficulty(uint32 difficultyID)
{
    auto itr = _mapDifficultyCondition.find(difficultyID);
    if (itr != _mapDifficultyCondition.end())
        return itr->second;
    return 0;
}

uint32 DB2Manager::GetSpellMisc(uint32 spellID)
{
    auto data = _spellMiscBySpellIDContainer.find(spellID);
    if (data != _spellMiscBySpellIDContainer.end())
        return data->second;
    return 0;
}

std::vector<QuestLineXQuestEntry const*> const* DB2Manager::GetQuestsByQuestLine(uint32 lineID) const
{
    return Trinity::Containers::MapGetValuePtr(_questsByQuestLine, lineID);
}

bool DB2Manager::HasCharacterFacialHairStyle(uint8 race, uint8 gender, uint8 variationId) const
{
    return _characterFacialHairStyles.find(std::make_tuple(race, gender, variationId)) != _characterFacialHairStyles.end();
}

bool DB2Manager::HasCharSections(uint8 race, uint8 gender, CharBaseSectionVariation variation) const
{
    auto range = Trinity::Containers::MapEqualRange(_charSections, std::make_tuple(race, gender, variation));
    return range.begin() != range.end();
}

CharSectionsEntry const* DB2Manager::GetCharSectionEntry(uint8 race, uint8 gender, CharBaseSectionVariation variation, uint8 variationIndex, uint8 colorIndex) const
{
    for (auto const& section : Trinity::Containers::MapEqualRange(_charSections, std::make_tuple(race, gender, variation)))
        if (section.second->VariationIndex == variationIndex && section.second->ColorIndex == colorIndex)
            return section.second;

    return nullptr;
}

DB2Manager::SimpleFactionsList const* DB2Manager::GetFactionTeamList(uint32 faction)
{
    return Trinity::Containers::MapGetValuePtr(_factionTeam, faction);
}

ParagonReputationEntry const* DB2Manager::GetFactionParagon(uint32 factionID)
{
    return Trinity::Containers::MapGetValuePtr(_paragonFaction, factionID);
}

ParagonReputationEntry const* DB2Manager::GetQuestParagon(uint32 questID)
{
    return Trinity::Containers::MapGetValuePtr(_paragonQuest, questID);
}

WMOAreaTableEntry const* DB2Manager::GetWMOAreaTableEntryByTripple(int32 rootid, int32 adtid, int32 groupid)
{
    return Trinity::Containers::MapGetValuePtr(_WMOAreaInfoByTripple, WMOAreaTableTripple(rootid, adtid, groupid));
}

uint32 DB2Manager::GetLiquidFlags(uint32 liquidType)
{
    if (LiquidTypeEntry const* liq = sLiquidTypeStore.LookupEntry(liquidType))
        return 1 << liq->SoundBank;

    return 0;
}

uint32 DB2Manager::GetDefaultMapLight(uint32 mapID)
{
    for (LightEntry const* light : sLightStore)
        if (light->ContinentID == mapID && light->GameCoords.X == 0.0f && light->GameCoords.Y == 0.0f && light->GameCoords.Z == 0.0f)
            return light->ID;

    return 0;
}

uint32 DB2Manager::GetRequiredHonorLevelForPvpTalent(PvpTalentEntry const* talentInfo) const
{
    ASSERT(talentInfo);
    return _pvpTalentUnlock[talentInfo->TierID][talentInfo->ColumnIndex];
}

PvpTalentEntry const* DB2Manager::GetPvpTalentBySpellID(uint32 spellID)
{
    return Trinity::Containers::MapGetValuePtr(_pvpTalentBySpellID, spellID);
}

DB2Manager::ShipmentConteinerMapBounds DB2Manager::GetShipmentConteinerBounds(uint32 conteinerID) const
{
    return _charShipmentConteiner.equal_range(conteinerID);
}

DB2Manager::GarrTalentLineMap const*  DB2Manager::GetGarrTalentLine(uint16 __class)
{
    return Trinity::Containers::MapGetValuePtr(_garClassMap, __class);
}

DB2Manager::GarrTalentOptionMap const* DB2Manager::GetGarrTalentOptionMap(uint16 __class, uint16 __line)
{
    if (auto data = GetGarrTalentLine(__class))
        return Trinity::Containers::MapGetValuePtr(*data, __line);
    return nullptr;
}

std::vector<ArtifactAppearanceSetEntry const*> const* DB2Manager::GetArtifactAppearance(uint32 ArtifactID) const
{
    return Trinity::Containers::MapGetValuePtr(_artifactAppearanceSetConteiner, ArtifactID);
}

std::vector<ArtifactAppearanceEntry const*> const* DB2Manager::GetArtifactAppearanceBySet(uint32 AppearanceSetID) const
{
    return Trinity::Containers::MapGetValuePtr(_setToArtifactAppearanceContainer, AppearanceSetID);
}

std::unordered_set<uint32> const* DB2Manager::GetArtifactPowerLinks(uint32 artifactPowerId) const
{
    return Trinity::Containers::MapGetValuePtr(_artifactPowerLinks, artifactPowerId);
}

std::vector<ArtifactPowerEntry const*> DB2Manager::GetArtifactPowers(uint8 artifactId) const
{
    auto itr = _artifactPowerContainer.find(artifactId);
    if (itr != _artifactPowerContainer.end())
        return itr->second;

    return std::vector<ArtifactPowerEntry const*>{};
}

ArtifactPowerRankEntry const* DB2Manager::GetArtifactPowerRank(uint32 artifactPowerId, uint8 rank) const
{
    return Trinity::Containers::MapGetValuePtr(_artifactPowerRanks, { artifactPowerId, rank });
}

ItemChildEquipmentEntry const* DB2Manager::GetItemChildEquipment(uint32 itemId) const
{
    return Trinity::Containers::MapGetValuePtr(_itemChildEquipment, itemId);
}

bool DB2Manager::IsChildItem(uint32 itemId) const
{
    return Trinity::Containers::MapGetValuePtr(_isChildItem, itemId);
}

ItemClassEntry const* DB2Manager::GetItemClassByOldEnum(uint32 itemClass) const
{
    return _itemClassByOldEnum[itemClass];
}

bool DB2Manager::HasItemCurrencyCost(uint32 itemId) const
{
    return _itemsWithCurrencyCost.count(itemId) > 0;
}

std::vector<TransmogSetItemEntry const*> const* DB2Manager::GetTransmogSetItems(uint32 transmogSetId) const
{
    return Trinity::Containers::MapGetValuePtr(_transmogSetItemsByTransmogSet, transmogSetId);
}

std::vector<TransmogSetEntry const*> const * DB2Manager::GetTransmogSetsForItemModifiedAppearance(uint32 itemModifiedAppearanceId) const
{
    return Trinity::Containers::MapGetValuePtr(_transmogSetsByItemModifiedAppearance, itemModifiedAppearanceId);
}

PowerTypeEntry const* DB2Manager::GetPowerType(uint8 PowerID)
{
    return Trinity::Containers::MapGetValuePtr(_powerTypeContainer, PowerID);
}

WorldMapAreaEntry const* DB2Manager::GetWorldMapArea(uint16 ZoneID)
{
    return Trinity::Containers::MapGetValuePtr(_worldMapArea, ZoneID);
}

float DB2Manager::GetCurrencyPrecision(uint32 currencyId)
{
    if (CurrencyTypesEntry const* entry = sCurrencyTypesStore.LookupEntry(currencyId))
        return entry->Flags & CURRENCY_FLAG_HAS_PRECISION ? CURRENCY_PRECISION : 1.0f;

    return 1.0f;
}

uint32 DB2Manager::GetVirtualMapForMapAndZone(uint32 mapid, uint32 zoneId)
{
    if (mapid != 530 && mapid != 571 && mapid != 732)   // speed for most cases
        return mapid;

    if (WorldMapAreaEntry const* wma = GetWorldMapArea(zoneId))
        return wma->DisplayMapID >= 0 ? wma->DisplayMapID : wma->MapID;

    return mapid;
}

void DB2Manager::Zone2MapCoordinates(float& x, float& y, uint32 zone)
{
    WorldMapAreaEntry const* maEntry = GetWorldMapArea(zone);
    if (!maEntry)
        return;

    std::swap(x, y);                                         // at client map coords swapped
    x = x * ((maEntry->LocBottom - maEntry->LocTop) / 100) + maEntry->LocTop;
    y = y * ((maEntry->LocRight - maEntry->LocLeft) / 100) + maEntry->LocLeft;      // client y coord from top to down
}

void DB2Manager::Map2ZoneCoordinates(float& x, float& y, uint32 zone)
{
    WorldMapAreaEntry const* maEntry = GetWorldMapArea(zone);
    if (!maEntry)
        return;

    x = (x - maEntry->LocTop) / ((maEntry->LocBottom - maEntry->LocTop) / 100);
    y = (y - maEntry->LocLeft) / ((maEntry->LocRight - maEntry->LocLeft) / 100);    // client y coord from top to down
    std::swap(x, y);                                         // client have map coords swapped
}

std::vector<uint32> const* DB2Manager::GetGlyphBindableSpells(uint32 glyphPropertiesId) const
{
    return Trinity::Containers::MapGetValuePtr(_glyphBindableSpells, glyphPropertiesId);
}

std::vector<uint32> const* DB2Manager::GetGlyphRequiredSpecs(uint32 glyphPropertiesId) const
{
    return Trinity::Containers::MapGetValuePtr(_glyphRequiredSpecs, glyphPropertiesId);
}

bool DB2Manager::HasBattlePetSpeciesFlag(uint16 species, uint16 flag)
{
    if (species >= _battlePetSpeciesContainer.size())
        return false;

    if (auto const& speciesEntry = _battlePetSpeciesContainer[species])
        return (speciesEntry->Flags & flag) != 0;

    return false;
}

MapChallengeModeEntry const* DB2Manager::GetChallengeModeByMapID(uint32 mapID)
{
    return Trinity::Containers::MapGetValuePtr(_mapChallengeModeEntrybyMap, mapID);
}

std::vector<uint32> DB2Manager::GetChallngeMaps()
{
    return _challengeModeMaps;
}

std::vector<double> DB2Manager::GetChallngesWeight()
{
    return _challengeWeightMaps;
}

double DB2Manager::GetChallngeWeight(uint32 mapID)
{
    if (sWorld->getBoolConfig(CONFIG_ARGUSWOW_ENABLE))
    {
        switch(sWorld->getIntConfig(CONFIG_DUNGEON_ACTIVE_STEP))
        {
            case 0: // Disable all dungeons
            case 1: // step 7.0.3
                switch(mapID)
                {
                    case 1651: // Upper and Lower Karazhan
                    case 1571: // Court of Stars
                    case 1516: // The Arcway
                    case 1677: // Cathedral of Eternal Night
                    case 1753: // Seat of the Triumvirate
                        return 0.0;
                }
                break;
            case 2: // step 7.1.0
                switch(mapID)
                {
                    case 1571: // Court of Stars
                    case 1516: // The Arcway
                    case 1677: // Cathedral of Eternal Night
                    case 1753: // Seat of the Triumvirate
                        return 0.0;
                }
                break;
            case 3: // step 7.1.5
                switch(mapID)
                {
                    case 1677: // Cathedral of Eternal Night
                    case 1753: // Seat of the Triumvirate
                        return 0.0;
                }
                break;
            case 4: // step 7.2.5
                switch(mapID)
                {
                    case 1753: // Seat of the Triumvirate
                        return 0.0;
                }
                break;
            case 5: // step 7.3.2
            default:
                break;
        }
    }

    switch(mapID)
    {
        case 1492: // Maw of Souls
            return 10.0;
        case 1651: // Upper and Lower Karazhan
        case 1677: // Cathedral of Eternal Night
        case 1753: // Seat of the Triumvirate
            return 8.5;
        case 1493: // Vault of the Wardens
        case 1458: // Neltharion's Lair
        case 1516: // The Arcway
        case 1477: // Halls of Valor
            return 7.5;
        case 1571: // Court of Stars
        case 1501: // Black Rook Hold
        case 1466: // Darkheart Thicket
        case 1456: // Eye of Azshara
            return 6.5;
    }
    return 0.0;
}

std::vector<PvpTalentEntry const*> DB2Manager::GetPvpTalentByPosition(uint8 playerClass, uint8 row, uint8 column)
{
    auto data = _pvpTalentByPos[playerClass][row][column];
    for (auto const& v : _pvpTalentByPos[0][row][column])
        data.emplace_back(v);
    return data;
}

std::vector<uint16> const* DB2Manager::GetWorldMapZone(uint16 MapID)
{
    return Trinity::Containers::MapGetValuePtr(_worldMapZone, MapID);
}

uint32 DB2Manager::GetHonorLevelRewardPack(uint16 honorLevel, uint8 prestigeLevel)
{
    auto data = _rewardPackByHonorLevel.find(std::make_pair(honorLevel, prestigeLevel));
    if (data != _rewardPackByHonorLevel.end())
        return data->second;

    return 0;
}

RewardPackXItemEntry const* DB2Manager::GetRewardPackXItem(uint32 rewardPackID)
{
    return Trinity::Containers::MapGetValuePtr(_rewardPackXItem, rewardPackID);
}

RewardPackXCurrencyTypeEntry const* DB2Manager::GetRewardPackXCurrency(uint32 rewardPackID)
{
    return Trinity::Containers::MapGetValuePtr(_rewardPackXCurrency, rewardPackID);
}

DB2Manager::MountXDisplayContainer const* DB2Manager::GetMountDisplays(uint32 mountId) const
{
    return Trinity::Containers::MapGetValuePtr(_mountDisplays, mountId);
}

float DB2Manager::GetPvpScalingValueByEffectType(uint32 type, uint32 specID)
{
    return _pvpScalingEffectsBySpecID[specID][type];
}

std::vector<uint32> DB2Manager::GetLootItemsForInstanceByMapID(uint32 mapID)
{
    auto itemList = std::vector<uint32>();
    if (!mapID)
        return itemList;

    auto itr = _encounterIdByMapID.find(mapID);
    auto encounterID = itr != _encounterIdByMapID.end() ? itr->second : 0;
    if (!encounterID)
        return itemList;

    auto itr2 = _journalLootIDsByEncounterID.find(encounterID);
    if (itr2 == _journalLootIDsByEncounterID.end())
        return itemList;

    for (auto const& i : itr2->second)
    {
        auto itr3 = _instanceLootItemIDsByEncounterID.find(i);
        if (itr3 != _instanceLootItemIDsByEncounterID.end())
            for (auto const& v : itr3->second)
                itemList.emplace_back(v);
    }

    return itemList;
}

DB2Manager::GarrEffectContainer const* DB2Manager::GetGarrEffect(uint32 AbilityID) const
{
    return Trinity::Containers::MapGetValuePtr(_garrAbilityEffectContainer, AbilityID);
}

ArtifactUnlockEntry const* DB2Manager::GetArtifactUnlock(uint32 ArtifactID) const
{
    return Trinity::Containers::MapGetValuePtr(_artifactToUnlockContainer, ArtifactID);
}

DB2Manager::XData const* DB2Manager::getXMechanic(uint32 x) const
{
    return Trinity::Containers::MapGetValuePtr(_xMechanic, x);
}

DB2Manager::XData const* DB2Manager::getXEncounter(uint32 x) const
{
    return Trinity::Containers::MapGetValuePtr(_xEncounter, x);
}

std::set<uint32> DB2Manager::GetPhasesForGroup(uint32 group) const
{
    auto itr = _phasesByGroup.find(group);
    if (itr != _phasesByGroup.end())
        return itr->second;

    return {};
}

SkillLineAbilityEntry const* DB2Manager::GetSkillBySpell(uint32 SpellID) const
{
    return Trinity::Containers::MapGetValuePtr(_spellToSkillContainer, SpellID);
}

BattlePetSpeciesEntry const* DB2Manager::GetSpeciesBySpell(uint32 SpellID) const
{
    return Trinity::Containers::MapGetValuePtr(_spellToSpeciesContainer, SpellID);
}

BattlePetSpeciesEntry const* DB2Manager::GetSpeciesByCreatureID(uint32 CreatureID) const
{
    if (CreatureID >= _creatureToSpeciesContainer.size())
        return nullptr;

    return _creatureToSpeciesContainer[CreatureID];
}

LFGDungeonsEntry const* DB2Manager::GetLFGDungeonsByMapDIff(int16 MapID, uint8 DifficultyID) const
{
    auto itr = _lfgdungeonsContainer.find(MapID);
    if (itr == _lfgdungeonsContainer.end())
        return nullptr;

    return Trinity::Containers::MapGetValuePtr(itr->second, DifficultyID);
}

uint32 DB2Manager::LFGRoleRequirementCondition(uint32 lfgDungeonsId, uint8 roleType)
{
    auto itr = _LFGRoleRequirementCondition.find(std::make_pair(lfgDungeonsId, roleType));
    if (itr != _LFGRoleRequirementCondition.end())
        return itr->second;
    return 0;
}

uint32 DB2Manager::GetScalingByLevel(uint8 MinLevel, uint16 MaxLevel) const
{
    auto itr = _sandboxScalingContainer.find(MaxLevel);
    if (itr == _sandboxScalingContainer.end())
        return 0;

    auto iter = itr->second.find(MinLevel);
    if (iter == itr->second.end())
        return 0;

    return iter->second;
}

MapEntry const* DB2Manager::GetMapByID(uint32 mapID)
{
    auto itr = _mapEntryContainer.find(mapID);

    if (itr != _mapEntryContainer.end())
        return itr->second;

    return 0;
}

uint32 DB2Manager::GetHostileSpellVisualId(uint32 spellVisualId)
{
    auto itr = _hostileSpellVisualIdContainer.find(spellVisualId);
    if (itr != _hostileSpellVisualIdContainer.end())
        return itr->second;
    return 0;
}

std::vector<uint32> DB2Manager::GetSpecializationIDsForClass(uint32 classID)
{
    auto specializationIDList = std::vector<uint32>();
    if (!classID)
        return specializationIDList;

    for (auto spec : sChrSpecializationStore)
        if (spec->ClassID == classID)
            specializationIDList.push_back(spec->ID);

    return specializationIDList;
}

std::vector<uint32> DB2Manager::GetArtifactIDsForSpecialization(uint32 specializationID)
{
    auto artifactIdList = std::vector<uint32>();
    if (!specializationID)
        return artifactIdList;

    for (auto artifact : sArtifactStore)
        if (artifact->ChrSpecializationID == specializationID)
            artifactIdList.push_back(artifact->ID);

    return artifactIdList;
}

std::vector<uint32> DB2Manager::GetItemModifiedAppearanceIDsForItem(uint32 itemID)
{
    auto itemModifiedAppearanceIDList = std::vector<uint32>();
    if (!itemID)
        return itemModifiedAppearanceIDList;

    for (auto itemModifiedAppearance : sItemModifiedAppearanceStore)
        if (itemModifiedAppearance->ItemID == itemID)
            itemModifiedAppearanceIDList.push_back(itemModifiedAppearance->ItemAppearanceID);

    return itemModifiedAppearanceIDList;
}
