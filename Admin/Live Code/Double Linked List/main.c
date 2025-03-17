#include <stdlib.h>
#include <stdio.h>
#include "list.h"

int main(void) {
	// Create a Double Linked List
	struct list *list = list_new();

	// Acess List Length
	printf("list->len = %i\n", list->len);

	// Push Back [1; 20] Nodes
	for (int i = 0; i < 20; i++) {
		int *buff = (int *)malloc(sizeof(int));
		*buff = i;
		list_push_back(list, buff);
	}

	// Acess List Length
	printf("list->len = %i\n", list->len);
	
	// Push Front [1; 20] Nodes
	for (int i = 0; i < 20; i++) {
		int *buff = (int *)malloc(sizeof(int));
		*buff = i;
		list_push_front(list, buff);
	}

	// Acess List Length
	printf("list->len = %i\n", list->len);
	
	// Pop Back and Pop Front Nodes
	list_pop_back(list, free);
	list_pop_front(list, free);

	// Acess List Length
	printf("list->len = %i\n", list->len);

	// Acess Nodes in Double Linked List
	for (struct node *node = list->head; node != nullptr; node = node->next) {
		printf("Node Value: %i\n", *(int *)(node->buff));
	}

	// Pop Back and Pop Front [0; 32] Nodes
	for (int i = 0; i < 32; i++) {
		list_pop_back(list, free);
		list_pop_front(list, free);
	}

	// Acess List Length
	printf("list->len = %i\n", list->len);

	// Delete a Double Linked List
	list_delete(list, free);
}
