#include "so_long.h"

void	print_error(void)
{
	write(1, "Error\n", 6);
	exit(0);
}

void	ft_free_double(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

t_all	join_all(t_mlx *mlx, t_map *map, t_sprites *sprites)
{
	t_hero	mario;
	t_all	game;

	mario = def_mario(map);
	game.mario = mario;
	game.sprites = *sprites;
	game.mlx = *mlx;
	game.map = *map;
	return (game);
}

int	close_window(t_all *game)
{
	(void)game;
	exit(0);
	return (0);
}
