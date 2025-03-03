//
// Created by vladm on 3/13/2024.
//source file pentru functiile de test

#include "tests.h"
#include "electronic.h"
#include "electronicrepository.h"
#include "electronicservice.h"
#include "assert.h"
#include "string.h"
#include <stdio.h>

/*
 * functie de test pentru crearea unui electrocasnic
 */
void testCreateElectronic()
{
    Electronic elem;
    int ID = 1;
    char type[] = "masina";
    char producer[] = "Renault";
    char model[] = "Clio";
    int price = 4500;
    int quantity = 5;
    elem = createElectronic(ID, type, producer, model, price, quantity);
    assert(elem.ID == ID);
    assert(strcmp(elem.type, type) == 0);
    assert(strcmp(elem.producer, producer) == 0);
    assert(strcmp(elem.model, model) == 0);
    assert(elem.price == price);
    assert(elem.quantity == quantity);
}

/*
 * functie de test pentru validator electrocasnic
 */
void testValidateElectronic()
{
    Electronic elem;
    int ID = 1;
    char type[] = "";
    char producer[] = "Renault";
    char model[] = "Clio";
    int price = 4500;
    int quantity = 5;
    elem = createElectronic(ID, type, producer, model, price, quantity);
    assert(validateElectronic(elem) == 1);
    char type1[] = "masina";
    char producer1[] = "";
    elem = createElectronic(ID, type1, producer1, model, price, quantity);
    assert(validateElectronic(elem) == 1);
    char producer2[] = "Renault";
    char model1[] = "";
    elem = createElectronic(ID, type1, producer2, model1, price, quantity);
    assert(validateElectronic(elem) == 1);
    char type3[] = "masina";
    char producer3[] = "Renault";
    char model3[] = "Clio";
    elem = createElectronic(ID, type3, producer3, model3, price, quantity);
    assert(validateElectronic(elem) == 0);
    ID = -1;
    elem = createElectronic(ID, type3, producer3, model3, price, quantity);
    assert(validateElectronic(elem) == 1);
    ID = 1;
    price = -1;
    elem = createElectronic(ID, type3, producer3, model3, price, quantity);
    assert(validateElectronic(elem) == 1);
    price = 4500;
    quantity = -1;
    elem = createElectronic(ID, type3, producer3, model3, price, quantity);
    assert(validateElectronic(elem) == 1);
}

/*
 * functie de test pentru adaugarea in repo a unui electrocasnic
 */
void testAdd()
{
    MyList *Electronice = createEmpty();
    testResize();
    Electronic elem1 = createElectronic(1, "masina", "renault", "clio", 4500, 15);
    Electronic elem2 = createElectronic(2, "masina", "renault", "clio", 4500, 15);
    Electronic elem3 = createElectronic(3, "masina", "renault", "clio", 4500, 15);
    Electronic elem4 = createElectronic(4, "masina", "renault", "clio", 4500, 15);
    Electronic elem5 = createElectronic(5, "masina", "renault", "clio", 4500, 15);
    Electronic elem6 = createElectronic(6, "masina", "renault", "clio", 4500, 15);
    Electronic elem7 = createElectronic(7, "masina", "renault", "clio", 4500, 15);
    Electronic elem8 = createElectronic(8, "masina", "renault", "clio", 4500, 15);
    Electronic elem9 = createElectronic(9, "masina", "renault", "clio", 4500, 15);
    Electronic elem10 = createElectronic(10, "masina", "renault", "clio", 4500, 15);
    Electronic elem11 = createElectronic(11, "masina", "renault", "clio", 4500, 15);
    assert(Electronice->lg == 0);
    add(Electronice, elem1);
    add(Electronice, elem2);
    add(Electronice, elem3);
    add(Electronice, elem4);
    add(Electronice, elem5);
    add(Electronice, elem6);
    add(Electronice, elem7);
    add(Electronice, elem8);
    add(Electronice, elem9);
    add(Electronice, elem10);
    add(Electronice, elem11);
    assert(Electronice->lg == 11);
    assert(Electronice->capacity == 20);
}

/*
 * functie de test pentru marirea dimeansiunii vectorului dinamic
 */
