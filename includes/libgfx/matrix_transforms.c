/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_transforms.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 23:05:21 by ysibous           #+#    #+#             */
/*   Updated: 2018/03/14 00:30:07 by ysibous          ###   ########.fr       */
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

	init_matrix(translation_matrix);
	identity_matrix(translation_matrix);
	translation_matrix[3][0] = tx;
	translation_matrix[3][1] = ty;
	translation_matrix[3][2] = tz;
	ft_mult_mat_mat(mat, translate_matrix, mat);
}

void		scale_matrix(double mat_to_scale[4][4], double sx, double sy,
							double sz)
{
	double	scale_matrix[4][4];

	init_matrix(scale_matrix);
	scale_matrix[0][0] = sx;
	scale_matrix[1][1] = sy;
	scale_matrix[2][2] = sz;
	scale_matrix[3][3] = 1;
	ft_mult_mat_mat(mat_to_scale, scale_matrix, mat_to_scale);
}

void		rotate_matrix(double matrix[4][4], float ax, float ay, float az)
{
	float xmat[4][4];
	float ymat[4][4];
	float zmat[4][4];
	float mat1[4][4];
	float mat2[4][4];

	identity_matrix(init_matrix(xmat));
	identity_matrix(init_matrix(ymat));
	identity_matrix(init_matrix(zmat));
	xmat[1][1] = cos(ax);
	xmat[1][2] = sin(ax);
	xmat[2][1] = -sin(ax);
	xmat[2][2] = cos(ax);
	ymat[0][0] = cos(ay);
	ymat[0][2] = -sin(ay);
	ymat[2][0] = sin(ay);
	ymat[2][2] = cos(ay);
	zmat[0][0] = cos(az);
	zmat[0][1] = sin(az);
	zmat[1][0] = -sin(az);
	zmat[1][1] = cos(az);
	ft_mult_mat_mat(matrix, ymat, mat1);
	ft_mult_mat_mat(mat1, xmat, mat2);
	ft_mult_mat_mat(mat2, zmat, matrix);	
}


