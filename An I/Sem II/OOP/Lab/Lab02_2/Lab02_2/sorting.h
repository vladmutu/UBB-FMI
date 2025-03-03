#pragma once
#include "electronicrepository.h"

typedef int (*CompareFunction)(void* el1, void* el2);

void sort(MyList* v, CompareFunction cmp);