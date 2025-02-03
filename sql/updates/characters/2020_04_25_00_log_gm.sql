/*
Navicat MySQL Data Transfer

Source Server         : Local
Source Server Version : 50505
Source Host           : localhost:3306
Source Database       : origins_characters

Target Server Type    : MYSQL
Target Server Version : 50505
File Encoding         : 65001

Date: 2020-04-27 21:45:57
*/

SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for log_gm
-- ----------------------------
DROP TABLE IF EXISTS `log_gm`;
CREATE TABLE `log_gm` (
  `id` bigint(20) unsigned NOT NULL AUTO_INCREMENT,
  `date` datetime DEFAULT NULL,
  `gm_account_id` bigint(20) DEFAULT NULL,
  `gm_account_name` text,
  `gm_character_id` bigint(20) DEFAULT NULL,
  `gm_character_name` text,
  `gm_ip` text,
  `target_account_id` bigint(20) DEFAULT NULL,
  `target_account_name` text,
  `target_character_id` bigint(20) DEFAULT NULL,
  `target_character_name` text,
  `target_ip` text,
  `command` text,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=17781 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of log_gm
-- ----------------------------
