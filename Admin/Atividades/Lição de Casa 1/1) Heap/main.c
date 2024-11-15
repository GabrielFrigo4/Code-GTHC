#include <stdio.h>
#include "vector.h"

int main(void) {
	vector_t *vector = vector_new(0);

	long el;
	scanf("%li", &el);
	while (el != -1) {
		vector_push(vector, el);
		scanf("%li", &el);
	}

	for (int i = 0; i < vector_size(vector); i++) {
		printf("%li\n", vector_at(vector, i));
	}

	vector_delete(vector);
	return 0;
}
