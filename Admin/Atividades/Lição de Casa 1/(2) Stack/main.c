#include <stdio.h>

long get_choice() {
	long choice;
	long input;

	while(scanf("%li", &input) != EOF && input > -1) {
		choice = input;
	}
	return choice;
}

int main(void) {
	long choice_joaozinho = get_choice();
	long choice_sua = get_choice();

	if (choice_joaozinho == choice_sua) {
		printf("Acertou!! é %li! Mas COMO???", choice_joaozinho);
	}
	else {
		printf("Errou! Era %li e não %li...", choice_joaozinho, choice_sua);
	}
	return 0;
}