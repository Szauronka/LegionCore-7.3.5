DELETE FROM `gossip_menu_option` WHERE `MenuID`=55283 AND `OptionIndex`=0;
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionIndex`, `OptionNPC`, `OptionText`, `OptionType`, `OptionNpcflag`, `OptionNpcflag2`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxCurrency`, `BoxText`, `OptionBroadcastTextID`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES (55283, 0, 0, 'Tell me everything!', 1, 1, 0, 0, 0, 0, 0, 0, NULL, 0, 0, 0);
DELETE FROM `quest_objectives` WHERE `ID`=264491;
DELETE FROM `gossip_menu_option` WHERE `MenuID`=55284 AND `OptionIndex`=0;
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionIndex`, `OptionNPC`, `OptionText`, `OptionType`, `OptionNpcflag`, `OptionNpcflag2`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxCurrency`, `BoxText`, `OptionBroadcastTextID`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES (55284, 0, 0, 'Tell me everything!', 1, 1, 0, 0, 0, 0, 0, 0, NULL, 0, 0, 0);
DELETE FROM `gossip_menu_option` WHERE `MenuID`=55282 AND `OptionIndex`=0;
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionIndex`, `OptionNPC`, `OptionText`, `OptionType`, `OptionNpcflag`, `OptionNpcflag2`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxCurrency`, `BoxText`, `OptionBroadcastTextID`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES (55282, 0, 0, 'Tell me everything!', 1, 1, 0, 0, 0, 0, 0, 0, NULL, 0, 0, 0);
DELETE FROM `creature_template_addon` WHERE `entry`=55282;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (55282, 0, 0, 65536, 1, 0, '0');
DELETE FROM `quest_template_addon` WHERE `ID`=29733;
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `RewardMailTemplateID`, `RewardMailDelay`, `RewardMailTitle`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES (29733, 0, 0, 0, 29894, 0, 0, 0, 0, '', 0, 0, 0, 0, 0, 0, 0, 0, '');
DELETE FROM `gossip_menu_option` WHERE `MenuID`=55333 AND `OptionIndex`=0;
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionIndex`, `OptionNPC`, `OptionText`, `OptionType`, `OptionNpcflag`, `OptionNpcflag2`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxCurrency`, `BoxText`, `OptionBroadcastTextID`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES (55333, 0, 0, 'Tell me everything!', 1, 1, 0, 0, 0, 0, 0, 0, NULL, 0, 0, 0);
DELETE FROM `creature_template_addon` WHERE `entry`=55333;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (55333, 0, 0, 65543, 257, 0, '0');
