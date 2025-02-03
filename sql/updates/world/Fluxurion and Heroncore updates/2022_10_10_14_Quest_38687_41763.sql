DELETE FROM `quest_start_scripts` WHERE  `id` IN (38687, 41763);
UPDATE `quest_template` SET `StartScript`='0' WHERE  `ID` IN (38687, 41763);
UPDATE `creature` SET `PhaseId`='0' WHERE  `PhaseId`=6185;

DELETE FROM `creature` WHERE `guid`=296208278;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseId`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `npcflag2`, `unit_flags`, `dynamicflags`, `ScriptName`, `AiID`, `MovementID`, `MeleeID`, `isActive`, `skipClone`, `personal_size`, `isTeemingSpawn`, `unit_flags3`, `WpID`, `BoxID`, `protec_anti_doublet`) VALUES (296208278, 111228, 1220, 7558, 7665, 1, 1, '', 0, 0, 3459.1, 6124.46, 198.69, 3.17692, 300, 0, 0, 3325656, 1100000, 0, 0, 0, 0, 0, '', 0, 0, 0, 0, 0, 0, 0, 0, NULL, NULL, NULL);
DELETE FROM `creature` WHERE `guid`=296208291;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseId`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `npcflag2`, `unit_flags`, `dynamicflags`, `ScriptName`, `AiID`, `MovementID`, `MeleeID`, `isActive`, `skipClone`, `personal_size`, `isTeemingSpawn`, `unit_flags3`, `WpID`, `BoxID`, `protec_anti_doublet`) VALUES (296208291, 111258, 1220, 7558, 7665, 1, 1, '', 0, 0, 3612.3, 6131.42, 177.884, 2.05773, 300, 0, 0, 1299083776, 55000000, 0, 0, 0, 0, 0, '', 0, 0, 0, 0, 0, 0, 0, 0, NULL, NULL, NULL);
DELETE FROM `creature` WHERE `guid`=296208421;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseId`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `npcflag2`, `unit_flags`, `dynamicflags`, `ScriptName`, `AiID`, `MovementID`, `MeleeID`, `isActive`, `skipClone`, `personal_size`, `isTeemingSpawn`, `unit_flags3`, `WpID`, `BoxID`, `protec_anti_doublet`) VALUES (296208421, 111260, 1220, 7558, 7665, 1, 1, '', 0, 0, 3748.03, 6164.78, 184.363, 1.7632, 300, 0, 0, 1299083776, 55000000, 0, 0, 0, 0, 0, '', 0, 0, 0, 0, 0, 0, 0, 0, NULL, NULL, NULL);
DELETE FROM `creature` WHERE `guid`=296208505;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseId`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `npcflag2`, `unit_flags`, `dynamicflags`, `ScriptName`, `AiID`, `MovementID`, `MeleeID`, `isActive`, `skipClone`, `personal_size`, `isTeemingSpawn`, `unit_flags3`, `WpID`, `BoxID`, `protec_anti_doublet`) VALUES (296208505, 111259, 1220, 7558, 7665, 1, 1, '', 0, 0, 3770.46, 6349.22, 183.941, 3.74241, 300, 0, 0, 1299083776, 55000000, 0, 0, 0, 537165826, 0, '', 0, 0, 0, 0, 0, 0, 0, 0, NULL, NULL, NULL);
DELETE FROM `creature` WHERE `guid`=296208248;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseId`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `npcflag2`, `unit_flags`, `dynamicflags`, `ScriptName`, `AiID`, `MovementID`, `MeleeID`, `isActive`, `skipClone`, `personal_size`, `isTeemingSpawn`, `unit_flags3`, `WpID`, `BoxID`, `protec_anti_doublet`) VALUES (296208248, 104728, 1220, 7558, 7665, 1, 1, '', 0, 0, 3401.69, 6122.78, 215.032, 0.0392512, 300, 0, 0, 1299083776, 49500000, 0, 0, 0, 0, 0, '', 0, 0, 0, 0, 0, 0, 0, 0, NULL, NULL, NULL);

DELETE FROM `quest_template_addon` WHERE `ID`=38687;
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `RewardMailTemplateID`, `RewardMailDelay`, `RewardMailTitle`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES (38687, 0, 0, 0, 38684, 38743, 0, 0, 0, '', 0, 0, 0, 0, 0, 0, 0, 0, '');
DELETE FROM `quest_template_addon` WHERE `ID`=41763;
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `RewardMailTemplateID`, `RewardMailDelay`, `RewardMailTitle`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES (41763, 0, 0, 0, 0, 38743, 0, 0, 0, '', 0, 0, 0, 0, 0, 0, 0, 0, '');


 -- Tyrande Whisperwind 1
SET @ENTRY := 104728;
DELETE FROM `smart_scripts` WHERE `entryOrGuid` = @ENTRY;
UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'npc_tyrande_whisperwind_104728' WHERE `entry` = @ENTRY;

DELETE FROM `creature_text` WHERE `Entry`=104728 AND `Text`='I have no time for games! ';
INSERT INTO `creature_text` (`Entry`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextID`, `MinTimer`, `MaxTimer`, `SpellID`, `comment`) VALUES (104728, 8, 0, 'I have no time for games! ', 12, 0, 100, 0, 0, 64606, 0, 0, 0, 0, 'Tyrande Whisperwind');
DELETE FROM `creature_text` WHERE `Entry`=104728 AND `Text`='Where are you Malfurion? Answer me! ';
INSERT INTO `creature_text` (`Entry`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextID`, `MinTimer`, `MaxTimer`, `SpellID`, `comment`) VALUES (104728, 9, 0, 'Where are you Malfurion? Answer me! ', 12, 0, 100, 0, 0, 58068, 0, 0, 0, 0, 'Tyrande Whisperwind');
DELETE FROM `creature_text` WHERE `Entry`=104728 AND `Text`='I cannot tell where his voice is coming from! Quickly, search the buildings to the east. I will scour the west for signs of him! ';
INSERT INTO `creature_text` (`Entry`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextID`, `MinTimer`, `MaxTimer`, `SpellID`, `comment`) VALUES (104728, 10, 0, 'I cannot tell where his voice is coming from! Quickly, search the buildings to the east. I will scour the west for signs of him! ', 12, 0, 100, 0, 0, 64607, 0, 0, 0, 0, 'Tyrande Whisperwind');

