/* SYSTEM */
#include <stdio.h>
/* CUSTOM */
#include "rand.h"
#include "game.h"

int main(int argc, char **argv)
{
    uint32 rows, columns;
    get_terminal_size(&rows, &columns);
    clear_terminal();
    printf("Terminal info: rows:%u columns:%u\n", rows, columns);
    printf("\nRecomendamos maximizar o terminal :)\nAperte 'enter' para continuar\n");
    getc(stdin);

    init_rand();
    clear_terminal();
    return GAME_main();
}