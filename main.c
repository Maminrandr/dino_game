#include "include/raylib.h"
#include <stdio.h>

int	checking_collision(float *posX1, float *posX2, float *posY)
{
	if (*posX1 <= 150 && *posX1 >= 50 && *posY > 250)
		return (1);
	else
		return (0);
}

int	main(void)
{
	float	posX1;
	int		bk;
	int		up;
	float	posX2;
	float	posY;
	float	posfst;
	char	pos[50];

	posX1 = 700;
	bk = 1;
	up = 0;
	posX2 = 100;
	posY = 300;
	posfst = posY;
	InitWindow(800, 450, "basic window");
	SetTargetFPS(144);
	while (!WindowShouldClose())
	{
		posX1 -= GetFrameTime() * 400;
		if (posX1 < 0)
			posX1 = 800;
		if (IsKeyPressed(KEY_UP) && posY >= posfst)
		{
			up = 1;
		}
		if (posY < 161 && up == 1)
			up = 0;
		if (posY > 161 && up == 1)
			posY -= GetFrameTime() * 400;
		else if (up == 0 && posY <= posfst)
		{
			posY += GetFrameTime() * 400;
		}
		sprintf(pos, "posY : %.1f", posY);
		DrawText(pos, 10, 5, 20, RAYWHITE);
		BeginDrawing();
		ClearBackground(BLACK);
		DrawRectangle(posX1, 300, 50, 50, RED);
		DrawRectangle(posX2, 300, 50, 50, BLUE);
		
		// if (IsKeyPressed(KEY_SPACE))
		// {

		// }
		DrawLine(0, 350, 800, 351, GREEN);
		// if (checking_collision(&posX1, &posX2, &posY) > 0)
			// break ;
		EndDrawing();
	}
	CloseWindow();
	return (0);
}
