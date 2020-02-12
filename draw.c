/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnichell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 16:17:18 by tnichell          #+#    #+#             */
/*   Updated: 2020/02/03 16:17:20 by tnichell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_menu(fdf *fdf)
{
	int		y;
	void	*mlx;
	void	*win;

	y = 0;
	mlx = fdf->mlx_ptr;
	win = fdf->win_ptr;
	mlx_string_put(mlx, win, 65, y += 20, TEXT_COLOR, "How to Use");
	mlx_string_put(mlx, win, 15, y += 35, TEXT_COLOR, "Zoom: Scroll or +/-");
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "Move: Arrows");
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "Flatten: </>");
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "Rotate: Press & Move");
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "Rotate:");
	mlx_string_put(mlx, win, 57, y += 25, TEXT_COLOR, "X-Axis - 2/8");
	mlx_string_put(mlx, win, 57, y += 25, TEXT_COLOR, "Y-Axis - 4/6");
	mlx_string_put(mlx, win, 57, y += 25, TEXT_COLOR, "Z-Axis - 1(3)/7(9)");
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "Projection");
	mlx_string_put(mlx, win, 57, y += 25, TEXT_COLOR, "ISO: I Key");
	mlx_string_put(mlx, win, 57, y += 25, TEXT_COLOR, "Parallel: P Key");
}

float   mod(float i)
{
    return (i < 0) ? -i : i;
}

void isometricx(float x, float *y, float *z, float tetta)
{
	float y1;

	y1 = *y;
    *y = *y * cos(tetta) + *z * sin(tetta);
	*z = -y1 * sin(tetta) + *z * cos(tetta);
}

void isometricy(float *x, float y, float *z, float tetta)
{
    float x1;

    x1 = *x;
	*x = *x * cos(tetta) + *z * sin(tetta);
	*z = -x1 * sin(tetta) + *z * cos(tetta);
}

void isometricz(float *x, float *y, float z, float tetta)
{
	float	x1;

	x1 = *x;
	*x = *x * cos(tetta) - *y * sin(tetta);
	*y = x1 * sin(tetta) + *y * cos(tetta);
}
