#include "new_types.h"

typedef struct screen
{
    uint8 height, width;
    wchar *buffer;
} screen;

/* TERMINAL */
void clear_terminal();
void get_terminal_size(uint32 *rows, uint32 *columns);
/* SCREEN */
screen *create_screen(uint8 height, uint8 width);
screen *destroy_screen(screen *_screen);
void screen_write(screen *_screen);
void screen_flush(screen *_screen);
void screen_set_full(screen *_screen, wchar data);
void screen_set_internal(screen *_screen, wchar data);
void screen_set_edge(screen *_screen, wchar data);
void screen_set_line_ext(screen *_screen, wchar *data, uint32 data_size, uint8 line_index, uint8 line_offset);
void screen_set_line(screen *_screen, wchar *data, uint8 line_index, uint8 line_offset);
void screen_set_lines_ext(screen *_screen, wchar **data, uint32 data_size, uint8 start_line_index, uint8 line_offset);
void screen_set_lines(screen *_screen, wchar **data, uint8 start_line_index, uint8 line_offset);
void screen_set_column_ext(screen *_screen, wchar *data, uint32 data_size, uint8 collumn_index, uint8 collumn_offset);
void screen_set_column(screen *_screen, wchar *data, uint8 collumn_index, uint8 collumn_offset);
void screen_set_point(screen *_screen, wchar data, uint8 line_index, uint8 collumn_index);