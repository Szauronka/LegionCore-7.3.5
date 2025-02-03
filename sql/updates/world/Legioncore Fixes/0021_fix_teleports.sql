-- Fix existing teleport locations
DELETE FROM `game_tele` WHERE `name` IN ('CampNarache', 'Valormok', 'Sorrowmurk');
INSERT INTO `game_tele` (`id`, `position_x`, `position_y`, `position_z`, `orientation`, `map`, `name`) VALUES
(188, -2895.67, -247.76, 59.809, 4.0043, 1, 'CampNarache'),
(1280, 3006.65, -4151.15, 101.810, 2.5073, 1, 'Valormok'),
(899, -10204.53, -4182.26, 22.356, 4.3773, 0, 'Sorrowmurk');

-- Insert missing teleport locations (do not include id column)
DELETE FROM `game_tele` WHERE `name` IN ('Bogpaddle', 'HallOfMasks', 'ChamberOfBlood', 'TheButchery', 'HallOfBones');
INSERT INTO `game_tele` (`position_x`, `position_y`, `position_z`, `orientation`, `map`, `name`) VALUES
(-9761.64, -3918.13, 21.644, 1.5467, 0, 'Bogpaddle'),
(-10279.31, -3941.60, -70.849, 4.4575, 0, 'HallOfMasks'),
(-10346.10, -3903.84, -99.565, 4.4394, 0, 'ChamberOfBlood'),
(-10290.61, -4030.86, -76.550, 2.8293, 0, 'TheButchery'),
(-10237.99, -4021.33, -110.078, 1.1305, 0, 'HallOfBones');

-- Delete duplicate locations
-- 1175 = TheTempleOfAtalHakkar
DELETE FROM `game_tele` WHERE `id` = 1175;

-- Update existing teleport names
-- 991 = TempleOfAtalHakkar
UPDATE `game_tele` SET `name` = 'TheTempleOfAtalHakkar' WHERE `id` = 991;