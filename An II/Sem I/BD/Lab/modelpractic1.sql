CREATE DATABASE MagazinDeserturi;
USE MagazinDeserturi;

--cerinta 1
CREATE TABLE Producatori
(
	id_producator INT PRIMARY KEY IDENTITY NOT NULL,
	nume VARCHAR(100) NOT NULL,
	site_web VARCHAR(100) NOT NULL CHECK(site_web LIKE 'https://%')
);

CREATE TABLE TipuriDesert
(
	id_tip_desert INT PRIMARY KEY IDENTITY NOT NULL,
	nume VARCHAR(100) NOT NULL
);

CREATE TABLE Clienti
(
	id_client INT PRIMARY KEY IDENTITY NOT NULL,
	nume VARCHAR(100) NOT NULL,
	email VARCHAR(100) NOT NULL CHECK(email LIKE '%_@%_._%'),
	data_nasterii DATE NOT NULL
);

CREATE TABLE Deserturi
(
	id_desert INT PRIMARY KEY IDENTITY NOT NULL,
	nume VARCHAR(100) NOT NULL,
	mod_de_preparare VARCHAR(500) NOT NULL,
	pret REAL NOT NULL CHECK(pret > 0),
	nr_calorii INT NOT NULL CHECK(nr_calorii > 0),
	id_producator INT FOREIGN KEY 
				REFERENCES Producatori(id_producator) 
				ON DELETE CASCADE 
				ON UPDATE CASCADE
				NOT NULL,
	id_tip_desert INT FOREIGN KEY
				REFERENCES TipuriDesert(id_tip_desert)
				ON DELETE CASCADE
				ON UPDATE CASCADE
				NOT NULL
);

CREATE TABLE DesertClienti
(
	id_desert INT FOREIGN KEY REFERENCES Deserturi(id_desert)
			ON DELETE CASCADE
			ON UPDATE CASCADE
			NOT NULL,
	id_client INT FOREIGN KEY REFERENCES Clienti(id_client)
			ON DELETE CASCADE
			ON UPDATE CASCADE
			NOT NULL,
	cantitate INT NOT NULL,
	PRIMARY KEY(id_desert, id_client)
);

INSERT INTO Producatori(nume, site_web) VALUES
('Panemar', 'https://www.panemar.com'),
('Doina', 'https://www.deserturidoina.ro'),
('Deserturi Cu Gust', 'https://www.deserturicugust.ro'),
('Amandina', 'https://www.amandina.com'),
('Deserturile bunicii','https://deserturilebunicii.ro');

INSERT INTO TipuriDesert(nume) VALUES
('Prajitura'),
('Tort'),
('Cozonac'),
('Inghetata'),
('Ciocolata');

INSERT INTO Deserturi(nume, mod_de_preparare, pret, nr_calorii, id_producator, id_tip_desert) VALUES
('Lava Cake', 'Cuptor', 29.99, 1200, 1, 2),
('Prajitura cu mere', 'Faceti aluatul adaugati mere adaugati aluat bagati la cuptor', 15.99, 500, 4, 1),
('Prajitura cu visine','Faceti aluatul adaugati visine adaugati aluat bagati la cuptor', 12.99, 400, 2, 1),
('Inghetata de vanilie', 'Lapte vanilie congelator', 19.99, 350, 3, 4),
('Inghetata de ciocolata', 'Lapte ciocolata congelator', 19.99, 550, 3, 4),
('Amandine', 'Aluat frisca jeleu', 14.99, 600, 4, 1),
('Ciocolata dubai', 'Ciocolata fistic', 49.99, 1500, 5, 5),
('Cozonac cu mac', 'Aluat mac', 29.99, 1350, 1, 3),
('Cozonac cu nuca', 'Aluat nuca', 28.99, 1400, 4, 3);

INSERT INTO Clienti(nume, email, data_nasterii) VALUES
('Vlad Mutu', 'vladmutu@gmail.com', '2005-05-09'),
('Andrei Gonea', 'agonea@yahoo.com', '2004-07-20'),
('Stefan Gheorghe', 'stefanbigg@hotmail.com', '2002-09-12'),
('Ana Karenina', 'anak@yahoo.com', '2000-12-12'),
('Mircea Forus', 'mirceaforus@gmail.com', '1989-10-15'),
('Maria Ileana', 'mariaileana@hotmail.com', '2006-01-08'),
('Gigel Pop', 'gpop@gmail.com', '1997-02-25');

INSERT INTO DesertClienti(id_desert, id_client, cantitate) VALUES
(1, 2, 20),
(2, 1, 40),
(5, 3, 10),
(7, 6, 40),
(9, 4, 10),
(3, 5, 5),
(4, 4, 5),
(3, 3, 20),
(6, 2, 5);

SELECT * FROM DesertClienti;
SELECT * FROM Clienti;
SELECT * FROM Deserturi;
SELECT * FROM Producatori;
SELECT * FROM TipuriDesert;

--cerinta 2
GO
CREATE OR ALTER PROCEDURE adauga_sau_modifica
(
@id_desert INT,
@id_client INT,
@cantitate INT
)
AS
BEGIN
	IF(EXISTS (SELECT * FROM DesertClienti WHERE id_client = @id_client AND id_desert = @id_desert))
	BEGIN
		DECLARE @aux INT;
		SET @aux = (SELECT cantitate FROM DesertClienti WHERE id_client = @id_client AND id_desert = @id_desert)
		UPDATE DesertClienti 
		SET cantitate = @aux + @cantitate
		WHERE id_client = @id_client AND id_desert = @id_desert
	END
	ELSE
	BEGIN
		INSERT INTO DesertClienti(id_client, id_desert, cantitate) VALUES
		(@id_client, @id_desert, @cantitate);
	END
END
GO

DECLARE @id_desert INT = 1;
DECLARE @id_client INT = 2;
DECLARE @cantitate INT = 10;
EXECUTE adauga_sau_modifica @id_desert, @id_client, @cantitate;
SELECT * FROM DesertClienti;

--cerinta 3
GO
CREATE OR ALTER FUNCTION show_data()
RETURNS TABLE AS
	RETURN (
			SELECT Producatori.nume AS NumeProducator, Deserturi.nume AS NumeDesert, Deserturi.nr_calorii, DesertClienti.cantitate, Clienti.nume AS NumeClient FROM Clienti
			INNER JOIN DesertClienti ON DesertClienti.id_client = Clienti.id_client
			INNER JOIN Deserturi ON DesertClienti.id_desert = Deserturi.id_desert
			INNER JOIN Producatori ON Deserturi.id_producator = Producatori.id_producator
			WHERE Clienti.nume LIKE 'A%'
		   )
GO

SELECT * FROM show_data();