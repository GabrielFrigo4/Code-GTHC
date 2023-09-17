/* SYSTEM */
#include <stdio.h>
/* CUSTOM */
#include "new_types.h"
#include "profile.h"
#include "screen.h"
#include "input.h"
#include "rand.h"

int GAME_main();
int main(int argc, char **argv)
{
    clear_terminal();
    printf("Recomendamos maximizar o terminal :)\nAperte 'enter' para continuar");
    getc(stdin);
    init_rand();
    clear_terminal();
    return GAME_main();
}

int GAME_main()
{
    gameData game_data = {true, false};
    screen _screen = create_screen(38, 156);
    screen_set_edge(_screen, '#');
    screen_set_line(_screen, "Criador: Gabriel Frigo", 2, 3);
    screen_set_line(_screen, "Nome do Jogo: Caixa Larga de Sapato, A Aventura!", 4, 3);
    while (game_data.running)
    {
        /* SET OUTPUT */
        screen_flush(_screen);

        /* GET INPUT */
        char input[_screen.width];
        fgets(input, _screen.width - 1, stdin);

        switch (input[0])
        {
        case '#':
            input_command(input, &game_data);
            break;
        default:
            input_play(input);
            break;
        }
    }
    clear_terminal();
    _screen = destroy_screen(_screen);
    return 0;
}