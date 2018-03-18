/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_frame_of_reference.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 15:44:21 by ysibous           #+#    #+#             */
/*   Updated: 2018/03/18 14:58:47 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libgfx.h"

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
	y = -1;
	while (++y < info->plot->height)
	{
		x = -1;
		while (++x < info->plot->width)
			ft_mult_mat_vec(global, info->plot->point_matrix[y][x]->local,
							info->plot->point_matrix[y][x]->world);
	}
}

/*
** Create aligned matrix from world coordinates.
*/

void	world_to_aligned(t_info *info)
{
	double	global[4][4];
	int		i[2];

	identity_matrix(global);
	rotate_matrix(global, info->theta, info->phi, info->psi);
	scale_matrix(global, (info->scale * WIN_WIDTH) / info->plot->width,
				(info->scale * WIN_HEIGHT) / info->plot->height, info->scale);
	if (info->is_proj)
		translate_matrix(global, info->sx, info->sy, info->sz);
	else
		translate_matrix(global, info->sx + WIN_WIDTH / 2,
				info->sy + WIN_HEIGHT / 2, info->sz);
	i[0] = -1;
	while (++i[0] < info->plot->height)
	{
		i[1] = -1;
		while (++i[1] < info->plot->width)
		{
			ft_mult_mat_vec(global, info->plot->point_matrix[i[0]][i[1]]->world,
							info->plot->point_matrix[i[0]][i[1]]->aligned);
			info->plot->point_matrix[i[0]][i[1]]->aligned->z = info->is_proj ?
				info->plot->point_matrix[i[0]][i[1]]->aligned->z :
				info->plot->point_matrix[i[0]][i[1]]->local->z;
		}
	}
}

/*
** Project world coordinates to 2D, save in projected matrix.
*/

double	get_projection(int focal_dist, double coord, double z_max, double z)
{
	return ((focal_dist * coord) / (z_max - z) + WIN_WIDTH / 2);
}

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
			info->plot->point_matrix[y][x]->projected->x = get_projection(
				info->focal_distance,
				info->plot->point_matrix[y][x]->projected->x, info->plot->z_max,
				info->plot->point_matrix[y][x]->aligned->z);
			info->plot->point_matrix[y][x]->projected->y = get_projection(
				info->focal_distance,
				info->plot->point_matrix[y][x]->projected->y, info->plot->z_max,
				info->plot->point_matrix[y][x]->aligned->z);
			info->plot->point_matrix[y][x]->projected->z =
				info->plot->point_matrix[y][x]->local->z;
		}
	}
}
