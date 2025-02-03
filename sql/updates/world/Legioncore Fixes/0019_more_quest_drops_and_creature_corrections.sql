-- Fix loot chance for the following quest items
-- 2855 = Putrid Claw
-- 2858 = Darkhound Blood
-- 3264 = Duskbat Wing
-- 3265 = Scavenger Paw
-- 3901 = Bloodscalp Tusk
-- 3905 = Nezzliok's Head
-- 3924 = Maury's Clubbed Foot
-- 3935 = Smotts' Cutlass
-- 4053 = Large River Crocolisk Skin
-- 4435 = Mote of Myzrael
-- 4440 = Sigil of Strom
-- 4450 = Sigil Fragment
-- 4510 = Befouled Bloodstone Orb
-- 4512 = Highland Raptor Eye
-- 4513 = Raptor Heart
-- 4525 = Trelane's Wand of Invocation
-- 4527 = Azure Agate
-- 4551 = Or'Kalar's Head
-- 4751 = Windfury Talon
-- 4752 = Azure Feather
-- 4753 = Bronze Feather
-- 4758 = Prairie Wolf Paw
-- 4759 = Plainstrider Talon
-- 4769 = Trophy Swoop Quill
-- 4801 = Stalker Claws
-- 4802 = Cougar Claws
-- 4803 = Prairie Alpha Tooth
-- 4805 = Flatland Cougar Femur
-- 4819 = Fizsprocket's Clipboard (Supposed to be quest only)
-- 4871 = Searing Collar
-- 4888 = Crawler Mucus
-- 5084 = Cap'n Garvey's Head
-- 5087 = Plainstrider Beak
-- 5203 = Flatland Prowler Claw
-- 5830 = Kenata's Head
-- 5831 = Fardel's Head
-- 5832 = Marcel's Head
-- 6212 = Head of Jammal'an
-- 20482 = Arcane Sliver
-- 20483 = Tainted Arcane Sliver
-- 20760 = Chieftain Zul'Marosh's Head
-- 20764 = Prospector Anvilward's Head
-- 20772 = Springpaw Pelt
-- 20797 = Lynx Collar
-- 20799 = Felendren's Head
-- 21757 = Grimscale Murloc Head
-- 21771 = Captain Kelisendra's Cargo
-- 21776 = Captain Kelisendra's Lost Rutters
-- 21781 = Thaelis' Head
-- 21808 = Arcane Core
-- 22566 = Phantasmal Substance
-- 22567 = Gargoyle Fragment
-- 22570 = Plagued Blood Sample
-- 22579 = Plagued Murloc Spine
-- 22580 = Crystallized Mana Essence
-- 22597 = The Lady's Necklace
-- 22633 = Troll Juju
-- 22634 = Underlight Ore
-- 22639 = Zeb'Sora Troll Ear
-- 22640 = Head of Kel'gash the Wicked
-- 22641 = Rotting Heart (Not supposed to be quest only, it is a repeatable quest)
-- 22642 = Spinal Dust (Not supposed to be quest only, it is a repeatable quest)
-- 22653 = Dar'Khan's Head
-- 22677 = Catlord Claws
-- 22893 = Luzran's Head
-- 22894 = Knucklerot's Head
-- 23165 = Headhunter Axe
-- 23166 = Hexxer Stave
-- 23167 = Shadowcaster Mace
-- 23191 = Crystal Controlling Orb
-- 23249 = Amani Invasion Plans
-- 23269 = Felblood Sample
-- 23387 = Bonestripper Tail Feather
-- 23483 = Haal'eshi Scroll
-- 23679 = Bloodscalp Totem
-- 23707 = Spindleweb Silk Gland
-- 24469 = Muck-Ridden Core
-- 24473 = Enraged Crusher Core
-- 24496 = Horn of Banthar
-- 24502 = Warmaul Skull
-- 24503 = Gurok's Earthen Head
-- 24504 = Howling Wind
-- 24505 = Heart of Tusker
-- 24523 = Hoof of Bach'lor
-- 25433 = Obsidian Warbeads
-- 25463 = Pair of Ivory Tusks
-- 25468 = Boulderfist Plans
-- 24558 = Murkblood Invasion Plans (Horde)
-- 24559 = Murkblood Invasion Plans (Alliance)
-- 25416 = Oshu'gun Crystal Fragment
-- 25590 = Head of Cho'war
-- 25648 = Cho'war's Key
-- 25770/25771 = Fel Cannon Activator
-- 27807 = Air Elemental Gas
-- 27841 = Severed Talon of the Matriarch
-- 28562 = Unyielding Battle Horn
-- 29051 = Warp Nether
-- 29113 = Demonic Essence
-- 29162 = Galaxis Soul Shard
-- 29586 = Head of Forgefiend Razorsaw
-- 31374 = Worg Master's Head
-- 31529 = Grillok's Eyepatch
-- 33330 = Ingvar's Head
-- 46850 = King Reaperclaw's Horn
-- 47038 = Slab of Venison
-- 47039 = Scout's Orders
-- 47819 = Crystal Pendant
-- 49068 = Pristine Thunderhead Feather
-- 49204 = Secret Rocket Plans
-- 49208 = Mutilated Mistwing Carcass
-- 49356 = Amberwind's Journal
-- 49359 = Attuned Runestone
-- 49364 = Blackmaw Intelligence
-- 49365 = Briaroot Brew (was positive)
-- 49366 = Ambassador's Robes
-- 49533 = Ironwrought Key
-- 49535 = Stolen Rifle
-- 49540 = Grunwald's Head
-- 49674 = The Head of Jarrodenus
-- 50018 = Naj'tess' Orb of Corruption
-- 50222 = Wildmane Cat Pelt
-- 50473 = Mane of Thornmantle
-- 52080 = Fresh Crawler Meat
-- 52564 = Burning Blade Spellscroll
-- 57758 = Swine Belly
-- 57879 = Horde Infantry Rations
-- 59034 = Fitztittle's Ratcheting Torque Wrench
-- 59035 = Ephram's Jeweled Mirror
-- 59143 = Weather-Beaten Coin
-- 60270 = Icon of Tsul'Kalu
-- 60271 = Icon of Mahamba
-- 60272 = Icon of Pogeyan
-- 60874 = Deathless Sinew
-- 60875 = Ghostly Essence
-- 60878 = Silverlaine's Enchanted Crystal
-- 60880 = Springvale's Sharpening Stone
-- 62714 = Duskfang's Hide
-- 64386 = Yetimus' Twisted Horn
-- 72071 = Stolen Training Supplies
-- 82605 = Corrupted Insignia
-- 87267 = Codex of the Crusade
DELETE FROM `creature_loot_template` WHERE NOT `entry` = 2959 AND `item` = 4801;
DELETE FROM `creature_loot_template` WHERE NOT `entry` = 2960 AND `item` = 4803;
DELETE FROM `creature_loot_template` WHERE `entry` = 16346 AND `item` = 22677;
DELETE FROM `creature_loot_template` WHERE `entry` IN (16348, 16469) AND `item` = 23165;
DELETE FROM `creature_loot_template` WHERE `entry` = 16345 AND `item` = 23166;
DELETE FROM `creature_loot_template` WHERE `entry` IN (16344, 16348) AND `item` = 23167;
DELETE FROM `creature_loot_template` WHERE NOT `entry` = 16951 AND `item` = 23269;
DELETE FROM `creature_loot_template` WHERE NOT `entry` IN (16966, 16967, 17084) AND `item` = 23483;
DELETE FROM `creature_loot_template` WHERE NOT `entry` = 16978 AND `item` = 28562;
DELETE FROM `creature_loot_template` WHERE NOT `entry` = 17058 AND `item` = 29113;
DELETE FROM `creature_loot_template` WHERE NOT `entry` = 20798 AND `item` = 29586;
DELETE FROM `creature_loot_template` WHERE NOT `entry` = 19442 AND `item` = 31374;
DELETE FROM `creature_loot_template` WHERE `entry` = 3117 AND `item` = 47039;
DELETE FROM `creature_loot_template` WHERE NOT `entry` IN (3195, 3196, 3197, 3198, 3199) AND `item` = 52564;
DELETE FROM `creature_loot_template` WHERE NOT `entry` IN (17158, 17159, 17160) AND `item` = 24504;
DELETE FROM `creature_loot_template` WHERE NOT `entry` IN (17158, 17159, 17160) AND `item` = 27807;
DELETE FROM `creature_loot_template` WHERE `entry` = 19201 AND `item` = 24502;
DELETE FROM `creature_loot_template` WHERE NOT `entry` = 18334 AND `item` = 25463;
DELETE FROM `creature_loot_template` WHERE NOT `entry` = 18062 AND `item` = 24473;
DELETE FROM `creature_loot_template` WHERE NOT `entry` = 17149 AND `item` = 25416;
DELETE FROM `creature_loot_template` WHERE `entry` IN (18440, 19201) AND `item` = 25433;
DELETE FROM `creature_loot_template` WHERE `entry` = 18062 AND `item` = 24469;

