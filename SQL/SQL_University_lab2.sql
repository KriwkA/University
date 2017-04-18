SELECT * FROM dbo.Author

--������� ���������� ����
SELECT COUNT([Name]) as [Count names = '���������'] FROM dbo.Author
WHERE [Name] = '�������'

--����� ID ������� �� ���������� �� 3� �� 6, ���������� �� 10
SELECT SUM([AuthorID]*10) as [Summ ID] FROM dbo.Author
WHERE [AuthorID] between 3 and 6

--������ ����������� ID ������� ��� ������� �����
SELECT MIN([AuthorID]) as [ID], [Name] FROM dbo.Author
GROUP BY [Name]
HAVING MIN([AuthorID]) between 3 and 6