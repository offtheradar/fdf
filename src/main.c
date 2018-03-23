/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 19:41:03 by ysibous           #+#    #+#             */
/*   Updated: 2018/03/22 16:30:31 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#include <stdio.h>


int		main(int argc, char **argv)
{
	t_info	*info;

	int x = -1;
	int y = -1;
	if (argc != 2)
		return (0);
	info = init_info();
	info->plot = (t_plot *)ft_memalloc(sizeof(t_plot));
	create_vertices(info->plot, argv[1]);
	draw_wf(info);
	return (0);
}
