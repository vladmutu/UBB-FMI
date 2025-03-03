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
#include <stdlib.h>

void testCreateElectronic()
{
    Electronic* elem = createElectronic(1, "1", "1", "1", 1, 1);
    assert(elem->ID == 1);
    assert(strcmp(elem->type, "1") == 0);
    assert(strcmp(elem->producer, "1") == 0);
    assert(strcmp(elem->model, "1") == 0);
    assert(elem->price == 1);
    assert(elem->quantity == 1);
    destroyElectronic(elem);
}

void testValidateElectronic()
{
    Electronic* elem = createElectronic(1, "1", "1", "1", 1, 1);
	assert(validateElectronic(elem) == 0);
    destroyElectronic(elem);
    elem = createElectronic(1, "", "1", "1", 1, 1);
    assert(validateElectronic(elem) == 1);
    destroyElectronic(elem);
    elem = createElectronic(1, "1", "", "1", 1, 1);
    assert(validateElectronic(elem) == 1);
    destroyElectronic(elem);
    elem = createElectronic(1, "1", "1", "", 1, 1);
    assert(validateElectronic(elem) == 1);
    destroyElectronic(elem);
    elem = createElectronic(1, "1", "1", "1", -1, 1);
    assert(validateElectronic(elem) == 1);
    destroyElectronic(elem);
    elem = createElectronic(1, "1", "1", "1", 1, -1);   
    assert(validateElectronic(elem) == 1);
    destroyElectronic(elem);
    elem = createElectronic(-1, "1", "1", "1", 1, 1);
    assert(validateElectronic(elem) == 1);
    destroyElectronic(elem);
}

void testAdd()
{
    MyList* list = createEmpty(destroyElectronic);
    assert(list->lg == 0);
	Electronic* elem1 = createElectronic(1, "1", "1", "1", 1, 1);
    Electronic* elem2 = createElectronic(2, "2", "2", "2", 2, 2);
    Electronic* elem3 = createElectronic(3, "3", "3", "3", 3, 3);
    Electronic* elem4 = createElectronic(4, "4", "4", "4", 4, 4);
    Electronic* elem5 = createElectronic(5, "5", "5", "5", 5, 5);
    Electronic* elem6 = createElectronic(6, "6", "6", "6", 6, 6);
    Electronic* elem7 = createElectronic(7, "7", "7", "7", 7, 7);
    Electronic* elem8 = createElectronic(8, "8", "8", "8", 8, 8);
    Electronic* elem9 = createElectronic(9, "9", "9", "9", 9, 9);
    Electronic* elem10 = createElectronic(10, "10", "10", "10", 10, 10);
    Electronic* elem11 = createElectronic(11, "11", "11", "11", 11, 11);
	add(list, elem1);
    add(list, elem2);
    add(list, elem3);
    add(list, elem4);
    add(list, elem5);
    add(list, elem6);
	add(list, elem7);
	add(list, elem8);
	add(list, elem9);
	add(list, elem10);
	add(list, elem11);
	assert(list->lg == 11);
    assert(list->capacity == 20);
    destroy(list);
}

void testResize()
{
    MyList* list = createEmpty(destroyElectronic);
    assert(list->capacity == 5);
    Electronic* elem1 = createElectronic(1, "1", "1", "1", 1, 1);
    Electronic* elem2 = createElectronic(2, "2", "2", "2", 2, 2);
    Electronic* elem3 = createElectronic(3, "3", "3", "3", 3, 3);
    Electronic* elem4 = createElectronic(4, "4", "4", "4", 4, 4);
    Electronic* elem5 = createElectronic(5, "5", "5", "5", 5, 5);
    Electronic* elem6 = createElectronic(6, "6", "6", "6", 6, 6);
	add(list, elem1);
	add(list, elem2);
	add(list, elem3);
	add(list, elem4);
	add(list, elem5);
	add(list, elem6);
	assert(list->capacity == 10);
	destroy(list);
}

void testCreateEmpty()
{
    MyList* list = createEmpty(destroyElectronic);
    assert(list->lg == 0);
    destroy(list);
}

