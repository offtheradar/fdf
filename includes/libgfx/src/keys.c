/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 11:14:08 by ysibous           #+#    #+#             */
/*   Updated: 2018/03/24 20:14:36 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libgfx.h"

int		key_hook(int keycode, t_info *info)
{
	if (keycode == 53)
		exit(0);
	change_colours(keycode, info);
	change_angle(keycode, info);
	change_scale(keycode, info);
	change_translation(keycode, info);
	return (1);
}

void	change_colours(int keycode, t_info *info)
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
}

void	change_angle(int keycode, t_info *info)
{
	if (keycode == 124)
		change_var(1, &info->theta, info);
	if (keycode == 126)
		change_var(1, &info->phi, info);
	if (keycode == 24)
		change_var(1, &info->psi, info);
	if (keycode == 123)
		change_var(0, &info->theta, info);
	if (keycode == 125)
		change_var(0, &info->phi, info);
	if (keycode == 27)
		change_var(0, &info->psi, info);
	if (keycode == 26)
		change_var(0, &info->scale, info);

}

void	change_scale(int keycode, t_info *info)
{
	if (keycode == 6)
		change_var(1, &info->sz, info);
	if (keycode == 16)
		change_var(1, &info->sy, info);
	if (keycode == 7)
		change_var(1, &info->sx, info);
	if (keycode == 0)
		change_var(0, &info->sz, info);
	if (keycode == 4)
		change_var(0, &info->sy, info);
	if (keycode == 1)
		change_var(0, &info->sx, info);
}

void	change_translation(int keycode, t_info *info)
{
	if (keycode == 2)
		change_var(1, &info->tx, info);
	if (keycode == 3)
		change_var(1, &info->ty, info);
	if (keycode == 5)
		change_var(1, &info->tz, info);
	if (keycode == 14)
		change_var(0, &info->tx, info);
	if (keycode == 9)
		change_var(0, &info->ty, info);
	if (keycode == 11)
		change_var(0, &info->tz, info);
}
