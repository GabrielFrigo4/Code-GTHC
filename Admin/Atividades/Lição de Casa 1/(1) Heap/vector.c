#include <stdlib.h>
#include "vector.h"

vector_t *vector_new(size_t size) {
	vector_t *vector = (vector_t *)malloc(sizeof(vector_t *));
	vector->size = size;
	vector->reserve = (1 << ((sizeof(long)*8) - __builtin_clzl(size))) + (size == 0);
	vector->vec = (long *)calloc(vector->reserve, sizeof(long));
	return vector;
}

void vector_delete(vector_t *vector) {
	free(vector->vec);
	free(vector);
}

long vector_at(vector_t *vector, size_t index) {
	if (vector->size > index) {
		return vector->vec[index];
	}
	return 0;
}

size_t vector_size(vector_t *vector) {
	return vector->size;
}

void vector_push(vector_t *vector, long element) {
	if (vector->size >= vector->reserve) {
		vector->reserve *= 2;
		vector->vec = (long *)realloc(vector->vec, vector->reserve * sizeof(long));
	}
	vector->vec[vector->size++] = element;
}

long vector_pop(vector_t *vector) {
	if (vector->size <= 0) {
		return 0;
	}
	return vector->vec[--vector->size];
}

void vector_reserve(vector_t *vector, size_t reserve) {
	vector->vec = (long *)realloc(vector->vec, reserve * sizeof(long));
}
