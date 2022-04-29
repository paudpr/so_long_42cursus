#include "so_long.h"

t_hero def_mario(t_map *map)
{
	int i;
	int j;
	t_hero	mario;

	i = 0;
	while(i < map->size_y)
	{
		j = 0;
		while(map->coords[i][j])
		{
			if(map->coords[i][j] == 'P')
			{
				mario.x = j;
				mario.y = i;
			}
			j++;
		}
		i++;
	}
	mario.collect = 0;
	mario.moves = 0;
	return(mario);
}