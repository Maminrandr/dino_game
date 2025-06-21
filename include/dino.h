
#ifndef DINO_H
# define DINO_H

# ifndef SCREEN_WIDTH
#  define SCREEN_WIDTH 1200
# endif
# ifndef SCREEN_HEIGHT
#  define SCREEN_HEIGHT 800
# endif
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
	int 		new_score;
	bool		jump;
	bool		jumping;
}				t_data;

void			show_position(t_data *dino, t_data *stick);

#endif