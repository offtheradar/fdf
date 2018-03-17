/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 14:36:22 by ysibous           #+#    #+#             */
/*   Updated: 2018/03/14 20:02:37 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FDF_H
# define FDF_H
# include "libft/libft.h"
# include "libgfx/libgfx.h"

int					open_file(char *file_name);

int					*load_file(char *file_name);
#endif