-- Waypoints
DELETE FROM `script_waypoint` WHERE `entry`=104728 AND `pointid`=1;
INSERT INTO `script_waypoint` (`entry`, `pointid`, `location_x`, `location_y`, `location_z`, `waittime`, `point_comment`) VALUES (104728, 1, 3442.3, 6123.41, 202.9, 0, NULL);
DELETE FROM `script_waypoint` WHERE `entry`=104728 AND `pointid`=2;
INSERT INTO `script_waypoint` (`entry`, `pointid`, `location_x`, `location_y`, `location_z`, `waittime`, `point_comment`) VALUES (104728, 2, 3499.97, 6121.56, 188.04, 0, NULL);
DELETE FROM `script_waypoint` WHERE `entry`=104728 AND `pointid`=3;
INSERT INTO `script_waypoint` (`entry`, `pointid`, `location_x`, `location_y`, `location_z`, `waittime`, `point_comment`) VALUES (104728, 3, 3531.56, 6148.95, 178.189, 0, NULL);
DELETE FROM `script_waypoint` WHERE `entry`=104728 AND `pointid`=4;
INSERT INTO `script_waypoint` (`entry`, `pointid`, `location_x`, `location_y`, `location_z`, `waittime`, `point_comment`) VALUES (104728, 4, 3553.62, 6152.96, 178.223, 0, NULL);
DELETE FROM `script_waypoint` WHERE `entry`=104728 AND `pointid`=5;
INSERT INTO `script_waypoint` (`entry`, `pointid`, `location_x`, `location_y`, `location_z`, `waittime`, `point_comment`) VALUES (104728, 5, 3563.41, 6162.29, 178.215, 0, NULL);
DELETE FROM `script_waypoint` WHERE `entry`=104728 AND `pointid`=6;
INSERT INTO `script_waypoint` (`entry`, `pointid`, `location_x`, `location_y`, `location_z`, `waittime`, `point_comment`) VALUES (104728, 6, 3547.18, 6233.59, 170.54, 0, NULL);
DELETE FROM `script_waypoint` WHERE `entry`=104728 AND `pointid`=7;
INSERT INTO `script_waypoint` (`entry`, `pointid`, `location_x`, `location_y`, `location_z`, `waittime`, `point_comment`) VALUES (104728, 7, 3546.87, 6299.75, 165.344, 0, NULL);



  -- Image of Xavius
