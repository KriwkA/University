--������, �.�. � ������� ���������� ���� ������ � AuthorID = 1
--� ��������� ����������� ���������� ��������
delete from dbo.Author
where AuthorID = 1

select * from dbo.Publication

--�������� ��������
delete from dbo.Author
where AuthorID = 10

--������, ���������� ���������� AuthorID 
--�� ������������ � ������� Author ��� �� ������ NULL
update dbo.Publication
set AuthorID = 15
where Title = '6testTitle'

--�������� ���������
update dbo.Publication
set ThemeID = 1
where Title = '6testTitle'