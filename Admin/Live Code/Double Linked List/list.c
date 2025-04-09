#include <stdlib.h>
#include <string.h>
#include "list.h"

struct list_it *list_it_new(size_t len, char buff[len]) {
	struct list_it *list_it = (struct list_it *)malloc(sizeof(struct list_it) + sizeof(char) * len);
	list_it->prev = nullptr;
	list_it->next = nullptr;
	list_it->len = len;
	memcpy(list_it->buff, buff, len);
	return list_it;
}

void list_it_delete(struct list_it *list_it, void (*delete)(size_t, char[])) {
	if (delete != nullptr) {
		delete(list_it->len, list_it->buff);
	}
	free(list_it);
}

struct list *list_new() {
	struct list *list = (struct list *)malloc(sizeof(struct list));
	list->head = nullptr;
	list->tail = nullptr;
	list->len = 0;
	return list;
}

void list_delete(struct list *list, void (*delete)(size_t, char[])) {
	for (struct list_it *list_it = list->head; list_it != list->tail; list_it = list_it->next) {
		if (list_it->prev != nullptr) {
			list_it_delete(list_it->prev, delete);
		}
	}
	if (list->tail != nullptr) {
		list_it_delete(list->tail, delete);
	}
	free(list);
}

void list_push_back(struct list *list, size_t len, char buff[len]) {
	struct list_it *list_it = list_it_new(len, buff);
	list_it->prev = list->tail;
	if (list_it->prev != nullptr) {
		list_it->prev->next = list_it;
	}

	if (list->head == nullptr) {
		list->head = list_it;
	}
	list->tail = list_it;
	list->len++;
}

void list_push_front(struct list *list, size_t len, char buff[len]) {
	struct list_it *list_it = list_it_new(len, buff);
	list_it->next = list->head;
	if (list_it->next != nullptr) {
		list_it->next->prev = list_it;
	}

	list->head = list_it;
	if (list->tail == nullptr) {
		list->tail = list_it;
	}
	list->len++;
}

void list_pop_back(struct list *list, void (*delete)(size_t, char[])) {
	if (list->tail == nullptr) {
		return;
	}

	struct list_it *list_it = list->tail;
	list->tail = list_it->prev;
	if (list->tail != nullptr) {
		list->tail->next = nullptr;
	}
	else {
		list->head = nullptr;
	}
	list->len--;
	list_it_delete(list_it, delete);
}

void list_pop_front(struct list *list, void (*delete)(size_t, char[])) {
	if (list->head == nullptr) {
		return;
	}

	struct list_it *list_it = list->head;
	list->head = list_it->next;
	if (list->head != nullptr) {
		list->head->prev = nullptr;
	}
	else {
		list->tail = nullptr;
	}
	list->len--;
	list_it_delete(list_it, delete);
}
