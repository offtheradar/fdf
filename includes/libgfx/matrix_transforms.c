/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_transforms.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 23:05:21 by ysibous           #+#    #+#             */
/*   Updated: 2018/03/13 23:46:26 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgfx.h"

/*
** Initialize Zero Matrix
*/
void		init_matrix(double mat[4][4])
{
	int i;

	i = 0;
	while (mat[i])
	{
		ft_bzero(mat[i], sizeof(double) * 4);
		i++;
	}
}

/*
** Create a 4 x 4 Identity Matrix
*/
void		identity_matrix(double mat[4][4])
{
	int i;
	int j;

	i = 0;
	while (mat[i])
	{
		j = 0;
		while (mat[i][j])
		{
			if (i == j)
				mat[i][j] = 1;
			j++;
		}
		i++;
	}
}


void		translate_matrix(double mat[4][4], double tx, double ty, double tz)
{
	double translation_matrix[4][4];

	init_matrix(matrix);
	identity_matrix(matrix);
	translation_matrix[3][0] = tx;
	translate_matrix[3][1] = ty;
	translation_matrix[3][2] = tz;
	ft_mult_mat_mat(mat, translate_matrix,, mat);
}

void		scale_matrix(double mat[4][4], double sx, double sy, double sz)
