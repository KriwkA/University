SELECT * FROM dbo.Author

--Подсчет количества Вась
SELECT COUNT([Name]) as [Count names = 'Александр'] FROM dbo.Author
WHERE [Name] = 'Василий'

--Сумма ID авторов на промежутке от 3х до 6, умноженная на 10
SELECT SUM([AuthorID]*10) as [Summ ID] FROM dbo.Author
WHERE [AuthorID] between 3 and 6

--Список минимальных ID авторов для каждого имени
SELECT MIN([AuthorID]) as [ID], [Name] FROM dbo.Author
GROUP BY [Name]
HAVING MIN([AuthorID]) between 3 and 6