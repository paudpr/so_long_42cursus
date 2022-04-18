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
	char	*data_addr;
	int		bits_per_pixel;
	int		endian;
	int		size_line;
	int		counter;
} t_mlx;

typedef struct s_map
{
	int		size_x;
	int		size_y;
	int		collect;
	char	**coords;
} t_map;


/* map_main.c */
void	map_main(int argc, char **argv, t_map *map);
void	read_map(char **argv, t_map *map);
void	init_map(t_map *map);
int		check_valid_args(int argc);

/* read_map.c */
void	get_xy_size(char **argv, t_map *map);
size_t	split_len(char **split);


#endif