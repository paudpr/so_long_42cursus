#include "so_long.h"

/*
t_stimages	ft_images(void *mlx_ptr, t_coord *size_map, char **array)
{
	t_stimages	images;
	t_image		image;
	int			iter;

	iter = 0;
	image.path = "./sprites/tile.xpm";
	image.img = mlx_xpm_file_to_image(mlx_ptr, image.path, &image.width,
			&image.height);
	images.tile = image;
	while (iter != 5)
	{
		ft_fill_images(mlx_ptr, &images, iter);
		if (!image.img)
		{
			ft_destroy_img(mlx_ptr, &images, iter);
			ft_error_free(array, size_map, ERRMEM);
		}
		iter++;
	}
	return (images);
}

static void	ft_fill_images(void *mlx_ptr, t_stimages *images, int iter)
{
	t_image		image;

	if (iter == 0)
		image.path = "./sprites/wall.xpm";
	if (iter == 1)
		image.path = "./sprites/hero.xpm";
	if (iter == 2)
		image.path = "./sprites/coin.xpm";
	if (iter == 3)
		image.path = "./sprites/exit.xpm";
	if (iter == 4)
		image.path = "./sprites/enemy.xpm";
	image.img = mlx_xpm_file_to_image(mlx_ptr, image.path,
			&image.width, &image.height);
	if (iter == 0)
		images->wall = image;
	if (iter == 1)
		images->hero = image;
	if (iter == 2)
		images->coin = image;
	if (iter == 3)
		images->exit = image;
	if (iter == 4)
		images->enemy = image;
}



void	ft_fill_window(char **array, t_coord *size_map, t_ptr *ptr,
				t_stimages *images)
{
	int		iter_word;
	int		iter_char;
	t_coord	painted;

	iter_word = 0;
	painted.x = 0;
	painted.y = 0;
	while (iter_word < size_map->y)
	{
		iter_char = 0;
		painted.x = 0;
		while (array[iter_word][iter_char])
		{
			ft_paint(array[iter_word][iter_char], images, ptr, &painted);
			iter_char++;
			painted.x += TILE;
		}
		iter_word++;
		painted.y += TILE;
	}
}

static void	ft_paint(char letter, t_stimages *images,
t_ptr *ptr, t_coord *coord)
{
	if (letter == '0' || letter == 'C' || letter == 'E' || letter == 'P'
		|| letter == 'X')
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
			images->tile.img, coord->x, coord->y);
	if (letter == '1')
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
			images->wall.img, coord->x, coord->y);
	if (letter == 'C')
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
			images->coin.img, coord->x, coord->y);
	if (letter == 'E')
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
			images->exit.img, coord->x, coord->y);
	if (letter == 'P')
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
			images->hero.img, coord->x, coord->y);
	if (letter == 'X')
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
			images->enemy.img, coord->x, coord->y);
}
*/