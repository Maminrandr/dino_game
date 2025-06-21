
#include "dino.h"

void	show_position(t_data *dino, t_data *stick)
{
	char dino_pos_x[50];
	char dino_pos_y[50];
	char stick_pos_x[50];
	char stick_pos_y[50];
	char score[50];

	sprintf(dino_pos_x, "dino_pos.x : %.1f", dino->pos.x);
	DrawText(dino_pos_x, 10, 5, 20, RAYWHITE);
	sprintf(dino_pos_y, "dino_pos.y : %.1f", dino->pos.y);
	DrawText(dino_pos_y, 10, 100, 20, RAYWHITE);

	sprintf(stick_pos_x, "dino_pos.x : %.1f", stick->pos.x);
	DrawText(stick_pos_x, 1000, 5, 20, RAYWHITE);
	sprintf(stick_pos_y, "dino_pos.y : %.1f", stick->pos.y);
	DrawText(stick_pos_y, 1000, 100, 20, RAYWHITE);

	sprintf(score, "score : %d", dino->score);
	DrawText(score, 500, 100, 20, RAYWHITE);
}