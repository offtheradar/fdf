/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <ysibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 17:44:20 by ysibous           #+#    #+#             */
/*   Updated: 2018/05/06 16:56:32 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libgfx.h"

static int		swap_vars(t_3d_pixel *p0, t_3d_pixel *p1)
{
	float temp;

	if (fabs(p1->x - p0->x) > fabs(p1->y - p0->y))
		return (0);
	temp = p0->y;
	p0->y = p0->x;
	p0->x = temp;
	temp = p1->y;
	p1->y = p1->x;
	p1->x = temp;
	return (1);
}

void			draw_point(t_info *info, int x, int y, double z)
{
	int	colour_index;

	if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
	{
		colour_index = abs((int)(((z - info->plot->z_min) /
						(info->plot->z_max - info->plot->z_min))
						* (info->num_colours)) - 1);
		mlx_pixel_put(info->mlx_ptr, info->mlx_win, x, y,
							info->colours[12]);
	}
}

void			draw_line(t_3d_pixel p0, t_3d_pixel p1, t_info *info)
{
	float	delta[3];
	float	error;
	float	slope;
	int		dir;

	dir = swap_vars(&p0, &p1);
	delta[0] = p1.x - p0.x;
	delta[1] = p1.y - p0.y;
	delta[2] = p1.z - p0.z;
	slope = fabs(delta[1] / delta[0]);
	error = -1.0;
	while ((int)p0.x != (int)p1.x)
	{
		draw_point(info, dir ? p0.y : p0.x, dir ? p0.x : p0.y, p0.z);
		error += slope;
		if (error >= 0.0)
		{
			p0.y += (p0.y > p1.y) ? -1.0 : 1.0;
			error -= 1.0;
		}
		p0.z += delta[2] / fabs(delta[0]);
		p0.x += (p0.x > p1.x) ? -1.0 : 1.0;
	}
}

