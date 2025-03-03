USE [Firma-De-Imobiliare];

--cheie primara si nicio cheie straina: Agenti
--cheie primara si cel putin o cheie straina: Plati
--cheie primara compusa: ProprietatiServicii

INSERT INTO [Tables](name) VALUES
('Agenti'),
('Contacte'),
('ProprietatiServicii');


--view cu un simplu select
GO
CREATE OR ALTER VIEW View_Agenti AS
	SELECT id_agent, nume, email, telefon, [comision(%)] FROM Agenti
GO

--view cu select pe doua tabele
GO
CREATE OR ALTER VIEW View_Contacte_Clienti AS
	SELECT Contacte.id_client, Contacte.data_contactulul, Contacte.descriere_contact, Contacte.tip_contact, Clienti.nume, Clienti.tip_client FROM Contacte
	INNER JOIN Clienti
	ON Contacte.id_client = Clienti.id_client;
GO

--view cu select pe 2 tabele cu un group by
GO
CREATE OR ALTER VIEW View_ProprietatiServicii AS
	SELECT Proprietati.adresa, COUNT(*) AS Cate_Tipuri_De_Proprietati FROM ProprietatiServicii
	INNER JOIN Proprietati ON Proprietati.id_proprietate = ProprietatiServicii.id_proprietate
	INNER JOIN Servicii ON Servicii.id_serviciu = ProprietatiServicii.id_serviciu
	GROUP BY Proprietati.tip_proprietate, Proprietati.adresa
GO


--inseram in Views view-urile create
INSERT INTO [Views](Name) VALUES 
('View_Agenti'),
('View_Contacte_Clienti'),
('View_ProprietatiServicii');


--inseram denumirile testelor
INSERT INTO Tests(Name) VALUES 
('Test_Agenti'),
('Test_Contacte'),
('Test_ProprietatiServicii');

-- Legam testele de tabele
INSERT INTO TestTables(TestID,TableID,NoOfRows,Position) VALUES
    -- Test_Agenti
    (1, 1, 10, 1),
    -- Test_Contacte
    (2, 2, 7, 2),
    -- Test_ProprietatiServicii
    (3, 3, 5, 3);

-- Legam testele de view-uri
INSERT INTO TestViews(TestID, ViewID) VALUES
    (1, 1), -- View_Agenti
    (2, 2), -- View_Contacte
    (3, 3); -- View_ProprietatiServicii

--SELECT * FROM Tests;
--SELECT * FROM [Tables];
--SELECT * FROM [Views];
--SELECT * FROM TestViews;
--SELECT * FROM TestTables;
--DBCC CHECKIDENT ('Tests', RESEED, 0);
--DBCC CHECKIDENT ('[Tables]', RESEED, 0);
--DBCC CHECKIDENT ('[Views]', RESEED, 0);
--DELETE FROM TestTables;
--DELETE FROM TestViews;
--DELETE FROM [Views];
--DELETE FROM [Tables];
--DELETE FROM Tests;

--procedura de inserare pentru testul pe tabela Agenti
GO
CREATE OR ALTER PROCEDURE ins_test_Agenti
@NoOfRows INT
AS
BEGIN
    SET NOCOUNT ON;
    DECLARE @nume NVARCHAR(100), @email NVARCHAR(100), @telefon NVARCHAR(10), @comision INT;
    DECLARE @currentRowNr INT = 0;

    WHILE @currentRowNr < @NoOfRows
    BEGIN
        SET @nume = 'Agent Test ' + CAST(@currentRowNr AS NVARCHAR(10));
        SET @email = 'test' + CAST(@currentRowNr AS NVARCHAR(10)) + '@example.com';
        SET @telefon = RIGHT('0000000000' + CAST(@currentRowNr AS NVARCHAR(10)), 10);
        SET @comision = @currentRowNr;
        
        INSERT INTO Agenti (nume, email, telefon, [comision(%)])
        VALUES (@nume, @email, @telefon, @comision);
        
        SET @currentRowNr = @currentRowNr + 1;
    END

    PRINT 'S-au inserat ' + CAST(@NoOfRows AS NVARCHAR(10)) + ' valori in Agenti.';
END;
GO

