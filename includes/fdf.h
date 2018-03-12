/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 14:36:22 by ysibous           #+#    #+#             */
/*   Updated: 2018/03/12 15:30:56 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FDF_H
# define FDF_H
# include "libft/libft.h"

typedef struct		s_display_info
{
	void	*mlx_ptr;
	void	*mlx_win;
	void	*img;
	int		width;
	int		height;
	int		min_x;
	int		max_x;
	int		min_y;
	int		max_y;
	int		min_z;
	int		max_z;
}					t_display_info;

typedef struct		s_3d_pixel
{
	double				x;
	double				y;
	double				z;
	struct s_3d_pixel	*next;
}					t_3d_pixel;

void	draw_line(int x0, int y0, int x1, int y1, t_display_info *info);

#endif
