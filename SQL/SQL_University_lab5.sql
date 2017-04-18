--����� ����������, ���� ������� ����������� ����� 5 ���
select * from dbo.Publication as outTable
where 5 <	(select  Count(*) 
			from dbo.Publication as inTable
			where outTable.ThemeID = inTable.ThemeID)

--����� �������, ������� �������� ������ �� ����� ��� 1 ������ ����
select (outTable.Name + ' ' + outTable.Sername) as [Author] 
from dbo.Author as outTable
where 1 <  	(select COUNT( DISTINCT ThemeID)
			from dbo.Publication as inTable
			where outTable.AuthorID = inTable.AuthorID)

--����� �������, ������� �� ������ ������ � ������������ ������
select * from dbo.Author
where	NOT EXISTS	(select dbo.Publication.AuthorID
		from dbo.Publication
		where ThemeID is not null and dbo.Author.AuthorID = dbo.Publication.AuthorID)

--����� �������, ������� ������ ������ � ������������ ������
select * from dbo.Author
where	dbo.Author.AuthorID = 
		ANY	(select dbo.Publication.AuthorID
		from dbo.Publication
		where ThemeID is not null)

--����� �������, ������� ������ ������ ������ �� ���� � ID 1
select * from dbo.Author
where	1 = ALL(select dbo.Publication.ThemeID
		from dbo.Publication
		where dbo.Author.AuthorID = dbo.Publication.AuthorID)