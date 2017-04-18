--Создание таблицы авторов
CREATE TABLE Author
(
	AuthorID int IDENTITY(1,1) PRIMARY KEY,
	Sername varchar(20) not null,
	Name varchar(20) not null,
	Patronymic varchar(20) not null,
	Adress varchar(100) null
)

--Создание таблицы статей
CREATE TABLE Article
(
	ID int IDENTITY(1,1) PRIMARY KEY,
	Publishing varchar(30) not null
)

--Создание таблицы журналов
CREATE TABLE Magazine
(
	ID int IDENTITY(1,1) PRIMARY KEY,
	Title varchar(30) not null,
	Number int not null
)

--Создание таблицы тем публикаций
CREATE TABLE Theme
(
	ID int IDENTITY(1,1) PRIMARY KEY,
	Title varchar(50) not null
)

--Создание таблицы хранящей информацию о публикациях
CREATE TABLE Publication
(
	ThemeID int null FOREIGN KEY REFERENCES dbo.Theme([ID]) on delete cascade on update cascade,
	AuthorID int null FOREIGN KEY REFERENCES dbo.Author([AuthorID]) on delete cascade on update cascade,
	Title varchar(100) not null,
	ReleaseDate date not null,
	PublicationType varchar(30) not null check (PublicationType in('Magazine','Article')),
)