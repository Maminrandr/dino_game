#ifndef SCREEN_H
#define SCREEN_H
#include "./dino.h"
#include <stdbool.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define GROUND_HEIGHT 100
#define PLAYER_WIDTH 20
#define PLAYER_HEIGHT 50
#define ENEMY_WIDTH 20
#define ENEMY_HEIGHT 50
#define JUMPING_PLAYER -15.0f
#define FALLING_PLAYER 0.8f

extern float GAME_SPEED;
extern float ground_y;
extern Legends player;
extern Enemy enemy[3];
extern int score;
extern bool game_over;
extern Texture2D player_texture;
void init_game();

#endif
