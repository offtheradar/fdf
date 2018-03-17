/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_vertex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 13:23:52 by ysibous           #+#    #+#             */
/*   Updated: 2018/03/16 13:36:54 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgfx.h"

t_2d_pixel	*create_2d_pix(double x, double y)
{
	t_2d_pixel	*pix;

	pix = (t_2d_pixel *)malloc(sizeof(t_2d_pixel));
	pix->x = x;
	pix->y = y;
	return (pix);
}

t_3d_pixel	*create_3d_pix(double x, double y, double z)
{
	t_3d_pixel *pix;

	pix = (t_3d_pixel *)malloc(sizeof(t_3d_pixel));
	pix->x = x;
	pix->y = y;
	pix->z = z;
	return (pix);
}

t_vertex	*create_vertex(double x, double y, double z)
{
	t_vertex *vertex;

	vertex = (vertex *)malloc(sizeof(t_vertex));
	vertex->local = create_3d_pix(x, y, z);
	vertex->world = create_3d_pix(0, 0, 0);
	vertex->aligned = create_3d_pix(0, 0, 0);
	vertex->projected = create_3d_pix(0, 0, 0);
	return (out);
	return (pix);
}
