/*
 Navicat Premium Data Transfer

 Source Server         : sy4
 Source Server Type    : MySQL
 Source Server Version : 80011
 Source Host           : localhost:3306
 Source Schema         : sy4_flight

 Target Server Type    : MySQL
 Target Server Version : 80011
 File Encoding         : 65001

 Date: 03/09/2023 23:14:37
*/

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for flight
-- ----------------------------
DROP TABLE IF EXISTS `flight`;
CREATE TABLE `flight`  (
  `fid` int(11) NOT NULL AUTO_INCREMENT,
  `flight_num` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL COMMENT '航班号（名）',
  `flight_date` date NOT NULL COMMENT '航班日期',
  `departure_city` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '起飞城市',
  `arrival_city` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '到达城市',
  `departure_time` datetime(0) NULL DEFAULT NULL COMMENT '起飞时间',
  `arrival_time` datetime(0) NULL DEFAULT NULL COMMENT '到达时间',
  `ticket_price` int(11) NULL DEFAULT NULL COMMENT '票价',
  `ticket_left` int(11) NULL DEFAULT NULL COMMENT '余票',
  PRIMARY KEY (`fid`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 5 CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of flight
-- ----------------------------
INSERT INTO `flight` VALUES (3, 'CA1916', '2023-07-17', '郑州', '北京', '2023-07-25 09:20:00', '2023-07-25 13:00:00', 819, 99);
INSERT INTO `flight` VALUES (4, 'CA1913', '2023-07-06', '北京', '郑州', '2023-07-25 14:55:00', '2023-07-25 16:45:00', 947, 76);

-- ----------------------------
-- Table structure for flightorder
-- ----------------------------
DROP TABLE IF EXISTS `flightorder`;
CREATE TABLE `flightorder`  (
  `oid` varchar(100) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `order_time` datetime(0) NULL DEFAULT NULL COMMENT '下单时间',
  `order_amount` int(11) NULL DEFAULT NULL COMMENT '订单金额',
  `order_status` int(11) NULL DEFAULT NULL COMMENT '订单状态 1未完成  2 已完成 3 已取消',
  `username` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '下单用户',
  `fid` int(11) NULL DEFAULT NULL COMMENT '航班id',
  `pid` int(11) NULL DEFAULT NULL COMMENT '乘客id',
  PRIMARY KEY (`oid`) USING BTREE,
  INDEX `username`(`username`) USING BTREE,
  INDEX `fid`(`fid`) USING BTREE,
  INDEX `pid`(`pid`) USING BTREE,
  CONSTRAINT `flightorder_ibfk_1` FOREIGN KEY (`username`) REFERENCES `user_ft` (`username`) ON DELETE RESTRICT ON UPDATE RESTRICT,
  CONSTRAINT `flightorder_ibfk_2` FOREIGN KEY (`fid`) REFERENCES `flight` (`fid`) ON DELETE RESTRICT ON UPDATE RESTRICT,
  CONSTRAINT `flightorder_ibfk_3` FOREIGN KEY (`pid`) REFERENCES `passenger_ft` (`pid`) ON DELETE RESTRICT ON UPDATE RESTRICT
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of flightorder
-- ----------------------------
INSERT INTO `flightorder` VALUES ('071a7a660c8641a7a081b4c6fabdad37', '2023-07-21 11:04:24', 819, 3, 'Jerry', 3, 10);
INSERT INTO `flightorder` VALUES ('122c3f144dcf45e1a0bfda8b34ca05ac', '2023-07-21 11:02:45', 819, 3, 'Jerry', 3, 10);
INSERT INTO `flightorder` VALUES ('16e018160c1e40da99bb245428262052', '2023-07-22 12:58:30', 819, 3, 'Jerry', 3, 8);
INSERT INTO `flightorder` VALUES ('1d45202802d946cf9f210e4e48554204', '2023-07-21 11:01:30', 819, 3, 'Jerry', 3, 8);
INSERT INTO `flightorder` VALUES ('2456f74321be4c41be054c9c038f84a0', '2023-07-21 16:16:22', 819, 3, 'Jerry', 3, 9);
INSERT INTO `flightorder` VALUES ('3e1bc603f9c34587a1b07dc16eaa3e7d', '2023-07-21 16:43:20', 819, 1, 'Jerry', 3, 8);
INSERT INTO `flightorder` VALUES ('5aa92710773a40f4afed7860e34878b8', '2023-07-21 11:04:24', 819, 1, 'Jerry', 3, 10);
INSERT INTO `flightorder` VALUES ('64559e2d0c864ec8a517e81aa2af2562', '2023-07-21 16:27:56', 819, 1, 'Jerry', 3, 9);
INSERT INTO `flightorder` VALUES ('aaa9d0f6a46c49c3a9f99f2a76d7d586', '2023-07-21 12:17:18', 819, 1, 'Jerry', 3, 8);
INSERT INTO `flightorder` VALUES ('bf32526be48e4862975f9972638a6739', '2023-09-03 22:55:40', 819, 1, 'Jerry', 3, 9);
INSERT INTO `flightorder` VALUES ('dbdb414aea094a01aa91271ee014f571', '2023-07-21 16:39:46', 819, 1, 'Jerry', 3, 8);
INSERT INTO `flightorder` VALUES ('df05e516b6044dada6b2ba383e05eaa4', '2023-07-21 16:26:20', 819, 1, 'Jerry', 3, 10);
INSERT INTO `flightorder` VALUES ('e4f84f65e4ba4f31a640bb8ca19db011', '2023-07-21 16:44:59', 819, 1, 'Jerry', 3, 8);
INSERT INTO `flightorder` VALUES ('f105b6f060f24027bcf0d15f62fc1c85', '2023-07-21 11:04:24', 819, 1, 'Jerry', 3, 10);

-- ----------------------------
-- Table structure for passenger_ft
-- ----------------------------
DROP TABLE IF EXISTS `passenger_ft`;
CREATE TABLE `passenger_ft`  (
  `pid` int(11) NOT NULL AUTO_INCREMENT COMMENT '乘客编号',
  `pname` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `cardnum` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `phone` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `username` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '外键',
  `add_time` date NULL DEFAULT NULL COMMENT '添加日期',
  `status` int(11) NULL DEFAULT NULL COMMENT '0待审核 1已通过',
  PRIMARY KEY (`pid`) USING BTREE,
  INDEX `username`(`username`) USING BTREE,
  CONSTRAINT `passenger_ft_ibfk_1` FOREIGN KEY (`username`) REFERENCES `user_ft` (`username`) ON DELETE RESTRICT ON UPDATE RESTRICT
) ENGINE = InnoDB AUTO_INCREMENT = 10 CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of passenger_ft
-- ----------------------------
INSERT INTO `passenger_ft` VALUES (1, '张三', '411420200305081234', '18236000000', 'Jerry', NULL, 0);
INSERT INTO `passenger_ft` VALUES (2, '张三1', '411420200305081235', '18236000001', 'Jerry', NULL, 0);
INSERT INTO `passenger_ft` VALUES (3, '张三2', '411421199902126069', '18236980002', 'Jerry', NULL, 0);
INSERT INTO `passenger_ft` VALUES (4, '张三3', '411421199806051259', '18236980003', 'Jerry', NULL, 0);
INSERT INTO `passenger_ft` VALUES (5, '张三4', '411421199806051260', '18236980004', 'Jerry', NULL, 0);
INSERT INTO `passenger_ft` VALUES (6, '张三5', '4111111111111111111', '18222222222', 'Jerry', NULL, 0);
INSERT INTO `passenger_ft` VALUES (7, 'ls1', '412000198912054568', '18200000005', 'ls', NULL, 0);
INSERT INTO `passenger_ft` VALUES (8, '张三', '411421199902126068', '18236980140', 'Jerry', '2023-07-20', 1);
INSERT INTO `passenger_ft` VALUES (9, '张三', '411421199902126061', '18236980141', 'Jerry', '2023-07-20', 1);
INSERT INTO `passenger_ft` VALUES (10, '张三', '411421199902126062', '18236980143', 'Jerry', '2023-07-20', 1);

-- ----------------------------
-- Table structure for user_ft
-- ----------------------------
DROP TABLE IF EXISTS `user_ft`;
CREATE TABLE `user_ft`  (
  `username` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `password` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `balance` float NULL DEFAULT NULL COMMENT '余额',
  PRIMARY KEY (`username`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of user_ft
-- ----------------------------
INSERT INTO `user_ft` VALUES ('Jerry', '123456', 4000);
INSERT INTO `user_ft` VALUES ('ls', '123456', 4000);
INSERT INTO `user_ft` VALUES ('Lucy', '123456', 4000);
INSERT INTO `user_ft` VALUES ('mazi', '123456', 4000);
INSERT INTO `user_ft` VALUES ('Mr.halou', '123456', 4000);
INSERT INTO `user_ft` VALUES ('Mr.sun', '123456', 4000);
INSERT INTO `user_ft` VALUES ('Tom', '123456', 1234);
INSERT INTO `user_ft` VALUES ('ww', '123456', 1000);
INSERT INTO `user_ft` VALUES ('zhangsan', '123456', 2682);
INSERT INTO `user_ft` VALUES ('铁锤', '123456', 1234);

SET FOREIGN_KEY_CHECKS = 1;
