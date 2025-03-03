//
// Created by vladm on 4/2/2024.
//
#pragma once

/*
 * functie de test pentru adaugare masina in repository
 */
void testAddRepo();

/*
 * functie de test pentru validarea unei masini
 */
void testValidateMasina();

/*
 * functie de test pentru stergerea unei masini
 */
void testStergeMasina();

/*
 * functie de test pentru modificarea unei masini
 */
void testModificaMasina();

/*
 * functie de test pentru adaugarea unei masini in service
 */
void testAdaugaMasinaService();

/*
 * functie de test pentru stergerea unei masini in service
 */
void testStergeMasinaService();

/*
 * functie de test pentru modificarea unei masini in service
 */
void testModificaMasinaService();

/*
 * functie de test mesajul de exceptie din repo
 */
void testRepoExceptionMsg();

/*
 * functie de test mesajul de exceptie din domain
 */
void testMasinaExceptionMsg();

/*
 * functie de test pentru masina& operator=
 */
void testOperator();

/*
 * functie de test pentru filtrarea dupa producator
 */
void testFilterProducator();

/*
 * functie de test pentru filtrarea dupa tip
 */
void testFilterTip();

/*
 * functie de test pentru sortare
 */
void testSortare();

/*
 * functie de test pentru operatorul de atribuire
 */
void testAssignmentOperator();

/*
 * functie de test pentru sortarea dupa producator
 */
void testSortProducator();

/*
 * functie de test pentru sortarea dupa model
 */
void testSortModel();

/*
 * functie ce apeleaza toate testele
 */
void allTests();