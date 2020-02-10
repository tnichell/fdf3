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
