/* Converted from Shadowlands by Fluxurion specially to HeronCore  */

-- horde warboard spell script linking
DELETE FROM `spell_script_names` WHERE `spell_id`=261655;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES (261655, 'spell_warboard_horde_261655');

-- horde warboard gameobject template
DELETE FROM `gameobject_template` WHERE `entry`=281340;
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `faction`, `flags`, `size`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `unkInt32`, `AIName`, `ScriptName`, `WorldEffectID`, `StateWorldEffectID`, `SpellVisualID`, `SpellStateVisualID`, `SpellStateAnimID`, `SpellStateAnimKitID`, `MaxVisible`, `IgnoreDynLos`, `MinGold`, `MaxGold`, `VerifiedBuild`) VALUES (281340, 22, 10014, 'Warchief\'s Command Board', '', '', '', 29, 0, 1, 0, 0, 0, 0, 0, 0, 261655, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 8830, 0, 0, 0, 0, 0, 0, 0, 0, 0, 32535);

-- horde warboard spawn
SET @OGUID := 5000100; -- alliance is 5000000

-- cleaning first: remove all horde warboard old and new
DELETE FROM gameobject WHERE id IN (281340, 206116, 206109);
/*
heroncore 2022.10.11. backup:

DELETE FROM `gameobject` WHERE `guid`=107490;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseId`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `AiID`, `state`, `ScriptName`, `isActive`, `personal_size`) VALUES (107490, 206116, 1, 1637, 5168, 1, 1, '', 1914.14, -4661.89, 33.6092, 0.383971, 0, 0, 0, 1, 180, 255, 0, 1, '', 0, 0);
DELETE FROM `gameobject` WHERE `guid`=107487;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseId`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `AiID`, `state`, `ScriptName`, `isActive`, `personal_size`) VALUES (107487, 206109, 1, 1637, 5170, 1, 3, '', 1600.99, -4369.74, 21.0694, 3.67392, 0, 0, 0, 1, 180, 255, 0, 1, '', 0, 0);

*/

-- horde warboard spawn Orgrimmar valley of strength
DELETE FROM `gameobject` WHERE `guid` = @OGUID;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `PhaseId`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(@OGUID, 281340, 1, 1637, 5170, 0, 1600.9896240234375, -4369.73974609375, 21.06940078735351562, 3.630291461944580078, 0, 0, -0.97029495239257812, 0.241925001144409179, 120, 255, 0); -- 281340 (Area: 5170 - Difficulty: 0)

/* HORDE PlayerChoices, not all there is more data to sniff. */

DELETE FROM `playerchoice` WHERE `ChoiceId`=342;
INSERT INTO `playerchoice` (`ChoiceId`, `UiTextureKitId`, `Question`, `HideWarboardHeader`, `VerifiedBuild`) VALUES
(342, 262, 'The Warchief needs you! Take a flyer.', 0, 32535);

ALTER TABLE `playerchoice_response`
	DROP PRIMARY KEY;

