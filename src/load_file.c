/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 23:51:12 by ysibous           #+#    #+#             */
/*   Updated: 2018/03/19 13:03:27 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

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

void	ft_lst_add_to_end(t_list *new_l, t_list *lst)
{
	while (lst->next)
		lst = lst->next;
	lst->next = new_l;
}

t_list	*load_file(t_plot *plt, int fd)
{
	char	*line;
	t_list	*lst;
	int		num_words;

	plt->width = -1;
	lst = NULL;
	num_words = 0;
	plt->width = -1;
	plt->z_min = MAX_INT;
	plt->z_max = MIN_INT;
	while (get_next_line(fd, &line) == 1)
	{
		if ((num_words = ft_count_words(line, ' ')) > plt->width)
			plt->width = num_words;
		ft_lst_add_to_end((ft_lstnew(line, ft_strlen(line) + 1)), lst);
		(plt->height)++;
	}
	return (lst);
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
	char	**buff;

	plt->point_matrix = (t_vertex ***)ft_memalloc(sizeof(t_vertex **) * plt->height);
	y = 0;
	while (y < plt->height)
	{
		x = 0;
		plt->point_matrix[y] = (t_vertex **)ft_memalloc(sizeof(t_vertex *) * plt->width);
		buff = ft_strsplit(lst->content, ' ');
		while (x < plt->width)
		{
			z = ft_atoi(lst->content);
			plt->point_matrix[y][x] = create_vertex(x, y, z);
			plt->z_min = (z < plt->z_min ? z : plt->z_min);
			plt->z_max = (z > plt->z_max ? z : plt->z_max);
			x++;
		}
		lst = lst->next;
		y++;
	}
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


