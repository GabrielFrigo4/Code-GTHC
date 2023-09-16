#include "new_types.h"

typedef struct gameData
{
    bool running;
    bool start;
} gameData;

void input_command(char *input, gameData *game_data);
void input_play(char *input);