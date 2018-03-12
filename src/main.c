#include "minilibx/mlx.h"
#include <unistd.h>
#include <stdlib.h>
#include <math.h>

typedef struct	s_pixel
{
	int x;
	int y;
	int z;
}				t_pixel;

typedef struct	s_mouse_info
{
	void *mlx_ptr;
	void *mlx_win;
}				t_mouse_info;

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		mouse_hook(int button, int x, int y, t_mouse_info *info)
{
	mlx_pixel_put(info->mlx_ptr, info->mlx_win, x, y, 0x000FFF);
	return (0);
}

void	draw_line(int x0, int y0, int x1, int y1, t_mouse_info *info)
{
	int	delta_x;
	int	delta_y;
	int	error;
	int	step_x;
	int	step_y;

	delta_x = ((x1 - x0) >= 0) ? x1 - x0 : -(x1 - x0);
	delta_y = ((y1 - y0) >= 0) ? y1 - y0 : -(y1 - y0);
	step_x = ((x1 - x0) >= 0) ? 1 : -1;
	step_y = ((y1 - y0) >= 0 ? 1 : -1);
	if ((x0 >= 0) && (y0 >= 0))
		mlx_pixel_put(info->mlx_ptr, info->mlx_win, x0, y0, 0x000FFF);
	if (delta_x > delta_y)
	{
		error = 2 * delta_y - delta_x;
		while (x0 != x1)
		{
			x0 += step_x;
			if (error >= 0)
			{
				y0 += step_y;
				error -= delta_x;
			}
			error += delta_y;
			mlx_pixel_put(info->mlx_ptr, info->mlx_win, x0, y0, 0x000FFF);
		}
	}
	else
	{
		error = 2 * delta_x - delta_y;
		while (y0 != y1)
		{
			if (error >= 0)
			{
				x0 += step_x;
				error -= delta_y;
			}
			y0 += step_y;
			error += delta_x;
			mlx_pixel_put(info->mlx_ptr, info->mlx_win, x0, y0, 0x000FFF);
		}
	}
}

int		main()
{
	t_mouse_info	*info;

	info = malloc(sizeof(t_mouse_info));
	info->mlx_ptr = mlx_init();
	info->mlx_win = mlx_new_window(info->mlx_ptr, 500, 500, "hello");
	mlx_mouse_hook(info->mlx_win, mouse_hook, info);
	draw_line(0, 0, 250, 250, info);
	mlx_loop(info->mlx_ptr);
}
