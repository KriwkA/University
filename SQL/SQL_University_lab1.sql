--Вывод списка всех авторов
SELECT * FROM dbo.Author

--Вывод данных об каждом авторе без ID
SELECT [Name], [Sername], [Patronymic], [AuthorID], [Adress] FROM dbo.Author

--Вывод всех разных имен автора
SELECT DISTINCT [Name] as AuthorName FROM dbo.Author

--Вывод всех авторов имеющих запись о месте жительства
SELECT * FROM dbo.Author
WHERE [Adress] is NULL

--Вывод авторов, чей ID находится в промежутке [3,8], имеет инф. о месте жительтсва
--и имя начинающееся на "Алекс"
SELECT * FROM dbo.Author
WHERE [AuthorID] between 3 and 8 and [Name] like 'Алекс%' and [Adress] is not null

--Вывод всех авторов, чьи ID не находятся в множестве {2,4,6,8,10}
SELECT * FROM dbo.Author
WHERE [AuthorID] NOT IN(2,4,6,8,10)

