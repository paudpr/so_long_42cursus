/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-pin <pdel-pin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 19:01:36 by pdel-pin          #+#    #+#             */
/*   Updated: 2022/05/03 19:01:38 by pdel-pin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	check_leaks(void)
// {
// 	write(1, "\n", 1);
// 	system("leaks -q so_long");
// }

int	main(int argc, char **argv)
{
	t_mlx	mlx;
	t_map	map;

	map_main(argc, argv, &map);
	so_long(&mlx, &map);
	ft_free_double(map.coords);
	return (0);
}