SET @ENTRY := 111228;
DELETE FROM `smart_scripts` WHERE `entryOrGuid` = @ENTRY;
UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'npc_image_of_xavius_111228' WHERE `entry` = @ENTRY;

DELETE FROM `creature_text` WHERE `Entry`=111228 AND `Text`='Welcome to my "dream" home! Your beloved Malfurion awaits within. ';
INSERT INTO `creature_text` (`Entry`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextID`, `MinTimer`, `MaxTimer`, `SpellID`, `comment`) VALUES (111228, 0, 0, 'Welcome to my "dream" home! Your beloved Malfurion awaits within. ', 12, 0, 100, 1, 7000, 64604, 0, 0, 0, 0, 'Image of Xavius');
DELETE FROM `creature_text` WHERE `Entry`=111228 AND `Text`='But what\'s this? Which Malfurion is real, and which is part of the Nightmare...? [Laugh] ';
INSERT INTO `creature_text` (`Entry`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextID`, `MinTimer`, `MaxTimer`, `SpellID`, `comment`) VALUES (111228, 1, 0, 'But what\'s this? Which Malfurion is real, and which is part of the Nightmare...? [Laugh] ', 12, 0, 100, 1, 7000, 64605, 0, 0, 0, 0, 'Image of Xavius');


 -- Malfurion Stormrage 1
SET @ENTRY := 111258;
DELETE FROM `smart_scripts` WHERE `entryOrGuid` = @ENTRY;
UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'npc_malfurion_stormrage_111258_111259_111260' WHERE `entry` = @ENTRY;

 -- Malfurion Stormrage 2
SET @ENTRY := 111260;
DELETE FROM `smart_scripts` WHERE `entryOrGuid` = @ENTRY;
UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'npc_malfurion_stormrage_111258_111259_111260' WHERE `entry` = @ENTRY;

 -- Malfurion Stormrage 3
SET @ENTRY := 111259;
DELETE FROM `smart_scripts` WHERE `entryOrGuid` = @ENTRY;
UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'npc_malfurion_stormrage_111258_111259_111260' WHERE `entry` = @ENTRY;

 -- Shala'nir Druid
SET @ENTRY := 97554;
DELETE FROM `smart_scripts` WHERE `entryOrGuid` = @ENTRY;
UPDATE `creature_template` SET `AIName` = '', `ScriptName` = '' WHERE `entry` = @ENTRY;

 -- Tyrande Whisperwind 2
SET @ENTRY := 104799;
DELETE FROM `smart_scripts` WHERE `entryOrGuid` = @ENTRY;
UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'npc_tyrande_whisperwind_104799' WHERE `entry` = @ENTRY;


-- Xavius set to can't interact with player
UPDATE `creature_template` SET `unit_flags`='0', `unit_flags2`='0', `faction`='35' WHERE  `entry`=111228;
DELETE FROM `creature_template_addon` WHERE `entry`=111228;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (111228, 0, 0, 33554432, 1, 0, NULL);



