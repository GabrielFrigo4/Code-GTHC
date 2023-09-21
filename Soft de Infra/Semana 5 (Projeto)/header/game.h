#include "new_types.h"
#include "profile.h"
#include "screen.h"
#include "rand.h"

#define STATE_INIT 0
#define STATE_MENU 1
#define STATE_PLAY 2

typedef struct gameData
{
    bool running;
    uint8 state;
} gameData;

/* MAIN */
int GAME_main();
/* INPUT */
void game_input_geral(char *input, gameData *game_data);
void game_input_menu(char *input);
void game_input_play(char *input);
void game_input_slot(uint32 slot_index);
/* SCREEN */
void game_set_screen_template(screen *_screen);
void game_screen_set_init(screen *_screen);
void game_screen_set_menu(screen *_screen);
void game_screen_set_menu_slot(screen *_screen, uint32 slot_index);
void game_screen_set_play(screen *_screen);