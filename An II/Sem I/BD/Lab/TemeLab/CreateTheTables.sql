CREATE DATABASE [Firma-De-Imobiliare];

USE [Firma-De-Imobiliare];

CREATE TABLE Agenti(
	id_agent INT PRIMARY KEY IDENTITY(1,1),
	nume VARCHAR(100) NOT NULL,
	email VARCHAR(100) NOT NULL CHECK (email LIKE '%_@_%._%'),
	telefon VARCHAR(10) NOT NULL CHECK (LEN(telefon) = 10),
	[comision(%)] INT NOT NULL CHECK ([comision(%)] BETWEEN 0 AND 100)
);

CREATE TABLE Proprietati(
	id_proprietate INT PRIMARY KEY IDENTITY(1,1),
	adresa VARCHAR(100) NOT NULL,
	tip_proprietate VARCHAR(100) NOT NULL,
	pret INT NOT NULL,
	[suprafata(m^2)] INT NOT NULL,
	id_agent INT NOT NULL,
	id_proprietar INT NOT NULL FOREIGN KEY REFERENCES Clienti(id_client) ON DELETE NO ACTION ON UPDATE NO ACTION,
	CONSTRAINT FK_Proprietati_Agenti FOREIGN KEY(id_agent) 
		REFERENCES Agenti(id_agent) 
		ON DELETE CASCADE ON UPDATE CASCADE
);



CREATE TABLE Clienti(
	id_client INT PRIMARY KEY IDENTITY(1,1),
	nume VARCHAR(100) NOT NULL,
	email VARCHAR(100) NOT NULL CHECK (email LIKE '%_@_%._%'),
	telefon VARCHAR(10) NOT NULL CHECK (LEN(telefon) = 10),
	adresa VARCHAR(100) NOT NULL,
	tip_client VARCHAR(15) NOT NULL CHECK(tip_client LIKE 'cumparator' OR tip_client LIKE 'vanzator')
);

CREATE TABLE Tranzactii(
	id_tranzactie INT PRIMARY KEY IDENTITY(1,1),
	id_proprietate INT NOT NULL,
	id_client INT NOT NULL,
	id_agent INT NOT NULL,
	[pret_final(Euro)] INT NOT NULL,
	data_tranzactiei DATE NOT NULL,
	CONSTRAINT FK_Tranzactii_Proprietati FOREIGN KEY(id_proprietate) 
		REFERENCES Proprietati(id_proprietate) 
		ON DELETE CASCADE ON UPDATE CASCADE,
	CONSTRAINT FK_Tranzactii_Clienti FOREIGN KEY(id_client) 
		REFERENCES Clienti(id_client) 
		ON DELETE CASCADE ON UPDATE CASCADE,
	CONSTRAINT FK_Tranzactii_Agenti FOREIGN KEY(id_agent) 
		REFERENCES Agenti(id_agent) 
		ON DELETE NO ACTION ON UPDATE NO ACTION
);

CREATE TABLE Servicii(
	id_serviciu INT PRIMARY KEY IDENTITY(1,1),
	nume VARCHAR(100) NOT NULL,
	descriere VARCHAR(512) NOT NULL
	id_client INT NOT NULL FOREIGN KEY REFERENCES Clienti(id_client) ON DELETE CASCADE ON UPDATE CASCADE,
	id_proprietate INT NOT NULL FOREIGN KEY REFERENCES Proprietati(id_proprietate) ON DELETE NO ACTION ON UPDATE NO ACTION
);

CREATE TABLE ProprietatiServicii(
	id_proprietate INT NOT NULL,
	id_serviciu INT NOT NULL,
	pret INT NOT NULL
	CONSTRAINT FK_ProprietatiServicii_Proprietate FOREIGN KEY(id_proprietate) 
		REFERENCES Proprietati(id_proprietate) 
		ON DELETE CASCADE ON UPDATE CASCADE,
	CONSTRAINT FK_ProprietatiServicii_Serviciu FOREIGN KEY(id_serviciu) 
		REFERENCES Servicii(id_serviciu) 
		ON DELETE CASCADE ON UPDATE CASCADE,
	PRIMARY KEY(id_proprietate, id_serviciu)
);

CREATE TABLE Plati(
	id_plata INT PRIMARY KEY IDENTITY(1,1),
	id_tranzactie INT NOT NULL,
	suma DECIMAL(10,2) NOT NULL,
	metoda_plata VARCHAR(100) NOT NULL CHECK(metoda_plata LIKE 'Numerar' OR metoda_plata LIKE 'Transfer bancar'),
	data_plata DATE NOT NULL,
	CONSTRAINT FK_Plati_Tranzactii FOREIGN KEY(id_tranzactie) 
		REFERENCES Tranzactii(id_tranzactie) 
		ON DELETE CASCADE ON UPDATE CASCADE
);

CREATE TABLE Contacte(
	id_contact INT PRIMARY KEY IDENTITY(1,1),
	id_client INT NOT NULL,
	data_contactulul DATE NOT NULL,
	tip_contact VARCHAR(100) NOT NULL CHECK(tip_contact LIKE 'email' OR tip_contact LIKE 'telefon'),
	descriere_contact VARCHAR(512) NOT NULL,
	CONSTRAINT FK_Contacte_Clienti FOREIGN KEY(id_client) 
		REFERENCES Clienti(id_client) 
		ON DELETE CASCADE ON UPDATE CASCADE
);

CREATE TABLE FeedBack(
	id_feedback INT PRIMARY KEY IDENTITY(1,1),
	id_client INT NOT NULL,
	id_agent INT NOT NULL,
	descriere VARCHAR(512) NOT NULL,
	evaluare INT NOT NULL CHECK(evaluare BETWEEN 1 AND 10),
	CONSTRAINT FK_FeedBack_Client FOREIGN KEY(id_client) 
		REFERENCES Clienti(id_client) 
		ON DELETE CASCADE ON UPDATE CASCADE,
	CONSTRAINT FK_FeedBack_Agent FOREIGN KEY(id_agent) 
		REFERENCES Agenti(id_agent) 
		ON DELETE CASCADE ON UPDATE CASCADE
);

CREATE TABLE Contracte(
	id_contract INT PRIMARY KEY IDENTITY(1,1),
	id_client INT NOT NULL,
	id_agent INT NOT NULL,
	[durata_contract(luni)] INT NOT NULL,
	CONSTRAINT FK_Contracte_Clienti FOREIGN KEY(id_client) 
		REFERENCES Clienti(id_client) 
		ON DELETE CASCADE ON UPDATE CASCADE,
	CONSTRAINT FK_Contracte_Agenti FOREIGN KEY(id_agent) 
		REFERENCES Agenti(id_agent) 
		ON DELETE CASCADE ON UPDATE CASCADE
);
