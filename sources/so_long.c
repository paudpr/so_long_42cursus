#include "so_long.h"

void	so_long(t_mlx *mlx, t_map *map)
{
	mlx = ft_calloc(1, sizeof(t_mlx));
	if (mlx == NULL)
		print_error();
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, map->size_x, map->size_y, "so_long");
	mlx->image = mlx_new_image(mlx->mlx, map->size_x, map->size_y);
	mlx->data_addr = mlx_get_data_addr(mlx->image, &mlx->bits_per_pixel,
		&mlx->size_line, &mlx->endian);
	draw_map(mlx, map);
}


void	draw_map(t_mlx *mlx, t_map *map)
{
	int		i;
	int		j;
	t_coord	coord;

	i = 0;
	while(i < map->size_x)
	{
		j = 0;
		coord.x = i;
		while(j < map->size_y)
		{
			coord.y = j;
			fill_img(map->coords[i][j], map, mlx, coord);
			j++;
		}
		i++;
	}
}

void	fill_img(char code, t_map *map, t_mlx *mlx, t_coord coord)
{
	t_sprites *sprites;

	sprites = get_sprites(mlx);
	if (code == '0' || code == 'C' || code == 'E' || code == 'P'
		|| code == 'X')
		mlx_put_image_to_window(mlx->mlx, mlx->win, sprites->floor, coord.x, coord.y);
	if (code == '1')		
		mlx_put_image_to_window(mlx->mlx, mlx->win, sprites->wall, coord.x, coord.y);
	if (code == 'C')		
		mlx_put_image_to_window(mlx->mlx, mlx->win, sprites->collect, coord.x, coord.y);
	if (code == 'E')		
		mlx_put_image_to_window(mlx->mlx, mlx->win, sprites->exit, coord.x, coord.y);
	if (code == 'P')		
		mlx_put_image_to_window(mlx->mlx, mlx->win, sprites->mario, coord.x, coord.y);
	// if (code == 'X')		
	// 	mlx_put_image_to_window(mlx->mlx, mlx->win, sprites->mush, coord.x, coord.y);
}

t_sprites	*get_sprites(t_mlx *mlx)
{
	t_sprites	*sprites;
	int			size;

	size = 32;
	sprites->floor = mlx_xpm_file_to_image(mlx->mlx, "./sprites/floor.xpm", &size, &size);
	sprites->wall = mlx_xpm_file_to_image(mlx->mlx, "./sprites/wall.xpm", &size, &size);
	sprites->collect = mlx_xpm_file_to_image(mlx->mlx, "./sprites/collect.xpm", &size, &size);
	sprites->exit = mlx_xpm_file_to_image(mlx->mlx, "./sprites/exit.xpm", &size, &size);
	sprites->mario = mlx_xpm_file_to_image(mlx->mlx, "./sprites/mario.xpm", &size, &size);
	// sprites->mush = mlx_xpm_file_to_image(mlx->mlx, "./sprites/mush.xpm", &size, &size);
	return(sprites);
}