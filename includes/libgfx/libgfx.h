/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libgfx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 15:36:44 by ysibous           #+#    #+#             */
/*   Updated: 2018/03/15 20:44:12 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBGFX_H
# define LIBGFX_H
# include "../libft/libft.h"
# include <math.h>

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

typedef struct		s_vertex
{
	t_3d_pixel	*local;
	t_3d_pixel	*world;
	t_3d_pixel	*aligned;
}					t_vertex;

typedef	struct		s_plot
{
	t_vertex	***point_matrix;
	int			width;
	int			height;
	int			z_min;
	int			z_max;
}					t_plot;

typedef struct		s_info
{
	void	*mlx_ptr;
	void	*mlx_win;
	void	*img;
	int		width;
	int		height;
	int		min_z;
	int		max_z;
	t_plot	*plot;
}					t_info;

void				zero_matrix(double **mat);

void				identity_matrix(double **mat);

void				ft_cp_matrix(float src[4][4], float dst[4][4]);

void				ft_mult_mat_vec(float mat[4][4], t_3d_pixel *src,
									t_3d_pixel *dst);

void				ft_mult_mat_mat(float mat1[4][4], float mat2[4][4],
									float dest[4][4]);

void				draw_line(int x0, int y0, int x1, int y1, t_info *info);
#endif
