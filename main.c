#include "include/raylib.h"
#include "include/dino.h"
#include <stdio.h>

#define	WIDTH 800
#define	HEIGHT 450

void	run(Texture2D *png, int curr, int speed)
{
	if (speed >= 7)
		curr = (curr + 1) % 3;
}

int main()
{
	float		ennemi_pos = 700;
	float		player_pos = 100;
	float		player_pos_y = 300;
	float		first_pos;
	char		pos[50];
    char score_final[50];
	Texture2D	pj[3];
	Texture2D	jmp[2];
	Texture2D	ennemi[3];
	Texture2D	attack;
	Texture2D	bkground;
	int			curr;
	int			curr2;
	int			speed;
    int score;
    bool jump;
    bool jumping;
    bool gameover = false;
    int player_speed;
    int player_score;
    int speed_frame = 0;
    player_speed = 300;


	InitWindow(WIDTH, HEIGHT, "basic window");
	SetTargetFPS(60);
	pj[0] = LoadTexture("run/run0.png");
	pj[1] = LoadTexture("run/run1.png");
	pj[2] = LoadTexture("run/run2.png");
	jmp[0] = LoadTexture("jump/jump.png");
	jmp[1] = LoadTexture("jump/fall.png");
	ennemi[0] = LoadTexture("zombie/run0.png");
	ennemi[1] = LoadTexture("zombie/run1.png");
	ennemi[2] = LoadTexture("zombie/run2.png");
	attack = LoadTexture("attack.png");
	bkground = LoadTexture("background.png");
	speed = 500;
	curr = 0;
	curr2 = 0;
    score = 0;
    player_score = 0;

	Rectangle src_player = {0, 0, 96, 128};
	Rectangle dst_player = {player_pos, player_pos_y, 96 * 0.7, 128 * 0.7};
	Rectangle	src_ennemi = {0, 0, -96, 128};
	Rectangle	dst_ennemi = {ennemi_pos, 300, -96 *0.7, 128 * 0.7};
	Rectangle	src_bg = {0, 0, 1024, 1024};
	Rectangle	dst_bg = {0, 0, 800, 450};
	first_pos = dst_player.y;
	while (!WindowShouldClose() && gameover ==false)
	{
        speed_frame ++;
		if (speed_frame >= 7)
		{
			curr = (curr + 1) % 3;
			curr2 = (curr2 + 1) % 2;
			speed_frame = 0;
		}
		dst_ennemi.x -= GetFrameTime() * speed;
		if (dst_ennemi.x < 0)
		{
			dst_ennemi.x  = WIDTH;
			score += 100;
		}
		if (IsKeyPressed(KEY_SPACE) && dst_player.y  == 300 && dst_player.x  <= 50)
		{
			jump = true;
			jumping = true;
		}
		if (jump && jumping)
		{
			dst_player.y  -= GetFrameTime() * player_speed;
			dst_player.x  += GetFrameTime() * 100;
			if (dst_player.y  <= 200)
			{
				jumping = false;
			}
		}
		if (jump && !jumping)
		{
			dst_player.y  += GetFrameTime() * player_speed/2;
			if (dst_player.y  >= 300)
			{
				dst_player.y  = 300;
				jump = false;
			}
		}
		if (!jump && !jumping)
		{
			if (dst_player.x  >= 50)
			{
				dst_player.x  -= GetFrameTime() * player_speed;
			}
		}
		if ((dst_player.x + 50 > dst_ennemi.x) && (dst_player.y > dst_ennemi.y - 43))
        {
			gameover = true;
		}

		if (score >= (player_score + 400))
		{
			speed += 50;
			player_speed += 40;
			player_score = score;
		}
		BeginDrawing();
			ClearBackground(RAYWHITE);
            
            char scores[50];


            sprintf(scores, "score : %d", score);
            DrawText(scores, 10, 100, 50, BLACK);

				DrawTexturePro(bkground, src_bg, dst_bg, (Vector2){0, 0}, 0, WHITE);
				DrawLine(0, 400, WIDTH, 400, MAROON);
				if (!jump && !jumping)
					DrawTexturePro(pj[curr], src_player, dst_player, (Vector2){0, 0}, 0, WHITE);
				else if (jump)
					DrawTexturePro(jmp[0], src_player, dst_player, (Vector2){0, 0}, 0, WHITE);
				else
					DrawTexturePro(jmp[1], src_player, dst_player, (Vector2){0, 0}, 0, WHITE);
				if (dst_ennemi.x <= 250 && dst_ennemi.x >= 50)
					DrawTexturePro(attack, src_ennemi, dst_ennemi, (Vector2){0, 0}, 0, WHITE);
				else
					DrawTexturePro(ennemi[curr2], src_ennemi, dst_ennemi, (Vector2){0, 0}, 0, WHITE);
					
			EndDrawing();
	}
    while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(BLACK);
		DrawText("GAME OVER",WIDTH/3, HEIGHT/2,  50, RED);
		sprintf(score_final, "ton score final est de %d",score);
		DrawText(score_final, 600, 300, 20, RAYWHITE);

		EndDrawing();
		if (IsKeyPressed(KEY_ESCAPE))
			break ;
	}
	UnloadTexture(pj[0]);
	UnloadTexture(pj[1]);
	UnloadTexture(pj[2]);
	UnloadTexture(ennemi[0]);
	UnloadTexture(ennemi[1]);
	UnloadTexture(attack);
	CloseWindow();
	return 0;
}
