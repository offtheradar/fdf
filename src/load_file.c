/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 14:38:51 by ysibous           #+#    #+#             */
/*   Updated: 2018/03/12 16:38:09 by ysibous          ###   ########.fr       */
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
	char	**split_line;
	int		x;
	int		y;
	int		fd;

	fd = open_file(file_name);
	y = 0;
	while (get_next_line(fd, line) == 1)
	{
		split_line = ft_strsplit(*line, ' ');
		x = 0;
		while (*split_line)
		{
			ft_strmap(*split_line, ft_atoi);
			split_line++;
		}
	}
}
