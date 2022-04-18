#include "so_long.h"

void	check_leaks(void)
{
	write(1, "\n", 1);
	system("leaks -q so_long");
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;
	t_map	map;

	atexit(check_leaks);
	map_main(argc, argv, &map);
	so_long(&mlx, &map);
	free(map.coords);
	return (0);
}
