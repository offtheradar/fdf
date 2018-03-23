/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_wire_frame.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 10:12:09 by ysibous           #+#    #+#             */
/*   Updated: 2018/03/22 21:58:05 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libgfx.h"
#include <stdio.h>

void	construct_wf(t_info *info)
{
	int x;
	int y;

	y = -1;
	while (++y < info->plot->height)
	{
		x = -1;
		while (++x < info->plot->width)
		{
			if (x < info->plot->width - 1)
				draw_line(*(info->plot->point_matrix[y][x]->projected),
							*(info->plot->point_matrix[y][x + 1]->projected),
								info);
			if (y < info->plot->height - 1)
				draw_line(*(info->plot->point_matrix[y][x]->projected),
							*(info->plot->point_matrix[y + 1][x]->projected),
								info);
		}
	}
}

int		change_colours(int keycode, t_info *info)
{
	if (keycode == 8)
	{
		info->r = rand() % 3;
		info->g = rand() % 3;
		info->b = rand() % 3;
		info->colours = init_colours(info);
		mlx_clear_window(info->mlx_ptr, info->mlx_win);
		draw_wf(info);
	}
	if (keycode == 6)
	{
		info->sz += 0.25;
		mlx_clear_window(info->mlx_ptr, info->mlx_win);
		draw_wf(info);
	}
	if (keycode == 16)
	{
		info->sy += 0.25;
		mlx_clear_window(info->mlx_ptr, info->mlx_win);
		draw_wf(info);
	}
	if (keycode == 7)
	{
		info->sx += 0.25;
		mlx_clear_window(info->mlx_ptr, info->mlx_win);
		draw_wf(info);
	}
	if (keycode == 0)
	{
		info->sz -= 0.25;
		mlx_clear_window(info->mlx_ptr, info->mlx_win);
		draw_wf(info);
	}
	if (keycode == 4)
	{
		info->sy -= 0.25;
		mlx_clear_window(info->mlx_ptr, info->mlx_win);
		draw_wf(info);
	}
	if (keycode == 1)
	{
		info->sx -= 0.5;
		mlx_clear_window(info->mlx_ptr, info->mlx_win);
		draw_wf(info);
	}
	if (keycode == 2)
	{
		info->tx += 0.25;
		mlx_clear_window(info->mlx_ptr, info->mlx_win);
		draw_wf(info);
	}
	if (keycode == 3)
	{
		info->ty += 0.25;
		mlx_clear_window(info->mlx_ptr, info->mlx_win);
		draw_wf(info);
	}
	if (keycode == 5)
	{
		info->tz += 0.25;
		mlx_clear_window(info->mlx_ptr, info->mlx_win);
		draw_wf(info);
	}
	if (keycode == 8)
	{
		info->tx -= 0.25;
		mlx_clear_window(info->mlx_ptr, info->mlx_win);
		draw_wf(info);
	}
	if (keycode == 9)
	{
		info->ty -= 0.25;
		mlx_clear_window(info->mlx_ptr, info->mlx_win);
		draw_wf(info);
	}
	if (keycode == 11)
	{
		info->tz -= 0.5;
		mlx_clear_window(info->mlx_ptr, info->mlx_win);
		draw_wf(info);
	}
	if (keycode == 124)
	{
		info->theta += 0.5;
		mlx_clear_window(info->mlx_ptr, info->mlx_win);
		draw_wf(info);
	}
	if (keycode == 126)
	{
		info->phi += 0.5;
		mlx_clear_window(info->mlx_ptr, info->mlx_win);
		draw_wf(info);
	}
	if (keycode == 24)
	{
		info->psi += 0.5;
		mlx_clear_window(info->mlx_ptr, info->mlx_win);
		draw_wf(info);
	}
	if (keycode == 123)
	{
		info->theta -= 0.5;
		mlx_clear_window(info->mlx_ptr, info->mlx_win);
		draw_wf(info);
	}
	if (keycode == 125)
	{
		info->phi -= 0.5;
		mlx_clear_window(info->mlx_ptr, info->mlx_win);
		draw_wf(info);
	}
	if (keycode == 27)
	{
		info->psi -= 0.5;
		mlx_clear_window(info->mlx_ptr, info->mlx_win);
		draw_wf(info);
	}
	if (keycode == 53)
		exit(0);

	return (1);
}

void	draw_wf(t_info *info)
{
	local_to_world(info);
	world_to_aligned(info);
	aligned_to_projected(info);
	construct_wf(info);
	mlx_key_hook(info->mlx_win, change_colours, info);
	mlx_loop(info->mlx_ptr);
}