void testResize()
{
    MyList *Electronice = createEmpty();
    Electronic elem = createElectronic(1, "masina", "renault", "clio", 4500, 15);
    assert(Electronice->lg == 0);
    add(Electronice, elem);
    resize(Electronice);
    assert(Electronice->capacity == 20);
}

/*
 *functie de test pentru crearea unei liste
 * care sa fie goala
 */
void testCreateEmpty()
{
    MyList * Electronics = createEmpty();
    assert(Electronics != NULL);
    assert(Electronics->lg == 0);
}

/*
 * functie de test pentru stergerea unui element din lista de electrocasnice
 */
void testDelete()
{
    MyList * Electronics = createEmpty();
    Electronic elem1 = createElectronic(1, "masina", "renault", "clio", 4500, 15);
    Electronic elem2 = createElectronic(2, "masina", "renault", "clio", 4500, 15);
    add(Electronics, elem1);
    add(Electronics, elem2);
    assert(Electronics->lg == 2);
    delete(Electronics, 0);
    assert(Electronics->lg == 1);
    assert(Electronics->elems[0].ID == elem2.ID);
    assert(strcmp(Electronics->elems[0].type, elem2.type) == 0);
    assert(strcmp(Electronics->elems[0].producer, elem2.producer) == 0);
    assert(strcmp(Electronics->elems[0].model, elem2.model) == 0);
    assert(Electronics->elems[0].price == elem2.price);
    assert(Electronics->elems[0].quantity == elem2.quantity);
}

/*
 * functie de test pentru service adaugare electrocasnic
 */
void testAddElectronicService()
{
    MyList *Electronics = createEmpty();
    assert(addElectronicService(Electronics, 1, "masina", "renault", "clio", 4500, 15) == 0);
    assert(addElectronicService(Electronics, 1, "masina", "renault", "", 4500, 15) == 1);
}

/*
 * functie de test service pentru actualizarea unui element din lista
 */
void testUpdateElectronicService()
{
    MyList *Electronics = createEmpty();
    Electronic elem1 = createElectronic(1, "masina", "renault", "clio", 4500, 15);
    add(Electronics, elem1);
    updateElectronicService(Electronics, 1, 4600, 15);
    assert(Electronics->elems[0].price == 4600);
    assert(Electronics->elems[0].quantity == 15);
    updateElectronicService(Electronics, 1, 4600, -1);
    assert(Electronics->elems[0].quantity == 15);
    updateElectronicService(Electronics, 1, -1, 15);
    assert(Electronics->elems[0].price == 4600);
    int error = updateElectronicService(Electronics, 1, 4600, 15);
    assert(error == 0);
}

/*
 * functie de test service pentru stergerea unui electrocasnic din lista
 */
void testDeleteElectronicService()
{
    MyList *Electronics = createEmpty();
    Electronic elem1 = createElectronic(1, "masina", "renault", "clio", 4500, 15);
    add(Electronics, elem1);
    assert(Electronics->lg == 1);
    deleteElectronicService(Electronics, 1);
    assert(Electronics->lg == 0);
}

/*
 * functie de test pentru actualizarea cantitatii unui electrocasnic
 */
void testUpdateQuantity()
{
    MyList *Electronics = createEmpty();
    Electronic elem1 = createElectronic(1, "masina", "renault", "clio", 4500, 15);
    add(Electronics, elem1);
    assert(Electronics->lg == 1);
    updateQuantity(Electronics, 1, 4);
    assert(Electronics->elems[0].quantity == 19);
    updateQuantity(Electronics, 1, 4);
    assert(Electronics->elems[0].quantity == 23);
    updateQuantity(Electronics, 1, -4);
    assert(Electronics->elems[0].quantity == 19);
}

/*
 * functie de test pentru destroy
 */
void testDestroy()
{
    MyList *Electronics = createEmpty();
    destroy(Electronics);
    assert(Electronics);
}

/*
 * functie de rularea a tuturor testelor
 */
void runAllTests()
{
    printf("Rularea testelor a inceput.......\n");
    testCreateElectronic();
    testValidateElectronic();
    testAdd();
    testResize();
    testCreateEmpty();
    testDelete();
    testAddElectronicService();
    testUpdateElectronicService();
    testDeleteElectronicService();
    testUpdateQuantity();
    testDestroy();
    printf("......Testele au rulat cu succes\n");
}