-- Quest Objectives
DELETE FROM `quest_objectives` WHERE `ID`=285652;
INSERT INTO `quest_objectives` (`ID`, `QuestID`, `Type`, `StorageIndex`, `ObjectID`, `Amount`, `Flags`, `Flags2`, `TaskStep`, `Description`, `VerifiedBuild`) VALUES (285652, 38687, 0, 0, 104799, 1, 0, 0, 0, 'Follow Tyrande into Shala\'nir', 26972);
DELETE FROM `quest_objectives` WHERE `ID`=285653;
INSERT INTO `quest_objectives` (`ID`, `QuestID`, `Type`, `StorageIndex`, `ObjectID`, `Amount`, `Flags`, `Flags2`, `TaskStep`, `Description`, `VerifiedBuild`) VALUES (285653, 38687, 0, 1, 111258, 1, 2, 0, 0, 'Search for Malfurion at the Inn', 26972);
DELETE FROM `quest_objectives` WHERE `ID`=285654;
INSERT INTO `quest_objectives` (`ID`, `QuestID`, `Type`, `StorageIndex`, `ObjectID`, `Amount`, `Flags`, `Flags2`, `TaskStep`, `Description`, `VerifiedBuild`) VALUES (285654, 38687, 0, 2, 111260, 1, 2, 0, 0, 'Search for Malfurion near the Lake', 26972);
DELETE FROM `quest_objectives` WHERE `ID`=285655;
INSERT INTO `quest_objectives` (`ID`, `QuestID`, `Type`, `StorageIndex`, `ObjectID`, `Amount`, `Flags`, `Flags2`, `TaskStep`, `Description`, `VerifiedBuild`) VALUES (285655, 38687, 0, 3, 111259, 1, 2, 0, 0, 'Search for Malfurion in the Village', 26972);
DELETE FROM `quest_objectives` WHERE `ID`=285657;
INSERT INTO `quest_objectives` (`ID`, `QuestID`, `Type`, `StorageIndex`, `ObjectID`, `Amount`, `Flags`, `Flags2`, `TaskStep`, `Description`, `VerifiedBuild`) VALUES (285657, 38687, 0, 5, 104764, 1, 2, 0, 0, 'Find Malfurion', 26972);
DELETE FROM `quest_objectives` WHERE `ID`=285658;
INSERT INTO `quest_objectives` (`ID`, `QuestID`, `Type`, `StorageIndex`, `ObjectID`, `Amount`, `Flags`, `Flags2`, `TaskStep`, `Description`, `VerifiedBuild`) VALUES (285658, 38687, 0, 6, 111238, 1, 28, 0, 0, 'Post Poof Conversation Credit', 26972);
DELETE FROM `quest_objectives` WHERE `ID`=285659;
INSERT INTO `quest_objectives` (`ID`, `QuestID`, `Type`, `StorageIndex`, `ObjectID`, `Amount`, `Flags`, `Flags2`, `TaskStep`, `Description`, `VerifiedBuild`) VALUES (285659, 38687, 0, 7, 111239, 1, 28, 0, 0, 'Post Satyr 1 Conversation Credit', 26972);
DELETE FROM `quest_objectives` WHERE `ID`=285639;
INSERT INTO `quest_objectives` (`ID`, `QuestID`, `Type`, `StorageIndex`, `ObjectID`, `Amount`, `Flags`, `Flags2`, `TaskStep`, `Description`, `VerifiedBuild`) VALUES (285639, 41763, 0, 0, 104799, 1, 0, 0, 0, 'Follow Tyrande into Shala\'nir', 26972);
DELETE FROM `quest_objectives` WHERE `ID`=285640;
INSERT INTO `quest_objectives` (`ID`, `QuestID`, `Type`, `StorageIndex`, `ObjectID`, `Amount`, `Flags`, `Flags2`, `TaskStep`, `Description`, `VerifiedBuild`) VALUES (285640, 41763, 0, 1, 111258, 1, 2, 0, 0, 'Search for Malfurion at the Inn', 26972);
DELETE FROM `quest_objectives` WHERE `ID`=285641;
INSERT INTO `quest_objectives` (`ID`, `QuestID`, `Type`, `StorageIndex`, `ObjectID`, `Amount`, `Flags`, `Flags2`, `TaskStep`, `Description`, `VerifiedBuild`) VALUES (285641, 41763, 0, 2, 111260, 1, 2, 0, 0, 'Search for Malfurion near the Lake', 26972);
DELETE FROM `quest_objectives` WHERE `ID`=285642;
INSERT INTO `quest_objectives` (`ID`, `QuestID`, `Type`, `StorageIndex`, `ObjectID`, `Amount`, `Flags`, `Flags2`, `TaskStep`, `Description`, `VerifiedBuild`) VALUES (285642, 41763, 0, 3, 111259, 1, 2, 0, 0, 'Search for Malfurion in the Village', 26972);
DELETE FROM `quest_objectives` WHERE `ID`=285644;
INSERT INTO `quest_objectives` (`ID`, `QuestID`, `Type`, `StorageIndex`, `ObjectID`, `Amount`, `Flags`, `Flags2`, `TaskStep`, `Description`, `VerifiedBuild`) VALUES (285644, 41763, 0, 5, 104764, 1, 2, 0, 0, 'Find Malfurion', 26972);
DELETE FROM `quest_objectives` WHERE `ID`=285645;
INSERT INTO `quest_objectives` (`ID`, `QuestID`, `Type`, `StorageIndex`, `ObjectID`, `Amount`, `Flags`, `Flags2`, `TaskStep`, `Description`, `VerifiedBuild`) VALUES (285645, 41763, 0, 6, 111238, 1, 28, 0, 0, 'Post Poof Conversation Credit', 26972);
DELETE FROM `quest_objectives` WHERE `ID`=285646;
INSERT INTO `quest_objectives` (`ID`, `QuestID`, `Type`, `StorageIndex`, `ObjectID`, `Amount`, `Flags`, `Flags2`, `TaskStep`, `Description`, `VerifiedBuild`) VALUES (285646, 41763, 0, 7, 111239, 1, 28, 0, 0, 'Post Satyr 1 Conversation Credit', 26972);


