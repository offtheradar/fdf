/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 23:51:12 by ysibous           #+#    #+#             */
/*   Updated: 2018/03/26 12:34:37 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libgfx/libgfx.h"

/*
**Safely open the file
*/

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

/*
** Loads the file to a list of strings, and then converts the string
** to an array of int's.
*/

t_list	*load_file(t_plot *plt, int fd)
{
	char	*buff;
	int		result;
	t_list	*list;

	list = NULL;
	plt->width = -1;
	plt->height = 0;
	plt->z_min = MAX_INT;
	plt->z_max = MIN_INT;
	while ((result = get_next_line(fd, &buff)) > 0)
	{
		if (plt->width == -1)
			plt->width = ft_count_words(buff, ' ');
		ft_lst_add_to_end(ft_lstnew(buff, ft_strlen(buff) + 1), &list);
		free(buff);
		(plt->height)++;
	}
	return (list);
}

/*
** Convert the list of strings to a 3D matrix, initializing local, world and
** aligned coordinates.
*/

void	convert_lst_to_arr(t_plot *plt, t_list *lst)
{
	int		x;
	int		y;
	int		z;
	t_list	*tmp;
	char	**buff;

	plt->point_matrix = (t_vertex ***)ft_memalloc(sizeof(t_vertex **)
														* plt->height);
	tmp = lst;
	y = -1;
	while (++y < plt->height && lst)
	{
		x = -1;
		plt->point_matrix[y] = (t_vertex **)ft_memalloc(sizeof(t_vertex *)
															* plt->width);
		buff = ft_strsplit(tmp->content, ' ');
		while (++x < plt->width && buff[x])
		{
			z = (double)ft_atoi(buff[x]);
			plt->point_matrix[y][x] = create_vertex(x, y, z);
			plt->z_min = (z < plt->z_min ? z : plt->z_min);
			plt->z_max = (z > plt->z_max ? z : plt->z_max);
		}
		ft_free_doublep(buff);
		tmp = tmp->next;
	}
	free(tmp);
	ft_free_lst(lst);
}

/*
** Creates matrix with local coordinates.
*/

void	create_vertices(t_plot *plt, char *filename)
{
	int fd;

	fd = open_file(filename);
	convert_lst_to_arr(plt, load_file(plt, fd));
	close(fd);
}