void testDelete()
{
    MyList* list = createEmpty(destroyElectronic);
    Electronic* elem1 = createElectronic(1, "1", "1", "1", 1, 1);
    Electronic* elem2 = createElectronic(2, "2", "2", "2", 2, 2);
    Electronic* elem3 = createElectronic(3, "3", "3", "3", 3, 3);
    add(list, elem1);
    add(list, elem2);
    add(list, elem3);
    assert(list->lg == 3);
    Electronic* aux = delete(list, 1);
    assert(aux->ID == 2);
    destroyElectronic(aux);
    assert(list->lg == 2);
    Electronic* elem = get(list, 1);
    assert(elem->ID == 3);
    destroy(list);
}

void testAddElectronicService()
{
    ListManager list = createListManager(destroy);
	int error = addElectronicService(&list, 1, "1", "1", "1", 1, 1);
	assert(error == 0);
	error = addElectronicService(&list, 1, "", "1", "1", 1, 1);
	assert(error == 1);
	error = addElectronicService(&list, 1, "1", "", "1", 1, 1);
	assert(error == 1);
	error = addElectronicService(&list, 1, "1", "1", "", 1, 1);
	assert(error == 1);
	error = addElectronicService(&list, 1, "1", "1", "1", -1, 1);
	assert(error == 1);
	error = addElectronicService(&list, 1, "1", "1", "1", 1, -1);
	assert(error == 1);
	error = addElectronicService(&list, -1, "1", "1", "1", 1, 1);
	assert(error == 1);
	destroyListManager(&list);
}

void testUpdateElectronicService()
{
    ListManager list = createListManager(destroy);
	addElectronicService(&list, 1, "1", "1", "1", 1, 1);
	int error = updateElectronicService(&list, 1, 2, -1);
	assert(error == 0);
	error = updateElectronicService(&list, 1, -1, 2);
	assert(error == 0);
	error = updateElectronicService(&list, 1, 2, 2);
	assert(error == 0);
    error = updateElectronicService(&list, 1, -1, -1);
    assert(error == 1);
	destroyListManager(&list);
}

void testDeleteElectronicService()
{
    ListManager list = createListManager(destroy);
	addElectronicService(&list, 1, "1", "1", "1", 1, 1);
	int error = deleteElectronicService(&list, 1);
	assert(error == 0);
    error = deleteElectronicService(&list, 2);
    assert(error == 1); 
	destroyListManager(&list);
}

void testUpdateQuantity()
{
    ListManager list = createListManager(destroy);
	Electronic* elem1 = createElectronic(1, "1", "1", "1", 1, 1);
	add(list.Electronics, elem1);
	updateQuantity(&list, 1, 2);
    Electronic* elem = get(list.Electronics, 0);
	assert(elem->quantity == 3);
	destroyListManager(&list);
}

void testDestroy()
{
}

void testDestroyElectronic()
{
}

void testSortElectronicsPriceAscending()
{
    MyList* list = createEmpty(destroyElectronic);
    Electronic* elem1 = createElectronic(1, "1", "1", "1", 2, 1);
    Electronic* elem2 = createElectronic(2, "2", "2", "2", 1, 2);
    add(list, elem1);
    add(list, elem2);
    MyList* aux = sortElectronicsPriceAscending(list);
    Electronic* aux1 = get(aux, 0);
	Electronic* aux2 = get(aux, 1);
    assert(aux1->price == 1);
    assert(aux2->price == 2);
    destroy(list);
    destroy(aux);
}

void testSortElectronicsPriceDescending()
{
    MyList* list = createEmpty(destroyElectronic);
    Electronic* elem1 = createElectronic(1, "1", "1", "1", 1, 1);
    Electronic* elem2 = createElectronic(2, "2", "2", "2", 2, 2);
    add(list, elem1);
    add(list, elem2);
    MyList* aux = sortElectronicsPriceDescending(list);
	Electronic* aux1 = get(aux, 0);
    Electronic* aux2 = get(aux, 1);
	assert(aux1->price == 2);
    assert(aux2->price == 1);
    destroy(list);
    destroy(aux);
}

void testSortElectronicsQuantityAscending()
{
	MyList* list = createEmpty(destroyElectronic);
	Electronic* elem1 = createElectronic(1, "1", "1", "1", 1, 2);
	Electronic* elem2 = createElectronic(2, "2", "2", "2", 2, 1);
    add(list, elem1);
    add(list, elem2);
    MyList* aux = sortElectronicsQuantityAscending(list);
	Electronic* aux1 = get(aux, 0);
    Electronic* aux2 = get(aux, 1);
	assert(aux1->quantity == 1);
    assert(aux2->quantity == 2);
    destroy(list);
    destroy(aux);
}

