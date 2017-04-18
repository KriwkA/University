--����� ������ ���� �������
SELECT * FROM dbo.Author

--����� ������ �� ������ ������ ��� ID
SELECT [Name], [Sername], [Patronymic], [AuthorID], [Adress] FROM dbo.Author

--����� ���� ������ ���� ������
SELECT DISTINCT [Name] as AuthorName FROM dbo.Author

--����� ���� ������� ������� ������ � ����� ����������
SELECT * FROM dbo.Author
WHERE [Adress] is NULL

--����� �������, ��� ID ��������� � ���������� [3,8], ����� ���. � ����� ����������
--� ��� ������������ �� "�����"
SELECT * FROM dbo.Author
WHERE [AuthorID] between 3 and 8 and [Name] like '�����%' and [Adress] is not null

--����� ���� �������, ��� ID �� ��������� � ��������� {2,4,6,8,10}
SELECT * FROM dbo.Author
WHERE [AuthorID] NOT IN(2,4,6,8,10)

