/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 14:36:22 by ysibous           #+#    #+#             */
/*   Updated: 2018/03/20 16:04:17 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "./includes/libft/libft.h"
# include "./includes/libgfx/libgfx.h"
# include "./includes/minilibx/mlx.h"
# include <fcntl.h>

int					open_file(char *file_name);

t_list				*load_file(t_plot *plt, int fd);

void				convert_lst_to_arr(t_plot *plt, t_list *lst);

void				create_vertices(t_plot *plt, char *filename);
#endif