UPDATE `creature_loot_template` SET `ChanceOrQuestChance` = -100 WHERE `item` IN (3905, 3924, 4510, 4525, 4527, 4551, 4769, 4801, 4802, 4805, 4819, 5084, 5830, 5831, 5832, 6212, 20483, 20760, 20764, 20797, 20799, 21781, 21808, 22566, 22640, 22653, 22893, 22894, 23679, 23707, 24496, 24503, 24505, 24523, 25468, 25590, 25648, 25770, 25771, 27841, 28562, 29051, 29162, 29586, 31374, 31529, 33330, 46850, 49204, 49356, 49366, 49535, 49540, 49674, 50018, 50222, 50473, 52080, 57758, 59034, 59035, 60878, 60880, 62714, 64386, 72071, 87267);
UPDATE `creature_loot_template` SET `ChanceOrQuestChance` = -90 WHERE `item` IN (2855, 3264, 3265, 4751, 4752, 4753, 49359);
UPDATE `creature_loot_template` SET `ChanceOrQuestChance` = -80 WHERE `item` IN (3901, 4435, 4512, 4513, 4758, 4759, 4803, 4871, 4888, 5087, 5203, 22570, 22579, 22580, 22633, 22634, 22677, 23165, 23166, 23167, 24473, 27807, 49068, 49208, 52564, 82605);
UPDATE `creature_loot_template` SET `ChanceOrQuestChance` = -70 WHERE `item` IN (20482, 22567, 47038);
UPDATE `creature_loot_template` SET `ChanceOrQuestChance` = -50 WHERE `item` IN (4440, 4053, 20772, 21757, 21771, 22639, 29113, 49364, 49365, 60874, 60875);
UPDATE `creature_loot_template` SET `ChanceOrQuestChance` = -40 WHERE `item` IN (23387, 24469, 49533);
UPDATE `creature_loot_template` SET `ChanceOrQuestChance` = -35 WHERE `item` IN (2858, 4450, 23269);
UPDATE `creature_loot_template` SET `ChanceOrQuestChance` = -30 WHERE `item` = 24502;
UPDATE `creature_loot_template` SET `ChanceOrQuestChance` = -20 WHERE `item` IN (23191, 47039, 47819, 60270, 60271, 60272);
UPDATE `creature_loot_template` SET `ChanceOrQuestChance` = -15 WHERE `item` = 23483;
UPDATE `creature_loot_template` SET `ChanceOrQuestChance` = 100 WHERE `item` IN (3935, 23249, 24558, 24559, 25463, 59143);
UPDATE `creature_loot_template` SET `ChanceOrQuestChance` = 50 WHERE `item` IN (25416, 25433);
UPDATE `creature_loot_template` SET `ChanceOrQuestChance` = 25 WHERE `item` = 24504;
UPDATE `creature_loot_template` SET `ChanceOrQuestChance` = 10 WHERE `item` IN (21776, 22597);

