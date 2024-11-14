#include <stdbool.h>
#include <stdlib.h>

typedef struct vector_t {
	size_t size;
	size_t reserve;
	int *vec;
} vector_t;

vector_t *vector_new(size_t size);
void vector_delete(vector_t *vector);
int vector_at(vector_t *vector, size_t index);
size_t vector_get_size(vector_t *vector);
void vector_push(vector_t *vector, int element);
int vector_pop(vector_t *vector);
void vector_reserve(vector_t *vector, size_t reserve);
