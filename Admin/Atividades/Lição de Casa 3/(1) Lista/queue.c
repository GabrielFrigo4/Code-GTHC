#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void check_null(const void *ptr, const char *msg) {
	if (ptr == NULL) {
		fprintf(stderr, "%s\n", msg);
		exit(-1);
	}
}

void check_zero(size_t numb, const char *msg) {
	if (numb == 0) {
		fprintf(stderr, "%s\n", msg);
		exit(-1);
	}
}

struct queue_t *queue_new() {
	struct queue_t *queue = (struct queue_t *)malloc(sizeof(struct queue_t));
	check_null(queue, "ERR: queue_new() => malloc() return NULL (failed!)");
	queue->head = NULL;
	queue->tail = NULL;
	queue->len = 0;
	return queue;
}

struct queue_t *queue_delete(struct queue_t *queue) {
	check_null(queue, "ERR: queue_delete() => queue is NULL");
	free(queue);
	return NULL;
}

void queue_push(struct queue_t *queue, struct data_t data) {
	check_null(queue, "ERR: queue_push() => queue is NULL");
	struct chunk_t * chunk = (struct chunk_t *)malloc(sizeof(struct chunk_t));
	chunk->next = NULL;
	chunk->data = data;
	if (queue->tail != NULL) {
		queue->tail->next = chunk;
		queue->tail = chunk;
	}
	else {
		queue->tail = chunk;
		queue->head = chunk;
	}
	queue->len++;
}

struct data_t queue_pop(struct queue_t *queue) {
	check_null(queue, "ERR: queue_pop() => queue is NULL");
	check_zero(queue->len, "ERR: queue_pop() => queue->len is 0");
	check_null(queue->head, "ERR: queue_pop() => queue->tail is NULL");
	struct data_t data = queue->head->data;
	if(queue->head->next != NULL) {
		struct chunk_t *tmp = queue->head;
		queue->head = tmp->next;
		free(tmp);
	}
	else {
		free(queue->head);
		queue->head = NULL;
		queue->tail = NULL;
	}
	queue->len--;
	return data;
}

size_t queue_len(struct queue_t *queue) {
	check_null(queue, "ERR: queue_len() => queue is NULL");
	return queue->len;
}
