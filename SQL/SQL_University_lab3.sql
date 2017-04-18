--ошибка, т.к. в таблице публикаций есть запись с AuthorID = 1
--и отключена возможность каскадного удаления
delete from dbo.Author
where AuthorID = 1

select * from dbo.Publication

--успешное удаление
delete from dbo.Author
where AuthorID = 10

--ошибка, невозможно установить AuthorID 
--не существующий в таблице Author или не равный NULL
update dbo.Publication
set AuthorID = 15
where Title = '6testTitle'

--успешное изменение
update dbo.Publication
set ThemeID = 1
where Title = '6testTitle'