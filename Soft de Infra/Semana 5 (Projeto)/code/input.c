/* SYSTEM */
#include <string.h>
/* CUSTOM */
#include "input.h"

void input_command(char *input, gameData *game_data)
{
    if (strcmp(input, "#exit\n") == 0)
    {
        game_data->running = false;
    }
    else if (strcmp(input, "#start\n") == 0)
    {
        game_data->start = true;
    }
}

void input_play(char *input)
{
}