/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libgfx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 15:36:44 by ysibous           #+#    #+#             */
/*   Updated: 2018/03/22 15:54:29 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBGFX_H
# define LIBGFX_H
# define WIN_WIDTH 2000
# define WIN_HEIGHT 1500
# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include <stdlib.h>
# include <fcntl.h>
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

typedef	struct		s_draw
{
	double		delta_x;
	double		delta_y;
	double		delta_z;
	double		step_x;
	double		step_y;
	double		big_delta;
	double		small_delta;
	double		big_step;
	double		small_step;
	double		leading_var_0;
	double		leading_var_1;
	double		follow_var_0;
	double		follow_var_1;
}					t_draw;

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
	void		*mlx_ptr;
	void		*mlx_win;
	void		*img;
	double		focal_distance;
	double		scale;
	double		sx;
	double		sy;
	double		sz;
	double		tx;
	double		ty;
	double		tz;
	int			r;
	int			g;
	int			b;
	int			num_colours;
	int			*colours;
	double		theta;
	double		phi;
	double		psi;
	t_plot		*plot;
}					t_info;

t_2d_pixel			*create_2d_pix(double x, double y);

t_3d_pixel			*create_3d_pix(double x, double y, double z);

t_vertex			*create_vertex(double x, double y, double z);

t_info				*init_info(void);

void				draw_point(t_info *info, int x, int y, double z);

int					*init_colours(t_info *info);

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

void				create_delta_step(t_draw *var, t_3d_pixel *p0,
										t_3d_pixel *p1);

void				draw_line(t_3d_pixel p0, t_3d_pixel ip1, t_info *info);

void				local_to_world(t_info *info);

void				world_to_aligned(t_info *info);

double				get_projection(int focal_dist, double coord, double z_max,
									double z);

void				aligned_to_projected(t_info *info);

t_info				*init_info(void);

void				construct_wf(t_info *info);

void				draw_wf(t_info *info);

int					open_file(char *file_name);

t_list				*load_file(t_plot *plt, int fd);

void				convert_lst_to_arr(t_plot *plt, t_list *lst);

void				create_vertices(t_plot *plt, char *filename);
#endif
