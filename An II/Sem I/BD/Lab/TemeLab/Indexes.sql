--ProprietatiServicii
--Proprietati
--Servicii
--Clienti
--Agenti
USE [Firma-De-Imobiliare];
--Views

--view pentru observarea numarului de proprietati asupra carora s-au efectuat anumite tipuri de servicii
GO
CREATE OR ALTER VIEW View_ProprietatiServicii
AS
	SELECT COUNT(P.pret) AS [De cate ori], S.nume
	FROM ProprietatiServicii AS PS
	INNER JOIN Proprietati AS P 
	ON P.id_proprietate = PS.id_proprietate
	INNER JOIN Servicii AS S
	ON S.id_serviciu = PS.id_serviciu
	GROUP BY S.nume
GO

SELECT * FROM View_ProprietatiServicii;

--indecsi pentru optimizarea join-urilor
CREATE NONCLUSTERED INDEX NIX_proprietati_servicii ON ProprietatiServicii(id_proprietate, id_serviciu);
CREATE NONCLUSTERED INDEX NIX_servicii_proprietati ON ProprietatiServicii(id_serviciu, id_proprietate);

--indecsi pentru optimizarea gruparilor
CREATE NONCLUSTERED INDEX NIX_nume_serviciu ON Servicii(nume);
CREATE NONCLUSTERED INDEX NIX_proprietati_pret ON Proprietati(pret);

--view pentru aflarea numarului de agenti asociat fiecarul client
GO
CREATE OR ALTER VIEW View_Proprietati_Clienti
AS
	SELECT COUNT(A.nume) AS [Cati Agenti], C.nume AS [Nume Client]
	FROM Proprietati AS P
	INNER JOIN Agenti AS A
	ON P.id_agent = A.id_agent
	INNER JOIN Clienti AS C
	ON P.id_proprietar = C.id_client
	GROUP BY C.nume;
GO

SELECT * FROM View_Proprietati_Clienti;

--indecsi pentru optimizarea filtrarilor si gruparilor
CREATE NONCLUSTERED INDEX NIX_nume_agent ON Agenti(nume);
CREATE NONCLUSTERED INDEX NIX_nume_proprietar ON Clienti(nume);
--indecsi pentru optimizarea join-urilor
CREATE NONCLUSTERED INDEX NIX_proprietati_agenti_proprietari ON Proprietati(id_proprietar, id_agent);
CREATE NONCLUSTERED INDEX NIX_proprietati_proprietari_agenti ON Proprietati(id_agent, id_proprietar);
--CRUD

--pt crud client
--validare tip client
GO
CREATE OR ALTER FUNCTION Validare_tip_client(@tip_client VARCHAR(100))
RETURNS BIT AS
BEGIN
	IF(@tip_client = 'cumparator' OR @tip_client = 'vanzator')
		RETURN 1;
	RETURN 0;
END;
GO

--validare email
GO
CREATE OR ALTER FUNCTION Validare_email_client(@email VARCHAR(100))
RETURNS BIT AS
BEGIN
	IF(@email LIKE '%_@%_.%_')
		RETURN 1;
	RETURN 0;
END;
GO

--validare telefon
GO
CREATE OR ALTER FUNCTION Validare_telefon_client(@telefon VARCHAR(100))
RETURNS BIT AS
BEGIN 
	IF(LEN(@telefon) = 10 AND TRY_CAST(@telefon AS INT) IS NOT NULL)
		RETURN 1;
	RETURN 0;
END;
GO

--validare generala Clienti
GO
CREATE OR ALTER FUNCTION Validare_Client(
@nume VARCHAR(100), 
@telefon NVARCHAR(100), 
@email NVARCHAR(100),	
@tip_client NVARCHAR(100), 
@adresa NVARCHAR(100))
RETURNS BIT AS
BEGIN
	IF(dbo.Validare_email_client(@email) = 1 AND
		dbo.Validare_telefon_client(@telefon) = 1 AND
		dbo.Validare_tip_client(@tip_client) = 1 AND
		@nume IS NOT NULL AND
		@adresa IS NOT NULL AND
		LEN(@nume) > 0 AND
		LEN(@adresa) > 0)
		RETURN 1;
	RETURN 0;
