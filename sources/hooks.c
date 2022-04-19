#include "so_long.h"


//int mlx_key_hook ( void *win_ptr, int (*funct_ptr)(), void *param);

//int mlx_key_hook



int handle_keypress(int keycode, t_mlx *mlx)
{
	// int i;

	if (keycode == 53)
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
		exit(0);
	}
	return(0);
}

int close_window(t_mlx *vars)
{
	(void)vars;
	exit(0);
	return(0);
}

// #define MOUSE_CLICK 1



// int mouse_release(int elem, int pepe, int manolo, t_mlx *mlx)
// {
// 	int i;

// 	(void)pepe;
// 	(void)manolo;
// 	if (elem != MOUSE_CLICK)
// 	{
// 		i = WIDTH_SIZE/2 - 10;
// 		while(i < WIDTH_SIZE/2 + 10)
// 		{
// 			mlx_pixel_put(mlx->mlx, mlx->win, i, HEIGHT_SIZE/2 - 10, 0xFFFF);
// 			i++;
// 		}
// 	}
// 	return(0);
// }

void	define_hooks(t_mlx *mlx)
{
	mlx_hook(mlx->win, 2, 0, &handle_keypress, mlx);
	mlx_hook(mlx->win, 17, 0, close_window, &mlx);
	// mlx_hook(mlx->win, 4, 0, mouse_press, mlx);
	// mlx_hook(mlx->win, 5, 0, mouse_release, mlx);
	//otro hook para los movimientos de raton -> buttonpress & buttonrelease & mousemove?
	//otro hook para 
}

