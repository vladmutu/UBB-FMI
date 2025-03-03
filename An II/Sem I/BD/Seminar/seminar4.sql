CREATE DATABASE ParcDeDistractii;

USE ParcDeDistractii;

CREATE TABLE Categorii
(
	cod_c INT PRIMARY KEY IDENTITY,
	nume VARCHAR(20)
);

CREATE TABLE Vizitatori
(
	cod_v INT PRIMARY KEY IDENTITY,
	nume VARCHAR(20),
	email VARCHAR(50),
	cod_c INT FOREIGN KEY REFERENCES Categorii(cod_c) ON UPDATE CASCADE ON DELETE CASCADE
);

CREATE TABLE Sectiuni
(
	cod_s INT PRIMARY KEY IDENTITY,
	nume VARCHAR(20),
	descriere VARCHAR(255)
);

CREATE TABLE Atractii 
(
	cod_a INT PRIMARY KEY IDENTITY,
	nume VARCHAR(20),
	descriere VARCHAR(255),
	varsta_min INT,
	cod_s INT FOREIGN KEY REFERENCES Sectiuni(cod_s)  ON UPDATE CASCADE ON DELETE CASCADE
);

CREATE TABLE Note
(
	cod_a INT FOREIGN KEY REFERENCES Atractii(cod_a)  ON UPDATE CASCADE ON DELETE CASCADE,
	cod_v INT FOREIGN KEY REFERENCES Vizitatori(cod_v)  ON UPDATE CASCADE ON DELETE CASCADE,
	nota INT,
	PRIMARY KEY(cod_a, cod_v)
);

GO
CREATE OR ALTER FUNCTION CategoryCode(@category_name VARCHAR(20))
RETURNS INT
AS
	BEGIN
	DECLARE @category_code INT 
	SELECT @category_code=cod_c FROM Categorii WHERE nume=@category_name;
	IF(@category_code is NULL)
		RETURN 0;
	RETURN @category_code;
	END;
GO

INSERT INTO Categorii(nume) VALUES ('categorie1');

PRINT dbo.CategoryCode('categorie1');

GO
CREATE OR ALTER TRIGGER PreventDeleteOnCategories ON Categorii
INSTEAD OF DELETE
AS
	BEGIN
		RAISERROR('Nu se pot sterge date din acest tabel',16,1);
	END;
GO

INSERT INTO Categorii(nume) VALUES 
('Pensionari');

GO
CREATE OR ALTER VIEW View_ShowDataFromCategorii
AS
	SELECT * FROM Categorii
	WHERE nume IN ('Pensionari','Copii');
GO

SELECT * FROM View_ShowDataFromCategorii;

GO 
CREATE OR ALTER VIEW View_StartsWithC
AS
	SELECT cod_s, nume, descriere FROM Sectiuni
	WHERE nume LIKE 'C%';
GO

INSERT INTO Sectiuni(nume, descriere) VALUES 
('C2', 'dawdsdaw'),
('daw','dawda');

SELECT * FROM View_StartsWithC;

GO
CREATE OR ALTER FUNCTION endsWithLetter(@letter CHAR)
RETURNS TABLE AS
	RETURN SELECT nume, descriere FROM Sectiuni WHERE nume LIKE '_%'+@letter;
GO

INSERT INTO Sectiuni(nume, descriere) VALUES
('dawdsdwac', 'dadsdw'),
('c', 'dawdsdwa');

SELECT * FROM Sectiuni
SELECT * FROM endsWithLetter('c');

GO
CREATE OR ALTER VIEW View_showNameGradeAtraction
AS
	SELECT Vizitatori.nume AS NumeVizitator, Note.nota AS Nota, Atractii.nume AS NumeAtractie FROM NOTE
	INNER JOIN Vizitatori ON Vizitatori.cod_v = Note.cod_v
	INNER JOIN Atractii ON Atractii.cod_a = Note.cod_a
GO

