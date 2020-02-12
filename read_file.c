//
// Created by Trebor Nichelle on 01/02/2020.
//

#include "fdf.h"
#include <fcntl.h>


unsigned long long int	ft_degree(unsigned
	                                long long int x, unsigned long long int n)
{
	if (n == 0)
		return (1);
	else if (n == 1)
		return (x);
	else if (n % 2 == 0)
		return (ft_degree(x * x, n / 2));
	else
		return (ft_degree(x * x, n / 2) * x);
}

int perevod(char *s)
{
	int i;
	int m;
	int l;
	int b;

	i = 0;
	l = strlen(s);
	m = 0;
	while (s[i])
	{
		b = s[i] > 64 ? s[i] - 55  : s[i] - 48;
		m += b * ft_degree(16, --l );
		i++;
	}
	return (m);
}

int     get_height(char *file_name)
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
  close(fd);
  return(height);
}

int     get_width(char *file_name)
{
    int width;
    int fd;
    char *line;

    fd = open(file_name, O_RDONLY, 0);
    get_next_line(fd, &line);
    width = wordcount(line, ' ');
    free(line);
   // close(fd);
    return (width);
}

int ft_isnumber(const char *s)
{
	int i;

	i = 0;
	if (s[0] == '-')
		i++;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

void    error()
{
	ft_putstr("ERROR\n");
	exit(0);
}

void     stop(char *s2, t_ili *z_line)
{
	int i;

	i = 2;
	s2++;
	if (*s2 != '0' && *(s2 + 1) != 'x' && *(s2 + 9) != 0)
		error();
	while (s2[i])
	{
		if (!((s2[i] >= 'A' && s2[i] <= 'F') || ft_isdigit(s2[i])))
			error();
		i++;
	}
	z_line->color = perevod(s2 + 2);
}

void    fill_matrix(t_ili *z_line, char *line)
{
	char **nums;
	int i;
	char *s2;

	nums = ft_strsplit(line, ' ');
	i = 0;
	while (nums[i])
	{
		if ((s2 = ft_strchr(nums[i], ',')))
			stop(s2, z_line + i);
		else
		{
			if (!ft_isnumber(nums[i]))
				error();
			z_line[i].color = 0;
		}
		z_line[i].number = ft_atoi(nums[i]);
		i++;
	}
}

void    read_file(char *file_name, fdf **data)
{
	int fd;
	char *line;
	int i;

	(*data)->height = get_height(file_name);
	(*data)->width = get_width(file_name);
	(*data)->z_matrix = (t_ili **)malloc(sizeof(t_ili *) * ((*data)->height + 1));
	i = 0;
	while (i <= (*data)->height)
		(*data)->z_matrix[i++] = (t_ili *)malloc(sizeof(t_ili) * ((*data)->width + 1));
	fd = open(file_name, O_RDONLY, 0);
	i = 0;
	while (get_next_line(fd, &line))
	{
		printf("%s\n", line);
		fill_matrix((*data)->z_matrix[i], line);
		free(line);
		i++;
	}
	close(fd);
	(*data)->z_matrix[i] = NULL;
}
