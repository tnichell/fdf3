
#include "fdf.h"
#include "stdio.h"

int deal_key(int key, void *data)
{
	printf("%d", key);
	return (0);
}

int main(int argc, char **argv)
{
	fdf *data;

	data = (fdf*)malloc(sizeof(fdf));
	read_file(argv[1], data);

	int i;
	int j;

	i = 0;
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "FDF");
	bresenham(10, 10, 600, 300, data);
	mlx_key_hook(data->win_ptr, deal_key, NULL);
	mlx_loop(data->mlx_ptr);

}