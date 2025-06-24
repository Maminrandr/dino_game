#include "raylib.h"

#include "game.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void)
{
    GameInit();
    InitWindow(800,500,"DINO_GAME");
    SetTargetFPS(60);
    InitAudioDevice();

   
    Texture2D player_main = LoadTexture("dino/dino.png");
    Texture2D cactus_sprite = LoadTexture("cactus/pixel_art.png");
    Music music = LoadMusicStream("music/jump.mp3");

    while (!WindowShouldClose()){
        BeginDrawing();
        UpdateMusicStream(music);

        ClearBackground(WHITE);
        DrawRectangle(0, 400, GetScreenWidth(), 100, RED);
        DrawTexture(player_main,Player.x,Player.y,WHITE); 
        DrawTexture(cactus_sprite,cactus.x,380,WHITE);

        // Gestion du saut du joueur
        if (IsKeyDown(KEY_SPACE) && !Player.IsJumping){ 
             PlayMusicStream(music);
            Player.IsJumping = true;
        }

        if (Player.IsJumping == true){
            if (Player.jumpcount >= -10){
                Player.y -= (Player.jumpcount * abs(Player.jumpcount)) * .4;
                Player.jumpcount -= 1;
            }
            else{
                Player.jumpcount = 10;
                Player.y = 380; // Retourne à la position y initiale
                StopMusicStream(music);
                Player.IsJumping = false;
            }
        }

        
        MoveCactus(); 

        if (IfCactusCollision() == true){ 
            ResetGameState(); 
        }

        if (cactus.x < 0){ // Si le cactus sort de l'écran par la gauche
            ResetCactusState(); // Réinitialise le cactus et incrémente le score
        }

        DrawText(TextFormat("Score: %02i", Player.score), 50,50,20,GREEN);

        EndDrawing();
    }

    UnloadTexture(player_main);
    UnloadTexture(cactus_sprite);
    UnloadMusicStream(music);
    CloseAudioDevice();
    CloseWindow();

    return 0;
}
