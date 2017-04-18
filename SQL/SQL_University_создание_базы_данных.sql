
--Создание базы данных
CREATE DATABASE University ON(
	NAME = publication_dat,
	FILENAME = 'D:\DataBase\University\publication.mdf',
	SIZE = 10MB,
	MAXSIZE = 100MB,
	FILEGROWTH = 5MB
) LOG ON (
	NAME = publication_log,
	FILENAME = 'D:\DataBase\University\publication.ldf',
	SIZE = 10MB,
	MAXSIZE = 50MB,
	FILEGROWTH = 5MB
)