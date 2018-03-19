/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 17:44:20 by ysibous           #+#    #+#             */
/*   Updated: 2018/03/19 10:06:43 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libgfx.h>

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
