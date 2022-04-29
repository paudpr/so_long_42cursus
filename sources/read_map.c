#include "so_long.h"

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

void	check_border(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->size_y)
	{
		j = 0;
		while (j < map-> size_x - 1)
		{
			if (i == 0 || i == map->size_y - 1)
			{	
				if (map->coords[i][j] != '1')
					print_error();
			}
			j++;
		}
		if (i > 0 && i < map->size_y - 1)
		{
			if (map->coords[i][0] != '1'
				|| map->coords[i][map->size_x - 2] != '1')
				print_error();
		}
		i++;
	}
}

void	check_chars(t_map *map)
{
	int	i;
	int	j;
	int p;
	int e;

	i = 0;
	p = 0;
	e = 0;
	while (i < map->size_y)
	{
		j = 0;
		while (map->coords[i][j])
		{
			if (map->coords[i][j] == 'P')
				p++;
			if (map->coords[i][j] == 'C')
				map->collect++;
			if (map->coords[i][j] == 'E')
				e++;
			j++;
		}
		i++;
	}
	if (p != 1 || map->collect == 0 || e == 0)
		print_error();
}
