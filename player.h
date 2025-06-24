#ifndef PLAYER_H
#define PLAYER_H

#include <stdbool.h> 

typedef struct player{
    int x;
    int y;
    int jumpcount;
    bool IsJumping;
    int score;
}player;

static player Player; 
#endif 