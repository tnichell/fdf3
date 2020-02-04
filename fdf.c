/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnichell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 23:30:40 by tnichell          #+#    #+#             */
/*   Updated: 2020/01/21 23:30:42 by tnichell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int 	get_height(char *file_name)
{
	char *line;
	int fd;
	int height;

	fd = open(file_name, O_RDONLY, 0);
	height = 0;
	while(get_next_line(fd, &line))
	{
		height++;
		free(line);
	}
}

void 	read_file(fdf *data, fdf *data2)
{
	data->height = get_height(file_name)

}
