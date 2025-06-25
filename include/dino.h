
#ifndef DINO_H
# define DINO_H

# include "raylib.h"
# include <stdio.h>

typedef struct position
{
	float		x;
	float		y;
}				t_position;

typedef struct data
{
	t_position	pos;

	int			width;
	int			height;
	int			score;
	int			new_score;
	bool		jump;
	bool		jumping;
}				t_data;

// void			show_position(float *player_x, float *player_y, float *ennemi_x,
// 					float *ennemi_y, int *score);

#endif