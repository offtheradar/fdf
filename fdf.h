/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 14:36:22 by ysibous           #+#    #+#             */
/*   Updated: 2018/03/19 19:40:49 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "./includes/libft/libft.h"
# include "./includes/libgfx/libgfx.h"
# include "./includes/minilibx/mlx.h"
# include <fcntl.h>

int					open_file(char *file_name);

void				ft_lst_add_to_end(t_list *new_l, t_list *lst);

t_list				*load_file(t_plot *plt, int fd);

void				convert_lst_to_arr(t_plot *plt, t_list *lst);

void				create_vertices(t_plot *plt, char *filename);
#endif