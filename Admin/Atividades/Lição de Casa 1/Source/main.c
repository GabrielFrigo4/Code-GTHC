#include <stdio.h>
#include "vector.h"

int main(void) {
	vector_t *vector = vector_new(0);

	int len;
	scanf("%i", &len);
	for (int i = 0; i < len; i++) {
		vector_push(vector, i);
	}
	for (int i = 0; i < len; i++) {
		printf("%i\n", vector_at(vector, i));
	}

	vector_delete(vector);
	return 0;
}
