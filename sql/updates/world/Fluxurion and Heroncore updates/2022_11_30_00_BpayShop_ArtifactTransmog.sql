DELETE FROM `battlepay_display_info` WHERE `DisplayInfoId`=1007;
INSERT INTO `battlepay_display_info` (`DisplayInfoId`, `CreatureDisplayInfoID`, `FileDataID`, `Flags`, `Name1`, `Name2`, `Name3`, `Name4`) VALUES (1007, 1112940, 0, 0, 'Artifact Appearances', '', 'Unlock almost all artifact appearance!', '');
DELETE FROM `battlepay_product` WHERE `ProductID`=1007;
INSERT INTO `battlepay_product` (`ProductID`, `NormalPriceFixedPoint`, `CurrentPriceFixedPoint`, `Type`, `ChoiceType`, `Flags`, `DisplayInfoID`, `ScriptName`, `ClassMask`, `WebsiteType`) VALUES (1007, 500, 300, 0, 2, 0, 1007, '', 0, 31);
DELETE FROM `battlepay_product_item` WHERE `ID`=1007;
INSERT INTO `battlepay_product_item` (`ID`, `ProductID`, `ItemID`, `Quantity`, `DisplayID`, `PetResult`) VALUES (1007, 1007, 0, 1, 0, 0);
DELETE FROM `battlepay_shop_entry` WHERE `EntryID`=1007;
INSERT INTO `battlepay_shop_entry` (`EntryID`, `GroupID`, `ProductID`, `Ordering`, `Flags`, `BannerType`, `DisplayInfoID`) VALUES (1007, 20, 1007, 1, 0, 0, 0);
