DELETE FROM `creature_queststarter` WHERE `id`=39883 AND `quest`=25602;
INSERT INTO `creature_queststarter` (`id`, `quest`) VALUES (39883, 25602);
DELETE FROM `quest_template_addon` WHERE `ID`=25602;
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `RewardMailTemplateID`, `RewardMailDelay`, `RewardMailTitle`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES (25602, 0, 0, 0, 25390, 25459, 0, 0, 0, '', 0, 0, 0, 0, 0, 0, 0, 0, '');
DELETE FROM `quest_template_addon` WHERE `ID`=25459;
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `RewardMailTemplateID`, `RewardMailDelay`, `RewardMailTitle`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES (25459, 0, 0, 0, 25602, 25638, 0, 0, 0, '', 0, 0, 0, 0, 0, 0, 0, 0, '');
DELETE FROM `gameobject_loot_template` WHERE `entry`=203113 AND `item`=55143;
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES (203113, 55143, 99.527, 1, 0, 1, 1);
