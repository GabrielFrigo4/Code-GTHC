#include <stdlib.h>
#include <stdio.h>
#include "list.h"

int main(void) {
	// Create a Double Linked List
	struct list *list = list_new();

	// Acess List Length
	printf("list->len = %i\n", list->len);

	// Push Back [1; 20] Elements
	for (int i = 1; i <= 20; i++) {
		list_push_back(list, sizeof(i), (char *)&i);
	}

	// Acess List Length
	printf("list->len = %i\n", list->len);

	// Push Front [1; 20] Elements
	for (int i = 1; i <= 20; i++) {
		list_push_front(list, sizeof(i), (char *)&i);
	}

	// Acess List Length
	printf("list->len = %i\n", list->len);

	// Pop Back and Pop Front Elements
	list_pop_back(list, nullptr);
	list_pop_front(list, nullptr);

	// Acess List Length
	printf("list->len = %i\n", list->len);

	// Acess Elements in Double Linked List
	for (struct list_it *list_it = list->head; list_it != nullptr; list_it = list_it->next) {
		printf("Element Value: %i\n", *(int *)list_it->buff);
	}

	// Pop Back and Pop Front [0; 32] Elements
	for (int i = 0; i <= 32; i++) {
		list_pop_back(list, nullptr);
		list_pop_front(list, nullptr);
	}

	// Acess List Length
	printf("list->len = %i\n", list->len);

	// Delete a Double Linked List
	list_delete(list, nullptr);
}
