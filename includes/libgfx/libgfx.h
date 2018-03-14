/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libgfx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 15:36:44 by ysibous           #+#    #+#             */
/*   Updated: 2018/03/13 16:37:19 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBGFX_H
# define LIBGFX_H

typedef struct		s_info
{
	void	*mlx_ptr;
	void	*mlx_win;
	void	*img;
	int		width;
	int		height;
	int		min_z;
	int		max_z;
}					t_info;

typedef	struct		s_plot
{
	t_vertex	***point_matrix;
	int			width;
	int			height;
	float		z_min;
	float		z_max;
}					t_plot;

typedef struct		s_vertex
{
	t_3d_pixel	*local;
	t_3d_pixel	*world;
	t_3d_pixel	*aligned;
}					t_vertex;

typedef struct		s_2d_pixel
{
	float				x;
	float				y;
}					t_2d_pixel;


typedef struct		s_3d_pixel
{
	float				x;
	float				y;
	float				z;
}					t_3d_pixel;



void	draw_line(int x0, int 	y0, int x1, int y1, t_info *info);
#endif
