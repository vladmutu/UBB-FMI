--crearea unei baze de date
/*
comentariu pe mai multe linii
*/
CREATE DATABASE Lab1;

--conectarea la o baza de date ( USE )
USE Lab1;

--crearea unui tabel
CREATE TABLE Persoane
(
	cod_persoana INT PRIMARY KEY IDENTITY(1,1),
	nume VARCHAR(100),
	prenume VARCHAR(100),
	data_nasterii DATE
);