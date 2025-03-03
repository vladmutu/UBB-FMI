USE [Firma-De-Imobiliare];


--modificare tip coloana
GO
CREATE OR ALTER PROCEDURE versiune1
AS
BEGIN
	ALTER TABLE Plati
	ALTER COLUMN data_plata DATETIME
	PRINT 'S-a modificat tipul coloanei data_plata de la DATE la DATETIME'
END;
GO


GO
CREATE OR ALTER PROCEDURE undo_versiune1
AS
BEGIN
	ALTER TABLE Plati
	ALTER COLUMN data_plata DATE
	PRINT 'S-a modificat tipul coloanei data_plata de la DATETIME la DATE'
END;
GO


--adaugare constrangere de valoare implicita
GO
CREATE OR ALTER PROCEDURE versiune2
AS
BEGIN
	ALTER TABLE Clienti
	ADD CONSTRAINT default_nume DEFAULT 'John Doe' FOR nume
	PRINT 'S-a adaugat constrangerea default asupra coloanei nume din tabelul agenti'
END;
GO

CREATE OR ALTER PROCEDURE undo_versiune2
AS
BEGIN
	ALTER TABLE Clienti
	DROP CONSTRAINT default_nume
	PRINT 'S-a sters constrangerea default asupra coloanei nume din tabelul agenti'
END;
GO

--creare/stergere tabela
GO
CREATE OR ALTER PROCEDURE versiune3
AS
BEGIN
	DROP TABLE IF EXISTS Sedii
	CREATE TABLE Sedii
	(
		id_sediu INT PRIMARY KEY IDENTITY,
		locatie VARCHAR(50)
	)
	PRINT 'S-a creat tabelul Sedii'
END;
GO

GO
CREATE OR ALTER PROCEDURE undo_versiune3
AS
BEGIN
	DROP TABLE IF EXISTS Sedii;
	PRINT 'S-a sters tabelul Sedii'
END;
GO



--adauga coloana noua
GO
CREATE OR ALTER PROCEDURE versiune4
AS
BEGIN
	ALTER TABLE Agenti
	ADD id_sediu INT
	PRINT 'S-a creat coloana id_sediu pentru tabelul Agenti'
END;
GO


CREATE OR ALTER PROCEDURE undo_versiune4
AS
BEGIN
	ALTER TABLE Agenti
	DROP COLUMN id_sediu
	PRINT 'S-a sters coloana id_sediu pentru tabelul Agenti'
END;
GO



--creare/sterge o constrangere de cheie straina
CREATE OR ALTER PROCEDURE versiune5
AS
BEGIN
	ALTER TABLE Agenti
	ADD CONSTRAINT FK_Agenti_Sedii FOREIGN KEY(id_sediu) REFERENCES Sedii(id_sediu)
	PRINT 'S-a adaugat constrangerea de cheie straina asupra id_sediu'
END;
GO

CREATE OR ALTER PROCEDURE undo_versiune5
AS
BEGIN
	ALTER TABLE Agenti
	DROP CONSTRAINT FK_Agenti_Sedii
	PRINT 'S-a sters constrangerea de cheie straina asupra id_sediu'
END;
GO

-- Tabela pentru memorarea versiunii structurii de baza
CREATE TABLE VersiuneDB (
	cod_v INT PRIMARY KEY IDENTITY,
	nr_versiune INT
);

INSERT INTO VersiuneDB (nr_versiune) VALUES(0);


-- procedura de setare a versiunilor
GO
CREATE OR ALTER PROCEDURE main @versiune INT
AS
BEGIN
	IF @versiune < 0 OR @versiune > 5
	BEGIN
		PRINT 'Versiune invalida'
		RETURN
	END

	DECLARE @versiune_curenta AS INT
	SET @versiune_curenta = (SELECT nr_versiune FROM VersiuneDB)

	IF @versiune = @versiune_curenta
	BEGIN
		PRINT 'Versiunea actuala este deja cea curenta'
		RETURN
	END

	DECLARE @proc VARCHAR(30)
	DECLARE @proc_undo VARCHAR(30)
	DECLARE @ok AS INT
	SET @ok = 0

	DELETE FROM VersiuneDB
	INSERT INTO VersiuneDB(nr_versiune) VALUES (@versiune)

	WHILE(@versiune_curenta < @versiune)
	BEGIN
		SET @ok = @ok + 1
		SET @versiune_curenta = @versiune_curenta + 1
		SET @proc = 'versiune' + CAST(@versiune_curenta AS VARCHAR(10))
		PRINT 'Se executa ' + @proc
		EXEC @proc
	END

	IF(@ok > 0)
	BEGIN
		RETURN
	END

	WHILE(@versiune_curenta > @versiune)
	BEGIN
		SET @proc_undo = 'undo_versiune' + CAST(@versiune_curenta AS VARCHAR(10))
		PRINT 'Se executa ' + @proc_undo
		EXEC @proc_undo
		SET @versiune_curenta = @versiune_curenta - 1
	END
END
GO


SELECT * FROM VersiuneDB;


EXEC main 0;
EXEC main 1;
EXEC main 2;
EXEC main 3;
EXEC main 4;
EXEC main 5;
