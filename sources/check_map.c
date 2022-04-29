#include "so_long.h"

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
	int	p;
	int	e;

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

void	check_map(t_map *map)
{
	check_border(map);
	check_chars(map);
}