-- Conversation better times between talks (legion version)
DELETE FROM `conversation_data` WHERE `entry`=3137 AND `id`=6623;
INSERT INTO `conversation_data` (`entry`, `id`, `idx`, `textId`, `unk1`, `unk2`) VALUES (3137, 6623, 0, 0, 0, 0);
DELETE FROM `conversation_data` WHERE `entry`=3137 AND `id`=6624;
INSERT INTO `conversation_data` (`entry`, `id`, `idx`, `textId`, `unk1`, `unk2`) VALUES (3137, 6624, 1, 3650, 0, 0);
DELETE FROM `conversation_data` WHERE `entry`=3138 AND `id`=6626;
INSERT INTO `conversation_data` (`entry`, `id`, `idx`, `textId`, `unk1`, `unk2`) VALUES (3138, 6626, 0, 0, 99, 0);
DELETE FROM `conversation_data` WHERE `entry`=3139 AND `id`=6627;
INSERT INTO `conversation_data` (`entry`, `id`, `idx`, `textId`, `unk1`, `unk2`) VALUES (3139, 6627, 0, 0, 585, 0);
DELETE FROM `conversation_data` WHERE `entry`=3140 AND `id`=6628;
INSERT INTO `conversation_data` (`entry`, `id`, `idx`, `textId`, `unk1`, `unk2`) VALUES (3140, 6628, 0, 0, 99, 0);
DELETE FROM `conversation_data` WHERE `entry`=3140 AND `id`=6629;
INSERT INTO `conversation_data` (`entry`, `id`, `idx`, `textId`, `unk1`, `unk2`) VALUES (3140, 6629, 1, 5000, 101, 1);
DELETE FROM `conversation_data` WHERE `entry`=3141 AND `id`=6630;
INSERT INTO `conversation_data` (`entry`, `id`, `idx`, `textId`, `unk1`, `unk2`) VALUES (3141, 6630, 0, 0, 585, 0);
DELETE FROM `conversation_data` WHERE `entry`=3141 AND `id`=6631;
INSERT INTO `conversation_data` (`entry`, `id`, `idx`, `textId`, `unk1`, `unk2`) VALUES (3141, 6631, 1, 4000, 101, 1);
DELETE FROM `conversation_data` WHERE `entry`=3142 AND `id`=6632;
INSERT INTO `conversation_data` (`entry`, `id`, `idx`, `textId`, `unk1`, `unk2`) VALUES (3142, 6632, 0, 0, 99, 0);
DELETE FROM `conversation_data` WHERE `entry`=3142 AND `id`=6633;
INSERT INTO `conversation_data` (`entry`, `id`, `idx`, `textId`, `unk1`, `unk2`) VALUES (3142, 6633, 1, 5000, 101, 1);
DELETE FROM `conversation_data` WHERE `entry`=3143 AND `id`=6634;
INSERT INTO `conversation_data` (`entry`, `id`, `idx`, `textId`, `unk1`, `unk2`) VALUES (3143, 6634, 0, 0, 99, 0);
DELETE FROM `conversation_data` WHERE `entry`=3143 AND `id`=6635;
INSERT INTO `conversation_data` (`entry`, `id`, `idx`, `textId`, `unk1`, `unk2`) VALUES (3143, 6635, 1, 5000, 101, 1);
DELETE FROM `conversation_data` WHERE `entry`=3143 AND `id`=8388;
INSERT INTO `conversation_data` (`entry`, `id`, `idx`, `textId`, `unk1`, `unk2`) VALUES (3143, 8388, 2, 10000, 101, 1);

