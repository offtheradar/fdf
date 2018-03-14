/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 14:38:51 by ysibous           #+#    #+#             */
/*   Updated: 2018/03/13 16:29:23 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int		open_file(char *file_name)
{
	int fd;

	if ((fd = open(file_name, O_RDONLY)) == -1)
	{
		ft_putstr("File Error!");
		exit(0);
	}
	return (fd);
}

int		*load_file(char *file_name)
{
	char	*line;
	int		gnl;
	int		fd;
	t_list	*lst;
	t_info	*info;

	info = (t_info)ft_memalloc(sizeof(t_info));
	info->width = -1;
	info->z_min = MAX_INT;
	info->z_max = MIN_INT;
	lst = NULL;
	fd = open_file(file_name);
	while ((gnl = get_next_line(fd, &line)) == 1)
	{
		if (info->width == -1)
			info->width = ft_count_words(line, ' ');
		if (info->width != ft_count_words(line, ' '))
			ft_putstr("The map is invalid!");
		ft
	}
}
