from                                
	timetable                                                                        
GROUP BY `discipline` 
ORDER BY owo DESC
LIMIT 1
16)
SELECT DISTINCT(`discipline`), `cabinet`
FROM timetable
WHERE `cabinet` = '308';
17)
SELECT DISTINCT(`teacher`)
FROM timetable
WHERE `discipline` = 'Базы данных' AND `date` > '2020-01-01' AND `date` < '2020-05-31';
18)
SELECT `discipline`
FROM timetable
WHERE `cabinet` AND `date` > '2020-09-17';
19)
 SELECT discipline FROM timetable WHERE teacher LIKE 'Корсакова%' 
20)
 SELECT                           
 DISTINCT(`class`)  
from                                
	timetable                                                                        
WHERE teacher LIKE 'Корсакова%' 
21)
SELECT                           
 DISTINCT(`discipline`)
from                                
	timetable                                                                        
ORDER BY CHAR_LENGTH(discipline) DESC
	LIMIT 1
22)
 SELECT                           
 DISTINCT(`teacher`)  
from                                
	timetable                                                                        
WHERE `date` >= '2020-09-01' AND `date` <= '2020-12-31'
23)
SELECT `class` , `discipline`, `date`
FROM timetable 
WHERE `class` = 'АИСТбд-21' AND `discipline` = 'Базы данных' AND `date` > '2020-01-01' AND `date` < '2020-07-15' 
24)
 SELECT DISTINCT(`discipline`), `cabinet` FROM timetable WHERE `teacher` LIKE `Згуральская%`
25)
 SELECT  DISTINCT(`discipline`) FROM timetable WHERE `type` = `Discord`
26)
 SELECT  DISTINCT(`teacher`) FROM timetable where`discipline` = 'Основы интернет верстки'
27)
SELECT                           
 DISTINCT(`discipline`), COUNT(`class`) AS 'lll'    
from                                
	timetable                                                                        
WHERE`date` >= '2020-01-01' AND `date` <= '2020-07-30' AND `discipline` = 'Высшая математика' AND `type` ='Лекция' 
GROUP BY `discipline` 
ORDER BY lll DESC 
28)
SELECT                           
 DISTINCT(`discipline`), COUNT(`class`) AS 'lll'    
from                                
	timetable                                                                        
WHERE`date` >= '2020-01-01' AND `date` <= '2020-07-30' AND `discipline` = 'Высшая математика' AND `type` ='Практика'
	
29)
SELECT                           
 DISTINCT(`date_of_update`)
from                                
	timetable                                                                        
ORDER BY date_of_update DESC
LIMIT 1
30)
SELECT DISTINCT(`teacher`)           

from                                
	timetable                                                                        
	 where `date` >= '2020-01-01' AND `date` <= '2020-07-30' AND WEEKDAY(`date`)	= 5
 
