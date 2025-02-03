SET 
@entry := 800500,
@name := 'Teleport to Imonar',
@iconname := 'openhandglow',
@displayid := 8632,
@spell := 199249,
@map := 1712,
@x := -10574.159,
@y := 8771.274,
@z := 1871.464,
@o := 4.741;

INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `faction`, `flags`, `size`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `unkInt32`, `AIName`, `ScriptName`, `WorldEffectID`, `StateWorldEffectID`, `SpellVisualID`, `SpellStateVisualID`, `SpellStateAnimID`, `SpellStateAnimKitID`, `MaxVisible`, `IgnoreDynLos`, `MinGold`, `MaxGold`, `VerifiedBuild`) 
VALUES (@entry, 10, @displayid, @name, @iconname, '', '', 0, 32, 1, 0, 0, 0, 0, 0, 0, 0, 0, @entry, 3000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'SmartGameObjectAI', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 16357);

INSERT INTO `event_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) 
VALUES (@entry, 0, 6, @map, 0, 0, @x, @y, @z, @o);

INSERT INTO `event_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) 
VALUES (@entry, 0, 15, @spell, 1, 0, 0, 0, 0, 0);