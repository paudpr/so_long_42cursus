/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-pin <pdel-pin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 19:01:59 by pdel-pin          #+#    #+#             */
/*   Updated: 2022/05/03 19:02:00 by pdel-pin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//int mlx_key_hook ( void *win_ptr, int (*funct_ptr)(), void *param);

//int mlx_key_hook

void	move_up(t_all *game)
{
	char	next;

	next = game->map.coords[game->mario.y - 1][game->mario.x];
	if (next != '1' && (next != 'E'
			|| (next == 'E' && game->map.collect == game->mario.collect)))
	{
		if (next == 'C')
			game->mario.collect++;
		game->map.coords[game->mario.y][game->mario.x] = '0';
		game->map.coords[game->mario.y - 1][game->mario.x] = 'P';
		game->mario.y--;
		game->mario.moves++;
		if (next == 'E')
		{
			printf("You win!\n");
			mlx_destroy_window(game->mlx.mlx, game->mlx.win);
			exit(0);
		}
		printf("Moves: %d\n", game->mario.moves);
		draw_map(&game->mlx, &game->map, &game->sprites);
	}
}

void	move_down(t_all *game)
{
	char	next;

	next = game->map.coords[game->mario.y + 1][game->mario.x];
	if (next != '1' && (next != 'E'
			|| (next == 'E' && game->map.collect == game->mario.collect)))
	{
		if (next == 'C')
			game->mario.collect++;
		game->map.coords[game->mario.y][game->mario.x] = '0';
		game->map.coords[game->mario.y + 1][game->mario.x] = 'P';
		game->mario.y++;
		game->mario.moves++;
		if (next == 'E')
		{
			printf("You win!\n");
			mlx_destroy_window(game->mlx.mlx, game->mlx.win);
			exit(0);
		}
		printf("Moves: %d\n", game->mario.moves);
		draw_map(&game->mlx, &game->map, &game->sprites);
	}
}

void	move_left(t_all *game)
{
	char	next;

	next = game->map.coords[game->mario.y][game->mario.x - 1];
	if (next != '1' && (next != 'E'
			|| (next == 'E' && game->map.collect == game->mario.collect)))
	{
		if (next == 'C')
			game->mario.collect++;
		game->map.coords[game->mario.y][game->mario.x] = '0';
		game->map.coords[game->mario.y][game->mario.x - 1] = 'P';
		game->mario.x--;
		game->mario.moves++;
		if (next == 'E')
		{
			printf("You win!\n");
			mlx_destroy_window(game->mlx.mlx, game->mlx.win);
			exit(0);
		}
		printf("Moves: %d\n", game->mario.moves);
		draw_map(&game->mlx, &game->map, &game->sprites);
	}
}

void	move_right(t_all *game)
{
	char	next;

	next = game->map.coords[game->mario.y][game->mario.x + 1];
	if (next != '1' && (next != 'E'
			|| (next == 'E' && game->map.collect == game->mario.collect)))
	{
		if (next == 'C')
			game->mario.collect++;
		game->map.coords[game->mario.y][game->mario.x] = '0';
		game->map.coords[game->mario.y][game->mario.x + 1] = 'P';
		game->mario.x++;
		game->mario.moves++;
		if (next == 'E')
		{
			printf("You win!\n");
			mlx_destroy_window(game->mlx.mlx, game->mlx.win);
			exit(0);
		}
		printf("Moves: %d\n", game->mario.moves);
		draw_map(&game->mlx, &game->map, &game->sprites);
	}
}

int	handle_keypress(int keycode, t_all *game)
{
	if (keycode == 53)
	{
		mlx_destroy_window(game->mlx.mlx, game->mlx.win);
		exit(0);
	}
	if (keycode == 13 || keycode == 126)
		move_up(game);
	if (keycode == 1 || keycode == 125)
		move_down(game);
	if (keycode == 0 || keycode == 123)
		move_left(game);
	if (keycode == 2 || keycode == 124)
		move_right(game);
	return (0);
}
