/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 17:44:20 by ysibous           #+#    #+#             */
/*   Updated: 2018/03/15 22:03:51 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libgfx.h>

void	compute_delta_step(double delta_x, double delta_y, double step_x,
							double step_y, 
void	draw_line(int x0, int y0, int x1, int y1, t_info *info)
{
	double	delta_x;
	double	delta_y;
	double	error;
	double	step_x;
	double	step_y;

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
