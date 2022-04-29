#include "so_long.h"

int	check_valid_args(int argc, char **argv)
{
	int		argv_len;
	char	*point;

	if (argc != 2)
		print_error();
	argv_len = ft_strlen(argv[1]);
	point = ft_strrchr(argv[1], '.');
	if (point == NULL)
		print_error();
	if (ft_strncmp(point, ".ber", ft_strlen(point) + 1) != 0)
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

//recorre el array de coordenadas para guardar el valor máximo y mínimo de z
void	get_xy_size(char **argv, t_map *map)
{
	int		fd;
	char	*line;
	int		y;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		print_error();
	line = get_next_line(fd);
	if (line == NULL)
		print_error();
	map->size_x = ft_strlen(line);
	y = 0;
	while (line)
	{
		y++;
		free(line);
		line = get_next_line(fd);
	}
	map->size_y = y;
	free(line);
	close(fd);
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
		if (ft_strlen(line) != (size_t)map->size_x)
			print_error();
		map->coords[i] = ft_strdup(line);
		i++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
}

void	map_main(int argc, char **argv, t_map *map)
{
	int	i;

	if (argv)
		i = 0;
	check_valid_args(argc, argv);
	init_map(map);
	read_map(argv, map);
	check_map(map);
}
