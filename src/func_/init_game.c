#include <stdio.h>
#include "../../header/dino.h"
#include "../../header/screen.h"

float ground_y;
Legends player;
int score;
bool game_over;
float GAME_SPEED;
Enemy enemy[3];
void init_game()
{
    player.player_position.x = 100;
    player.player_position.y = ground_y - PLAYER_HEIGHT;
    player.player_velocity.x = 0;
    player.player_velocity.y = 0;
    player.is_jumping = false;

    ground_y = SCREEN_HEIGHT - GROUND_HEIGHT;
    for (int i = 0; i < 3; i++)
    {
        /* code */
        enemy[i].enemy_position.x = SCREEN_WIDTH + (i * 300);
        enemy[i].enemy_position.y = ground_y - ENEMY_HEIGHT;
        enemy[i].active = true;
    }

    score = 0;
    game_over = false;
    GAME_SPEED = 5.0f;
}
