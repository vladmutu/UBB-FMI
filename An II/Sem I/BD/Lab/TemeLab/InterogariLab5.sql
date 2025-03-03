USE [Firma-De-Imobiliare];

-- 1. Afiseaza numele, telefonul si emailul agentilor unici care au un comision mai mic de 20% si au reusit 
--tranzactii cu clienti cu o valoare finala peste 150000 de euro.
SELECT DISTINCT Agenti.nume, Agenti.telefon, Agenti.email
FROM Agenti
INNER JOIN Tranzactii ON Agenti.id_agent = Tranzactii.id_agent
INNER JOIN Proprietati ON Tranzactii.id_proprietate = Proprietati.id_proprietate
WHERE Agenti.[comision(%)] < 20 AND Tranzactii.[pret_final(Euro)] > 150000;

-- 2. Afiseaza numele si tipul de contact al clientilor unici care au contactat firma si sunt de tip 'cumparator' 
--si care 'doreste' sa cumpere apartamentul sau sa vada daca pretul este negociabil,
--iar pretul final este mai mic de 200000 de euro
SELECT DISTINCT Clienti.nume, Contacte.tip_contact, Contacte.descriere_contact, Tranzactii.[pret_final(Euro)]
FROM Clienti
INNER JOIN Contacte ON Clienti.id_client = Contacte.id_client
INNER JOIN Tranzactii ON Clienti.id_client = Tranzactii.id_client
WHERE Clienti.tip_client = 'cumparator' AND Tranzactii.[pret_final(Euro)] <= 200000
  AND Contacte.descriere_contact LIKE '%doreste%';

-- 3. Afiseaza adresa si tipul de serviciu unice pentru proprietatile care au avut servicii asociate, si care au servicii de curatare.
SELECT DISTINCT Proprietati.adresa, Servicii.nume AS tip_serviciu
FROM Proprietati
INNER JOIN ProprietatiServicii ON Proprietati.id_proprietate = ProprietatiServicii.id_proprietate
INNER JOIN Servicii ON ProprietatiServicii.id_serviciu = Servicii.id_serviciu
WHERE Servicii.nume LIKE 'curatare';

-- 4. Afiseaza numele clientilor care au facut o tranzactie in mai multe plati 
--si numarul total de plati realizate de acestia, dar doar pentru clientii care au facut cel putin 3 plati.
SELECT Clienti.nume, COUNT(Plati.id_plata) AS numar_plati
FROM Clienti
INNER JOIN Tranzactii ON Clienti.id_client = Tranzactii.id_client
INNER JOIN Plati ON Tranzactii.id_tranzactie = Plati.id_tranzactie
GROUP BY Clienti.nume
HAVING COUNT(Plati.id_plata) >= 3;

-- 5. Afiseaza numele agentilor si scorul mediu de evaluare primit, dar doar pentru agenții cu o medie mai mare de 7, 
--excluzand agentii care nu au feedback de la cel puțin 2 clienti.
SELECT Agenti.nume, AVG(FeedBack.evaluare) AS medie_evaluari
FROM Agenti
INNER JOIN FeedBack ON Agenti.id_agent = FeedBack.id_agent
INNER JOIN Tranzactii ON Agenti.id_agent = Tranzactii.id_agent
GROUP BY Agenti.nume
HAVING AVG(FeedBack.evaluare) > 7 AND COUNT(FeedBack.id_client) >= 2;

-- 6. Afiseaza numele fiecarui agent si adresele proprietatilor tranzactionate de acestia,
--unde tranzactiile au un pret final mai mare de 200000 de euro
SELECT DISTINCT Agenti.nume, Proprietati.adresa
FROM Agenti
INNER JOIN Tranzactii ON Agenti.id_agent = Tranzactii.id_agent
INNER JOIN Proprietati ON Tranzactii.id_proprietate = Proprietati.id_proprietate
WHERE Tranzactii.[pret_final(Euro)] >=200000;

-- 7. Afiseaza tipul de proprietate daca este 'casa' si numarul total de tranzactii.
SELECT Proprietati.tip_proprietate, COUNT(Tranzactii.id_tranzactie) AS numar_tranzactii
FROM Proprietati
INNER JOIN Tranzactii ON Proprietati.id_proprietate = Tranzactii.id_proprietate
INNER JOIN Clienti ON Tranzactii.id_client = Clienti.id_client
WHERE Proprietati.tip_proprietate LIKE 'casa'
GROUP BY Proprietati.tip_proprietate;

-- 8. Afiseaza numele clientilor, adresa proprietatilor si tipul de serviciu oferit fiecarei proprietati, 
--pentru clientii care au dorit sa efectueze servicii de curatare sau fotografiere asupra proprietatior lor
SELECT DISTINCT Clienti.nume AS nume_client, Proprietati.adresa AS adresa_proprietate, Servicii.nume AS tip_serviciu
FROM Clienti
INNER JOIN Servicii ON Clienti.id_client = Servicii.id_client
INNER JOIN Proprietati ON Servicii.id_proprietate = Proprietati.id_proprietate
INNER JOIN ProprietatiServicii ON Proprietati.id_proprietate = ProprietatiServicii.id_proprietate
WHERE Servicii.nume LIKE 'Fotografiere' OR Servicii.nume LIKE 'Curatare';

-- 9. Afiseaza agentii care au intocmit contracte pe mai mult de 12 luni si cu cati clienti au reusit acest lucru
SELECT COUNT(Clienti.nume) AS cati_clienti, Agenti.nume, Contracte.[durata_contract(luni)]
FROM Clienti
INNER JOIN Contracte ON Clienti.id_client = Contracte.id_client
INNER JOIN Agenti ON Contracte.id_agent = Agenti.id_agent
GROUP BY Agenti.nume, Contracte.[durata_contract(luni)]
HAVING Contracte.[durata_contract(luni)] > 12;

-- 10. Afiseaza adresa si tipul de proprietate, numele agentului responsabil si tipul de serviciu oferit
--pentru proprietatile de tip apartament
SELECT Proprietati.adresa, Proprietati.tip_proprietate, Agenti.nume AS nume_agent, Servicii.nume AS tip_serviciu
FROM Proprietati
INNER JOIN ProprietatiServicii ON Proprietati.id_proprietate = ProprietatiServicii.id_proprietate
INNER JOIN Servicii ON ProprietatiServicii.id_serviciu = Servicii.id_serviciu
INNER JOIN Agenti ON Proprietati.id_agent = Agenti.id_agent
WHERE Proprietati.tip_proprietate LIKE 'apartament';

