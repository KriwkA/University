
--Создание представления публикаций
create view PublicationView as
select 
	dbo.Author.Name + ' ' + SUBSTRING(dbo.Author.Name, 1, 1) + '.' + 
	SUBSTRING(dbo.Author.Patronymic, 1, 1) + '.' as Author,
	dbo.Theme.Title as Theme,
	dbo.Publication.Title,
	dbo.Publication.ReleaseDate,
	dbo.Publication.PublicationType as [type]
from 
	(dbo.Author join dbo.Publication
	on dbo.Author.AuthorID = dbo.Publication.AuthorID)
	join dbo.Theme
	on dbo.Theme.ID = dbo.Publication.ThemeID

update dbo.PublicationView
set Theme = 'Магия'
where Theme = 'Наука'

drop view dbo.PublicationView