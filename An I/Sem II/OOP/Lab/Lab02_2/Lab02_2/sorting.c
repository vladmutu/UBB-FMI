#include "sorting.h"

void sort(MyList* list, CompareFunction cmp) {
	int i, j;
	for (i = 0; i < list->lg; i++) {
		for (j = i + 1; j < list->lg; j++) {
			void* elem1 = get(list, i);
			void* elem2 = get(list, j);
			if (cmp(elem1, elem2) > 0) {
				set(list, i, elem2);
				set(list, j, elem1);
			}
		}
	}
}