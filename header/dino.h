#ifndef GAME_H
#define GAME_H
#include "raylib.h"
#include <stdbool.h>

typedef struct
{
    float x;
    float y;
} Position;

typedef struct
{
    Position player_position;
    Position player_velocity;
    bool is_jumping;
    Rectangle player_view;  
} Legends;

typedef struct
{
    Position enemy_position;
    Rectangle enemy_view;   
    bool active;
} Enemy;

void draw_game(void);
void update_view(void);
void update_game();

#endif