UPDATE `creature_loot_template` SET `ChanceOrQuestChance` = 50 WHERE `entry` = 16301 AND `item` = 22641;
UPDATE `creature_loot_template` SET `ChanceOrQuestChance` = 70 WHERE `entry` = 16302 AND `item` = 22641;
UPDATE `creature_loot_template` SET `ChanceOrQuestChance` = 30 WHERE `entry` = 16303 AND `item` = 22642;
UPDATE `creature_loot_template` SET `ChanceOrQuestChance` = 70 WHERE `entry` = 16305 AND `item` = 22642;
UPDATE `creature_loot_template` SET `ChanceOrQuestChance` = 20 WHERE `entry` = 16307 AND `item` = 22642;
UPDATE `creature_loot_template` SET `ChanceOrQuestChance` = 40 WHERE `entry` = 16308 AND `item` = 22642;

-- TODO Fix when loot system is fixed!
UPDATE `creature_loot_template` SET `ChanceOrQuestChance` = 100 WHERE `item` = 57879;

-- Fix loot chance for the following game objects
-- 2846 = Tirisfal Pumpkin
-- 3906 = Balia'mah Trophy
-- 3907 = Ziata'jai Trophy
-- 3920 = Bloodsail Charts
-- 4492 = Elven Gem
-- 4530 = Trelane's Phylactery
-- 4531 = Trelane's Orb
-- 4532 = Trelane's Ember Agate
-- 4863 = Gnomish Tools
-- 4918 = Sack of Supplies
-- 5012 = Fungal Spores
-- 12708 = Crossroads Supply Crate
-- 20743 = Unstable Mana Crystal
-- 20771 = Tainted Soil Sample
-- 22413 = Sin'dorei Armaments
-- 22414 = Antheol's Elemental Grimoire
-- 22583 = Rathis Tomber's Supplies
-- 22590 = Night Elf Plans: An'daroth
-- 22591 = Night Elf Plans: An'owyn
-- 22592 = Night Elf Plans: Scrying on the Sin'dorei
-- 22598 = Stone of Light
-- 22599 = Stone of Flame
-- 22674 = Wavefront Medallion
-- 24419 = Digested Caracoli
-- 25416 = Oshu'gun Crystal Fragment
-- 25554 = Kil'sorrow Armaments
-- 45004 = Serviceable Arrow
-- 46742 = Stolen Grain
-- 48128 = Mountainfoot Iron
-- 48525 = Recovered Artifacts
-- 48921 = Sarcen Stone
-- 49012 = Abjurer's Manual
-- 49036 = Animate Basalt
-- 49062 = Goblin Mortar Shell
-- 49082 = Living Ire Thyme
-- 49094 = Keystone Shard
-- 49162 = Kawphi Bean
-- 49207 = Azsharite Sample
-- 49365 = Briaroot Brew (was positive)
-- 49367 = Blackmaw Meeting Agenda
-- 49642 = Heart of Arkkoroc
-- 52558 = Kul Tiras Treasure
-- 58877 = Naga Icon
-- 59145 = Bloodsail Orders
-- 59151 = Bloodsail Cannonball
-- 60386 = Pure Water
-- 60871 = Moontouched Wood
-- 60872 = Moonsteel Ingots
-- 64581 = Corpse-Stitching Twine
-- 64582 = Thick Embalming Fluid
-- 69919 = Plump Cockroach
-- 69988 = Pine Nut
DELETE FROM `creature_loot_template` WHERE `item` IN (48128, 49642);

