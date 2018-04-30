/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <ysibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 19:41:03 by ysibous           #+#    #+#             */
/*   Updated: 2018/04/29 20:29:32 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	t_info	*info;

	if (argc != 2)
	{
		ft_putstr("Usage: ./fdf file-name");
		return (1);
	}
	info = init_info();
	create_vertices(info->plot, argv[1]);
	draw_wf(info);
	while (1){};
	return (0);
}
