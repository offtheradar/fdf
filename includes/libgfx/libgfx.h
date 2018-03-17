/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libgfx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 15:36:44 by ysibous           #+#    #+#             */
/*   Updated: 2018/03/16 16:25:35 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBGFX_H
# define LIBGFX_H
# include "../libft/libft.h"
# include <math.h>

typedef struct		s_2d_pixel
{
	double				x;
	double				y;
}					t_2d_pixel;

typedef struct		s_3d_pixel
{
	double				x;
	double				y;
	double				z;
}					t_3d_pixel;

typedef struct		s_vertex
{
	t_3d_pixel	*local;
	t_3d_pixel	*world;
	t_3d_pixel	*aligned;
	t_3d_pixel	*projected;
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

t_2d_pixel			*create_2d_pix(double x, double y);

t_3d_pixel			*create_3d_pix(double x, double y, double z);

t_vertex			*create_vertex(double x, double y, double z);

void				zero_matrix(double mat[4][4]);

void				identity_matrix(double mat[4][4]);

void				ft_cp_matrix(double src[4][4], double dst[4][4]);

void				ft_mult_mat_vec(double mat[4][4], t_3d_pixel *src,
									t_3d_pixel *dst);

void				ft_mult_mat_mat(double mat1[4][4], double mat2[4][4],
									double dest[4][4]);

void				rotate_matrix_x(double matrix[4][4], double theta);

void				rotate_matrix_y(double matrix[4][4], double phi);

void				rotate_matrix_z(double matrix[4][4], double psi);

void				translate_matrix(double mat[4][4], double tx, double ty,
										double tz);

void				scale_matrix(double mat_to_scale[4][4], double sx,
									double sy, double sz);

void				rotate_matrix(double matrix[4][4], double theta, double phi,
									double psi);

void				draw_line(int x0, int y0, int x1, int y1, t_info *info);
#endif
