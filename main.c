
#include "fdf.h"

int deal_key(int key, fdf *data)
{
	printf("%d\n", key);
	if (key == 53)
		exit(0);
	if (key == 126)
		data->shift_y -= 10;
	if (key == 125)
		data->shift_y += 10;
	if (key == 123)
		data->shift_x -= 10;
	if (key == 124)
		data->shift_x += 10;
	if (key == 7)
		data->tettax += 0.1;
	if (key == 8)
		data->tettay += 0.1;
	if (key == 9)
		data->tettaz += 0.1;
	if (key == 13)
		data->zoomz *= 1.2;
	if (key == 1)
		data->zoomz /= 1.2;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw(data);
	return (0);
}

void    printfmap(fdf *data)
{
	int i;
	int j;

	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			printf("%d ", data->z_matrix[i][j].color);
			j++;
		}
		printf("\n");
		i++;
	}
}

int main(int argc, char **argv)
{
	fdf *data;

	data = (fdf*)malloc(sizeof(fdf));
	read_file(argv[1], &data);
	printfmap(data);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "FDF");
	data->zoom = 20;
	data->shift_x = 0;
	data->shift_y = 0;
	data->tettax = 0;
	data->tettay = 0;
	data->tettaz = 0;
	data->zoomz = 10;
	draw(data);
	mlx_hook(data->win_ptr, 2, 0, deal_key, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
