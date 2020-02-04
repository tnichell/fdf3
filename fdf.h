//
// Created by Trebor Nichelle on 23/01/2020.
//

#ifndef FDF_H
#define FDF_H

#include "libft/libft.h"
#include "minilibx_macos/mlx.h"

typedef struct s_fdf
{
	int width;
	int height;
	int **z_matrix;

	void *mlx_ptr;
	void *win_ptr;
}			fdf;

void    read_file(fdf *data, fdf *data2);
void	bresenham(float x, float y, float x1, float y1, fdf *data);

#endif //FDF_H