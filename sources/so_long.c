#include "so_long.h"

void	so_long(t_mlx *mlx, t_map *map)
{
	t_sprites	sprites;
	t_all		game;

	mlx->mlx = mlx_init();
	if(mlx->mlx == NULL)
		print_error();
	mlx->win = mlx_new_window(mlx->mlx, (map->size_x - 1) * 32, map->size_y * 32, "so_long");
	if(mlx->win == NULL)
	{
		mlx_destroy_image(mlx->mlx, mlx->image);
		ft_free_double(map->coords);
		print_error();
	}
	sprites = get_sprites(mlx);
	draw_map(mlx, map, &sprites);
	game = join_all(mlx, map, &sprites);

	mlx_key_hook(game.mlx.win, handle_keypress, &game);
	mlx_hook(game.mlx.win, 17, 0, close_window, &game);

	printf("AQUI so_long\n");
	mlx_loop(game.mlx.mlx);
}


