-- --------------------------------------------------------
-- Хост:                         127.0.0.1
-- Версия сервера:               10.4.14-MariaDB - mariadb.org binary distribution
-- Операционная система:         Win64
-- HeidiSQL Версия:              11.0.0.5919
-- --------------------------------------------------------

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET NAMES utf8 */;
/*!50503 SET NAMES utf8mb4 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;


-- Дамп структуры базы данных sowwy
CREATE DATABASE IF NOT EXISTS `sowwy` /*!40100 DEFAULT CHARACTER SET utf8mb4 */;
USE `sowwy`;

-- Дамп структуры для таблица sowwy.nazvanie
CREATE TABLE IF NOT EXISTS `nazvanie` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(50) NOT NULL DEFAULT '0',
  `projecttt` int(11) NOT NULL DEFAULT 0,
  `year` int(11) NOT NULL DEFAULT 0,
  PRIMARY KEY (`id`),
  KEY `project` (`projecttt`),
  CONSTRAINT `FK_nazvanie_projectt` FOREIGN KEY (`projecttt`) REFERENCES `projectt` (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=11 DEFAULT CHARSET=utf8mb4 COMMENT='and year uwu';

-- Дамп данных таблицы sowwy.nazvanie: ~5 rows (приблизительно)
/*!40000 ALTER TABLE `nazvanie` DISABLE KEYS */;
REPLACE INTO `nazvanie` (`id`, `name`, `projecttt`, `year`) VALUES
	(4, 'Удалой', 1, 1980),
	(6, 'Адмирал Трибуц', 1, 1985),
	(7, 'Североморск', 1, 1987),
	(8, 'Москва', 2, 1982),
	(9, 'Варяг', 2, 1983);
/*!40000 ALTER TABLE `nazvanie` ENABLE KEYS */;

-- Дамп структуры для таблица sowwy.projectt
CREATE TABLE IF NOT EXISTS `projectt` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `project` varchar(50) NOT NULL DEFAULT '0',
  `crew` int(11) NOT NULL DEFAULT 0,
  PRIMARY KEY (`id`),
  KEY `id` (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8mb4 COMMENT='and crew owo';

-- Дамп данных таблицы sowwy.projectt: ~2 rows (приблизительно)
/*!40000 ALTER TABLE `projectt` DISABLE KEYS */;
REPLACE INTO `projectt` (`id`, `project`, `crew`) VALUES
	(1, '1155', 220),
	(2, '1164', 510);
/*!40000 ALTER TABLE `projectt` ENABLE KEYS */;

/*!40101 SET SQL_MODE=IFNULL(@OLD_SQL_MODE, '') */;
/*!40014 SET FOREIGN_KEY_CHECKS=IF(@OLD_FOREIGN_KEY_CHECKS IS NULL, 1, @OLD_FOREIGN_KEY_CHECKS) */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;






SELECT `year`, `name`, `project`,`crew`
FROM sowwy.nazvanie
	JOIN  sowwy.projectt ON nazvanie.projecttt = projectt.id	

