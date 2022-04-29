#ifndef SO_LONG_H
#define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>
# include "../libft/libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <math.h>


typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*image;
}	t_mlx;

typedef struct s_hero
{
	int	x;
	int	y;
	int	collect;
	int	moves;
}	t_hero;

typedef struct s_map
{
	int		size_x;
	int		size_y;
	int		collect;
	char	**coords;
	t_hero	mario;
}	t_map;

typedef struct s_coord
{
	int x;
	int y;
}	t_coord;

typedef struct s_sprites
{
	void *floor;
	void *wall;
	void *collect;
	void *exit;
	void *mario;
}	t_sprites;

typedef struct s_all
{
	t_map map;
	t_mlx mlx;
	t_hero	mario;
	t_sprites	sprites;
}	t_all;

/* map_main.c */
void	map_main(int argc, char **argv, t_map *map);
void	read_map(char **argv, t_map *map);
void	init_map(t_map *map);
int		check_valid_args(int argc);

/* read_map.c */
void	get_xy_size(char **argv, t_map *map);
size_t	split_len(char **split);
void	save_coords(char *line, int i, t_map *map);
void	check_border(t_map *map);
void	check_chars(t_map *map);

/* fill_img.c */
void		draw_map(t_mlx *mlx, t_map *map, t_sprites *sprites);
void		fill_img(char code, t_mlx *mlx, t_coord coord, t_sprites *sprites);
t_sprites	get_sprites(t_mlx *mlx);

/* so_long.c */
void	so_long(t_mlx *mlx, t_map *map);

/* utils.c */
void	ft_free_double(char **tab);
void	print_error(void);
void clean_image(t_mlx *mlx, t_sprites *sprites);
t_all join_all(t_mlx *mlx, t_map *map, t_sprites *sprites);

/* def_mario.c */
t_hero def_mario(t_map *map);

/* hooks.c */
int handle_keypress(int keycode, t_all *game);
int close_window(t_all *game);

#endif