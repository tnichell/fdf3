/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnichell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 17:57:15 by tnichell          #+#    #+#             */
/*   Updated: 2019/10/29 22:38:59 by tnichell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "stdio.h"
# include "fcntl.h"
# include "unistd.h"
# include "stdlib.h"
# include "libft/libft.h"
# define BUFF_SIZE 100

typedef	struct				s_get_next_line
{
	int						fd;
	char					*reminder;
	struct s_get_next_line	*next;
}							t_gnl;

int							get_next_line(int fd, char **line);

#endif
