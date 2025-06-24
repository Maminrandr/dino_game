#include <stdio.h>
#include "raylib.h"
#include "../header/dino.h"
#include "../header/screen.h"

int main(void)
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Run for your life");
    SetTargetFPS(30);
    init_game();

    while (!WindowShouldClose())
    {
        /* code */
    }

    CloseWindow();
    return 0;
}