END;
GO

--verificare existenta ID Client
GO
CREATE OR ALTER FUNCTION Validare_id_client(@id INT)
RETURNS BIT AS
BEGIN
	IF(NOT EXISTS(SELECT * FROM Clienti WHERE id_client = @id))
		RETURN 0;
	RETURN 1;
END;
GO



--CRUD pt Clienti



--C
GO 
CREATE OR ALTER PROCEDURE create_client(
@nume VARCHAR(100), 
@email VARCHAR(100), 
@telefon VARCHAR(100), 
@adresa VARCHAR(100),
@tip_client VARCHAR(100)) AS
BEGIN
	IF(dbo.Validare_Client(@nume, @telefon, @email, @tip_client, @adresa) = 1)
	BEGIN
		INSERT INTO Clienti(nume, email, telefon, adresa, tip_client) VALUES
		(@nume, @email, @telefon, @adresa, @tip_client);
		PRINT 'Clientul a fost adaugat cu succes';
	END
	ELSE
	BEGIN
		RAISERROR('Datele clientului nu pot fi validate
				email trebuie sa fie de forma ceva@ceva.ceva
				telefon trebuie sa fie de lungime 10 si sa contina doar cifre
				tip_client trebuie sa fie cumparator sau vanzator
				iar adresa si nume trebuie sa fie nenule', 16, 1);
	END
END
GO

EXECUTE create_client 'test', 'test@gmail.com', '0770102742', 'test', 'cumparator';


--R
GO 
CREATE OR ALTER PROCEDURE read_client(@id_client INT) AS
BEGIN
	IF(dbo.Validare_id_client(@id_client) = 1)
	BEGIN
		SELECT * FROM Clienti WHERE id_client = @id_client;
		PRINT 'Client afisat cu succes';
	END
	ELSE
	BEGIN
		RAISERROR('Clientul cu acest id nu exista',16,1);
	END
END
GO

EXECUTE read_client 9;

--U
GO
CREATE OR ALTER PROCEDURE update_client(
@id_client INT, 
@nume VARCHAR(100), 
@email VARCHAR(100), 
@telefon VARCHAR(100),
@adresa VARCHAR(100),
@tip_client VARCHAR(100)) AS
BEGIN
	IF(dbo.Validare_id_client(@id_client) = 0)
	BEGIN
		RAISERROR('Clientul nu exista',16,1)
	END;
	ELSE
	BEGIN
		IF(dbo.Validare_Client(@nume, @telefon, @email, @tip_client, @adresa) = 1)
		BEGIN
			UPDATE Clienti
			SET nume = @nume, email = @email, telefon = @telefon, adresa = @adresa, tip_client = @tip_client
			WHERE id_client = @id_client
			PRINT 'Client actualizat cu succes'
		END;
		ELSE
		BEGIN
			RAISERROR('Datele clientului nu pot fi validate
					email trebuie sa fie de forma ceva@ceva.ceva
					telefon trebuie sa fie de lungime 10 si sa contina doar cifre
					tip_client trebuie sa fie cumparator sau vanzator
					iar adresa si nume trebuie sa fie nenule', 16, 1);
		END;
	END;
END
GO

EXECUTE update_client 9, 'test', 'test@gmail.com', '0770102742', 'test', 'vanzator';

--D
GO
CREATE OR ALTER PROCEDURE delete_client(@id_client INT) AS
BEGIN
	IF(dbo.Validare_id_client(@id_client) = 0)
	BEGIN
		RAISERROR('Acest client nu exista', 16, 1);
	END
	ELSE
	BEGIN
		DELETE FROM Clienti
		WHERE id_client = @id_client;
		PRINT 'S-a sters clientul cu id-ul dat';
	END
END
GO

EXECUTE delete_client 10;

--validari pt Agenti
--comision
GO
CREATE OR ALTER FUNCTION Validare_comision_agent(@comision INT)
RETURNS BIT AS
BEGIN
	IF(@comision <= 100 AND @comision >= 0)
		RETURN 1;
	RETURN 0;
END;
GO

--email
GO
CREATE OR ALTER FUNCTION Validare_email_agent(@email VARCHAR(100))
RETURNS BIT AS
BEGIN
	IF(@email LIKE '%_@%_.%_')
		RETURN 1;
	RETURN 0;
END;
GO

--telefon
GO 
CREATE OR ALTER FUNCTION Validare_telefon_agent(@telefon VARCHAR(100))
RETURNS BIT AS
BEGIN 
	IF(LEN(@telefon) = 10 AND TRY_CAST(@telefon AS INT) IS NOT NULL)
		RETURN 1;
	RETURN 0;
END;
GO

--id
GO
CREATE OR ALTER FUNCTION Validare_id_agent(@id_agent INT)
RETURNS BIT AS
BEGIN
	IF(NOT EXISTS(SELECT * FROM Agenti WHERE id_agent = @id_agent))
		RETURN 0;
	RETURN 1;
END
GO


--validare generala pt agenti
GO
CREATE OR ALTER FUNCTION Validare_agent(
@nume VARCHAR(100),
@email VARCHAR(100),
@telefon VARCHAR(100),
@comision INT)
RETURNS BIT AS
BEGIN
	IF(dbo.Validare_email_agent(@email) = 1 AND
		dbo.Validare_comision_agent(@comision) = 1 AND
		dbo.Validare_telefon_agent(@telefon) = 1 AND
		@nume IS NOT NULL AND 
		LEN(@nume) > 0)
		RETURN 1;
	RETURN 0;
END
GO


--CRUD pt Agenti


--C
GO
CREATE OR ALTER PROCEDURE Create_agent(
@nume VARCHAR(100),
@email VARCHAR(100),
@telefon VARCHAR(100),
@comision INT) AS
BEGIN
	IF(dbo.Validare_agent(@nume, @email, @telefon, @comision) = 0)
		RAISERROR('Datele nu pot fi validate
					nume trebuie sa nu fie null
					email trebuie sa fie de forma ceva@ceva.ceva
					telefon trebuie sa aiba lungimea 10 si sa contina doar cifre
					comision trebuie sa fie intre 0 si 100',16,1);
	ELSE
	BEGIN
		INSERT INTO Agenti(nume, email,telefon,[comision(%)]) VALUES
		(@nume, @email, @telefon, @comision);
		PRINT 'Agentul a fost inserat cu succes';
	END
END
GO

EXECUTE create_agent 'Agent', 'ceva@gmail.com', '0000000000', 10;

--R
GO
CREATE OR ALTER PROCEDURE Read_agent(@id_agent INT) AS
BEGIN 
	IF(dbo.Validare_id_agent(@id_agent) = 0)
		RAISERROR('Acest agent nu exista',16,1);
	ELSE
	BEGIN
		SELECT * FROM Agenti WHERE id_agent = @id_agent;
		PRINT 'Agent afisat cu succes';
	END
END
GO

EXECUTE Read_agent 9;

--U
GO
CREATE OR ALTER PROCEDURE Update_agent(
@id_agent INT,
@nume NVARCHAR(100),
@email NVARCHAR(100),
@telefon NVARCHAR(100),
@comision INT) AS
BEGIN
	IF(dbo.Validare_id_agent(@id_agent) = 0)
		RAISERROR('Agentul cu acest id nu exista',16,1);
	IF(dbo.Validare_agent(@nume, @email, @telefon, @comision) = 0)
		RAISERROR('Datele nu pot fi validate
					nume trebuie sa nu fie null
					email trebuie sa fie de forma ceva@ceva.ceva
					telefon trebuie sa aiba lungimea 10 si sa contina doar cifre
					comision trebuie sa fie intre 0 si 100',16,1);
	ELSE
	BEGIN
		UPDATE Agenti
		SET nume = @nume, email = @email, telefon = @telefon, [comision(%)] = @comision
		WHERE id_agent = @id_agent;
		PRINT 'S-au actualizat datele agentului dorit';
	END
END
GO

EXECUTE Update_agent 9, 'Agent test', 'test4@gmail.com', '0000000000', 50;

--D
GO 
CREATE OR ALTER PROCEDURE Delete_agent(@id INT) AS
BEGIN
	IF(dbo.Validare_id_agent(@id) = 0)
		RAISERROR('Agentul cu acest id nu exista',16,1);
	ELSE
	BEGIN
		DELETE FROM Agenti
		WHERE id_agent = @id;
		PRINT 'S-a sters agentul dorit';
	END
END
GO

EXECUTE Delete_agent 10;


--CRUD pt Proprietati
--validare tip
GO
CREATE OR ALTER FUNCTION Verificare_tip_proprietate(@tip_proprietate NVARCHAR(100))
RETURNS BIT AS
BEGIN
	IF(@tip_proprietate = 'casa' OR @tip_proprietate = 'apartament')
		RETURN 1;
	RETURN 0;
END
GO

--verificare id_proprietate
GO
CREATE OR ALTER FUNCTION Verificare_id_proprietate(@id_proprietate INT)
RETURNS BIT AS
BEGIN
	IF(NOT EXISTS(SELECT * FROM Proprietati WHERE id_proprietate = @id_proprietate))
		RETURN 0;
	RETURN 1;
END
GO

--verificare id_proprietar
GO
CREATE OR ALTER FUNCTION Verificare_id_proprietar(@id_proprietar INT)
RETURNS BIT AS
BEGIN
	IF(NOT EXISTS(SELECT * FROM Clienti WHERE id_client = @id_proprietar))
		RETURN 0;
	RETURN 1;
END
GO

--validare id_agent
GO
CREATE OR ALTER FUNCTION Verificare_id_agent_pt_proprietate(@id_agent INT)
RETURNS BIT AS
BEGIN
	IF(NOT EXISTS(SELECT * FROM Agenti WHERE id_agent = @id_agent))
		RETURN 0;
	RETURN 1;
END
GO

--validare proprietate
GO 
CREATE OR ALTER FUNCTION Validare_proprietate(
@adresa VARCHAR(100),
@tip_proprietate NVARCHAR(100),
@id_agent INT,
@id_proprietar INT,
@pret INT,
@suprafara INT)
RETURNS BIT AS
BEGIN
	IF(dbo.Verificare_id_proprietar(@id_proprietar) = 1
		AND dbo.Verificare_tip_proprietate(@tip_proprietate) = 1
		AND dbo.Verificare_id_agent_pt_proprietate(@id_agent) = 1
		AND @adresa IS NOT NULL
		AND @pret IS NOT NULL
		AND @suprafara IS NOT NULL
		AND LEN(@adresa) > 0)
		RETURN 1;
	RETURN 0;
END
GO

--C
GO
CREATE OR ALTER PROCEDURE Create_Proprietate(
@adresa NVARCHAR(100),
@tip_proprietate NVARCHAR(100),
@pret INT,
@suprafata INT,
@id_agent INT,
@id_proprietar INT) AS
BEGIN
	IF(dbo.Validare_proprietate(@adresa, @tip_proprietate, @id_agent, @id_proprietar, @pret, @suprafata) = 0)
		RAISERROR('Datele nu pot fi validate
				adresa, pret si suprafata nu trebuie sa fie null
				tip_proprietate trebuie sa fie casa sau apartament
				id_agent si id_proprietar trebuie sa fie id-uri existente in tabelele Agenti, respectiv Clienti', 16, 1);
	ELSE
	BEGIN
		INSERT INTO Proprietati(adresa, tip_proprietate, pret, [suprafata(m^2)], id_agent, id_proprietar) VALUES
		(@adresa, @tip_proprietate, @pret, @suprafata, @id_agent, @id_proprietar);
		PRINT 'Proprietate a fost inserata cu succes';
	END
END
GO

EXECUTE Create_Proprietate 'test', 'casa', 5, 7, 1, 1;


--R
GO
CREATE OR ALTER PROCEDURE Read_Proprietate(@id_proprietate INT)
AS
BEGIN
	IF(dbo.Verificare_id_proprietate(@id_proprietate) = 0)
		RAISERROR('Nu exista o proprietate cu acest id', 16, 1);
	ELSE
	BEGIN
		SELECT * FROM Proprietati WHERE id_proprietate = @id_proprietate;
		PRINT 'Proprietate afisata cu succes';
	END
END
GO

SELECT * FROM Proprietati;

EXECUTE Read_Proprietate 1014;

--U
GO
CREATE OR ALTER PROCEDURE Update_Proprietate(
@id_proprietate INT,
@adresa NVARCHAR(100),
@tip_proprietate NVARCHAR(100),
@pret INT,
@suprafata INT,
@id_agent INT,
@id_proprietar INT) AS
BEGIN
	IF(dbo.Verificare_id_proprietate(@id_proprietate) = 0)
		RAISERROR('Nu exista o proprietate cu acest id', 16, 1);
	IF(dbo.Validare_proprietate(@adresa, @tip_proprietate, @id_agent, @id_proprietar, @pret, @suprafata) = 0)
		RAISERROR('Datele nu pot fi validate
				adresa, pret si suprafata nu trebuie sa fie null
				tip_proprietate trebuie sa fie casa sau apartament
				id_agent si id_proprietar trebuie sa fie id-uri existente in tabelele Agenti, respectiv Clienti', 16, 1);
	ELSE
	BEGIN
		UPDATE Proprietati
		SET adresa = @adresa, tip_proprietate = @tip_proprietate, pret = @pret, [suprafata(m^2)] = @suprafata, id_agent = @id_agent, id_proprietar = @id_proprietar
		WHERE id_proprietate = @id_proprietate;
		PRINT 'S-a actualizat proprietatea  dorita';
	END
END
GO

EXECUTE Update_Proprietate 4, 'test', 'casa', 10, 10, 4, 4;
SELECT * FROM Proprietati WHERE id_proprietate = 4;

--D
GO
CREATE OR ALTER PROCEDURE Delete_Proprietate(@id_proprietate INT) AS
BEGIN
	IF(dbo.Verificare_id_proprietate(@id_proprietate) = 0)
		RAISERROR('Nu exista o proprietate cu acest id', 16, 1);
	ELSE
	BEGIN
		DELETE FROM Proprietati
		WHERE id_proprietate = @id_proprietate;
		PRINT 'Proprietatea a fost stearsa cu succes';
	END
END
GO

EXECUTE Delete_Proprietate 1014;



--CRUD pt Servicii
--validare id serviciu
GO
CREATE OR ALTER FUNCTION Verificare_id_serviciu(@id_serviciu INT)
RETURNS BIT AS
BEGIN
	IF(NOT EXISTS(SELECT * FROM Servicii WHERE id_serviciu = @id_serviciu))
		RETURN 0;
	RETURN 1;
END
GO

--validare id_proprietate
GO
CREATE OR ALTER FUNCTION Verificare_id_proprietate_pt_servicii(@id_proprietate INT)
RETURNS BIT AS
BEGIN
	IF(NOT EXISTS(SELECT * FROM Proprietati WHERE id_proprietate = @id_proprietate))
		RETURN 0;
	RETURN 1;
END
GO

--verificare id_Client
GO
CREATE OR ALTER FUNCTION Verificare_id_client_pt_servicii(@id_client INT)
RETURNS BIT AS
BEGIN
	IF(NOT EXISTS(SELECT * FROM Clienti WHERE id_client = @id_client))
		RETURN 0;
	RETURN 1;
END
GO

--validare serviciu
GO
CREATE OR ALTER FUNCTION Validare_serviciu
(
@nume VARCHAR(100),
@descriere VARCHAR(100),
@id_client INT,
@id_proprietate INT
)
RETURNS BIT AS
BEGIN
	IF(dbo.Verificare_id_client_pt_servicii(@id_client) = 1
		AND dbo.Verificare_id_proprietate_pt_servicii(@id_proprietate) = 1
		AND @nume IS NOT NULL
		AND @descriere IS NOT NULL
		AND LEN(@nume) > 0
		AND LEN(@descriere) > 0)
		RETURN 1;
	RETURN 0;
END
GO

--C
GO
CREATE OR ALTER PROCEDURE Create_Serviciu(
@nume VARCHAR(100),
@descriere VARCHAR(200),
@id_client INT,
@id_proprietate INT) AS
BEGIN
	IF(dbo.Validare_serviciu(@nume, @descriere, @id_client, @id_proprietate) = 0)
		RAISERROR('Nu se pot valida datele
				nume si descriere trebuie sa fie nenule
				id_client si id_proprietate trebuie sa fie id-uri valide din tabelurile Clienti, respectiv Proprietati', 16, 1);
	ELSE
	BEGIN
		INSERT INTO Servicii(nume, descriere, id_client, id_proprietate) VALUES
		(@nume, @descriere, @id_client, @id_proprietate);
		PRINT 'Serviciul a fost inserat cu succes';
	END
END
GO

EXECUTE Create_Serviciu '', '', 10, 10;


--R
GO
CREATE OR ALTER PROCEDURE Read_Serviciu(@id_serviciu INT) AS
BEGIN
	IF(dbo.Verificare_id_serviciu(@id_serviciu) = 0)
		RAISERROR('Nu exista un serviciu cu acest id', 16, 1);
	ELSE
	BEGIN
		SELECT * FROM Servicii WHERE id_serviciu = @id_serviciu;
		PRINT 'Serviciul a fost afisat cu succes';
	END
END
GO

EXECUTE Read_Serviciu 13;

--U
GO
CREATE OR ALTER PROCEDURE Update_serviciu(
@id_serviciu INT,
@nume VARCHAR(100),
@descriere VARCHAR(100),
@id_client INT,
@id_proprietate INT) AS
BEGIN
	IF(dbo.Verificare_id_serviciu(@id_serviciu) = 0)
		RAISERROR('Nu exista un serviciu cu acest id', 16, 1);
	IF(dbo.Validare_serviciu(@nume , @descriere, @id_client, @id_proprietate) = 0)
		RAISERROR('Nu se pot valida datele
				nume si descriere trebuie sa fie nenule
				id_client si id_proprietate trebuie sa fie id-uri valide din tabelurile Clienti, respectiv Proprietati', 16, 1);
	ELSE
	BEGIN
		UPDATE Servicii
		SET nume = @nume, descriere = @descriere, id_client = @id_client, id_proprietate = @id_proprietate
		WHERE id_serviciu = @id_serviciu;
		PRINT 'Serviciul dorit a fost actualizat cu succes';
	END
END
GO

EXECUTE Update_serviciu 13, '', '', 3, 4;

--D
GO
CREATE OR ALTER PROCEDURE Delete_Serviciu(@id_serviciu INT) AS
BEGIN
	IF(dbo.Verificare_id_serviciu(@id_serviciu) = 0)
		RAISERROR('Nu exista un serviciu cu acest id', 16, 1);
	ELSE
	BEGIN
		DELETE FROM Servicii
		WHERE id_serviciu = @id_serviciu;
		PRINT 'Serviciul a fost sters cu succes';
	END;
END
GO

EXECUTE Delete_Serviciu 14;


--CRUD pt ProprietatiServicii
--verificare id_proprietate pt ps
GO
CREATE OR ALTER FUNCTION Verificare_id_proprietate_pt_ps(@id_proprietate INT)
RETURNS BIT AS
BEGIN
	IF(NOT EXISTS(SELECT * FROM Proprietati WHERE id_proprietate = @id_proprietate))
		RETURN 0;
	RETURN 1;
END
GO

--verificare id_serviciu pt ps
GO
CREATE OR ALTER FUNCTION Verificare_id_serviciu_pt_ps(@id_serviciu INT)
RETURNS BIT AS
BEGIN
	IF(NOT EXISTS(SELECT * FROM Servicii WHERE id_serviciu = @id_serviciu))
		RETURN 0;
	RETURN 1;
END
GO


--validare generala pt ps
GO
CREATE OR ALTER FUNCTION Validare_ProprietatiServiciu(@pret INT, @id_serviciu INT, @id_proprietate INT)
RETURNS BIT AS
BEGIN
	IF(@pret IS NULL)
	BEGIN
		RETURN 0;
	END
	IF(dbo.Verificare_id_proprietate_pt_ps(@id_proprietate) = 1 AND
		dbo.Verificare_id_serviciu_pt_ps(@id_serviciu) = 1)
		RETURN 1;
	RETURN 0;
END
GO

--validare id_ps
GO
CREATE OR ALTER FUNCTION Validare_ids(@id_proprietate INT, @id_serviciu INT)
RETURNS BIT AS
BEGIN
	IF(NOT EXISTS(SELECT * FROM ProprietatiServicii WHERE id_proprietate = @id_proprietate AND id_serviciu = @id_serviciu))
		RETURN 0;
	RETURN 1;
END
GO


--C
GO
CREATE OR ALTER PROCEDURE Create_ProprietatiServicii(@id_proprietate INT, @id_serviciu INT, @pret INT) AS
BEGIN
	IF(dbo.Validare_ProprietatiServiciu(@pret, @id_serviciu, @id_proprietate) = 0)
		RAISERROR('Datele nu pot fi validate
				pret trebuie sa fie nenul
				id_serviciu si id_proprietate trebuie sa fie id-uri valide din tabelul Servicii, respectiv Proprietati', 16,1);
	ELSE
	BEGIN
		INSERT INTO ProprietatiServicii(id_serviciu, id_proprietate, pret) VALUES
		(@id_serviciu, @id_proprietate, @pret);
		PRINT 'Datele au fost introduse cu succes in tabel';
	END;
END
GO

EXECUTE Create_ProprietatiServicii 10, 10, 200;

--R
GO
CREATE OR ALTER PROCEDURE Read_ProprietatiServicii(@id_serviciu INT, @id_proprietate INT) AS
BEGIN
	IF(dbo.Validare_ids(@id_proprietate, @id_serviciu) = 0)
		RAISERROR('Nu exista o intrare in tabel cu aceste id-uri', 16, 1);
	ELSE
	BEGIN
		SELECT * FROM ProprietatiServicii WHERE id_serviciu = @id_serviciu AND id_proprietate = @id_proprietate;
		PRINT 'Datele au fost afisate cu succes';
	END
END
GO

EXECUTE Read_ProprietatiServicii 1, 4;

--U
GO
CREATE OR ALTER PROCEDURE Update_ProprietatiServicii(@id_serviciu INT, @id_proprietate INT, @pret INT) AS
BEGIN
	IF(dbo.Validare_ProprietatiServiciu(@pret, @id_serviciu, @id_proprietate) = 0)
		RAISERROR('Datele nu pot fi validate
				pret trebuie sa fie nenul
				id_serviciu si id_proprietate trebuie sa fie id-uri valide din tabelul Servicii, respectiv Proprietati', 16,1);
	ELSE
	BEGIN
		IF(dbo.Validare_ids(@id_proprietate, @id_serviciu) = 0)
		BEGIN
			RAISERROR('Nu exista o intrare in tabel cu aceste id-uri', 16, 1);
		END
		ELSE
		BEGIN
			UPDATE ProprietatiServicii
			SET pret = @pret
			WHERE id_proprietate = @id_proprietate AND id_serviciu = @id_serviciu;
			PRINT 'S-au actualizat datele';
		END
	END
END
GO


EXECUTE Update_ProprietatiServicii 1, 4, 0;

--D
GO
CREATE OR ALTER PROCEDURE Delete_ProprietatiServicii(@id_proprietate INT, @id_serviciu INT) AS
BEGIN
	IF(dbo.Validare_ids(@id_proprietate, @id_serviciu) = 0)
		RAISERROR('Nu exista o intrare in tabel cu aceste id-uri', 16, 1);
	ELSE
	BEGIN
		DELETE FROM ProprietatiServicii
		WHERE id_proprietate = @id_proprietate AND id_serviciu = @id_serviciu;
		PRINT 'Datele au fost sterse cu succes';
	END
END
GO

EXECUTE Delete_ProprietatiServicii 1, 2;