#include <stdlib.h>
#include "list.h"

struct node *node_new() {
	struct node *node = (struct node *)malloc(sizeof(struct node));
	node->prev = nullptr;
	node->next = nullptr;
	node->buff = nullptr;
	return node;
}

void node_delete(struct node *node, void (*delete)(void *)) {
	if (delete != nullptr) {
		delete(node->buff);
	}
	free(node);
}

struct list *list_new() {
	struct list *list = (struct list *)malloc(sizeof(struct list));
	list->head = nullptr;
	list->tail = nullptr;
	list->len = 0;
	return list;
}

void list_delete(struct list *list, void (*delete)(void *)) {
	for (struct node *node = list->head; node != list->tail; node = node->next) {
		if (node->prev != nullptr) {
			node_delete(node->prev, delete);
		}
	}
	if (list->tail != nullptr) {
		node_delete(list->tail, delete);
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
	list->len++;
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
	list->len++;
}

void list_pop_back(struct list *list, void (*delete)(void *)) {
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
	list->len--;
	node_delete(node, delete);
}

void list_pop_front(struct list *list, void (*delete)(void *)) {
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
	list->len--;
	node_delete(node, delete);
}