DELETE FROM `playerchoice_response` WHERE `ChoiceId` = 342;
INSERT INTO `playerchoice_response` (`ChoiceId`, `ResponseId`, `Index`, `ChoiceArtFileId`, `Header`, `Answer`, `Description`, `Confirmation`, `VerifiedBuild`) VALUES (342, 871, 0, 1851092, 'Arathi Highlands', 'Travel to Arathi Highlands', 'The Forsaken march on the Highlands, seeking to put it under the watchful eye of the Dark Lady.\n\nClaim the Arathi Highlands for the Horde.', '', 32535);
INSERT INTO `playerchoice_response` (`ChoiceId`, `ResponseId`, `Index`, `ChoiceArtFileId`, `Header`, `Answer`, `Description`, `Confirmation`, `VerifiedBuild`) VALUES (342, 871, 1, 1851092, 'Arathi Highlands', 'Travel to Arathi Highlands', 'The Forsaken march on the Highlands, seeking to put it under the watchful eye of the Dark Lady.\n\nClaim the Arathi Highlands for the Horde.', '', 32535);
INSERT INTO `playerchoice_response` (`ChoiceId`, `ResponseId`, `Index`, `ChoiceArtFileId`, `Header`, `Answer`, `Description`, `Confirmation`, `VerifiedBuild`) VALUES (342, 868, 0, 1851080, 'Hillsbrad Foothills', 'Reclaim the Foothills', 'The Forsaken are continuing their campaign to conquer the Eastern Kingdoms for the Horde.\n\nAssist them with their operations in Hillsbrad.', '', 32535);
INSERT INTO `playerchoice_response` (`ChoiceId`, `ResponseId`, `Index`, `ChoiceArtFileId`, `Header`, `Answer`, `Description`, `Confirmation`, `VerifiedBuild`) VALUES (342, 871, 2, 1851092, 'Arathi Highlands', 'Travel to Arathi Highlands', 'The Forsaken march on the Highlands, seeking to put it under the watchful eye of the Dark Lady.\n\nClaim the Arathi Highlands for the Horde.', '', 32535);
INSERT INTO `playerchoice_response` (`ChoiceId`, `ResponseId`, `Index`, `ChoiceArtFileId`, `Header`, `Answer`, `Description`, `Confirmation`, `VerifiedBuild`) VALUES (342, 868, 1, 1851080, 'Hillsbrad Foothills', 'Reclaim the Foothills', 'The Forsaken are continuing their campaign to conquer the Eastern Kingdoms for the Horde.\n\nAssist them with their operations in Hillsbrad.', '', 32535);
INSERT INTO `playerchoice_response` (`ChoiceId`, `ResponseId`, `Index`, `ChoiceArtFileId`, `Header`, `Answer`, `Description`, `Confirmation`, `VerifiedBuild`) VALUES (342, 864, 0, 1851086, 'Silverpine Forest', 'Defeat the Gilneans', 'Guerilla forces sent by Gilneas continue to attack Horde outposts in Silverpine Forest.\n\nAssist the Forsaken and crush the Gilnean opposition.', '', 32535);
INSERT INTO `playerchoice_response` (`ChoiceId`, `ResponseId`, `Index`, `ChoiceArtFileId`, `Header`, `Answer`, `Description`, `Confirmation`, `VerifiedBuild`) VALUES (342, 864, 2, 1851086, 'Silverpine Forest', 'Defeat the Gilneans', 'Guerilla forces sent by Gilneas continue to attack Horde outposts in Silverpine Forest.\n\nAssist the Forsaken and crush the Gilnean opposition.', '', 32535);
INSERT INTO `playerchoice_response` (`ChoiceId`, `ResponseId`, `Index`, `ChoiceArtFileId`, `Header`, `Answer`, `Description`, `Confirmation`, `VerifiedBuild`) VALUES (342, 872, 0, 1851104, 'Northern Stranglethorn', 'Secure Our Trade Routes', 'Recent attacks are hindering our ability to keep supply routes open to Stonard.\n\nAid Commander Aggro\'gosh in creating a safe route to our other outposts.', '', 32535);
INSERT INTO `playerchoice_response` (`ChoiceId`, `ResponseId`, `Index`, `ChoiceArtFileId`, `Header`, `Answer`, `Description`, `Confirmation`, `VerifiedBuild`) VALUES (342, 872, 1, 1851104, 'Northern Stranglethorn', 'Secure Our Trade Routes', 'Recent attacks are hindering our ability to keep supply routes open to Stonard.\n\nAid Commander Aggro\'gosh in creating a safe route to our other outposts.', '', 32535);
INSERT INTO `playerchoice_response` (`ChoiceId`, `ResponseId`, `Index`, `ChoiceArtFileId`, `Header`, `Answer`, `Description`, `Confirmation`, `VerifiedBuild`) VALUES (342, 873, 0, 1851103, 'The Hinterlands', 'Assist the Revantusk Tribe', 'One of our troll allies, the Revantusk tribe, are attempting to secure the Hinterlands for their people.\n\nHelp them with their goal. Show them they are not forgotten by the Horde.', '', 32535);
INSERT INTO `playerchoice_response` (`ChoiceId`, `ResponseId`, `Index`, `ChoiceArtFileId`, `Header`, `Answer`, `Description`, `Confirmation`, `VerifiedBuild`) VALUES (342, 873, 2, 1851103, 'The Hinterlands', 'Assist the Revantusk Tribe', 'One of our troll allies, the Revantusk tribe, are attempting to secure the Hinterlands for their people.\n\nHelp them with their goal. Show them they are not forgotten by the Horde.', '', 32535);
INSERT INTO `playerchoice_response` (`ChoiceId`, `ResponseId`, `Index`, `ChoiceArtFileId`, `Header`, `Answer`, `Description`, `Confirmation`, `VerifiedBuild`) VALUES (342, 874, 0, 1851096, 'The Cape of Stranglethorn', 'Assist Sassy Hardwrench', 'The Bilgewater Cartel has built a resort on the shores of Stranglethorn, but are surrounded by naga and pirates lurking in the surrounding area.\n\nSee what the Horde can do to assist the goblins of Hardwrench Hideaway.', '', 32535);
INSERT INTO `playerchoice_response` (`ChoiceId`, `ResponseId`, `Index`, `ChoiceArtFileId`, `Header`, `Answer`, `Description`, `Confirmation`, `VerifiedBuild`) VALUES (342, 872, 2, 1851104, 'Northern Stranglethorn', 'Secure Our Trade Routes', 'Recent attacks are hindering our ability to keep supply routes open to Stonard.\n\nAid Commander Aggro\'gosh in creating a safe route to our other outposts.', '', 32535);
INSERT INTO `playerchoice_response` (`ChoiceId`, `ResponseId`, `Index`, `ChoiceArtFileId`, `Header`, `Answer`, `Description`, `Confirmation`, `VerifiedBuild`) VALUES (342, 874, 1, 1851096, 'The Cape of Stranglethorn', 'Assist Sassy Hardwrench', 'The Bilgewater Cartel has built a resort on the shores of Stranglethorn, but are surrounded by naga and pirates lurking in the surrounding area.\n\nSee what the Horde can do to assist the goblins of Hardwrench Hideaway.', '', 32535);
INSERT INTO `playerchoice_response` (`ChoiceId`, `ResponseId`, `Index`, `ChoiceArtFileId`, `Header`, `Answer`, `Description`, `Confirmation`, `VerifiedBuild`) VALUES (342, 851, 0, 1851070, 'Ashenvale', 'Reinforce the Rampart', 'The might of Ashenvale is bearing down on our forces at the Mor\'shan Rampart.\n\nRepel the night elves and claim Ashenvale\'s resources for the Horde!', '', 32535);
INSERT INTO `playerchoice_response` (`ChoiceId`, `ResponseId`, `Index`, `ChoiceArtFileId`, `Header`, `Answer`, `Description`, `Confirmation`, `VerifiedBuild`) VALUES (342, 874, 2, 1851096, 'The Cape of Stranglethorn', 'Assist Sassy Hardwrench', 'The Bilgewater Cartel has built a resort on the shores of Stranglethorn, but are surrounded by naga and pirates lurking in the surrounding area.\n\nSee what the Horde can do to assist the goblins of Hardwrench Hideaway.', '', 32535);
INSERT INTO `playerchoice_response` (`ChoiceId`, `ResponseId`, `Index`, `ChoiceArtFileId`, `Header`, `Answer`, `Description`, `Confirmation`, `VerifiedBuild`) VALUES (342, 851, 1, 1851070, 'Ashenvale', 'Reinforce the Rampart', 'The might of Ashenvale is bearing down on our forces at the Mor\'shan Rampart.\n\nRepel the night elves and claim Ashenvale\'s resources for the Horde!', '', 32535);
INSERT INTO `playerchoice_response` (`ChoiceId`, `ResponseId`, `Index`, `ChoiceArtFileId`, `Header`, `Answer`, `Description`, `Confirmation`, `VerifiedBuild`) VALUES (342, 848, 0, 1851084, 'Northern Barrens', 'Defend the Barrens', 'The quilboars and centaurs advancing on the Northern Barrens pose a threat to the supply caravans being sent out of Orgrimmar.\n\nStop them!', '', 32535);
INSERT INTO `playerchoice_response` (`ChoiceId`, `ResponseId`, `Index`, `ChoiceArtFileId`, `Header`, `Answer`, `Description`, `Confirmation`, `VerifiedBuild`) VALUES (342, 848, 1, 1851084, 'Northern Barrens', 'Defend the Barrens', 'The quilboars and centaurs advancing on the Northern Barrens pose a threat to the supply caravans being sent out of Orgrimmar.\n\nStop them!', '', 32535);
INSERT INTO `playerchoice_response` (`ChoiceId`, `ResponseId`, `Index`, `ChoiceArtFileId`, `Header`, `Answer`, `Description`, `Confirmation`, `VerifiedBuild`) VALUES (342, 847, 0, 1851071, 'Azshara', 'Defend Orgrimmar', 'The Alliance are attempting to reverse the efforts made by our forces in Azshara.\n\nPush them back!', '', 32535);
INSERT INTO `playerchoice_response` (`ChoiceId`, `ResponseId`, `Index`, `ChoiceArtFileId`, `Header`, `Answer`, `Description`, `Confirmation`, `VerifiedBuild`) VALUES (342, 852, 0, 1851107, 'Stonetalon Mountains', 'For the Horde!', 'The Alliance seek to control more territory in Kalimdor. This cannot happen. Suit up and report to Blood Guard Aldo Rockrain in Ashenvale.\n\nThe Warchief\'s eyes are upon you.', '', 32535);
INSERT INTO `playerchoice_response` (`ChoiceId`, `ResponseId`, `Index`, `ChoiceArtFileId`, `Header`, `Answer`, `Description`, `Confirmation`, `VerifiedBuild`) VALUES (342, 852, 1, 1851107, 'Stonetalon Mountains', 'For the Horde!', 'The Alliance seek to control more territory in Kalimdor. This cannot happen. Suit up and report to Blood Guard Aldo Rockrain in Ashenvale.\n\nThe Warchief\'s eyes are upon you.', '', 32535);
INSERT INTO `playerchoice_response` (`ChoiceId`, `ResponseId`, `Index`, `ChoiceArtFileId`, `Header`, `Answer`, `Description`, `Confirmation`, `VerifiedBuild`) VALUES (342, 853, 0, 1851087, 'Southern Barrens', 'Fortify the Barrens', 'The Southern Barrens belongs to the Horde, but recent Alliance victories are threatening our control of the land.\n\nShow them that this is our land, and we will defend it.', '', 32535);
INSERT INTO `playerchoice_response` (`ChoiceId`, `ResponseId`, `Index`, `ChoiceArtFileId`, `Header`, `Answer`, `Description`, `Confirmation`, `VerifiedBuild`) VALUES (342, 854, 0, 1851097, 'Desolace', 'Lend Aid to Desolace', 'The Alliance, the Burning Blade, and demons. We have many enemies, and they must be beat back so that the Horde can launch their campaign on Desolace.\n\nGo to Tethris Aran and speak with Furien.', '', 32535);
INSERT INTO `playerchoice_response` (`ChoiceId`, `ResponseId`, `Index`, `ChoiceArtFileId`, `Header`, `Answer`, `Description`, `Confirmation`, `VerifiedBuild`) VALUES (342, 853, 2, 1851087, 'Southern Barrens', 'Fortify the Barrens', 'The Southern Barrens belongs to the Horde, but recent Alliance victories are threatening our control of the land.\n\nShow them that this is our land, and we will defend it.', '', 32535);
INSERT INTO `playerchoice_response` (`ChoiceId`, `ResponseId`, `Index`, `ChoiceArtFileId`, `Header`, `Answer`, `Description`, `Confirmation`, `VerifiedBuild`) VALUES (342, 882, 0, 1851122, 'Zangarmarsh', 'Assist the Expedition', 'The Cenarion Expedition is currently studying the exotic flora and fauna in the marshes of Zangarmarsh.\n\nHelping them with their mission will also help the Horde gain a better understanding of Outland.', '', 32535);
INSERT INTO `playerchoice_response` (`ChoiceId`, `ResponseId`, `Index`, `ChoiceArtFileId`, `Header`, `Answer`, `Description`, `Confirmation`, `VerifiedBuild`) VALUES (342, 882, 1, 1851122, 'Zangarmarsh', 'Assist the Expedition', 'The Cenarion Expedition is currently studying the exotic flora and fauna in the marshes of Zangarmarsh.\n\nHelping them with their mission will also help the Horde gain a better understanding of Outland.', '', 32535);
INSERT INTO `playerchoice_response` (`ChoiceId`, `ResponseId`, `Index`, `ChoiceArtFileId`, `Header`, `Answer`, `Description`, `Confirmation`, `VerifiedBuild`) VALUES (342, 881, 0, 1851116, 'Hellfire Peninsula', 'Travel to Outland', 'The Dark Portal has reopened and the Burning Legion is now positioned to attack Azeroth yet again.\n\nStop the demon filth from taking control of the Dark Portal and cutting off supplies to our forces in Hellfire Peninsula.', '', 32535);
INSERT INTO `playerchoice_response` (`ChoiceId`, `ResponseId`, `Index`, `ChoiceArtFileId`, `Header`, `Answer`, `Description`, `Confirmation`, `VerifiedBuild`) VALUES (342, 854, 2, 1851097, 'Desolace', 'Lend Aid to Desolace', 'The Alliance, the Burning Blade, and demons. We have many enemies, and they must be beat back so that the Horde can launch their campaign on Desolace.\n\nGo to Tethris Aran and speak with Furien.', '', 32535);
INSERT INTO `playerchoice_response` (`ChoiceId`, `ResponseId`, `Index`, `ChoiceArtFileId`, `Header`, `Answer`, `Description`, `Confirmation`, `VerifiedBuild`) VALUES (342, 888, 0, 1851153, 'Howling Fjord', 'Fly to Vengeance Landing', 'The Forsaken have established a beachhead on the shores of Howling Fjord named Vengeance Landing.\n\nFly to Howling Fjord and assist the Royal Apothecary Society in delivering a plague that will devour the Scourge.', '', 32535);
INSERT INTO `playerchoice_response` (`ChoiceId`, `ResponseId`, `Index`, `ChoiceArtFileId`, `Header`, `Answer`, `Description`, `Confirmation`, `VerifiedBuild`) VALUES (342, 882, 2, 1851122, 'Zangarmarsh', 'Assist the Expedition', 'The Cenarion Expedition is currently studying the exotic flora and fauna in the marshes of Zangarmarsh.\n\nHelping them with their mission will also help the Horde gain a better understanding of Outland.', '', 32535);
INSERT INTO `playerchoice_response` (`ChoiceId`, `ResponseId`, `Index`, `ChoiceArtFileId`, `Header`, `Answer`, `Description`, `Confirmation`, `VerifiedBuild`) VALUES (342, 888, 1, 1851153, 'Howling Fjord', 'Fly to Vengeance Landing', 'The Forsaken have established a beachhead on the shores of Howling Fjord named Vengeance Landing.\n\nFly to Howling Fjord and assist the Royal Apothecary Society in delivering a plague that will devour the Scourge.', '', 32535);
INSERT INTO `playerchoice_response` (`ChoiceId`, `ResponseId`, `Index`, `ChoiceArtFileId`, `Header`, `Answer`, `Description`, `Confirmation`, `VerifiedBuild`) VALUES (342, 887, 0, 1851148, 'Borean Tundra', 'Fly to Warsong Hold', 'Under the command of Garrosh Hellscream, the Warsong Offensive has established an outpost on the western shore of Northrend.\n\nTravel to Borean Tundra and show the Scourge the Horde\'s might.', '', 32535);
INSERT INTO `playerchoice_response` (`ChoiceId`, `ResponseId`, `Index`, `ChoiceArtFileId`, `Header`, `Answer`, `Description`, `Confirmation`, `VerifiedBuild`) VALUES (342, 852, 2, 1851107, 'Stonetalon Mountains', 'For the Horde!', 'The Alliance seek to control more territory in Kalimdor. This cannot happen. Suit up and report to Blood Guard Aldo Rockrain in Ashenvale.\n\nThe Warchief\'s eyes are upon you.', '', 32535);
INSERT INTO `playerchoice_response` (`ChoiceId`, `ResponseId`, `Index`, `ChoiceArtFileId`, `Header`, `Answer`, `Description`, `Confirmation`, `VerifiedBuild`) VALUES (342, 900, 0, 1851133, 'The Jade Forest', 'Report to Grommash Hold', 'A naval battle has erupted between the Alliance and Horde, with the Horde securing decisive victories.\n\nDestroy what remains of the weakened Alliance fleet.', '', 32535);
INSERT INTO `playerchoice_response` (`ChoiceId`, `ResponseId`, `Index`, `ChoiceArtFileId`, `Header`, `Answer`, `Description`, `Confirmation`, `VerifiedBuild`) VALUES (342, 900, 1, 1851133, 'The Jade Forest', 'Report to Grommash Hold', 'A naval battle has erupted between the Alliance and Horde, with the Horde securing decisive victories.\n\nDestroy what remains of the weakened Alliance fleet.', '', 32535);
INSERT INTO `playerchoice_response` (`ChoiceId`, `ResponseId`, `Index`, `ChoiceArtFileId`, `Header`, `Answer`, `Description`, `Confirmation`, `VerifiedBuild`) VALUES (342, 1013, 0, 1851147, 'Tanaan Jungle', 'Enter the Dark Portal', 'The Iron Horde are invading Azeroth!\n\nWe must stop them to save our world. For Azeroth!', '', 32535);
INSERT INTO `playerchoice_response` (`ChoiceId`, `ResponseId`, `Index`, `ChoiceArtFileId`, `Header`, `Answer`, `Description`, `Confirmation`, `VerifiedBuild`) VALUES (342, 1429, 0, 1851120, 'Broken Shore', 'Fight the Legion', 'The Burning Legion has returned to Azeroth!', '', 32535);
INSERT INTO `playerchoice_response` (`ChoiceId`, `ResponseId`, `Index`, `ChoiceArtFileId`, `Header`, `Answer`, `Description`, `Confirmation`, `VerifiedBuild`) VALUES (342, 900, 2, 1851133, 'The Jade Forest', 'Report to Grommash Hold', 'A naval battle has erupted between the Alliance and Horde, with the Horde securing decisive victories.\n\nDestroy what remains of the weakened Alliance fleet.', '', 32535);
INSERT INTO `playerchoice_response` (`ChoiceId`, `ResponseId`, `Index`, `ChoiceArtFileId`, `Header`, `Answer`, `Description`, `Confirmation`, `VerifiedBuild`) VALUES (342, 1429, 1, 1851120, 'Broken Shore', 'Fight the Legion', 'The Burning Legion has returned to Azeroth!', '', 32535);
INSERT INTO `playerchoice_response` (`ChoiceId`, `ResponseId`, `Index`, `ChoiceArtFileId`, `Header`, `Answer`, `Description`, `Confirmation`, `VerifiedBuild`) VALUES (342, 1013, 1, 1851147, 'Tanaan Jungle', 'Enter the Dark Portal', 'The Iron Horde are invading Azeroth!\n\nWe must stop them to save our world. For Azeroth!', '', 32535);
INSERT INTO `playerchoice_response` (`ChoiceId`, `ResponseId`, `Index`, `ChoiceArtFileId`, `Header`, `Answer`, `Description`, `Confirmation`, `VerifiedBuild`) VALUES (342, 1013, 2, 1851147, 'Tanaan Jungle', 'Enter the Dark Portal', 'The Iron Horde are invading Azeroth!\n\nWe must stop them to save our world. For Azeroth!', '', 32535);
INSERT INTO `playerchoice_response` (`ChoiceId`, `ResponseId`, `Index`, `ChoiceArtFileId`, `Header`, `Answer`, `Description`, `Confirmation`, `VerifiedBuild`) VALUES (342, 851, 2, 1851070, 'Ashenvale', 'Reinforce the Rampart', 'The might of Ashenvale is bearing down on our forces at the Mor\'shan Rampart.\n\nRepel the night elves and claim Ashenvale\'s resources for the Horde!', '', 32535);
INSERT INTO `playerchoice_response` (`ChoiceId`, `ResponseId`, `Index`, `ChoiceArtFileId`, `Header`, `Answer`, `Description`, `Confirmation`, `VerifiedBuild`) VALUES (342, 864, 1, 1851086, 'Silverpine Forest', 'Defeat the Gilneans', 'Guerilla forces sent by Gilneas continue to attack Horde outposts in Silverpine Forest.\n\nAssist the Forsaken and crush the Gilnean opposition.', '', 32535);
INSERT INTO `playerchoice_response` (`ChoiceId`, `ResponseId`, `Index`, `ChoiceArtFileId`, `Header`, `Answer`, `Description`, `Confirmation`, `VerifiedBuild`) VALUES (342, 868, 2, 1851080, 'Hillsbrad Foothills', 'Reclaim the Foothills', 'The Forsaken are continuing their campaign to conquer the Eastern Kingdoms for the Horde.\n\nAssist them with their operations in Hillsbrad.', '', 32535);
INSERT INTO `playerchoice_response` (`ChoiceId`, `ResponseId`, `Index`, `ChoiceArtFileId`, `Header`, `Answer`, `Description`, `Confirmation`, `VerifiedBuild`) VALUES (342, 847, 1, 1851071, 'Azshara', 'Defend Orgrimmar', 'The Alliance are attempting to reverse the efforts made by our forces in Azshara.\n\nPush them back!', '', 32535);
INSERT INTO `playerchoice_response` (`ChoiceId`, `ResponseId`, `Index`, `ChoiceArtFileId`, `Header`, `Answer`, `Description`, `Confirmation`, `VerifiedBuild`) VALUES (342, 853, 1, 1851087, 'Southern Barrens', 'Fortify the Barrens', 'The Southern Barrens belongs to the Horde, but recent Alliance victories are threatening our control of the land.\n\nShow them that this is our land, and we will defend it.', '', 32535);
INSERT INTO `playerchoice_response` (`ChoiceId`, `ResponseId`, `Index`, `ChoiceArtFileId`, `Header`, `Answer`, `Description`, `Confirmation`, `VerifiedBuild`) VALUES (342, 854, 1, 1851097, 'Desolace', 'Lend Aid to Desolace', 'The Alliance, the Burning Blade, and demons. We have many enemies, and they must be beat back so that the Horde can launch their campaign on Desolace.\n\nGo to Tethris Aran and speak with Furien.', '', 32535);
INSERT INTO `playerchoice_response` (`ChoiceId`, `ResponseId`, `Index`, `ChoiceArtFileId`, `Header`, `Answer`, `Description`, `Confirmation`, `VerifiedBuild`) VALUES (342, 873, 1, 1851103, 'The Hinterlands', 'Assist the Revantusk Tribe', 'One of our troll allies, the Revantusk tribe, are attempting to secure the Hinterlands for their people.\n\nHelp them with their goal. Show them they are not forgotten by the Horde.', '', 32535);
INSERT INTO `playerchoice_response` (`ChoiceId`, `ResponseId`, `Index`, `ChoiceArtFileId`, `Header`, `Answer`, `Description`, `Confirmation`, `VerifiedBuild`) VALUES (342, 887, 1, 1851148, 'Borean Tundra', 'Fly to Warsong Hold', 'Under the command of Garrosh Hellscream, the Warsong Offensive has established an outpost on the western shore of Northrend.\n\nTravel to Borean Tundra and show the Scourge the Horde\'s might.', '', 32535);
INSERT INTO `playerchoice_response` (`ChoiceId`, `ResponseId`, `Index`, `ChoiceArtFileId`, `Header`, `Answer`, `Description`, `Confirmation`, `VerifiedBuild`) VALUES (342, 888, 2, 1851153, 'Howling Fjord', 'Fly to Vengeance Landing', 'The Forsaken have established a beachhead on the shores of Howling Fjord named Vengeance Landing.\n\nFly to Howling Fjord and assist the Royal Apothecary Society in delivering a plague that will devour the Scourge.', '', 32535);
INSERT INTO `playerchoice_response` (`ChoiceId`, `ResponseId`, `Index`, `ChoiceArtFileId`, `Header`, `Answer`, `Description`, `Confirmation`, `VerifiedBuild`) VALUES (342, 881, 1, 1851116, 'Hellfire Peninsula', 'Travel to Outland', 'The Dark Portal has reopened and the Burning Legion is now positioned to attack Azeroth yet again.\n\nStop the demon filth from taking control of the Dark Portal and cutting off supplies to our forces in Hellfire Peninsula.', '', 32535);
INSERT INTO `playerchoice_response` (`ChoiceId`, `ResponseId`, `Index`, `ChoiceArtFileId`, `Header`, `Answer`, `Description`, `Confirmation`, `VerifiedBuild`) VALUES (342, 881, 2, 1851116, 'Hellfire Peninsula', 'Travel to Outland', 'The Dark Portal has reopened and the Burning Legion is now positioned to attack Azeroth yet again.\n\nStop the demon filth from taking control of the Dark Portal and cutting off supplies to our forces in Hellfire Peninsula.', '', 32535);
INSERT INTO `playerchoice_response` (`ChoiceId`, `ResponseId`, `Index`, `ChoiceArtFileId`, `Header`, `Answer`, `Description`, `Confirmation`, `VerifiedBuild`) VALUES (342, 887, 2, 1851148, 'Borean Tundra', 'Fly to Warsong Hold', 'Under the command of Garrosh Hellscream, the Warsong Offensive has established an outpost on the western shore of Northrend.\n\nTravel to Borean Tundra and show the Scourge the Horde\'s might.', '', 32535);