UPDATE `gameobject_loot_template` SET `ChanceOrQuestChance` = -100 WHERE `item` IN (2846, 3906, 3907, 3920, 4492, 4530, 4531, 4532, 4863, 4918, 5012, 12708, 20743, 20771, 22413, 22414, 22583, 22590, 22591, 22592, 22598, 22599, 22674, 24419, 25416, 25554, 45004, 46742, 48128, 48525, 48921, 49012, 49036, 49062, 49082, 49094, 49162, 49207, 49365, 49367, 49642, 52558, 58877, 59145, 59151, 60386, 60871, 60872, 64581, 64582, 69919);
UPDATE `gameobject_loot_template` SET `ChanceOrQuestChance` = -100, `mincountOrRef` = 5, `maxcount` = 5 WHERE `item` = 69988;

-- Fix broken "Lily, Oh Lily" quest (can't loot the lillies)
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 4 AND `SourceEntry` = 69917;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(4, 208833, 69917, 0, 0, 9, 0, 29332, 0, 0, 0, 0, '', '');

UPDATE `gameobject_template` SET `type` = 3 WHERE `entry` = 208833;

-- Fix broken "Kasha Will Fly Again" quest (can't loot the mushrooms)
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 4 AND `SourceEntry` = 3502;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(4, 1723, 3502, 0, 0, 9, 0, 28354, 0, 0, 0, 0, '', '');

UPDATE `gameobject_template` SET `type` = 3 WHERE `entry` = 1723;

-- Fix broken "Burstcap Mushrooms, Mon!" quest (can't loot the mushrooms)
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 4 AND `SourceEntry` = 24468;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(4, 182095, 24468, 0, 0, 9, 0, 9814, 0, 0, 0, 0, '', '');

UPDATE `gameobject_template` SET `type` = 3 WHERE `entry` = 182095;

-- Fix loot chance for the following quest items (from fishing)
-- 58951 = Giant Furious Pike
-- 69901 = Severed Abomination Head
UPDATE `fishing_loot_template` SET `ChanceOrQuestChance` = -10 WHERE `item` = 69901;

-- Fix NPCs that incorrectly aggressively attack the player
-- 44112 = Airwyn Bantamflax
-- 44866 = Auctioneer Drezmit
UPDATE `creature_template` SET `flags_extra` = 2 WHERE `entry` IN (44112, 44866);

-- Fix creature level scaling
-- 6118 = Varo'then's Ghost
-- 17207 = Naias
-- 35558 = Ectoplasmic Exhaust
-- 36130 = Scalding Water Lord
-- 36156 = Mutant Goblin
-- 36822 = Lord Kassarus
UPDATE `creature_template` SET `minlevel` = 25, `maxlevel` = 25, `ScaleLevelMin` = 25, `ScaleLevelMax` = 60 WHERE `entry` = 17207;
UPDATE `creature_template` SET `minlevel` = 10, `maxlevel` = 10, `ScaleLevelMin` = 10, `ScaleLevelMax` = 60 WHERE `entry` IN (6118, 35558, 36130, 36156, 36822);

-- Fix creatures that should not give XP
-- 35296 = Explosives Stockpile
UPDATE `creature_template` SET `flags_extra` = 64 WHERE `entry` = 35296;

-- Remove duplicate creatures (by GUID)
-- 39819 = Gomegaz
-- 126040 = Zaeldarr the Outcast
DELETE FROM `creature` WHERE `guid` IN (39819, 126040);

-- Remove/update horribly placed or problematic creatures (by GUID)
-- 40335 = Bloodwash Enchantress (right next to quest giver by no others of its kind)
-- 40336 = Neptool (in a terrible spot, looks like he's forever falling/swimming)
-- 88399 = Deadwind Widow (only spider in Stonard, too close to flight master)
DELETE FROM `creature` WHERE `guid` IN (40335, 88399);

UPDATE `creature` SET `position_x` = -12036.07, `position_y` = -3789.83, `position_z` = 26.3827, `orientation` = 0.4514 WHERE `guid` = 40336;

-- Fix game event start time
-- 14 = Stranglethorn Fishing Extravaganza Announce
-- 15 = Stranglethorn Fishing Extravaganza Fishing Pools
-- 62 = Stranglethorn Fishing Extravaganza Turn-ins
UPDATE `game_event` SET `start_time` = '2016-10-29 00:00:00', `length` = 1440 WHERE `eventEntry` = 14;
UPDATE `game_event` SET `start_time` = '2016-10-30 14:00:00' WHERE `eventEntry` IN (15, 62);