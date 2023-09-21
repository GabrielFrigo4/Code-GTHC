/* SYSTEM */
#include <string.h>
#include <stdio.h>
/* CUSTOM */
#include "game.h"

void game_input_geral(char *input, gameData *game_data)
{
    if (strcmp(input, "#exit\n") == 0)
    {
        game_data->running = false;
    }
    else if (strcmp(input, "#init\n") == 0)
    {
        game_data->state = STATE_INIT;
    }
    else if (strcmp(input, "#menu\n") == 0)
    {
        game_data->state = STATE_MENU;
    }
}

void game_input_menu(char *input)
{
    if (strcmp(input, "$slot1\n") == 0)
    {
        game_input_slot(SLOT1);
    }
    else if (strcmp(input, "$slot2\n") == 0)
    {
        game_input_slot(SLOT2);
    }
    else if (strcmp(input, "$slot3\n") == 0)
    {
        game_input_slot(SLOT3);
    }

    if (strcmp(input, "$rels1\n") == 0)
    {
        remove_profile_slot(SLOT1);
    }
    else if (strcmp(input, "$rels2\n") == 0)
    {
        remove_profile_slot(SLOT2);
    }
    else if (strcmp(input, "$rels3\n") == 0)
    {
        remove_profile_slot(SLOT3);
    }
}

void game_input_play(char *input)
{
}

void game_input_slot(uint32 slot_index)
{
    clear_terminal();
    printf("Nome do personagem: ");
    char player_name[PLAYER_NAME_SIZE] = {'\0'};
    scanf("%[^\n]33s", player_name);
    for (uint32 i = 0; i < PLAYER_NAME_SIZE; i++)
    {
        if (player_name[i] == '\n')
        {
            player_name[i] = '\0';
        }
        else if (player_name[i] == '\0')
        {
            break;
        }
    }

    uint64 mode;
    printf("\nTorre[1] = Facíl\nTorre[2] = Medio\nTorre[3] = Difícil\n");
    printf("Modo de jogo, a difículdade (coloque apenas o numero da torre): ");
    scanf("%d", &mode);

    uint64 seed = rdrand64();
    set_rand_seed();

    char str_seed[SEED_SIZE] = {'\0'};
    printf("\nOPICIONAL!\n");
    printf("A 'seed' para a geração do seu mundo (coloque um numero negativo para ignorar): ");
    scanf("%33s", str_seed);
    if (str_seed[0] != '-')
    {
        sscanf(str_seed, "%d", &seed);
    }

    player _player = create_player(player_name);
    profile *_profile = create_profile(0, mode, seed, _player);
    set_profile_slot(slot_index, _profile);
    printf(_profile->player_data.name);
}