DELETE FROM `conversation_actor` WHERE `entry`=3138 AND `id`=0;
INSERT INTO `conversation_actor` (`entry`, `id`, `actorId`, `creatureId`, `displayId`, `unk1`, `unk2`, `unk3`, `duration`) VALUES (3138, 0, 52174, 111204, 35095, 0, 1, 0, 3000);
DELETE FROM `conversation_actor` WHERE `entry`=3139 AND `id`=0;
INSERT INTO `conversation_actor` (`entry`, `id`, `actorId`, `creatureId`, `displayId`, `unk1`, `unk2`, `unk3`, `duration`) VALUES (3139, 0, 52175, 111228, 71620, 0, 1, 0, 3000);
DELETE FROM `conversation_actor` WHERE `entry`=3140 AND `id`=0;
INSERT INTO `conversation_actor` (`entry`, `id`, `actorId`, `creatureId`, `displayId`, `unk1`, `unk2`, `unk3`, `duration`) VALUES (3140, 0, 52174, 111204, 35095, 0, 1, 0, 3000);
DELETE FROM `conversation_actor` WHERE `entry`=3140 AND `id`=1;
INSERT INTO `conversation_actor` (`entry`, `id`, `actorId`, `creatureId`, `displayId`, `unk1`, `unk2`, `unk3`, `duration`) VALUES (3140, 1, 52166, 104728, 67912, 0, 1, 0, 3000);
DELETE FROM `conversation_actor` WHERE `entry`=3141 AND `id`=0;
INSERT INTO `conversation_actor` (`entry`, `id`, `actorId`, `creatureId`, `displayId`, `unk1`, `unk2`, `unk3`, `duration`) VALUES (3141, 0, 52175, 111228, 71620, 0, 1, 0, 3000);
DELETE FROM `conversation_actor` WHERE `entry`=3141 AND `id`=1;
INSERT INTO `conversation_actor` (`entry`, `id`, `actorId`, `creatureId`, `displayId`, `unk1`, `unk2`, `unk3`, `duration`) VALUES (3141, 1, 52166, 104799, 67912, 0, 1, 0, 3000);
DELETE FROM `conversation_actor` WHERE `entry`=3142 AND `id`=0;
INSERT INTO `conversation_actor` (`entry`, `id`, `actorId`, `creatureId`, `displayId`, `unk1`, `unk2`, `unk3`, `duration`) VALUES (3142, 0, 52174, 111204, 35095, 0, 1, 0, 3000);
DELETE FROM `conversation_actor` WHERE `entry`=3142 AND `id`=1;
INSERT INTO `conversation_actor` (`entry`, `id`, `actorId`, `creatureId`, `displayId`, `unk1`, `unk2`, `unk3`, `duration`) VALUES (3142, 1, 52166, 104799, 67912, 0, 1, 0, 3000);
DELETE FROM `conversation_actor` WHERE `entry`=3143 AND `id`=0;
INSERT INTO `conversation_actor` (`entry`, `id`, `actorId`, `creatureId`, `displayId`, `unk1`, `unk2`, `unk3`, `duration`) VALUES (3143, 0, 52174, 111204, 35095, 0, 1, 0, 3000);
DELETE FROM `conversation_actor` WHERE `entry`=3143 AND `id`=1;
INSERT INTO `conversation_actor` (`entry`, `id`, `actorId`, `creatureId`, `displayId`, `unk1`, `unk2`, `unk3`, `duration`) VALUES (3143, 1, 52166, 104799, 67912, 0, 1, 0, 3000);

