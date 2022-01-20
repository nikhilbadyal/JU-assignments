-- MySQL dump 10.13  Distrib 8.0.23, for Win64 (x86_64)
--
-- Host: localhost    Database: assignment02
-- ------------------------------------------------------
-- Server version	8.0.23

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `department`
--

DROP TABLE IF EXISTS `department`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `department` (
  `DEPT_CODE` char(5) NOT NULL,
  `DEPT_NAME` char(15) DEFAULT NULL,
  PRIMARY KEY (`DEPT_CODE`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `department`
--

LOCK TABLES `department` WRITE;
/*!40000 ALTER TABLE `department` DISABLE KEYS */;
INSERT INTO `department` VALUES ('DP000','HOD'),('DP001','Personnel'),('DP002','Production'),('DP003','Purchase'),('DP004','Finance'),('DP005','Research');
/*!40000 ALTER TABLE `department` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `designation`
--

DROP TABLE IF EXISTS `designation`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `designation` (
  `DESIG_CODE` char(6) NOT NULL,
  `DESIG_DESC` char(20) DEFAULT NULL,
  PRIMARY KEY (`DESIG_CODE`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `designation`
--

LOCK TABLES `designation` WRITE;
/*!40000 ALTER TABLE `designation` DISABLE KEYS */;
INSERT INTO `designation` VALUES ('DES00','Authority'),('DES01','Manager'),('DES02','Executive'),('DES03','Officer'),('DES04','Clerk'),('DES05','Helper');
/*!40000 ALTER TABLE `designation` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `emp`
--

DROP TABLE IF EXISTS `emp`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `emp` (
  `EMP_CODE` char(5) NOT NULL,
  `EMP_NAME` char(20) DEFAULT NULL,
  `DEPT_CODE` char(5) DEFAULT NULL,
  `DESIG_CODE` char(6) DEFAULT NULL,
  `SEX` char(1) DEFAULT NULL,
  `ADDRESS` char(25) DEFAULT NULL,
  `CITY` char(20) DEFAULT NULL,
  `STATE` char(20) DEFAULT NULL,
  `PIN` char(6) DEFAULT NULL,
  `BASIC` int DEFAULT NULL,
  `JN_DT` date DEFAULT NULL,
  PRIMARY KEY (`EMP_CODE`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `emp`
--

LOCK TABLES `emp` WRITE;
/*!40000 ALTER TABLE `emp` DISABLE KEYS */;
INSERT INTO `emp` VALUES ('EM001','Nikhil Badyal','DP004','DES06','M','Kathua','JAMMU','Jammu and Kashmir','184143',100000,'2021-01-06'),('EM002','Aikhil Badyal','DP005','DES08','F','Kathua','JAMMU','Jammu and Kashmir','184143',100000,'2021-02-22'),('EM005','New Name','DP003','DES07','F','HIRANAGAR','QWE','rty','457889',3891,'2021-09-23'),('EM006','NIKHIL BADYAL','DP000','DES00','F','KATHUA','JAMMU','JAMMU AND KASHMIR','184143',20001,'2021-02-21'),('EM007','AIKHIL BADYAL','DP001','DES02','M','Delhi','MUMBAI','Gujrat','700104',0,'1980-02-03'),('EM008','Aikhil Badyal','DP000','DES09','F','Kathua','JAMMU','Jammu and Kashmir','184143',100000,'2021-02-22');
/*!40000 ALTER TABLE `emp` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2021-03-26 23:28:21
