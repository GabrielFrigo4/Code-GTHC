#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void game_izi();
void game_rard();

int main(void) {
	printf("GAME_1D\n");
	printf("MODO (1:IZI, 2:RARD):\n");
	int mode;
	if(scanf("%i", &mode) == EOF) {
		exit(-1);
	}

	srand(time(0));
	switch(mode) {
		case 1:
			game_izi();
			break;
		case 2:
			game_rard();
			break;
	}
	return 0;
}

int cmp(const void *a, const void *b) {
	return (*(int *)a - *(int *)b);
}

void game_izi() {
	int size = rand() % 256 + 128;
	const int gold_pos = rand() % (size/2) + size/4;
	int *map = malloc(sizeof(int) * size);
	for (int i = 0; i < size; i++) {
		map[i] = rand() % 7919;
	}
	qsort(map, size, sizeof(int), cmp);

	printf("MAPA GERADO!\n");
	printf("SIZE => %i\n", size);
	printf("MIN => %i\n", map[0]);
	printf("MAX => %i\n", map[size-1]);
	printf("GOLD => %i\n", map[gold_pos]);

	int pos;
	do {
		if(scanf("%i", &pos) == EOF) {
			exit(-1);
		}
		if (map[pos] > map[gold_pos]) {
			printf("uff quase, o número achado é maior\n");
		}
		if (map[pos] < map[gold_pos]) {
			printf("uff quase, o número achado é menor\n");
		}
	} while (pos != gold_pos);
	printf("O_O, slk se achou o OURO, BOA!");
}

void game_rard() {
	int size = rand() % 256 + 128;
	int health = rand() % 5 + 2;
	const int gold_pos = rand() % (size/2) + size/4;
	int *map = malloc(sizeof(int) * size);
	for (int i = 0; i < size; i++) {
		map[i] = rand() % 7919;
	}
	qsort(map, size, sizeof(int), cmp);

	printf("MAPA GERADO!\n");
	printf("SIZE => %i\n", size);
	printf("MIN => %i\n", map[0]);
	printf("MAX => %i\n", map[size-1]);
	printf("GOLD => %i\n", map[gold_pos]);
	printf("HEALTH => %i\n", health);

	int pos;
	do {
		if(scanf("%i", &pos) == EOF) {
			exit(-1);
		}
		if (map[pos] > map[gold_pos] && health > 1) {
			printf("aiai, o número achado é maior, perdeu uma vida...\n");
			health--;
		}
		else if (map[pos] > map[gold_pos]) {
			printf("aiai, o número achado é maior, perdeu a sua última vida, F...\n");
			return;
		}
		if (map[pos] < map[gold_pos]) {
			printf("uff quase, o número achado é menor\n");
		}
	} while (pos != gold_pos);
	printf("O_O, slk se achou o OURO, BOA!");
}