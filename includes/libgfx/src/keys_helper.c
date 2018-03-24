/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 15:57:07 by ysibous           #+#    #+#             */
/*   Updated: 2018/03/23 17:46:42 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libgfx.h"

/*
** Redraw grid.
*/

void	redraw(t_info *info)
{
	mlx_clear_window(info->mlx_ptr, info->mlx_win);
	draw_wf(info);
}

/*
** Change given variable - angle, scale, translation.
*/

void	change_var(int plus, double *to_change, t_info *info)
{
	if (plus)
		*to_change += 0.25;
	else
		*to_change -= 0.25;
	redraw(info);
}
