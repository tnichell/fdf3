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

#define MAX(a, b) (a > b ? a : b)
#define MOD(a) ((a < 0) ? -a : a)

float   mod(float i)
{
    return (i < 0) ? -i : i;
}

void    bresenham(float x, float y, float x1, float y1, fdf *data)
{
    float x_step;
    float y_step;
    int max;

    x_step = x1 - x;
    y_step = y1 - y;

    max /= MAX(MOD(x_step), MOD(y_step));
    x_step /= max;
    y_step /= max;
    while((int)(x - x1) || (int)(y - y1))
    {
        mlx_pixel_put(data->mlx_ptr, data->win_ptr, x,  y, 0xffffff);
        x += x_step;
        y += y_step;
    }


}