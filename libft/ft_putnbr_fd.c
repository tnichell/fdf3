/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnichell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 19:53:17 by tnichell          #+#    #+#             */
/*   Updated: 2019/09/22 21:39:24 by tnichell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		k;
	int		i;
	char	buf[11];

	if (n != -2147483648)
	{
		if (n < 0)
		{
			ft_putchar_fd('-', fd);
			n = n * -1;
		}
		i = ft_lennbr(n);
		buf[i] = '\0';
		k = i;
		while (i > 0)
		{
			buf[i - 1] = n % 10 + '0';
			n = n / 10;
			i--;
		}
		write(fd, buf, k);
	}
	else
		write(fd, "-2147483648", 11);
}