-- Procedura de inserare pentru testul pe tabela Contacte
GO
CREATE OR ALTER PROCEDURE ins_test_Contacte
@NoOfRows INT
AS
BEGIN
    SET NOCOUNT ON;

    DECLARE @currentRowNr INT = 0;
    DECLARE @id_client INT;
    DECLARE @nume NVARCHAR(100);
    DECLARE @email NVARCHAR(100);
    DECLARE @telefon NVARCHAR(10);
    DECLARE @adresa NVARCHAR(200);
    DECLARE @tip_client NVARCHAR(50);
	

    -- Inserare Client Test
    SET @nume = 'Client Test';
    SET @email = 'client_test@gmail.com';
    SET @telefon ='0000000000';
    SET @adresa = 'Adresa Test';
    SET @tip_client = 'cumparator';

    INSERT INTO Clienti (nume, email, telefon, adresa, tip_client)
    VALUES (@nume, @email, @telefon, @adresa, @tip_client);

    SET @id_client =(SELECT MAX(Clienti.id_client) FROM Clienti);
	DECLARE @data_contactului DATETIME;
	DECLARE @tip_contact NVARCHAR(100);
	DECLARE @descriere_contact NVARCHAR(200);
    
    WHILE @currentRowNr < @NoOfRows
    BEGIN
        SET @data_contactului = '2000-01-01';
		SET @descriere_contact = 'test';
		SET @tip_contact = 'telefon';
        INSERT INTO Contacte (id_client, data_contactulul, tip_contact, descriere_contact)
        VALUES (@id_client, @data_contactului, @tip_contact, @descriere_contact);

        SET @currentRowNr = @currentRowNr + 1;
    END

    PRINT 'S-au inserat ' + CAST(@NoOfRows AS NVARCHAR(10)) + ' valori în Contacte si un Client.';
END;
GO



--procedura de inserare pentru testul pe tabela ProprietatiServicii
GO
CREATE OR ALTER PROCEDURE ins_test_ProprietatiServicii
@NoOfRows INT
AS
BEGIN
    SET NOCOUNT ON;
	DECLARE @currentRowNr INT;
	SET @currentRowNr = 0;
	DECLARE @id_serviciu INT, @id_client INT ,@id_proprietate INT, @id_agent INT;

	--client
	DECLARE @nume_client NVARCHAR(100), @email NVARCHAR(100), @telefon NVARCHAR(10), @adresa NVARCHAR(100), @tip_client NVARCHAR(15);
	SET @nume_client = 'Client test';
	SET @email = 'test@gmail.com';
	SET @telefon = '0000000000';
	SET @adresa = 'adresa test';
	SET @tip_client = 'cumparator';

	INSERT INTO Clienti(nume, email, telefon, adresa, tip_client) VALUES 
	(@nume_client, @email, @telefon, @adresa, @tip_client);
	SET @id_client = (SELECT MAX(Clienti.id_client) FROM Clienti);
	--agenti
	EXEC ins_test_Agenti 1;

	SET @id_agent = (SELECT MAX(Agenti.id_agent) FROM Agenti);

	--pt proprietate
	DECLARE @id_proprietar INT;
	SET @id_proprietar = (SELECT MAX(Clienti.id_client) FROM Clienti);
	DECLARE @adresa_proprietate NVARCHAR(100) = 'adresa test';
	DECLARE @tip_proprietate NVARCHAR(100) = 'casa';
	DECLARE @pret INT = 0;
	DECLARE @suprafata INT = 0;

	INSERT INTO Proprietati(adresa, tip_proprietate, pret, [suprafata(m^2)], id_agent, id_proprietar) VALUES
	(@adresa_proprietate, @tip_proprietate, @pret, @suprafata, @id_agent, @id_proprietar);

	--pt servicii
	DECLARE @descriere NVARCHAR(100), @nume NVARCHAR(100);

	SET @id_proprietate = (SELECT MAX(Proprietati.id_proprietate) FROM Proprietati);

    WHILE @currentRowNr < @NoOfRows
    BEGIN
        SET @descriere = 'descriere test ' + CAST(@currentRowNr AS NVARCHAR(10));
        SET @nume = 'nume test ' + CAST(@currentRowNr AS NVARCHAR(10)); 
		
        INSERT INTO Servicii (descriere, nume, id_client, id_proprietate)
        VALUES (@descriere, @nume, @id_client, @id_proprietate);

        SET @currentRowNr = @currentRowNr + 1;
    END

    -- Adaugam in ProprietatiServicii toate combinatiile intre primul id_proprietate si noile id-uri create
    INSERT INTO ProprietatiServicii (id_proprietate, id_serviciu, pret)
    SELECT @id_proprietate, id_serviciu, -1
    FROM Servicii
    WHERE descriere LIKE 'descriere test %';

    PRINT 'S-au inserat ' + CAST(@NoOfRows AS NVARCHAR(10)) + ' valori in Servicii si in ProprietatiServicii, si cate o valoare in agenti, clienti, si proprietati.';
    
