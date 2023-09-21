/* SYSTEM */
#include <stdio.h>
/* CUSTOM */
#include "game.h"

#define SLOT_OFFSET 10

char *menu_title[] = {
    "[#]==============[#]",
    "[#]  TELA  MENU  [#]",
    "[#]==============[#]",
    NULL,
};

char *menu_info[] = {
    "[===============================================]",
    "[]                                             []",
    "[]                                             []",
    "[]                                             []",
    "[]                                             []",
    "[]                                             []",
    "[]                                             []",
    "[===============================================]",
    NULL,
};

char *menu_slot[] = {
    "[=================================================]",
    "[] Slot (X)                                      []",
    "[] Player Name:                                  []",
    "[] Level:                                        []",
    "[] Mode:                                         []",
    "[] Seed:                                         []",
    "[=================================================]",
    NULL,
};

void game_screen_set_menu(screen *_screen)
{
    screen_set_lines(_screen, menu_title, 2, 68);
    screen_set_lines(_screen, menu_info, 6, 60);
    game_screen_set_menu_slot(_screen, SLOT1);
    game_screen_set_menu_slot(_screen, SLOT2);
    game_screen_set_menu_slot(_screen, SLOT3);
}

void game_screen_set_menu_slot(screen *_screen, uint32 slot_index)
{
    const uint8 offset = SLOT_OFFSET * slot_index;
    screen_set_lines(_screen, menu_slot, 6 + offset, 3);
    screen_set_point(_screen, '1' + slot_index, 7 + offset, 12);

    profile *_profile = get_profile_slot(slot_index);
    if (_profile)
    {
        char level[LEVEL_SIZE] = {'\0'}, mode[MODE_SIZE] = {'\0'}, seed[SEED_SIZE] = {'\0'};
        snprintf(level, LEVEL_SIZE, "%d", _profile->level);
        snprintf(mode, SEED_SIZE, "Torre[%d]", _profile->mode);
        snprintf(seed, SEED_SIZE, "%d", _profile->seed);
        screen_set_line(_screen, _profile->player_data.name, 8 + offset, 19);
        screen_set_line(_screen, level, 9 + offset, 13);
        screen_set_line(_screen, mode, 10 + offset, 12);
        screen_set_line(_screen, seed, 11 + offset, 12);
    }
    else
    {
        screen_set_line(_screen, "is empty", 7 + offset, 15);
    }
}