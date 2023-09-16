#include "new_types.h"

typedef struct screen
{
    uint8 height, width;
    char *buffer;
} screen;

void clear_terminal();
screen create_screen(uint8 height, uint8 width);
screen destroy_screen(screen _screen);
void screen_write(screen _screen);
void screen_flush(screen _screen);
void screen_set_full(screen _screen, char data);
void screen_set_internal(screen _screen, char data);
void screen_set_edge(screen _screen, char data);