/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 19:41:03 by ysibous           #+#    #+#             */
/*   Updated: 2018/03/19 19:41:18 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int		main(int argc, char **argv)
{
	t_info	*info;

	if (argc != 2)
		return (0);
	info = init_info();
	create_vertices(info->plot, argv[1]);
/*	draw_wf(info);*/
	return (0);
}
