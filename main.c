#include "minilibx/mlx.h"
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		deal_key(int key, void *param)
{
	ft_putchar('X');
	mlx_pixel_put(mlx_ptr, win_ptr, )
	return (0);
}

int		main()
{
	void	*mlx_ptr;
	void	*mlx_win;

	mlx_ptr = mlx_init();
	mlx_win = mlx_new_window(mlx_ptr, 500, 500, "hello");
	mlx_pixel_put(mlx_ptr, mlx_win, 250, 250, 0xFFFFFF);
	mlx_mouse_hook(mlx_win, deal_key, (void *)0);
	mlx_loop(mlx_ptr);
}
