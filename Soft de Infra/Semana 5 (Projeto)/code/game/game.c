/* SYSTEM */
#include <stdio.h>
/* CUSTOM */
#include "game.h"

wchar *template_comandos_gerais[] = {
    L"[=====================================]",
    L"[] Comandos gerais:                  []",
    L"[] #init  = vai para a tela inicial  []",
    L"[] #menu  = vai para o menu do jogo  []",
    L"[] #exit  = sai do jogo              []",
    L"[=====================================]",
    NULL,
};

wchar *template_comandos_menu[] = {
    L"[===============================]",
    L"[] Comandos do menu:           []",
    L"[] $slot1 = seleciona o slot 1 []",
    L"[] $slot2 = seleciona o slot 2 []",
    L"[] $slot3 = seleciona o slot 3 []",
    L"[] $dels1 = deleta o slot 1    []",
    L"[] $dels2 = deleta o slot 2    []",
    L"[] $dels3 = deleta o slot 3    []",
    L"[===============================]",
    NULL,
};

wchar *template_comandos_player[] = {
    L"[=========================]",
    L"[] Comandos do player:   []",
    L"[] w = anda pra cima     []",
    L"[] s = anda pra baixo    []",
    L"[] a = anda pra esquerda []",
    L"[] d = anda pra direita  []",
    L"[] e = anda pra direita  []",
    L"[=========================]",
    NULL,
};

int GAME_main()
{
    gameData game_data = {true, STATE_INIT};
    screen *_screen = create_screen(38, 156);
    while (game_data.running)
    {
        /* UPDATE GAME */
        set_rand_seed();
        switch (game_data.state)
        {
        case STATE_INIT:
            game_set_screen_template(_screen);
            game_screen_set_init(_screen);
            break;

        case STATE_MENU:
            game_set_screen_template(_screen);
            game_screen_set_menu(_screen);
            break;

        case STATE_PLAY:
            game_screen_set_play(_screen);
            break;

        default:
            return -1;
            break;
        }

        /* SET OUTPUT */
        screen_flush(_screen);

        /* GET INPUT */
        char input[_screen->width];
        fgets(input, _screen->width - 1, stdin);

        switch (game_data.state)
        {
        case STATE_INIT:
            switch (input[0])
            {
            case '#':
                game_input_geral(input, &game_data);
                break;
            default:
                game_input_play(input);
                break;
            }
            break;

        case STATE_MENU:
            switch (input[0])
            {
            case '#':
                game_input_geral(input, &game_data);
                break;
            case '$':
                game_input_menu(input);
                break;
            default:
                game_input_play(input);
                break;
            }
            break;

        case STATE_PLAY:
            switch (input[0])
            {
            case '#':
                game_input_geral(input, &game_data);
                break;
            default:
                game_input_play(input);
                break;
            }
            break;

        default:
            return -1;
            break;
        }
    }
    clear_terminal();
    _screen = destroy_screen(_screen);
    return 0;
}

void game_set_screen_template(screen *_screen)
{
    screen_set_edge(_screen, L'#');
    screen_set_internal(_screen, L'.');
    screen_set_lines(_screen, template_comandos_gerais, 6, 114);
    screen_set_lines(_screen, template_comandos_menu, 14, 114);
    screen_set_lines(_screen, template_comandos_player, 25, 114);
}