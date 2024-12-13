#include <stdint.h>
#include <stddef.h>

typedef struct vector_t {
	size_t size;
	size_t reserve;
	long *vec;
} vector_t;

vector_t *vector_new(size_t size);
void vector_delete(vector_t *vector);
long vector_at(vector_t *vector, size_t index);
size_t vector_size(vector_t *vector);
void vector_push(vector_t *vector, long element);
long vector_pop(vector_t *vector);
void vector_reserve(vector_t *vector, size_t reserve);
