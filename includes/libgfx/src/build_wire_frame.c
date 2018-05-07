/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_wire_frame.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 10:12:09 by ysibous           #+#    #+#             */
/*   Updated: 2018/05/05 17:00:11 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libgfx.h"
#include <stdio.h>

/*
** Draws a line between each point that shares an x coordinate, and each point
** that share a y coordinate.
*/

void	construct_wf(t_info *info)
{
	int x;
	int y;

	y = -1;
	while (++y < info->plot->height)
	{
		x = -1;
		while (++x < info->plot->width)
		{
			if (x < info->plot->width - 1 && x < WIN_WIDTH && x + 1 < WIN_WIDTH
					&& y >= 0 && y < WIN_HEIGHT)
				draw_line(*(info->plot->point_matrix[y][x]->projected),
							*(info->plot->point_matrix[y][x + 1]->projected),
								info);
			if (y < info->plot->height - 1 && y < WIN_HEIGHT && y + 1 < WIN_HEIGHT
					&& x >= 0 && x < WIN_WIDTH)
				draw_line(*(info->plot->point_matrix[y][x]->projected),
							*(info->plot->point_matrix[y + 1][x]->projected),
								info);
		}
	}
}

/*
** Function applies change of refrence frame matrix to input data, construct_wf
** the wireframe and waits for keys to be pressed, and proceeds to make the
** necessary changes - colour change, translation, rotation or scaling
*/

void	draw_wf(t_info *info)
{
	local_to_world(info);
	world_to_aligned(info);
	aligned_to_projected(info);
	construct_wf(info);
	mlx_key_hook(info->mlx_win, key_hook, info);
	mlx_loop(info->mlx_ptr);
}
