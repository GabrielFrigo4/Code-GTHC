/* SYSTEM */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <wchar.h>
#if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
#include <sys/ioctl.h>
#elif defined(_WIN32) || defined(_WIN64)
#include <windows.h>
#endif
/* CUSTOM */
#include "screen.h"
#include "utils.h"

const wchar *input = L"[INPUT]: \n\r";

void clear_terminal()
{
    printf("\033[H\033[2J\033[3J");

#if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
    system("clear");
#elif defined(_WIN32) || defined(_WIN64)
    system("cls");
#endif
}

void get_terminal_size(uint32 *rows, uint32 *columns)
{
#if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
    struct winsize w;
    ioctl(0, TIOCGWINSZ, &w);
    *rows = w.ws_row;
    *columns = w.ws_col;
#endif

#if defined(_WIN32) || defined(_WIN64)
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    *columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    *rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
#endif
}

screen *create_screen(uint8 height, uint8 width)
{
    const uint32 screen_size = height * (width + 1);
    const uint32 buffer_size = (screen_size + wstrlen(input)) * sizeof(wchar);

    wchar *buffer = malloc(buffer_size);
    memset(buffer, L' ', buffer_size);
    for (uint32 i = 0; i < height; i++)
    {
        buffer[width + i * (width + 1)] = '\n';
    }
    memcpy(buffer + screen_size, input, wstrlen(input));

    screen *_screen = malloc(sizeof(screen));
    screen _temp = {height, width, buffer};
    *_screen = _temp;
    return _screen;
}

screen *destroy_screen(screen *_screen)
{
    free(_screen->buffer);
    _screen->buffer = NULL;
    free(_screen);
    _screen = NULL;
    return _screen;
}

void screen_write(screen *_screen)
{
    wprintf(_screen->buffer);
}

void screen_flush(screen *_screen)
{
    clear_terminal();
    screen_write(_screen);
}

void screen_set_full(screen *_screen, wchar data)
{
    for (uint32 i = 0; i < _screen->height; i++)
    {
        void *screen_buffer = _screen->buffer + i * (_screen->width + 1);
        memset(_screen->buffer + i * (_screen->width + 1), data, _screen->width);
    }
}

void screen_set_internal(screen *_screen, wchar data)
{
    for (uint32 i = 1; i < _screen->height - 1; i++)
    {
        void *screen_buffer = _screen->buffer + i * (_screen->width + 1) + 1;
        memset(screen_buffer, data, _screen->width - 2);
    }
}

void screen_set_edge(screen *_screen, wchar data)
{
    const uint32 screen_size = _screen->height * (_screen->width + 1);

    memset(_screen->buffer, data, _screen->width);
    for (uint32 i = 1; i < _screen->height - 1; i++)
    {
        uint32 screen_start_index = i * (_screen->width + 1);
        uint32 screen_end_index = _screen->width - 1 + i * (_screen->width + 1);
        _screen->buffer[screen_start_index] = data;
        _screen->buffer[screen_end_index] = data;
    }
    memset(_screen->buffer + screen_size - (_screen->width + 1), data, _screen->width);
}

void screen_set_line_ext(screen *_screen, wchar *data, uint32 data_size, uint8 line_index, uint8 line_offset)
{
    void *screen_buffer = _screen->buffer + line_offset + line_index * (_screen->width + 1);
    memcpy(screen_buffer, data, data_size);
}

void screen_set_line(screen *_screen, wchar *data, uint8 line_index, uint8 line_offset)
{
    screen_set_line_ext(_screen, data, wstrlen((const wchar *)data), line_index, line_offset);
}

void screen_set_lines_ext(screen *_screen, wchar **data, uint32 data_size, uint8 start_line_index, uint8 line_offset)
{
    for (uint32 i = 0; i < data_size; i++)
    {
        screen_set_line(_screen, data[i], start_line_index + i, line_offset);
    }
}

void screen_set_lines(screen *_screen, wchar **data, uint8 start_line_index, uint8 line_offset)
{
    screen_set_lines_ext(_screen, data, arrlen((const void **)data), start_line_index, line_offset);
}

void screen_set_column_ext(screen *_screen, wchar *data, uint32 data_size, uint8 collumn_index, uint8 collumn_offset)
{
    for (uint32 i = 0; i < data_size; i++)
    {
        uint32 screen_index = collumn_index + (collumn_offset + i) * (_screen->width + 1);
        _screen->buffer[screen_index] = data[i];
    }
}

void screen_set_column(screen *_screen, wchar *data, uint8 collumn_index, uint8 collumn_offset)
{
    screen_set_column_ext(_screen, data, wstrlen(data), collumn_index, collumn_offset);
}

void screen_set_point(screen *_screen, wchar data, uint8 line_index, uint8 collumn_index)
{
    uint32 screen_index = collumn_index + line_index * (_screen->width + 1);
    _screen->buffer[screen_index] = data;
}