void testSortElectronicsQuantityDescending()
{
    MyList* list = createEmpty(destroyElectronic);
    Electronic* elem1 = createElectronic(1, "1", "1", "1", 1, 1);
    Electronic* elem2 = createElectronic(2, "2", "2", "2", 2, 2);
    add(list, elem1);
    add(list, elem2);
    MyList* aux = sortElectronicsQuantityDescending(list);
	Electronic* aux1 = get(aux, 0);
    Electronic* aux2 = get(aux, 1);
	assert(aux1->quantity == 2);
    assert(aux2->quantity == 1);
    destroy(list);
    destroy(aux);
}

void testCopyElectronic()
{
    Electronic* elem = createElectronic(1, "1", "1", "1", 1, 1);
	Electronic* copy = copyElectronic(elem);
	assert(elem->ID == copy->ID);
	assert(strcmp(elem->type, copy->type) == 0);
	assert(strcmp(elem->producer, copy->producer) == 0);
	assert(strcmp(elem->model, copy->model) == 0);
	assert(elem->price == copy->price);
	assert(elem->quantity == copy->quantity);
	destroyElectronic(elem);
	destroyElectronic(copy);
}

void testCopyList()
{
	MyList* list = createEmpty(destroyElectronic);
    Electronic* elem1 = createElectronic(1, "1", "1", "1", 1, 1);
	add(list, elem1);
	MyList* copy = CopyList(list, copyElectronic);
	assert(copy->lg == 1);
    assert(copy->capacity == 5);
    destroy(copy);
    destroy(list);

}

void testSize()
{
	MyList* list = createEmpty(destroyElectronic);
	Electronic* elem1 = createElectronic(1, "1", "1", "1", 1, 1);
	Electronic* elem2 = createElectronic(2, "2", "2", "2", 2, 2);
	add(list, elem1);
	add(list, elem2);
	assert(size(list) == 2);
	destroy(list);
}

void testGet()
{
	MyList* list = createEmpty(destroyElectronic);
	Electronic* elem1 = createElectronic(1, "1", "1", "1", 1, 1);
	Electronic* elem2 = createElectronic(2, "2", "2", "2", 2, 2);
	add(list, elem1);
	add(list, elem2);
	Electronic* aux = get(list, 0);
	assert(aux->ID == 1);
	destroy(list);
}

void testSet()
{
    MyList* list = createEmpty(destroyElectronic);
    Electronic* elem1 = createElectronic(1, "1", "1", "1", 1, 1);
    Electronic* elem2 = createElectronic(2, "2", "2", "2", 2, 2);
    add(list, elem1);
    Electronic* aux = set(list, 0, elem2);
    assert(aux->ID == 1);
    destroyElectronic(aux);
	destroy(list);
}

void testSort()
{
    MyList* list = createEmpty(destroyElectronic);
	Electronic* elem1 = createElectronic(1, "1", "1", "1", 2, 1);
	Electronic* elem2 = createElectronic(2, "2", "2", "2", 1, 2);
	add(list, elem1);
	add(list, elem2);
    sort(list, cmpPriceAscending);
    Electronic* aux1 = get(list, 0);
    Electronic* aux2 = get(list, 1);
	assert(aux1->price == 1);
	assert(aux2->price == 2);
	destroy(list);
    MyList* list2 = createEmpty(destroyElectronic);
    Electronic* elem3 = createElectronic(3, "3", "3", "3", 1, 2);
    Electronic* elem4 = createElectronic(4, "4", "4", "4", 2, 1);
    add(list2, elem3);
    add(list2, elem4);
    sort(list2, cmpPriceDescending);
    Electronic* aux3 = get(list2, 0);
    Electronic* aux4 = get(list2, 1);
    assert(aux3->price == 2);
    assert(aux4->price == 1);
    destroy(list2);
    MyList* list3 = createEmpty(destroyElectronic);
    Electronic* elem5 = createElectronic(5, "5", "5", "5", 1, 2);
    Electronic* elem6 = createElectronic(6, "6", "6", "6", 2, 1);
    add(list3, elem5);
    add(list3, elem6);
    sort(list3, cmpQuantityAscending);
    Electronic* aux5 = get(list3, 0);
    Electronic* aux6 = get(list3, 1);
    assert(aux5->quantity == 1);
    assert(aux6->quantity == 2);
    destroy(list3);
    MyList* list4 = createEmpty(destroyElectronic);
    Electronic* elem7 = createElectronic(7, "7", "7", "7", 2, 1);
    Electronic* elem8 = createElectronic(8, "8", "8", "8", 1, 2);
    add(list4, elem7);
    add(list4, elem8);
    sort(list4, cmpQuantityDescending);
    Electronic* aux7 = get(list4, 0);
    Electronic* aux8 = get(list4, 1);
    assert(aux7->quantity == 2);
    assert(aux8->quantity == 1);
    destroy(list4);
}

