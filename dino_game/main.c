#include "include/dino.h"

int	main(void)
{
	char score_final[50];
	t_data	dino;
	t_data	stick;
	int dino_speed;
	float	speed;
	bool	jump;
	bool	jumping;
	bool	gameover;
	Texture2D img[3];
	Rectangle source;
	Rectangle dest;

	dino.pos.x = 50.0;
	dino.pos.y = 300.0;
	stick.pos.x = SCREEN_WIDTH;
	stick.pos.y = 300;
	dino.score = 0;
	speed = 500;
	dino_speed = 300;
	dino.height = 50;
	dino.width = 20;
	stick.height = 50;
	stick.width = 20;
	dino.new_score = dino.score;
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "dinaozaoro");
	SetTargetFPS(60);
	while (!WindowShouldClose() && !gameover)
	{
		stick.pos.x -= GetFrameTime() * speed;
		if (stick.pos.x < 0)
		{
			stick.pos.x = SCREEN_WIDTH;
			dino.score += 100;
		}
		if (IsKeyPressed(KEY_SPACE) && dino.pos.y == 300 && dino.pos.x <= 50)
		{
			jump = true;
			jumping = true;
		}
		if (jump && jumping)
		{
			dino.pos.y -= GetFrameTime() * dino_speed;
			dino.pos.x += GetFrameTime() * 100;
			if (dino.pos.y <= 220)
			{
				jumping = false;
			}
		}
		if (jump && !jumping)
		{
			dino.pos.y += GetFrameTime() * dino_speed/2;
			if (dino.pos.y >= 300)
			{
				dino.pos.y = 300;
				jump = false;
			}
		}
		if (!jump && !jumping)
		{
			if (dino.pos.x >= 50)
			{
				dino.pos.x -= GetFrameTime() * 200;
			}
		}
		if (dino.pos.x < stick.pos.x + stick.width && dino.pos.x
			+ dino.width > stick.pos.x && dino.pos.y < stick.pos.y
			+ stick.height && dino.pos.y + dino.height > stick.pos.y)
		{
			gameover = true;
		}

		if (dino.score >= (dino.new_score + 400))
		{
			speed += 200;
			dino_speed += 30;
			dino.new_score = dino.score;
		}
		
		BeginDrawing();
		show_position(&dino, &stick);
		ClearBackground(BLACK);
		DrawRectangle(dino.pos.x, dino.pos.y, dino.width, dino.height, BLUE);
		DrawRectangle(stick.pos.x, stick.pos.y, stick.width, stick.height, RED);
		DrawLine(0, 350, SCREEN_WIDTH, 351, GREEN);
		EndDrawing();
	}
	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(BLACK);
		DrawText("GAME OVER",SCREEN_WIDTH/3, SCREEN_HEIGHT/2,  50, RED);
		sprintf(score_final, "ton score final est de %d",dino.score);
		DrawText(score_final, 600, 300, 20, RAYWHITE);

		EndDrawing();
		if (IsKeyPressed(KEY_ESCAPE))
			break ;
	}
	CloseWindow();
}
