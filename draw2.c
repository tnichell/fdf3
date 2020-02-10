
#include "fdf.h"

void    bresenham2(fdf *data)
{
	float z;
	float z1;

	z = data->z_matrix[(int) data->y][(int) data->x];
	z1 = data->z_matrix[(int) data->y1][(int) data->x1];
	data->x *= data->zoom;
	data->y *= data->zoom;
	data->x1 *= data->zoom;
	data->y1 *= data->zoom;
	z *= data->zoomz;
	z1 *= data->zoomz;
	data->x -= (data->width * data->zoom) / 2;
	data->x1 -= (data->width * data->zoom) / 2;
	data->y -= (data->height * data->zoom) / 2;
	data->y1 -= (data->height * data->zoom) / 2;
	data->color = (z || z1) ? 0xe80c0c : 0xffffff;
	isometricx(data->x, &(data->y), &z, data->tettax);
	isometricy(&(data->x), data->y, &z, data->tettay);
	isometricz(&(data->x), &(data->y), z, data->tettaz);
	isometricx(data->x1, &(data->y1), &z1, data->tettax);
	isometricy(&(data->x1), data->y1, &z1, data->tettay);
	isometricz(&(data->x1), &(data->y1), z1, data->tettaz);
}

void    bresenham(fdf *data)
{
	float x_step;
	float y_step;
	int max;

	bresenham2(data);
	data->x += data->shift_x;
	data->y += data->shift_y;
	data->x1 += data->shift_x;
	data->y1 += data->shift_y;
	x_step = data->x1 - data->x;
	y_step = data->y1 - data->y;
	max = MAX(MOD(x_step), MOD(y_step));
	x_step /= max;
	y_step /= max;
	while ((int) (data->x - data->x1) || (int) (data->y - data->y1))
	{
		mlx_pixel_put(data->mlx_ptr,
					  data->win_ptr, data->x, data->y, data->color);
		data->x += x_step;
		data->y += y_step;
	}
}

void 	draw2(int x, int y, fdf *data)
{
	if (x < data->width - 1)
	{
		data->y = y;
		data->x = x;
		data->x1 = data->x + 1;
		data->y1 = data->y;
		bresenham(data);
	}
	if (y < data->height - 1)
	{
		data->y = y;
		data->x = x;
		data->x1 = data->x ;
		data->y1 = data->y + 1;
		bresenham(data);
	}
}
void 	draw(fdf *data)
{
	int x;
	int y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			draw2(x, y, data);
			x++;
		}
		y++;
	}
}