#include "include/raylib.h"
#include "include/dino.h"
#include <stdio.h>

#define WIDTH 800
#define HEIGHT 450

typedef enum {
    MENU,
    PLAYING,
    GAME_OVER
} GameState;

typedef struct {
    float ennemi_pos;
    float player_pos;
    float player_pos_y;
    float first_pos;
    int curr;
    int curr2;
    int speed;
    int score;
    bool jump;
    bool jumping;
    int player_speed;
    int player_score;
    int speed_frame;
    Rectangle dst_player;
    Rectangle dst_ennemi;
} GameData;

void InitGame(GameData *game) {
    game->ennemi_pos = 700;
    game->player_pos = 100;
    game->player_pos_y = 300;
    game->curr = 0;
    game->curr2 = 0;
    game->speed = 500;
    game->score = 0;
    game->jump = false;
    game->jumping = false;
    game->player_speed = 300;
    game->player_score = 0;
    game->speed_frame = 0;
    
    game->dst_player = (Rectangle){game->player_pos, game->player_pos_y, 96 * 0.7, 128 * 0.7};
    game->dst_ennemi = (Rectangle){game->ennemi_pos, 300, -96 * 0.7, 128 * 0.7};
    game->first_pos = game->dst_player.y;
}

void UpdateGame(GameData *game) {
    game->speed_frame++;
    if (game->speed_frame >= 7) {
        game->curr = (game->curr + 1) % 3;
        game->curr2 = (game->curr2 + 1) % 2;
        game->speed_frame = 0;
    }
    
    game->dst_ennemi.x -= GetFrameTime() * game->speed;
    if (game->dst_ennemi.x < 0) {
        game->dst_ennemi.x = WIDTH;
        game->score += 100;
    }
    
    if (IsKeyPressed(KEY_SPACE) && game->dst_player.y == 300 && game->dst_player.x <= 50) {
        game->jump = true;
        game->jumping = true;
    }
    
    if (game->jump && game->jumping) {
        game->dst_player.y -= GetFrameTime() * game->player_speed;
        game->dst_player.x += GetFrameTime() * 100;
        if (game->dst_player.y <= 200) {
            game->jumping = false;
        }
    }
    
    if (game->jump && !game->jumping) {
        game->dst_player.y += GetFrameTime() * game->player_speed / 2;
        if (game->dst_player.y >= 300) {
            game->dst_player.y = 300;
            game->jump = false;
        }
    }
    
    if (!game->jump && !game->jumping) {
        if (game->dst_player.x >= 50) {
            game->dst_player.x -= GetFrameTime() * game->player_speed;
        }
    }
    
    if (game->score >= (game->player_score + 400)) {
        game->speed += 50;
        game->player_speed += 40;
        game->player_score = game->score;
    }
}

bool CheckCollision(GameData *game) {
    return (game->dst_player.x + 50 > game->dst_ennemi.x) && 
           (game->dst_player.y > game->dst_ennemi.y - 43);
}

void DrawGame(GameData *game, Texture2D *pj, Texture2D *jmp, Texture2D *ennemi, 
              Texture2D attack, Texture2D bkground, Rectangle src_player, 
              Rectangle src_ennemi, Rectangle src_bg, Rectangle dst_bg) {
    
    char scores[50];
    sprintf(scores, "Score: %d", game->score);
    
    DrawTexturePro(bkground, src_bg, dst_bg, (Vector2){0, 0}, 0, WHITE);
    DrawLine(0, 400, WIDTH, 400, MAROON);
    DrawText(scores, 10, 10, 30, BLACK);
    
    if (!game->jump && !game->jumping)
        DrawTexturePro(pj[game->curr], src_player, game->dst_player, (Vector2){0, 0}, 0, WHITE);
    else if (game->jump)
        DrawTexturePro(jmp[0], src_player, game->dst_player, (Vector2){0, 0}, 0, WHITE);
    else
        DrawTexturePro(jmp[1], src_player, game->dst_player, (Vector2){0, 0}, 0, WHITE);
    
    if (game->dst_ennemi.x <= 250 && game->dst_ennemi.x >= 50)
        DrawTexturePro(attack, src_ennemi, game->dst_ennemi, (Vector2){0, 0}, 0, WHITE);
    else
        DrawTexturePro(ennemi[game->curr2], src_ennemi, game->dst_ennemi, (Vector2){0, 0}, 0, WHITE);
}

