/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   def_mario.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-pin <pdel-pin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 19:01:51 by pdel-pin          #+#    #+#             */
/*   Updated: 2022/05/03 19:01:52 by pdel-pin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_hero	def_mario(t_map *map)
{
	int		i;
	int		j;
	t_hero	mario;

	i = 0;
	while (i < map->size_y)
	{
		j = 0;
		while (map->coords[i][j])
		{
			if (map->coords[i][j] == 'P')
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
	return (mario);
}
