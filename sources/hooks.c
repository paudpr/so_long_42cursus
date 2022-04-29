#include "so_long.h"


//int mlx_key_hook ( void *win_ptr, int (*funct_ptr)(), void *param);

//int mlx_key_hook

// void move_up(t_map *map, t_mlx *mlx)
// {
// 	char next;

// 	printf("%d, %d\n", map->mario.y - 1, map->mario.x);
// 	printf("AQUI MOVE UP\n");
// 	next = map->coords[map->mario.y - 1][map->mario.x];
// 	if(next != '1' && (next != 'E'
// 		|| (next == 'E' && map->collect == map->mario.collect)))
// 	{
// 		if(next == 'C')
// 			map->mario.collect++;
// 		map->coords[map->mario.y][map->mario.x] = '0';
// 		map->coords[map->mario.y - 1][map->mario.x] = 'P';
// 		map->mario.y--;
// 		map->mario.moves++;
// 		if(next == 'E')
// 		{
// 			printf("You win!\n");
// 			// clean_image(mlx, sprites);
// 		}
// 		printf("Moves: %d\n", map->mario.moves);
// 		draw_map(mlx, map);
// 	}
// }

int handle_keypress(int keycode, t_all *game)
{
	if (keycode == 53)
	{
		// ft_free_double(map->coords);

		mlx_destroy_window(game->mlx.mlx, game->mlx.win);
		exit(0);
	}
	// if(keycode == 13 || keycode == 126)
	// 	move_up(map, mlx);
	// if(keycode == 1 || keycode == 125)
	// 	move_down(map);
	// if(keycode == 0 || keycode == 123)
	// 	move_left(map);
	// if(keycode == 2 || keycode == 124)
	// 	move_right(map);
	return(0);
}

int close_window(t_all *game)
{
	(void)game;
	exit(0);
	return(0);
}


void	define_hooks(t_all *game)
{
	mlx_key_hook(game->mlx.win, handle_keypress, game);
	mlx_hook(game->mlx.win, 17, 0, close_window, game);

}

