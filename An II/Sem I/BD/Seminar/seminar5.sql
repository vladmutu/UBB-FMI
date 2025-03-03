CREATE DATABASE Seminar5;

GO
USE Seminar5;
CREATE TABLE Persoane
(
	cod_p INT NOT NULL,
	nume VARCHAR(100),
	prenume VARCHAR(200),
	data_nasterii DATE,
	localitate VARCHAR(100),
	email VARCHAR(100)
);

INSERT INTO Persoane(cod_p, nume, prenume, data_nasterii, localitate, email) VALUES 
(1, 'Pop', 'Mihai', '1991-12-21', 'Cluj-Napoca', 'mihaip@gmail.com'),
(-7, 'Pop', 'Andrei', '1999-03-03', 'Sibiu', 'popandrei@gmail.com'),
(30,'Ion', 'Bianca', '2000-02-02', 'Cluj-Napoca', 'bianca@gmail.com'),
(2, 'Ionescu', 'Andrei', '2002-02-02', 'Craiova', 'andreii@gmail.com'),
(10, 'Ioan', 'Andra', '1980-02-02', 'Tulcea', 'andraioan@gmail.com'),
(3, 'Ion', 'Oana', '1968-03-03', 'Sibiu', 'ionoana@gmail.com');

SELECT * FROM Persoane;
SELECT * FROM Persoane WHERE localitate = 'Sibiu';

SELECT nume, prenume FROM Persoane WHERE localitate = 'Cluj-Napoca';