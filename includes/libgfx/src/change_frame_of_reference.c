/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_frame_of_reference.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 15:44:21 by ysibous           #+#    #+#             */
/*   Updated: 2018/03/23 16:14:02 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libgfx.h"
#include <stdio.h>

/*
** Create global matrix from local coordinates.
*/

void	local_to_world(t_info *info)
{
	double	global[4][4];
	int		x;
	int		y;

	identity_matrix(global);
	translate_matrix(global, -((info->plot)->width / 2),
							-((info->plot)->height / 2), 0);
	scale_matrix(global, info->sx, info->sy, info->sz);
	y = 0;
	while (y < info->plot->height)
	{
		x = 0;
		while (x < info->plot->width)
		{
			ft_mult_mat_vec(global, info->plot->point_matrix[y][x]->local,
							info->plot->point_matrix[y][x]->world);
			x++;
		}
		y++;
	}
}

/*
** Create aligned matrix from world coordinates.
*/

void	world_to_aligned(t_info *info)
{
	double	global[4][4];
	int		x;
	int		y;

	identity_matrix(global);
	rotate_matrix(global, info->theta, info->phi, info->psi);
	scale_matrix(global, (info->scale * WIN_WIDTH) / info->plot->width,
				(info->scale * WIN_HEIGHT) / info->plot->height, info->scale);
	translate_matrix(global, info->tx, info->ty, info->tz);
	y = -1;
	while (++y < info->plot->height)
	{
		x = -1;
		while (++x < info->plot->width)
		{
			ft_mult_mat_vec(global, info->plot->point_matrix[y][x]->world,
							info->plot->point_matrix[y][x]->aligned);
		}
	}
}

/*
** Project world coordinates to 2D, save in projected matrix.
*/

void	aligned_to_projected(t_info *info)
{
	double	global[4][4];
	int		x;
	int		y;

	identity_matrix(global);
	y = -1;
	while (++y < info->plot->height)
	{
		x = -1;
		while (++x < info->plot->width)
		{
			if (info->plot->point_matrix[y][x]->aligned->z == 0)
				info->plot->point_matrix[y][x]->aligned->z = 0.001;
			info->plot->point_matrix[y][x]->projected->x =
				info->focal_distance *
				info->plot->point_matrix[y][x]->aligned->x
				/ (info->plot->z_max -
				info->plot->point_matrix[y][x]->aligned->z) + WIN_WIDTH / 2;
			info->plot->point_matrix[y][x]->projected->y = info->focal_distance
			* info->plot->point_matrix[y][x]->aligned->y / (info->plot->z_max -
				info->plot->point_matrix[y][x]->aligned->z) + WIN_HEIGHT / 2;
			info->plot->point_matrix[y][x]->projected->z =
				info->plot->point_matrix[y][x]->local->z;
		}
	}
}
