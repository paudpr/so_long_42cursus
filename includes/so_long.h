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
	int size_x;
	int size_y
} t_map;



#endif