DELETE FROM `creature_template_addon` WHERE `entry`=55368;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (55368, 0, 0, 65536, 1, 0, '0');
DELETE FROM `gossip_menu_option` WHERE `MenuID`=13137 AND `OptionIndex`=0;
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionIndex`, `OptionNPC`, `OptionText`, `OptionType`, `OptionNpcflag`, `OptionNpcflag2`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxCurrency`, `BoxText`, `OptionBroadcastTextID`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES (13137, 0, 0, 'Where is Shin?', 1, 1, 0, 0, 0, 0, 0, 0, '', 53908, 0, 0);
