/* SYSTEM */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
/* CUSTOM */
#include "screen.h"

const char *input = "[INPUT]: \n\r";

void clear_terminal()
{
    printf("\033[H\033[2J\033[3J");

#if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
    system("clear");
#endif

#if defined(_WIN32) || defined(_WIN64)
    system("cls");
#endif
}

screen create_screen(uint8 height, uint8 width)
{
    const uint32 screen_size = height * (width + 1);
    const uint32 buffer_size = screen_size + strlen(input);

    char *buffer = malloc(buffer_size);
    memset(buffer, ' ', buffer_size);
    for (uint32 i = 0; i < height; i++)
    {
        buffer[width + i * (width + 1)] = '\n';
    }
    memcpy(buffer + screen_size, input, strlen(input));

    screen _screen = {height, width, buffer};
    return _screen;
}

screen destroy_screen(screen _screen)
{
    free(_screen.buffer);
    _screen.buffer = NULL;
    return _screen;
}

void screen_write(screen _screen)
{
    printf(_screen.buffer);
}

void screen_flush(screen _screen)
{
    clear_terminal();
    screen_write(_screen);
}

void screen_set_full(screen _screen, char data)
{
    for (uint32 i = 0; i < _screen.height; i++)
    {
        void *screen_buffer = _screen.buffer + i * (_screen.width + 1);
        memset(_screen.buffer + i * (_screen.width + 1), data, _screen.width);
    }
}

void screen_set_internal(screen _screen, char data)
{
    for (uint32 i = 1; i < _screen.height - 1; i++)
    {
        void *screen_buffer = _screen.buffer + i * (_screen.width + 1) + 1;
        memset(screen_buffer, data, _screen.width - 2);
    }
}

void screen_set_edge(screen _screen, char data)
{
    const uint32 screen_size = _screen.height * (_screen.width + 1);

    memset(_screen.buffer, data, _screen.width);
    for (uint32 i = 1; i < _screen.height - 1; i++)
    {
        uint32 screen_start_index = i * (_screen.width + 1);
        uint32 screen_end_index = _screen.width - 1 + i * (_screen.width + 1);
        _screen.buffer[screen_start_index] = data;
        _screen.buffer[screen_end_index] = data;
    }
    memset(_screen.buffer + screen_size - (_screen.width + 1), data, _screen.width);
}

void screen_set_line(screen _screen, char *data, uint8 line, uint8 offset)
{
    void *screen_buffer = _screen.buffer + offset + line * (_screen.width + 1);
    memcpy(screen_buffer, data, strlen(data));
}