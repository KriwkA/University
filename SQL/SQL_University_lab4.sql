-- Объединение 2х таблиц с помощью оператора JOIN
select 
	[Name],
	[Sername], 
	[Title], 
	[PublicationType]
from 
	dbo.Publication join dbo.Author
on 
	dbo.Author.AuthorID = dbo.Publication.AuthorID

-- Объединение 2х таблиц без оператора JOIN
select
	[Name],
	[Sername],
	[Title],
	[PublicationType]
from 
	dbo.Publication,
	dbo.Author
where 
	dbo.Publication.AuthorID = dbo.Author.AuthorID

-- Объединение 3х таблиц с помощью оператора JOIN
select
	[Name],
	[Sername],
	dbo.Theme.Title as [Theme],
	dbo.Publication.Title as [Title],
	[PublicationType]
from 
	dbo.Theme join (dbo.Publication	join dbo.Author
					on dbo.Author.AuthorID = dbo.Publication.AuthorID)
	on dbo.Publication.ThemeID = dbo.Theme.ID

-- Объединение 3х таблиц без оператора JOIN
select
	[Name],
	[Sername],
	dbo.Theme.Title as [Theme],
	dbo.Publication.Title as [Title],
	[PublicationType]
from
	dbo.Author,
	dbo.Publication,
	dbo.Theme
where 
	dbo.Publication.AuthorID = dbo.Author.AuthorID and 
	dbo.Publication.ThemeID = dbo.Theme.ID

-- Выборка авторов с имеющих общие темы публикаций
select
	first.Name + ' ' + first.Sername as [FirstAuthor],
	second.Name + ' ' + second.Sername as [SecondAuthor],
	AuthorsWithOneTheme.ThemeID
from
	-- Выделение таблицы идентификаторов авторов имеющих общие темы 
	(select
		first.AuthorID as [fst],
		second.AuthorID as [sec],
		first.ThemeID
	from
		dbo.Publication first,
		dbo.Publication second
	where
		first.ThemeID = second.ThemeID and
		first.AuthorID < second.AuthorID) as AuthorsWithOneTheme,
	dbo.Author first,
	dbo.Author second
where
	AuthorsWithOneTheme.fst = first.AuthorID and
	AuthorsWithOneTheme.sec = second.AuthorID

select * from dbo.Publication
