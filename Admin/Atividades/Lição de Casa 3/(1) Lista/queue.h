#include <stdint.h>
#include <stddef.h>

struct data_t {
	char buf[256];
};

struct chunk_t {
	struct chunk_t *next;
	struct data_t data;
};

struct queue_t {
	struct chunk_t *head;
	struct chunk_t *tail;
	size_t len;
};

struct queue_t *queue_new();
struct queue_t *queue_delete(struct queue_t *queue);
void queue_push(struct queue_t *queue, struct data_t chunk);
struct data_t queue_pop(struct queue_t *queue);
size_t queue_len(struct queue_t *queue);
