#ifndef CACTUS_h
#define CACTUS_H

#include "player.h" 

typedef struct Cactus
{
    int x;
}Cactus;

static Cactus cactus;

// Fait bouger le cactus vers la gauche
static void MoveCactus(){
    cactus.x -= 10;
}

int IfCactusCollision(){
    // La logique de collision est conservée
    if (Player.x - cactus.x <= 50 && Player.x - cactus.x >= 0 && Player.y - 380 >= -50){
        return true;
    }
    return false; // Ajouter un retour false si pas de collision
}

static void ResetCactusState(){
    cactus.x = 500;
    Player.score ++;
}

#endif 