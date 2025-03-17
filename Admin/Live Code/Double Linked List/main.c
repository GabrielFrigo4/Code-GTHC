#include <stdlib.h>
#include <stdio.h>
#include "list.h"

int main(void) {
	// Create a Double Linked List
	struct list *list = list_new();

	// Push Back [1; 20] Nodes
	for (int i = 0; i < 20; i++) {
		int *buff = (int *)malloc(sizeof(int));
		*buff = i;
		list_push_back(list, buff);
	}

	// Push Front [1; 20] Nodes
	for (int i = 0; i < 20; i++) {
		int *buff = (int *)malloc(sizeof(int));
		*buff = i;
		list_push_front(list, buff);
	}

	// Pop Back and Pop Front Nodes
	list_pop_back(list);
	list_pop_front(list);

	// Acess Nodes in Double Linked List
	for (struct node *node = list->head; node != nullptr; node = node->next) {
		printf("Node Value: %i\n", *(int *)(node->buff));
	}

	// Pop Back and Pop Front [0; 32] Nodes
	for (int i = 0; i < 32; i++) {
		list_pop_back(list);
		list_pop_front(list);
	}

	// Delete a Double Linked List
	list_delete(list);
}
