/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_vertex_init_info.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 15:17:39 by ysibous           #+#    #+#             */
/*   Updated: 2018/03/26 14:16:23 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libgfx.h"

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

	vertex = malloc(sizeof(t_vertex));
	vertex->local = create_3d_pix(x, y, z);
	vertex->world = create_3d_pix(0, 0, 0);
	vertex->aligned = create_3d_pix(0, 0, 0);
	vertex->projected = create_3d_pix(0, 0, 0);
	return (vertex);
}

int			*init_colours(t_info *info)
{
	int		*colours;
	int		i;
	float	f;
	int		rgb[3];

	colours = (int *)ft_memalloc(sizeof(int) * info->num_colours);
	f = 0;
	i = 0;
	while (i < info->num_colours)
	{
		rgb[0] = (cos(f) + info->r) * 127;
		rgb[1] = (sin(f) + info->g) * 127;
		rgb[2] = (-cos(f) + info->b) * 127;
		colours[i] = ((int)rgb[2]) << 16 | ((int)rgb[1]) << 8 | rgb[0];
		f += M_PI / info->num_colours;
		i++;
	}
	return (colours);
}

t_info		*init_info(void)
{
	t_info	*info;

	info = (t_info *)ft_memalloc(sizeof(t_info));
	info->plot = (t_plot *)ft_memalloc(sizeof(t_plot));
	info->plot->height = 0;
	info->plot->width = 0;
	info->plot->z_min = MAX_INT;
	info->plot->z_max = MIN_INT;
	info->mlx_ptr = mlx_init();
	info->mlx_win = mlx_new_window(info->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "FDF");
	info->theta = 0.5;
	info->phi = 0.0;
	info->psi = 0.0;
	info->scale = 0.5;
	info->sx = 1.0;
	info->sy = 1.0;
	info->sz = 1.0;
	info->tx = 0.0;
	info->ty = 0.0;
	info->tz = 0.0;
	info->r = 255;
	info->g = 192;
	info->b = 203;
	info->num_colours = 100;
	info->colours = init_colours(info);
	info->focal_distance = 3.0;
	return (info);
}
