#include "so_long.h"

//recorre el array de coordenadas para guardar el valor máximo y mínimo de z
void	get_xy_size(char **argv, t_map *map)
{
	int		fd;
	char	*line;
	int		y;
	char	**split;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		print_error();
	line = get_next_line(fd);
	if (line == NULL)
		print_error();
	split = ft_split(line, ' ');
	map->size_x = split_len(split);
	y = 0;
	while (line)
	{
		y++;
		free(line);
		line = get_next_line(fd);
	}
	map->size_y = y;
	free(line);
	ft_free_double(split);
	close(fd);
}

void	save_coords(char *line, int i, t_map *map)
{
	int			j;
	int			c;

	i = 0;
	c = 0;
	while (line[c] && line[c] != '\n')
	{
		map->coords[i][j] = line[c];
		j++;
		c++;
	}
	map->coords[i][j] = 0;
}

void	check_border(t_map *map)
{
	int i;
	int j;

	i = 0;
	while(i < map->size_y)
	{
		j = 0;
		while(j < map-> size_x)
		{
			if(i == 0 || i == map->size_y - 1)
			{
				if(map->coords[i][j] != '1')
					print_error();
			}
			j++;
		}
		if(i > 0 && i < map->size_y - 1)
		{
			if(map->coords[i][0] != '1' || map->coords[i][map->size_x - 1] != '1')
				print_error();
		}
		i++;
	}
}

void	check_chars(t_map *map)
{
	int i;
	int j;
	int p;
	int c;
	int e;

	i = 0;
	p = 0;
	c = 0;
	e = 0;
	while(i < map->size_y)
	{
		j = 0;
		while(map->coords[i][j])
		{
			if(map->coords[i][j] == 'P')
				p++;
			if(map->coords[i][j] == 'C')
				c++;
			if(map->coords[i][j] == 'e')
				e++;
			j++;
		}
		i++;
	}
	if(p != 1 || c == 0 || e == 0)
		print_error();
}