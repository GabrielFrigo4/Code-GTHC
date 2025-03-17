#include <stdlib.h>
#include "list.h"

struct node *node_new() {
	struct node *node = (struct node *)malloc(sizeof(struct node));
	node->prev = nullptr;
	node->next = nullptr;
	return node;
}

void node_delete(struct node *node) {
	free(node->buff);
	free(node);
}

struct list *list_new() {
	struct list *list = (struct list *)malloc(sizeof(struct list));
	list->head = nullptr;
	list->tail = nullptr;
	return list;
}

void list_delete(struct list *list) {
	for (struct node *node = list->head; node != list->tail; node = node->next) {
		if (node->prev != nullptr) {
			node_delete(node->prev);
		}
	}
	if (list->tail != nullptr) {
		node_delete(list->tail);
	}
	free(list);
}

void list_push_back(struct list *list, void *buff) {
	struct node *node = node_new();
	node->buff = buff;
	node->prev = list->tail;
	if (node->prev != nullptr) {
		node->prev->next = node;
	}

	if (list->head == nullptr) {
		list->head = node;
	}
	list->tail = node;
}

void list_push_front(struct list *list, void *buff) {
	struct node *node = node_new();
	node->buff = buff;
	node->next = list->head;
	if (node->next != nullptr) {
		node->next->prev = node;
	}

	list->head = node;
	if (list->tail == nullptr) {
		list->tail = node;
	}
}

void list_pop_back(struct list *list) {
	if (list->tail == nullptr) {
		return;
	}

	struct node *node = list->tail;
	list->tail = node->prev;
	if (list->tail != nullptr) {
		list->tail->next = nullptr;
	}
	else {
		list->head = nullptr;
	}
	node_delete(node);
}

void list_pop_front(struct list *list) {
	if (list->head == nullptr) {
		return;
	}

	struct node *node = list->head;
	list->head = node->next;
	if (list->head != nullptr) {
		list->head->prev = nullptr;
	}
	else {
		list->tail = nullptr;
	}
	node_delete(node);
}