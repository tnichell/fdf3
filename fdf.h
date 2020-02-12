//
// Created by Trebor Nichelle on 23/01/2020.
//

#ifndef FDF_H
#define FDF_H

#include "libft/libft.h"
#include "minilibx_macos/mlx.h"

#include "math.h"
#include "stdio.h"
#define TEXT_COLOR  0xffffff
typedef struct s_ili
{
	int number;
	int color;
}               t_ili;

typedef struct s_fdf
{
	int max;
	int min;
	int width;
	int height;
	t_ili **z_matrix;
	int zoom;
	float zoomz;
	int color;
	int shift_x;
	int shift_y;
	float tettax;
	float tettay;
	float tettaz;
	void *mlx_ptr;
	void *win_ptr;
	float x;
	float y;
	float x1;
	float y1;
}			fdf;

void isometricz(float *x, float *y, float z, float tetta);
void isometricy(float *x, float y, float *z, float tetta);
void isometricx(float x, float *y, float *z, float tetta);
float   mod(float i);
void    read_file(char *data, fdf **data2);
void    bresenham(fdf *data);
void 	draw(fdf *data);
void	print_menu(fdf *fdf);

#endif //FDF_H