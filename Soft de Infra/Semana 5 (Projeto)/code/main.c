#include <stdio.h>

#include "new_types.h"
#include "profile.h"
#include "screen.h"
#include "rand.h"

int GAME_main();

int main(int argc, char **argv)
{
    init_rand();
    return GAME_main();
}

int GAME_main()
{
    bool running = true;
    screen _screen = create_screen(32, 128);
    while (running)
    {
        screen_flush(_screen);

        char input[_screen.width];
        fgets(input, _screen.width - 1, stdin);
    }
    return 0;
}