void testCreateListManager()
{
	ListManager list = createListManager(destroy);
	assert(list.Electronics->lg == 0);
	assert(list.Electronics->capacity == 5);
    assert(list.Electronics->destroyElemFunction != NULL);
    assert(list.UndoList->capacity == 5);
    assert(list.UndoList->lg == 0);
	destroyListManager(&list);
}

void testFilterByProducer()
{
    MyList* list = createEmpty(destroyElectronic);
    Electronic* elem1 = createElectronic(1, "1", "1", "1", 1, 1);
    Electronic* elem2 = createElectronic(2, "2", "2", "2", 2, 2);
    Electronic* elem3 = createElectronic(3, "3", "3", "3", 3, 3);
    add(list, elem1);
	add(list, elem2);
	add(list, elem3);
	MyList* aux = filterElectronicsByProducer(list, "1");
	assert(aux->lg == 1);
    Electronic* elem = get(aux, 0);
	assert(elem->ID == 1);
    destroy(aux);
    destroy(list);
}

void testFilterByPrice()
{
    MyList* list = createEmpty(destroyElectronic);
    Electronic* elem1 = createElectronic(1, "1", "1", "1", 1, 1);
    Electronic* elem2 = createElectronic(2, "2", "2", "2", 2, 2);
    Electronic* elem3 = createElectronic(3, "3", "3", "3", 3, 3);
    add(list, elem1);
    add(list, elem2);
    add(list, elem3);
    MyList* aux = filterElectronicsByPrice(list, 1);
    assert(aux->lg == 1);
    Electronic* elem = get(aux, 0);
    assert(elem->ID == 1);
    destroy(aux);
    destroy(list);
}

void testFilterByQuantity()
{
    MyList* list = createEmpty(destroyElectronic);
    Electronic* elem1 = createElectronic(1, "1", "1", "1", 1, 1);
    Electronic* elem2 = createElectronic(2, "2", "2", "2", 2, 2);
    Electronic* elem3 = createElectronic(3, "3", "3", "3", 3, 3);
    add(list, elem1);
    add(list, elem2);
    add(list, elem3);
    MyList* aux = filterElectronicsByQuantity(list, 1);
    assert(aux->lg == 1);
    Electronic* elem = get(aux, 0);
    assert(elem->ID == 1);
    destroy(aux);
    destroy(list);
}

void testUndoService()
{
    ListManager list = createListManager(destroy);
	addElectronicService(&list, 1, "1", "1", "1", 1, 1);
	addElectronicService(&list, 2, "2", "2", "2", 2, 2);
	addElectronicService(&list, 3, "3", "3", "3", 3, 3);
	int error = undoService(&list);
	assert(error == 0);
    error = undoService(&list);
    assert(error == 0);
    error = undoService(&list);
    assert(error == 0);
    error = undoService(&list);
    assert(error == 1);
	destroyListManager(&list);
}

void runAllTests()
{
    printf("Rularea testelor a inceput.......\n");
    testCreateElectronic();
    testValidateElectronic();
    testAdd();
    testResize();
    testCreateEmpty();
    testDelete();
    testCopyElectronic();
    testAddElectronicService();
    testDestroyElectronic();
    testDestroy();
    testUpdateElectronicService();
    testUpdateQuantity();
    testDeleteElectronicService();
    testSortElectronicsPriceAscending();
    testSortElectronicsPriceDescending();
    testSortElectronicsQuantityAscending();
    testSortElectronicsQuantityDescending();
    testCopyList();
    testSize();
    testSet();
    testGet();
    testSort();
    testCreateListManager();
    testFilterByProducer();
    testFilterByPrice();
    testFilterByQuantity();
    testUndoService();
    printf("......Testele au rulat cu succes\n");
}