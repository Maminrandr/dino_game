#include "../../header/dino.h"
#include "../../header/screen.h"
#include "raylib.h"

void draw_game()
{
    BeginDrawing();

    ClearBackground(WHITE);
    DrawRectangle(0, SCREEN_HEIGHT / 2, SCREEN_WIDTH, SCREEN_HEIGHT / 2, RED);
    DrawRectangle(0, 0, SCREEN_WIDTH / 6, SCREEN_HEIGHT, GREEN);

    // create the ground
    DrawRectangle(0, ground_y, SCREEN_WIDTH, GROUND_HEIGHT, DARKGREEN);

    Color tint_color = player.is_jumping ? ORANGE : WHITE;
    Vector2 position = {player.player_position.x, player.player_position.y};
    float scale = (float)PLAYER_WIDTH / player_texture.width * 2.0f;
    DrawTextureEx(player_texture, position, 0.0f, scale, tint_color);

    DrawRectangleLines(player.player_view.x, player.player_view.y, player.player_view.width, player.player_view.height, BLUE);

    for (int i = 0; i < 3; i++)
    {
        if (enemy[i].active)
        {
            DrawRectangle(enemy[i].enemy_position.x, enemy[i].enemy_position.y, ENEMY_WIDTH, ENEMY_HEIGHT, MAROON);
        }
    }
    DrawText(TextFormat("Score: %d", score), 10, 10, 20, BLACK);

    if (!game_over)
    {
        DrawText("Press space to run and avoid the enemies for your life", 10, SCREEN_HEIGHT - 30, 16, BLACK);
    }
    else
    {
        DrawText("You so noob, dieee", SCREEN_WIDTH / 2 - 80, SCREEN_HEIGHT / 2 - 40, 32, BLACK);
        DrawText("goo retryy brooooo don't die like that", SCREEN_WIDTH / 2 - 150, SCREEN_HEIGHT / 2, 16, BLACK);
    }
    EndDrawing();
}

void update_view(void)
{
    player.player_view = (Rectangle){
        player.player_position.x,
        player.player_position.y,
        PLAYER_WIDTH,
        PLAYER_HEIGHT};

    for (int i = 0; i < 3; i++)
    {
        enemy[i].enemy_view = (Rectangle){
            enemy[i].enemy_position.x,
            enemy[i].enemy_position.y,
            ENEMY_WIDTH,
            ENEMY_HEIGHT};
    }
}
void update_game()
{
    if (game_over)
    {
        if (IsKeyPressed(KEY_SPACE))
        {
            init_game();
        }
        return;
    }
    if (IsKeyPressed(KEY_SPACE) && !player.is_jumping)
    {
        player.player_velocity.y = JUMPING_PLAYER; // ty zany mapsoty azy
        player.is_jumping = true;
    }
    player.player_velocity.y += FALLING_PLAYER;
    player.player_position.y += player.player_velocity.y;
    // need to verify if player is in the ground
    if (player.player_position.y > ground_y - PLAYER_HEIGHT)
    {
        player.player_position.y = ground_y - PLAYER_HEIGHT;
        player.player_velocity.y = 0;
        player.is_jumping = false;
    }

    for (int i = 0; i < 3; i++)
    {
        if (enemy[i].active)
        {
            enemy[i].enemy_position.x -= GAME_SPEED;

            if (enemy[i].enemy_position.x < -ENEMY_WIDTH)
            {
                enemy[i].enemy_position.x = SCREEN_WIDTH + (i * 300);
                score = score + 20;
            }
            if (score > 100)
            {
                GAME_SPEED = 10;
            }
        }
    }
    update_view();

    for (int i = 0; i < 3; i++)
    {
        if (enemy[i].active && CheckCollisionRecs(player.player_view, enemy[i].enemy_view))
        {
            game_over = true;
        }
    }
}