END;
GO

--procedura de stergere pentru testul pe tabela Agenti
GO
CREATE OR ALTER PROCEDURE del_test_Agenti
AS
BEGIN
    SET NOCOUNT ON;
	DELETE FROM ProprietatiServicii;
	DELETE FROM Servicii;
	DELETE FROM Proprietati;
	DELETE FROM Agenti;
	DELETE FROM Contacte;
	DELETE FROM Clienti;
    PRINT 'S-au sters valorile test din Agenti.';
END;
GO

--procedura de stergere pentru testul pe tabela Contacte
GO
CREATE OR ALTER PROCEDURE del_test_Contacte
AS
BEGIN
    SET NOCOUNT ON;
	DELETE FROM ProprietatiServicii;
	DELETE FROM Servicii;
	DELETE FROM Proprietati;
	DELETE FROM Agenti;
	DELETE FROM Contacte;
	DELETE FROM Clienti;
    PRINT 'S-au sters valorile test din Contacte si Clienti.';
END;
GO

--procedura de stergere pentru testul pe tabela ProprietatiServicii
GO
CREATE OR ALTER PROCEDURE del_test_ProprietatiServicii
AS
BEGIN
    SET NOCOUNT ON;
    DELETE FROM ProprietatiServicii;
	DELETE FROM Servicii;
	DELETE FROM Proprietati;
	DELETE FROM Agenti;
	DELETE FROM Clienti;
    PRINT 'S-au sters valorile test din ProprietatiServicii, Proprietati, Servicii, Clienti, Agenti.';
END;
GO

--procedura generala de inserare
GO
CREATE OR ALTER PROCEDURE ins_test_general
@idTest INT
AS
BEGIN
    DECLARE @numeTabela NVARCHAR(50);
    DECLARE @NoOfRows INT;
    DECLARE @sql_cmd NVARCHAR(MAX);
    DECLARE @paramDefinition NVARCHAR(MAX);

    DECLARE cursorTab CURSOR FORWARD_ONLY FOR
    SELECT [Tables].Name, TestTables.NoOfRows 
    FROM TestTables
    INNER JOIN [Tables] ON TestTables.TableID = [Tables].TableID
    WHERE TestTables.TestID = @idTest
    ORDER BY TestTables.Position;

    OPEN cursorTab;
    FETCH NEXT FROM cursorTab INTO @numeTabela, @NoOfRows;

    WHILE @@FETCH_STATUS = 0
    BEGIN
        SET @sql_cmd = 'EXEC ins_test_' + @numeTabela + ' @NoOfRows';
        SET @paramDefinition = N'@NoOfRows INT';

        EXEC sp_executesql @sql_cmd, @paramDefinition, @NoOfRows = @NoOfRows;

        FETCH NEXT FROM cursorTab INTO @numeTabela, @NoOfRows;
    END;

    CLOSE cursorTab;
    DEALLOCATE cursorTab;
END;
GO

--procedura generala de stergere
GO
CREATE OR ALTER PROCEDURE stergere_test_general
@idTest INT
AS
BEGIN
    DECLARE @numeTabela NVARCHAR(50);

    DECLARE cursorTab CURSOR FORWARD_ONLY FOR
    SELECT [Tables].Name
    FROM TestTables
    INNER JOIN [Tables] ON TestTables.TableID = [Tables].TableID
    WHERE TestTables.TestID = @idTest
    ORDER BY TestTables.Position DESC;

    OPEN cursorTab;
    FETCH NEXT FROM cursorTab INTO @numeTabela;

    WHILE @@FETCH_STATUS = 0
    BEGIN
        EXEC ('del_test_' + @numeTabela);
        FETCH NEXT FROM cursorTab INTO @numeTabela;
    END;

    CLOSE cursorTab;
    DEALLOCATE cursorTab;
END;
GO

--procedura generala de executare a viewurilor pentru teste
GO
CREATE OR ALTER PROCEDURE view_testgen
@idTest INT
AS
BEGIN
	DECLARE @viewName NVARCHAR(50) = 
		(SELECT [Views].Name FROM [Views]
		INNER JOIN TestViews ON TestViews.ViewID = [Views].ViewID
		WHERE TestViews.TestID = @idTest);

	DECLARE @comanda NVARCHAR(55) = 
		N'SELECT * FROM ' + @viewName;
	
	EXECUTE (@comanda);
