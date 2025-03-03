USE [Firma-De-Imobiliare];

DELETE FROM Agenti;
DELETE FROM Clienti;
DELETE FROM Proprietati;
DELETE FROM Servicii;
DELETE FROM ProprietatiServicii;
DELETE FROM Contacte;
DELETE FROM Contracte;
DELETE FROM FeedBack;
DELETE FROM Tranzactii;
DELETE FROM Plati;

DBCC CHECKIDENT('Agenti', RESEED, 0);
DBCC CHECKIDENT('Clienti', RESEED, 0);
DBCC CHECKIDENT('Proprietati', RESEED, 0);
DBCC CHECKIDENT('Servicii', RESEED, 0);
DBCC CHECKIDENT('Contacte', RESEED, 0);
DBCC CHECKIDENT('Contracte', RESEED, 0);
DBCC CHECKIDENT('FeedBack', RESEED, 0);
DBCC CHECKIDENT('Tranzactii', RESEED, 0);
DBCC CHECKIDENT('Plati', RESEED, 0);

INSERT INTO Agenti(nume, email, telefon, [comision(%)])
VALUES 
('Gigel Popescu', 'gigi.popescu@gmail.com', '0770174232', 10),
('Andrei Cioplescu', 'andy1124@hotmail.com', '0742120045', 15),
('Ileana Brazea', 'ileanabrazea@yahoo.com', '0721857419', 20),
('Mircea Veres', 'mirceav1212@gmail.com', '0772102744', 30),
('Antonio Mocan', 'antonio.mocanu2@gmail.com', '0774121435', 25);


INSERT INTO Clienti(nume, email, telefon, adresa, tip_client)
VALUES
('Vlad Mutu', 'vladmutu05@gmail.com', '0770102742', 'Aleea Mestecenilor 6', 'cumparator'),
('Marcel Mincic','mincicmarcel123@gmail.com','0771172211', 'Strada Louis Pasteur 12', 'vanzator'),
('Rusca Dan','ruscadan2002@yahoo.com', '0772105745', 'Strada Teodor Mihali 56', 'vanzator'),
('Adrian Pavel', 'adrian.pavel89@hotmail.com', '0745123456', 'Strada Bucegi 14', 'vanzator'),
('Diana Munteanu', 'diana.munteanu22@hotmail.com', '0723987654','Strada Bucuresti 20', 'cumparator');


INSERT INTO Proprietati(adresa, tip_proprietate, pret, [suprafata(m^2)], id_agent, id_proprietar)
VALUES
('Strada Horea, Nr. 45, Bl. C, Sc. 1, Ap. 12', 'apartament', 150000, 80, 4, 4),
('Strada Fagului, Nr. 22', 'casa', 350000, 150, 3, 3),
('Strada Liviu Rebreanu, Nr. 58', 'casa', 400000, 135, 2, 2),
('Strada Memorandumului, Nr. 32, Bl. B, Sc. 4, Ap. 8', 'apartament', 200000, 90, 4, 4),
('Strada Edgar Quinet, Nr.16, Bl. A, Sc. 1, Ap. 10', 'apartament', 160000, 90, 3, 3);


INSERT INTO Contracte(id_client, id_agent, [durata_contract(luni)])
VALUES
(1, 3, 12),
(3, 3, 12),
(5, 2, 24),
(2, 2, 24);


INSERT INTO Contacte(id_client, data_contactulul, tip_contact, descriere_contact)
VALUES
(5, '2023-09-12', 'telefon', 'Clientul este hotarat sa cumpere imobilul'),
(1, '2024-02-02', 'email', 'Clientul doreste sa afle daca pretul este negociabil'),
(2, '2023-07-12', 'telefon', 'Clientul doreste sa realizeze o sedinta foto pentru promovarea imobilului'),
(1, '2024-02-04', 'telefon', 'Clientul doreste sa achizitioneze imobilul'),
(4, '2023-01-01', 'telefon', 'Clientul vrea sa incheie contractul cu firma de imobiliare'),
(3, '2022-02-12', 'email', 'Clientul vrea sa deschida un contract cu firma de imobiliare pentru a-si promova imobilul');

INSERT INTO FeedBack(id_client, id_agent, descriere, evaluare)
VALUES
(4, 4, 'Clientul nu a fost multumit de promovarea realizata de agent', 2),
(5, 2, 'Clientul este foarte multumit de colaborarea cu agentul', 10),
(2, 2, 'Clientul este foarte multumit de colaborarea cu agentul', 9),
(1, 3, 'Clientul este multumit de agent, insa considera ca este loc de imbunatatiri', 7),
(3, 3, 'Clientul nu este nici dezamagit, dar nici multumit de prestatia agentului', 5);


INSERT INTO Servicii(nume, descriere, id_client, id_proprietate)
VALUES 
('Curatare', 'Curatarea intregului apartament', 4, 4),
('Fotografiere', 'Fotografiere imobil plus incarcare pe site-uri de promovare', 2, 3),
('3D Tour', 'Tur 3D a intregului imobil plus incarcare pe site-uri de promovare', 2, 4),
('Curatare', 'Curatarea intregului imobil', 3, 2),
('Fotografiere', 'Fotografiere imobil', 3, 5),
('Curatare', 'Curatarea intregului imobil', 3, 2);


INSERT INTO Tranzactii(id_proprietate, id_client, id_agent, [pret_final(Euro)], data_tranzactiei)
VALUES
(3, 5, 2, 380000, '2023-09-12'),
(2, 1, 5, 160000, '2024-01-02');


INSERT INTO Plati(id_tranzactie, suma, metoda_plata, data_plata)
VALUES
(1, 190000, 'Numerar', '2023-09-12'),
(1, 190000, 'Numerar', '2023-09-12'),
(2, 40000, 'Transfer bancar', '2024-01-02'),
(2, 40000, 'Transfer bancar', '2024-01-03'),
(2, 40000, 'Transfer bancar', '2024-01-04'),
(2, 40000, 'Transfer bancar', '2024-01-05');

INSERT INTO ProprietatiServicii(id_proprietate, id_serviciu, pret)
VALUES 
(4, 1, 200),
(3, 2, 400),
(4, 3, 1000),
(2, 4, 250),
(5, 5, 400),
(2, 6, 180);


SELECT * FROM Clienti;
SELECT * FROM Agenti;
SELECT * FROM Proprietati;
SELECT * FROM Servicii;
SELECT * FROM ProprietatiServicii;
SELECT * FROM Contacte;
SELECT * FROM Contracte;
SELECT * FROM FeedBack;
SELECT * FROM Tranzactii;
SELECT * FROM Plati;