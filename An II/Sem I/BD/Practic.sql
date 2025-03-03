CREATE DATABASE Practic;
USE Practic;

CREATE TABLE Tari
(
	id_tara INT PRIMARY KEY IDENTITY,
	nume VARCHAR(100) NOT NULL,
	suprafata INT NOT NULL
);

CREATE TABLE Posesori
(
	id_posesor INT PRIMARY KEY IDENTITY,
	nume VARCHAR(100) NOT NULL,
	prenume VARCHAR(100) NOT NULL,
	adresa VARCHAR(100) NOT NULL,
	telefon VARCHAR(10) NOT NULL CHECK(TRY_CAST(telefon AS INT) IS NOT NULL),
	id_tara INT NOT NULL FOREIGN KEY REFERENCES Tari(id_tara) ON DELETE CASCADE ON UPDATE CASCADE
);

CREATE TABLE Struti
(
	id_strut INT PRIMARY KEY IDENTITY,
	nume VARCHAR(100) NOT NULL,
	data_nasterii DATE NOT NULL,
	descriere VARCHAR(100) NOT NULL,
	inaltime INT NOT NULL,
	greutate INT NOT NULL,
	id_posesor INT NOT NULL FOREIGN KEY REFERENCES Posesori(id_posesor) ON DELETE CASCADE ON UPDATE CASCADE
);

CREATE TABLE Competitii
(
	id_competitie INT PRIMARY KEY IDENTITY,
	nume VARCHAR(100) NOT NULL,
	descriere VARCHAR(100) NOT NULL,
	data_si_ora DATETIME NOT NULL,
	loc VARCHAR(100) NOT NULL
);

CREATE TABLE StrutiCompetitii
(
	id_competitie INT NOT NULL FOREIGN KEY REFERENCES Competitii(id_competitie) ON DELETE CASCADE ON UPDATE CASCADE,
	id_strut INT NOT NULL FOREIGN KEY REFERENCES Struti(id_strut) ON DELETE CASCADE ON UPDATE CASCADE,
	pozitie INT NOT NULL CHECK(pozitie > 0),
	PRIMARY KEY(id_competitie, id_strut)
);

INSERT INTO Tari(nume, suprafata) VALUES
('Anglia', 2000),
('Spania', 3000),
('Germania', 4000),
('Franta', 2500),
('Romania', 1500);

INSERT INTO Posesori(nume, prenume, adresa, telefon, id_tara) VALUES
('Andrei', 'Mutu', 'Nufarului 48', '0770102742', 5),
('Vlad', 'Mircea', 'Rogerius 50', '0742102742', 5),
('Fritz', 'Franz', 'Munchen 34', '0712421222', 3),
('Emanuel','Yamal', 'Barcelona 19', '0742102733', 2),
('John','Doe', 'London 39', '0722102344',1);

INSERT INTO Struti(nume, data_nasterii, descriere, inaltime, greutate, id_posesor) VALUES
('Strut 1', '2001-09-09', 'test1', 190, 190, 1),
('Strut 2', '2001-07-07', 'test2', 180, 180, 2),
('Strut 3', '2001-08-08', 'test3', 170, 170, 3),
('Strut 4', '2001-06-06', 'test4', 160, 160, 4),
('Strut 5', '2001-05-05', 'test5', 150, 150, 5),
('Strut 6', '2001-04-04', 'test6', 140, 140, 1),
('Strut 7', '2001-03-03', 'test7', 130, 130, 2);

INSERT INTO Competitii(nume, descriere, data_si_ora, loc) VALUES
('Competitia 1', 'test1', '2022-09-09 12:00', 'Germania'),
('Competitia 2', 'test2', '2024-08-08 13:30', 'Anglia'),
('Competitia 3', 'test3', '2024-07-07 14:30', 'Germania'),
('Competitia 4', 'test4', '2024-06-06 15:30', 'Spania'),
('Competitia 5', 'test5', '2024-05-05 16:30', 'Franta'),
('Competitia 6', 'test6', '2024-04-04 17:30', 'Romania');

INSERT INTO StrutiCompetitii(id_competitie, id_strut, pozitie) VALUES
(1,1,1),
(2,1,2),
(3,3,10),
(4,5,1),
(5,7,7),
(6,2,3),
(1,4,2),
(2,4,1),
(3,5,3),
(4,6,1);

SELECT * FROM StrutiCompetitii;
SELECT * FROM Struti;
SELECT * FROM Competitii;
SELECT * FROM Tari;
SELECT * FROM Posesori;


GO
CREATE OR ALTER PROCEDURE Update_Or_Add(@id_strut INT, @id_competitie INT, @pozitie INT)
AS
BEGIN
	IF EXISTS (SELECT * FROM StrutiCompetitii WHERE id_competitie = @id_competitie AND id_strut = @id_strut)
	BEGIN
		UPDATE StrutiCompetitii
		SET pozitie = @pozitie
		WHERE id_competitie = @id_competitie AND id_strut = @id_strut;
	END;
	ELSE
	BEGIN
		INSERT INTO StrutiCompetitii(id_competitie, id_strut, pozitie) VALUES
		(@id_competitie, @id_strut, @pozitie);
	END;
END
GO;

DECLARE @id_strut INT = 3;
DECLARE @id_competitie INT  = 1;
DECLARE @pozitie INT = 4;
EXECUTE Update_Or_Add @id_strut, @id_competitie, @pozitie;
SELECT * FROM StrutiCompetitii

GO
CREATE OR ALTER FUNCTION Show()
RETURNS TABLE AS
RETURN(
	SELECT Posesori.nume AS NumePosesor, Posesori.telefon, Aux.nume AS NumeStrut, Aux.data_nasterii FROM Posesori INNER JOIN
	(SELECT id_posesor, nume, data_nasterii FROM Struti WHERE id_strut IN
	(SELECT id_strut FROM StrutiCompetitii WHERE pozitie = 1 and id_strut IN 
	(SELECT id_strut FROM StrutiCompetitii WHERE id_strut NOT IN(
		SELECT id_strut FROM StrutiCompetitii WHERE pozitie = 2)
	))) Aux ON Posesori.id_posesor = Aux.id_posesor)
GO

--INSERT INTO StrutiCompetitii(id_competitie, id_strut, pozitie) VALUES
--(1,1,1),
--(2,1,2),
--(3,3,10),
--(4,5,1),
--(5,7,7),
--(6,2,3),
--(1,4,2),
--(2,4,1),
--(3,5,3),
--(4,6,1);

SELECT * FROM Show();