END
GO


--procedura generala de testare
GO
CREATE OR ALTER PROCEDURE run_test
@idTest INT
AS
BEGIN
	DECLARE @startTime DATETIME;
	DECLARE @interTime DATETIME;
	DECLARE @endTime DATETIME;

	SET @startTime = GETDATE();
	
	EXECUTE stergere_test_general @idTest;
	EXECUTE ins_test_general @idTest;
	
	SET @interTime = GETDATE();
	
	EXECUTE view_testgen @idTest;

	SET @endTime = GETDATE();

	DECLARE @testName NVARCHAR(50) =
		(SELECT [Tests].Name FROM [Tests] WHERE [Tests].TestID = @idTest);
	INSERT INTO TestRuns VALUES (@testName, @startTime, @endTime);

	DECLARE @viewID INT =
		(SELECT [Views].ViewID FROM [Views]
		INNER JOIN TestViews ON TestViews.ViewID = [Views].ViewID
		WHERE TestViews.TestID = @idTest);
	DECLARE @tableID INT =
		(SELECT [Tables].TableID FROM Tests
		INNER JOIN TestTables ON Tests.TestID = TestTables.TestID
		INNER JOIN [Tables] ON [Tables].TableID = TestTables.TableID
		WHERE Tests.TestID = @idTest AND 
		Tests.Name LIKE N'Test_' + [Tables].Name);
	DECLARE @testRunID INT = 
		(SELECT TOP 1 TestRuns.TestRunID FROM TestRuns
		WHERE TestRuns.Description = @testName
		ORDER BY TestRuns.TestRunID DESC);
	
	INSERT INTO TestRunTables VALUES (@testRunID, @tableID, @startTime, @interTime);
	INSERT INTO TestRunViews VALUES (@testRunID, @viewID, @interTime, @endTime);

	PRINT CHAR(10) + 'Test executat in ' + CONVERT(VARCHAR(10), DATEDIFF(millisecond, @startTime, @endTime)) + ' milisecunde.'
END
GO


EXEC run_test 1;
EXEC run_test 2;
EXEC run_test 3;
SELECT * FROM View_ProprietatiServicii;
SELECT * FROM Agenti;
SELECT * FROM Plati;
SELECT * FROM Contacte;
SELECT * FROM ProprietatiServicii;
SELECT * FROM Servicii;
SELECT * FROM TestTables;
SELECT * FROM TestViews;
SELECT * FROM TestRunViews;
SELECT * FROM TestRunTables;
SELECT * FROM TestRuns;
SELECT * FROM Tables;
SELECT * FROM Views;

DELETE FROM Agenti;
DELETE FROM Clienti;
DELETE FROM Proprietati;
DELETE FROM ProprietatiServicii;
DELETE FROM Contacte;
DELETE FROM Contracte;
DELETE FROM Servicii;
DELETE FROM FeedBack;
DELETE FROM Tranzactii;
DELETE FROM Plati;

SELECT * FROM Agenti;
SELECT * FROM Clienti;
SELECT * FROM Contacte;
SELECT * FROM Contracte;
SELECT * FROM FeedBack;
SELECT * FROM Plati;
SELECT * FROM Proprietati;
SELECT * FROM Tranzactii;
SELECT * FROM Servicii;
SELECT * FROM ProprietatiServicii;

SELECT * FROM Clienti;
SELECT * FROM Agenti;
SELECT * FROM Servicii;
SELECT * FROM Proprietati;
SELECT * FROM ProprietatiServicii;

SELECT * FROM Clienti;
SELECT * FROM Contacte;

EXEC del_test_Agenti;
EXEC del_test_Contacte;
EXEC del_test_ProprietatiServicii

DELETE FROM TestRuns;
DELETE FROM TestRunTables;
DELETE FROM TestRunViews;
DELETE FROM TestViews;
DELETE FROM TestTables;
DELETE FROM Tables;
DELETE FROM Views;
DELETE FROM Tests;

DBCC CHECKIDENT('Tables', RESEED, 0);
DBCC CHECKIDENT('Tests', RESEED, 0);
DBCC CHECKIDENT('Views', RESEED, 0);
DBCC CHECKIDENT('TestViews', RESEED, 0);
DBCC CHECKIDENT('TestRuns', RESEED, 0);
DBCC CHECKIDENT('TestRunTables', RESEED, 0);
DBCC CHECKIDENT('TestRunViews', RESEED, 0);
DBCC CHECKIDENT('TestTables', RESEED, 0);