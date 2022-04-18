#include "so_long.h"

void so_long(t_mlx *mlx, t_map *map)
{
	mlx = ft_calloc(1, sizeof(t_mlx));
	if (mlx == NULL)
		print_error();
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, map->size_x, map->size_y, "so_long");
	mlx->image = mlx_new_image(mlx->mlx, map->size_x, map->size_y);
	mlx->data_addr = mlx_get_data_addr(mlx->image, &mlx->bits_per_pixel,
		&mlx->size_line, &mlx->endian);






}
