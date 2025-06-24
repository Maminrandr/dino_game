#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "cactus.h"

// Initialise l'état du jeu pour le début direct
static void GameInit(){
    Player.x = 100;
    Player.y = 380;
    Player.jumpcount = 10;
    Player.IsJumping = false;
    cactus.x  = 500;
    Player.score = 0;
}

// Réinitialise l'état du jeu après une collision ou pour redémarrer
static void ResetGameState(){
    Player.score = 0;
    cactus.x = 500;
}
#endif 