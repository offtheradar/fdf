/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_frame_of_reference.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 15:44:21 by ysibous           #+#    #+#             */
/*   Updated: 2018/03/16 16:17:58 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libgfx.h>

/*
** Create global matrix from local coordinates.
*/

void	local_to_world(t_info *info)
{
	double	global[4][4];
	int		x;
	int		y;

	identity_matrix(global);
	rotate_matrix(global, -(info->width / 2), -(info->height / 2), 0);
	scale_matrix(global, info->sx, info->sy, info->sz);
	y = -1;
	while (++y < info->height)
	{
		x = -1;
		while (++x < info->width)
			ft_mut_mat_vec(global, info->points[y][x]->local,
							info->points[y][x]->global);
	}
}

void	world_to_aligned(t_info *info)
{
	double	global[4][4];
	int		x;
	int		y;

	identity_matrix(global);
	rotate_matrix(global, -(info->width / 2), -(info->height / 2), 0);
	scale_matrix(global, info->sx, info->sy, info->sz);
	y = -1;
	while (++y < info->height)
	{
		x = -1;
		while (++x < info->width)
			ft_mut_mat_vec(global, info->points[y][x]->local,
							info-points[y][x]->global);
	}
}
