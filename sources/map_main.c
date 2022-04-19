#include "so_long.h"

int	check_valid_args(int argc)
{
	if (argc != 2)
		print_error();
	return (0);
}

void	init_map(t_map *map)
{
	map->size_x = 0;
	map->size_y = 0;
	map->collect = 0;
	map->coords = NULL;
}

void	read_map(char **argv, t_map *map)
{
	int			fd;
	char		*line;
	int			i;

	get_xy_size(argv, map);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		print_error();
	line = get_next_line(fd);
	map->coords = malloc(sizeof(char *) * map->size_y + 1);
	if (map->coords == NULL)
		print_error();
	i = 0;
	while (line)
	{
		save_coords(line, i, map);
		i++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
}

void	check_map(t_map *map)
{
	check_border(map);
	check_chars(map);
}

void	map_main(int argc, char **argv, t_map *map)
{
	int	i;

	if (argv)
		i = 0;
	check_valid_args(argc);
	init_map(map);
	read_map(argv, map);
	check_map(map);
}

/*
get xy size
save coords en array
check map -> tengo todos los bordes cerrados
check map -> tengo todos los caracteres necesarios
		(p = 1)(c >0)(e >0)
		
poner tiles en imagen -> tipo de dato
crear imagen
llenar imagen
*/
