#include "include/raylib.h"
#include <stdio.h>

#define	WIDTH 800
#define	HEIGHT 450

int	checking_collision(float *posX1, float *posX2, float *posY)
{
	if (*posX1 <= 150 && *posX1 >= 50 && *posY > 250)
		return (1);
	else
		return (0);
}

void	initialize(Rectangle *src, Rectangle *dst)
{
	src->height = 128;
	src->width = 96;
	dst->height = 128 * 0.5;
	src->width = 96 * 0.5;
}
void	run(Texture2D *png, int curr, int speed)
{
	if (speed >= 7)
		curr = (curr + 1) % 3;
}

int main()
{
	float		posX1 = 700;
	int			bk = 1;
	int			up = 0;
	float		posX2 = 100;
	float		posY = 300;
	float		posfst;
	char		pos[50];
	Texture2D	pj[3];
	Texture2D	jmp[2];
	Texture2D	ennemi[3];
	Texture2D	attack;
	Texture2D	bkground;
	int			curr;
	int			curr2;
	int			speed;
	//Texture2D	ennemi;
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
	speed = 0;
	curr = 0;
	curr2 = 0;
	Rectangle src = {0, 0, 96, 128};
	Rectangle dst = {posX2, posY, 96 * 0.7, 128 * 0.7};
	Rectangle	src2 = {0, 0, -96, 128};
	Rectangle	dst2 = {posX1, 300, -96 *0.7, 128 * 0.7};
	Rectangle	bk_src = {0, 0, 1024, 1024};
	Rectangle	bk_dst = {0, 0, 800, 450};
	posfst = dst.y;
	while (!WindowShouldClose())
	{
		speed ++;
		if (speed >= 7)
		{
			curr = (curr + 1) % 3;
			curr2 = (curr2 + 1) % 2;
			speed = 0;
		}
		dst2.x -= GetFrameTime() * 400;
		if (checking_collision(&dst2.x, &dst.x, &dst.y) > 0)
			break;
		if (dst2.x < 0)
			dst2.x = 800;	
		if (IsKeyPressed(KEY_UP) && dst.y >= posfst)
		{
			up = 1;
			
		}
		if (dst.y < 161 && up == 1)
			up = 0;
		if (dst.y > 161 && up == 1)
			dst.y -= GetFrameTime() * 400;
		else if (up == 0 && dst.y <= posfst)
		{
			dst.y += GetFrameTime() * 400;
		}
		sprintf(pos, "posY : %.1f", dst.y);
		DrawText(pos, 10, 5, 20, BLACK);

		BeginDrawing();
			ClearBackground(RAYWHITE);
				DrawTexturePro(bkground, bk_src, bk_dst, (Vector2){0, 0}, 0, WHITE);
				DrawLine(0, 400, WIDTH, 400, MAROON);
				if (dst.y >= posfst)
					DrawTexturePro(pj[curr], src, dst, (Vector2){0, 0}, 0, WHITE);
				else if (up == 1)
					DrawTexturePro(jmp[0], src, dst, (Vector2){0, 0}, 0, WHITE);
				else
					DrawTexturePro(jmp[1], src, dst, (Vector2){0, 0}, 0, WHITE);
				if (dst2.x <= 250 && dst2.x >= 50)
					DrawTexturePro(attack, src2, dst2, (Vector2){0, 0}, 0, WHITE);
				else
					DrawTexturePro(ennemi[curr2], src2, dst2, (Vector2){0, 0}, 0, WHITE);
					
			EndDrawing();
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