DELETE FROM `playerchoice_response_reward` WHERE `ChoiceId`=342;
INSERT INTO `playerchoice_response_reward` (`ChoiceId`, `ResponseId`, `TitleId`, `PackageId`, `SkillLineId`, `SkillPointCount`, `ArenaPointCount`, `HonorPointCount`, `Money`, `Xp`, `SpellId`, `VerifiedBuild`) VALUES (342, 1013, 0, 0, 0, 0, 0, 0, 0, 0, 176352, 0);
INSERT INTO `playerchoice_response_reward` (`ChoiceId`, `ResponseId`, `TitleId`, `PackageId`, `SkillLineId`, `SkillPointCount`, `ArenaPointCount`, `HonorPointCount`, `Money`, `Xp`, `SpellId`, `VerifiedBuild`) VALUES (342, 847, 0, 0, 0, 0, 0, 0, 0, 0, 257809, 0);
INSERT INTO `playerchoice_response_reward` (`ChoiceId`, `ResponseId`, `TitleId`, `PackageId`, `SkillLineId`, `SkillPointCount`, `ArenaPointCount`, `HonorPointCount`, `Money`, `Xp`, `SpellId`, `VerifiedBuild`) VALUES (342, 848, 0, 0, 0, 0, 0, 0, 0, 0, 258477, 0);
INSERT INTO `playerchoice_response_reward` (`ChoiceId`, `ResponseId`, `TitleId`, `PackageId`, `SkillLineId`, `SkillPointCount`, `ArenaPointCount`, `HonorPointCount`, `Money`, `Xp`, `SpellId`, `VerifiedBuild`) VALUES (342, 851, 0, 0, 0, 0, 0, 0, 0, 0, 258479, 0);
INSERT INTO `playerchoice_response_reward` (`ChoiceId`, `ResponseId`, `TitleId`, `PackageId`, `SkillLineId`, `SkillPointCount`, `ArenaPointCount`, `HonorPointCount`, `Money`, `Xp`, `SpellId`, `VerifiedBuild`) VALUES (342, 852, 0, 0, 0, 0, 0, 0, 0, 0, 258481, 0);
INSERT INTO `playerchoice_response_reward` (`ChoiceId`, `ResponseId`, `TitleId`, `PackageId`, `SkillLineId`, `SkillPointCount`, `ArenaPointCount`, `HonorPointCount`, `Money`, `Xp`, `SpellId`, `VerifiedBuild`) VALUES (342, 853, 0, 0, 0, 0, 0, 0, 0, 0, 258482, 0);
INSERT INTO `playerchoice_response_reward` (`ChoiceId`, `ResponseId`, `TitleId`, `PackageId`, `SkillLineId`, `SkillPointCount`, `ArenaPointCount`, `HonorPointCount`, `Money`, `Xp`, `SpellId`, `VerifiedBuild`) VALUES (342, 854, 0, 0, 0, 0, 0, 0, 0, 0, 258483, 0);
INSERT INTO `playerchoice_response_reward` (`ChoiceId`, `ResponseId`, `TitleId`, `PackageId`, `SkillLineId`, `SkillPointCount`, `ArenaPointCount`, `HonorPointCount`, `Money`, `Xp`, `SpellId`, `VerifiedBuild`) VALUES (342, 864, 0, 0, 0, 0, 0, 0, 0, 0, 258492, 0);
INSERT INTO `playerchoice_response_reward` (`ChoiceId`, `ResponseId`, `TitleId`, `PackageId`, `SkillLineId`, `SkillPointCount`, `ArenaPointCount`, `HonorPointCount`, `Money`, `Xp`, `SpellId`, `VerifiedBuild`) VALUES (342, 868, 0, 0, 0, 0, 0, 0, 0, 0, 258495, 0);
INSERT INTO `playerchoice_response_reward` (`ChoiceId`, `ResponseId`, `TitleId`, `PackageId`, `SkillLineId`, `SkillPointCount`, `ArenaPointCount`, `HonorPointCount`, `Money`, `Xp`, `SpellId`, `VerifiedBuild`) VALUES (342, 871, 0, 0, 0, 0, 0, 0, 0, 0, 258497, 0);
INSERT INTO `playerchoice_response_reward` (`ChoiceId`, `ResponseId`, `TitleId`, `PackageId`, `SkillLineId`, `SkillPointCount`, `ArenaPointCount`, `HonorPointCount`, `Money`, `Xp`, `SpellId`, `VerifiedBuild`) VALUES (342, 872, 0, 0, 0, 0, 0, 0, 0, 0, 258498, 0);
INSERT INTO `playerchoice_response_reward` (`ChoiceId`, `ResponseId`, `TitleId`, `PackageId`, `SkillLineId`, `SkillPointCount`, `ArenaPointCount`, `HonorPointCount`, `Money`, `Xp`, `SpellId`, `VerifiedBuild`) VALUES (342, 873, 0, 0, 0, 0, 0, 0, 0, 0, 258499, 0);
INSERT INTO `playerchoice_response_reward` (`ChoiceId`, `ResponseId`, `TitleId`, `PackageId`, `SkillLineId`, `SkillPointCount`, `ArenaPointCount`, `HonorPointCount`, `Money`, `Xp`, `SpellId`, `VerifiedBuild`) VALUES (342, 874, 0, 0, 0, 0, 0, 0, 0, 0, 258500, 0);
INSERT INTO `playerchoice_response_reward` (`ChoiceId`, `ResponseId`, `TitleId`, `PackageId`, `SkillLineId`, `SkillPointCount`, `ArenaPointCount`, `HonorPointCount`, `Money`, `Xp`, `SpellId`, `VerifiedBuild`) VALUES (342, 881, 0, 0, 0, 0, 0, 0, 0, 0, 258510, 0);
INSERT INTO `playerchoice_response_reward` (`ChoiceId`, `ResponseId`, `TitleId`, `PackageId`, `SkillLineId`, `SkillPointCount`, `ArenaPointCount`, `HonorPointCount`, `Money`, `Xp`, `SpellId`, `VerifiedBuild`) VALUES (342, 882, 0, 0, 0, 0, 0, 0, 0, 0, 258511, 0);
INSERT INTO `playerchoice_response_reward` (`ChoiceId`, `ResponseId`, `TitleId`, `PackageId`, `SkillLineId`, `SkillPointCount`, `ArenaPointCount`, `HonorPointCount`, `Money`, `Xp`, `SpellId`, `VerifiedBuild`) VALUES (342, 887, 0, 0, 0, 0, 0, 0, 0, 0, 258517, 0);
INSERT INTO `playerchoice_response_reward` (`ChoiceId`, `ResponseId`, `TitleId`, `PackageId`, `SkillLineId`, `SkillPointCount`, `ArenaPointCount`, `HonorPointCount`, `Money`, `Xp`, `SpellId`, `VerifiedBuild`) VALUES (342, 888, 0, 0, 0, 0, 0, 0, 0, 0, 258518, 0);
INSERT INTO `playerchoice_response_reward` (`ChoiceId`, `ResponseId`, `TitleId`, `PackageId`, `SkillLineId`, `SkillPointCount`, `ArenaPointCount`, `HonorPointCount`, `Money`, `Xp`, `SpellId`, `VerifiedBuild`) VALUES (342, 900, 0, 0, 0, 0, 0, 0, 0, 0, 258531, 0);
INSERT INTO `playerchoice_response_reward` (`ChoiceId`, `ResponseId`, `TitleId`, `PackageId`, `SkillLineId`, `SkillPointCount`, `ArenaPointCount`, `HonorPointCount`, `Money`, `Xp`, `SpellId`, `VerifiedBuild`) VALUES (342, 1429, 0, 0, 0, 0, 0, 0, 0, 0, 281351, 0);
