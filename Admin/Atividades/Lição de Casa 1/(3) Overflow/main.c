#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct player_t {
	char name[16];
	int health;
	int power;
} player_t;

void player_print(player_t *player) {
	printf("\n######## PLAYER ########\nname: %s\nhealth: %i\npower: %i\n########################\n\n", player->name, player->health, player->power);
}

void player_init(player_t *player) {
	player->health = 1e3;
	player->power = 1e2;
	strcpy(player->name, "Sem Nome");
}

void player_setup(player_t *player) {
	printf("Digite o nome do jogador: ");
	if(scanf(" %[^\n]%*c", player->name) == EOF) {
		exit(-1);
	}
	player_print(player);

	int edit;
	printf("Se quiser editar o ataque ou a vida coloque \"1\", senão coloque \"0\" (ataque * vida <= 1e5): ");
	if(scanf("%i", &edit) == EOF) {
		exit(-1);
	}
	if (!edit) {
		return;
	}

	do {
		printf("Vida: ");
		if(scanf("%i", &player->health) == EOF) {
			exit(-1);
		}
		printf("Ataque: ");
		if(scanf("%i", &player->power) == EOF) {
			exit(-1);
		}
	} while (player->health * player->power > 1e5 || player->health <= 0 || player->power <= 0);
}

void player_battle(player_t *player1, player_t *player2) {
	do {
		player1->health -= player2->power;
		player2->health -= player1->power;

		printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
		player_print(player1);
		player_print(player2);
	} while(player1->health > 0 && player2->health > 0);

	if (player2->health <= 0) {
		printf("Joãozinho Ganhou!! Ele é muito bom msm");
	}
	else if (player1->health <= 0) {
		printf("Aff, você ganhou... Como??");
	}
}

int main(void) {
	player_t player_joaozinho;
	player_t player_voce;

	player_init(&player_joaozinho);
	player_init(&player_voce);

	printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
	player_print(&player_joaozinho);
	player_setup(&player_joaozinho);
	player_print(&player_joaozinho);

	printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
	player_print(&player_voce);
	player_setup(&player_voce);
	player_print(&player_voce);

	printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n\n");
	player_battle(&player_joaozinho, &player_voce);
	return 0;
}