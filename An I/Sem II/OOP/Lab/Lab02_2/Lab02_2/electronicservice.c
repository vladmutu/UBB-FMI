//
// Created by vladm on 3/12/2024.
//Source file service pentru electrocasnice
#include <stdio.h>
#include <stdbool.h>
#include "electronicservice.h"
#include "sorting.h"

ListManager createListManager()
{
	ListManager manager;
    manager.Electronics = createEmpty(destroyElectronic);
    manager.UndoList = createEmpty(destroy);
	return manager;
}

void destroyListManager(ListManager* manager)
{
	destroy(manager->Electronics);
	destroy(manager->UndoList);
}

int addElectronicService(ListManager* manager, int ID, char* type, char* producer, char* model, int price, int quantity)
{
    Electronic* elem = createElectronic(ID, type, producer, model, price, quantity);
    int error = validateElectronic(elem);
	if (error == 1)
		destroyElectronic(elem);
    else
    {
        MyList* toUndo = CopyList(manager->Electronics, copyElectronic);
        add(manager->Electronics, elem);
        add(manager->UndoList, toUndo);
        return 0;
    }
	return 1;
}

int updateElectronicService(ListManager* manager, int ID, int price, int quantity)
{
    if(price == -1 && quantity == -1)
		return 1;
	else {
		if (price == -1)
		{
			MyList* toUndo = CopyList(manager->Electronics, copyElectronic);
			add(manager->UndoList, toUndo);
			for (int i = 0; i < manager->Electronics->lg; i++)
			{
				Electronic* elem = get(manager->Electronics, i);
				if (elem->ID == ID)
				{
					elem->quantity = quantity;
				}
			}
		}
		else
		{
			MyList* toUndo = CopyList(manager->Electronics, copyElectronic);
			add(manager->UndoList, toUndo);
			for (int i = 0; i < manager->Electronics->lg; i++)
			{
				Electronic* elem = get(manager->Electronics, i);
				if (elem->ID == ID)
				{
					elem->price = price;
				}
			}
		}
	}
	return 0;
}

int deleteElectronicService(ListManager* manager, int ID)
{
    MyList* toUndo = CopyList(manager->Electronics, copyElectronic);
	add(manager->UndoList, toUndo);
	for(int i = 0; i < manager->Electronics->lg; i++)
	{
		Electronic* elem = get(manager->Electronics, i);
		if(elem->ID == ID)
		{
			Electronic* elem = delete(manager->Electronics, i);
			destroyElectronic(elem);
		}
		return 0;
	}
	return 1;
}

void updateQuantity(ListManager* manager, int ID, int quantity)
{
    for(int i = 0; i < manager->Electronics->lg; i++)
	{
		Electronic* elem = get(manager->Electronics, i);
		if(elem->ID == ID)
		{
			elem->quantity += quantity;
		}
	}
}

bool cmpPriceAscending(Electronic* a, Electronic* b)
{
	return a->price > b->price;
}

MyList* sortElectronicsPriceAscending(MyList* Electronics)
{
	MyList* sorted = CopyList(Electronics, copyElectronic);
	sort(sorted, cmpPriceAscending);
	return sorted;
}

bool cmpPriceDescending(Electronic* a, Electronic* b)
{
	return a->price < b->price;
}

MyList* sortElectronicsPriceDescending(MyList* Electronics)
{
	MyList* sorted = CopyList(Electronics, copyElectronic);
	sort(sorted, cmpPriceDescending);
	return sorted;
}

bool cmpQuantityAscending(Electronic* a, Electronic* b)
{
	return a->quantity > b->quantity;
}

MyList* sortElectronicsQuantityAscending(MyList* Electronics)
{
	MyList* sorted = CopyList(Electronics, copyElectronic);
	sort(sorted, cmpQuantityAscending);
	return sorted;
}

bool cmpQuantityDescending(Electronic* a, Electronic* b)
{
	return a->quantity < b->quantity;
}

MyList* sortElectronicsQuantityDescending(MyList* Electronics)
{
	MyList* sorted = CopyList(Electronics, copyElectronic);
	sort(sorted, cmpQuantityDescending);
	return sorted;
}

MyList* filterElectronicsByProducer(MyList* Electronics, char* producer)
{
	MyList* filtered = createEmpty(destroyElectronic);
	for(int i = 0; i < Electronics->lg; i++)
	{
		Electronic* aux = get(Electronics, i);
		Electronic* elem = copyElectronic(aux);
		if(strcmp(elem->producer, producer) == 0)
		{
			add(filtered, elem);
		}
		else
			destroyElectronic(elem);
	}
	return filtered;
}

MyList* filterElectronicsByPrice(MyList* Electronics, int price)
{
	MyList* filtered = createEmpty(destroyElectronic);
	for(int i = 0; i < Electronics->lg; i++)
	{
		Electronic* elem = get(Electronics, i);
		Electronic* aux = copyElectronic(elem);
		if(elem->price == price)
		{
			add(filtered, aux);
		}
		else
			destroyElectronic(aux);
	}
	return filtered;
}

MyList* filterElectronicsByQuantity(MyList* Electronics, int quantity)
{
	MyList* filtered = createEmpty(destroyElectronic);
	for(int i = 0; i < Electronics->lg; i++)
	{
		Electronic* elem = get(Electronics, i);
		Electronic* aux = copyElectronic(elem);
		if(elem->quantity == quantity)
		{
			add(filtered, aux);
		}
		else
			destroyElectronic(aux);
	}
	return filtered;
}

int undoService(ListManager* manager)
{
	if(manager->UndoList->lg == 0)
		return 1;
	else
	{
		MyList* list = delete(manager->UndoList, manager->UndoList->lg - 1);
		destroy(manager->Electronics);
		manager->Electronics = list;
	}
	return 0;
}