void DrawMenu() {
    ClearBackground(DARKBLUE);
    DrawText("Run for your life", WIDTH/2 - 150, HEIGHT/2 - 100, 50, WHITE);
    DrawText("Press SPACE to Start", WIDTH/2 - 120, HEIGHT/2 - 20, 30, LIGHTGRAY);
    DrawText("Use SPACE to Jump", WIDTH/2 - 100, HEIGHT/2 + 20, 20, GRAY);
}

void DrawGameOver(int final_score) {
    ClearBackground(BLACK);
    DrawText("GAME OVER", WIDTH/2 - 150, HEIGHT/2 - 50, 50, RED);
    
    char score_text[50];
    sprintf(score_text, "Final Score: %d", final_score);
    DrawText(score_text, WIDTH/2 - 100, HEIGHT/2 + 20, 25, WHITE);
    
    DrawText("Press SPACE to Restart", WIDTH/2 - 120, HEIGHT/2 + 70, 20, LIGHTGRAY);
    DrawText("Press ESC to Exit", WIDTH/2 - 80, HEIGHT/2 + 100, 20, GRAY);
}

int main() {
    GameState gameState = MENU;
    GameData game;
    
    InitWindow(WIDTH, HEIGHT, "Run for your life");
    SetTargetFPS(60);
    
    Texture2D pj[3];
    pj[0] = LoadTexture("run/run0.png");
    pj[1] = LoadTexture("run/run1.png");
    pj[2] = LoadTexture("run/run2.png");
    
    Texture2D jmp[2];
    jmp[0] = LoadTexture("jump/jump.png");
    jmp[1] = LoadTexture("jump/fall.png");
    
    Texture2D ennemi[3];
    ennemi[0] = LoadTexture("zombie/run0.png");
    ennemi[1] = LoadTexture("zombie/run1.png");
    ennemi[2] = LoadTexture("zombie/run2.png");
    
    Texture2D attack = LoadTexture("attack.png");
    Texture2D bkground = LoadTexture("background.png");
    

    Rectangle src_player = {0, 0, 96, 128};
    Rectangle src_ennemi = {0, 0, -96, 128};
    Rectangle src_bg = {0, 0, 1024, 1024};
    Rectangle dst_bg = {0, 0, 800, 450};
    
    while (!WindowShouldClose()) {
        BeginDrawing();
        
        switch (gameState) {
            case MENU:
                DrawMenu();
                if (IsKeyPressed(KEY_SPACE)) {
                    InitGame(&game);
                    gameState = PLAYING;
                }
                break;
                
            case PLAYING:
                UpdateGame(&game);
                
                if (CheckCollision(&game)) {
                    gameState = GAME_OVER;
                }
                
                ClearBackground(RAYWHITE);
                DrawGame(&game, pj, jmp, ennemi, attack, bkground, 
                        src_player, src_ennemi, src_bg, dst_bg);
                break;
                
            case GAME_OVER:
                DrawGameOver(game.score);
                
                if (IsKeyPressed(KEY_SPACE)) {
                    gameState = MENU;
                } else if (IsKeyPressed(KEY_ESCAPE)) {
                    goto cleanup;
                }
                break;
        }
        
        EndDrawing();
    }
    
cleanup:
    UnloadTexture(pj[0]);
    UnloadTexture(pj[1]);
    UnloadTexture(pj[2]);
    UnloadTexture(jmp[0]);
    UnloadTexture(jmp[1]);
    UnloadTexture(ennemi[0]);
    UnloadTexture(ennemi[1]);
    UnloadTexture(ennemi[2]);
    UnloadTexture(attack);
    UnloadTexture(bkground);
    
    CloseWindow();
    return 0;
}