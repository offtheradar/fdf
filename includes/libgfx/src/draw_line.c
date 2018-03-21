/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 17:44:20 by ysibous           #+#    #+#             */
/*   Updated: 2018/03/21 11:13:58 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libgfx.h>
/*
void	create_delta_step(t_draw *var, t_3d_pixel *p0, t_3d_pixel *p1)
{
	var->delta_x = ((p1->x - p0->x) >= 0) ? p1->x - p0->x : -(p1->x - p0->x);
	var->delta_y = ((p1->y - p0->y) >= 0) ? p1->y - p0->y : -(p1->y - p0->y);
	var->delta_z = p1->z - p0->z;
	var->big_delta = (var->delta_x > var->delta_y) ? var->delta_x :
														var->delta_y;
	var->small_delta = (var->delta_x > var->delta_y) ? var->delta_y :
														var->delta_x;
	var->step_x = ((p1->x - p0->x) >= 0) ? 1.0 : -1.0;
	var->step_y = ((p1->y - p0->y) >= 0) ? 1.0 : -1.0;
	var->big_step = (var->delta_x > var->delta_y) ? var->step_x : var->step_y;
	var->small_step = (var->delta_x > var->delta_y) ? var->step_y : var->step_x;
	var->leading_var_0 = (var->delta_x > var->delta_y) ? p0->x : p0->y;
	var->leading_var_1 = (var->delta_x > var->delta_y) ? p1->x : p1->y;
	var->follow_var_0 = (var->delta_x > var->delta_y) ? p0->y : p0->x;
	var->follow_var_1 = (var->delta_x > var->delta_y) ? p1->y : p1->x;
}

void	draw_line(t_3d_pixel *p0, t_3d_pixel *p1, t_info *info)
{
	t_draw	*var;
	double	error;

	var = malloc(sizeof(t_draw));
	create_delta_step(var, p0, p1);
	if ((p0->x >= 0) && (p0->y >= 0))
		mlx_pixel_put(info->mlx_ptr, info->mlx_win, p0->x, p0->y, 0x000FFF);
	error = 2.0 * var->small_delta - var->big_delta;
	while (var->leading_var_0 != var->leading_var_1)
	{
		var->leading_var_0 += var->big_step;
		if (error >= 0)
		{
			var->follow_var_0 += var->small_step;
			error -= var->big_delta;
		}
		error += var->small_delta;
		mlx_pixel_put(info->mlx_ptr, info->mlx_win, p0->x, p1->x, 0x000FFF);
	}
}
*/
static int	swap_vars(t_3d_pixel *p0, t_3d_pixel *p1)
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

void		draw_line(t_3d_pixel p0, t_3d_pixel p1, t_info *info)
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
		mlx_pixel_put(info->mlx_ptr, info->mlx_win, dir ? p0.y : p0.x, dir ? p0.x : p0.y, 0x000FFF);
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
