DELETE FROM `creature_queststarter` WHERE `id`=46458 AND `quest`=25732;
INSERT INTO `creature_queststarter` (`id`, `quest`) VALUES (46458, 25732);
DELETE FROM `creature_loot_template` WHERE `entry`=41018 AND `item`=55805;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`, `shared`) VALUES (41018, 55805, 99.5616, 1, 0, 1, 1, 0);
