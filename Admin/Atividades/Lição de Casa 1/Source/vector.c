#include "vector.h"

vector_t *vector_new(size_t size) {
	vector_t *vector = (vector_t *)malloc(sizeof(vector_t *));
	vector->size = size;
	vector->reserve = (size) + (size == 0);
	vector->vec = (int *)calloc(vector->reserve, sizeof(int));
	return vector;
}

void vector_delete(vector_t *vector) {
	free(vector->vec);
	free(vector);
}

int vector_at(vector_t *vector, size_t index) {
	if (vector->size > index) {
		return vector->vec[index];
	}
	return 0;
}

size_t vector_size(vector_t *vector) {
	return vector->size;
}

void vector_push(vector_t *vector, int element) {
	if (vector->size >= vector->reserve) {
		vector->reserve *= 2;
		vector->vec = (int *)realloc(vector->vec, vector->reserve * sizeof(int));
	}
	vector->vec[vector->size++] = element;
}

int vector_pop(vector_t *vector) {
	if (vector->size <= 0) {
		return 0;
	}
	return vector->vec[--vector->size];
}

void vector_reserve(vector_t *vector, size_t reserve) {
	vector->vec = (int *)realloc(vector->vec, reserve * sizeof(int));
}
