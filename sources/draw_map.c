#include "so_long.h"

void	draw_map(t_mlx *mlx, t_map *map, t_sprites *sprites)
{
	int		i;
	int		j;
	t_coord	coord;

	i = 0;
	while (i < map->size_y)
	{
		j = 0;
		coord.y = i;
		while (j < map->size_x)
		{
			coord.x = j;
			fill_img(map->coords[i][j], mlx, coord, sprites);
			j++;
		}
		i++;
	}
}

void	fill_img(char code, t_mlx *mlx, t_coord coord, t_sprites *sprites)
{
	if (code == '0' || code == 'C' || code == 'E' || code == 'P'
		|| code == 'X')
		mlx_put_image_to_window(mlx->mlx, mlx->win,
			sprites->floor, coord.x * 32, coord.y * 32);
	if (code == '1')
		mlx_put_image_to_window(mlx->mlx, mlx->win,
			sprites->wall, coord.x * 32, coord.y * 32);
	if (code == 'C')
		mlx_put_image_to_window(mlx->mlx, mlx->win,
			sprites->collect, coord.x * 32, coord.y * 32);
	if (code == 'E')
		mlx_put_image_to_window(mlx->mlx, mlx->win,
			sprites->exit, coord.x * 32, coord.y * 32);
	if (code == 'P')
		mlx_put_image_to_window(mlx->mlx, mlx->win,
			sprites->mario, coord.x * 32, coord.y * 32);
}

t_sprites	get_sprites(t_mlx *mlx)
{
	t_sprites	sprites;
	int			size;

	size = 32;
	sprites.floor = mlx_xpm_file_to_image(mlx->mlx,
			"./sprites/floor.xpm", &size, &size);
	sprites.wall = mlx_xpm_file_to_image(mlx->mlx,
			"./sprites/wall.xpm", &size, &size);
	sprites.collect = mlx_xpm_file_to_image(mlx->mlx,
			"./sprites/collect.xpm", &size, &size);
	sprites.exit = mlx_xpm_file_to_image(mlx->mlx,
			"./sprites/exit.xpm", &size, &size);
	sprites.mario = mlx_xpm_file_to_image(mlx->mlx,
			"./sprites/mario.xpm", &size, &size);
	return (sprites);
}
