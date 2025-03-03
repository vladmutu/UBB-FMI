//
// Created by vladm on 3/12/2024.
//source file pentru repository-ul electrocasnicelor
#include "electronicrepository.h"
#include <stdlib.h>

MyList* createEmpty(DestroyElemFunction f)
{
    MyList* list = malloc(sizeof(MyList));
    list->capacity = 5;
    list->elems = malloc(list->capacity * sizeof(ElemType));
    list->lg = 0;
    list->destroyElemFunction = f;
    return list;
}

void destroy(MyList* list)
{
    for (int i = 0; i < list->lg; i++)
        list->destroyElemFunction(list->elems[i]);
    list->lg = 0;
    free(list->elems);
    free(list);
}

ElemType get(MyList* list, int poz)
{
	return list->elems[poz];
}

int size(MyList* list)
{
	return list->lg;
}

void resize(MyList* list)
{
    int nCap = 2 * list->capacity;
    ElemType* nElems = malloc(nCap * sizeof(ElemType));
    for (int i = 0; i < list->lg; i++)
    {
        nElems[i] = list->elems[i];
    }  
	free(list->elems);
    list->elems = nElems;
    list->capacity = nCap;
}

void add(MyList* list, ElemType elem)
{
    if(list->lg == list->capacity)
		resize(list);
    list->elems[list->lg] = elem;
    list->lg++;
}

ElemType set(MyList* list, int poz, ElemType elem)
{
    ElemType old = list->elems[poz];
    list->elems[poz] = elem;
    return old;
}
 
ElemType delete(MyList* list, int poz)
{
    ElemType elemToDelete = list->elems[poz];
    for (int i = poz; i < list->lg - 1; i++) 
        list->elems[i] = list->elems[i + 1];
    list->lg--;
    return elemToDelete;
}

MyList* CopyList(MyList* list, CopyElemFunction copyFunction)
{
	MyList* list_copy = createEmpty(list->destroyElemFunction);
    for (int i = 0; i < list->lg; i++) {
        ElemType elem = get(list, i);
        add(list_copy, copyFunction(list->elems[i]));
    }
        
	return list_copy;
}
