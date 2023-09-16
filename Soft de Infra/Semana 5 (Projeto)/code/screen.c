#include <screen.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

const char *input = "[INPUT]: \n\r";

void clear_terminal()
{
#if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
    system("clear");
#endif

#if defined(_WIN32) || defined(_WIN64)
    system("cls");
#endif
}

screen create_screen(uint8 height, uint8 width)
{
    const uint32 buffer_size = height * (width + 1) + strlen(input);

    char *buffer = malloc(buffer_size);
    memset(buffer, '#', buffer_size);
    for (uint32 i = 0; i < height; i++)
    {
        buffer[width + i * (width + 1)] = '\n';
    }
    memcpy(buffer + height * (width + 1), input, strlen(input));

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