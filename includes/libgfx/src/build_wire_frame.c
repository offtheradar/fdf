/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_wire_frame.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 10:12:09 by ysibous           #+#    #+#             */
/*   Updated: 2018/03/19 12:24:45 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgfx.h"

void	construct_wf(t_info *info)
{
	int x;
	int y;

	y = -1;
	while (++y < info->plot->height - 1)
	{
		x = -1;
		while (++x < info->plot->width - 1)
		{
			if (x < info->plot->width - 1)
				draw_line(info->plot->point_matrix[y][x]->projected,
							info->plot->point_matrix[y][x + 1]->projected,
								info);
			if (y < info->plot->height - 1)
				draw_line(info->plot->point_matrix[y][x]->projected,
							info->plot->point_matrix[y + 1][x]->projected,
								info);
		}
	}
}

void	draw_wf(t_info *info)
{
	local_to_world(info);
	world_to_aligned(info);
	mlx_clear_window(info->mlx_ptr, info->mlx_win);
	construct_wf(info);
}
