/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_transforms.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 23:05:21 by ysibous           #+#    #+#             */
/*   Updated: 2018/03/18 11:59:02 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libgfx.h"

/*
** Initialize Zero Matrix
*/

void		zero_matrix(double mat[4][4])
{
	int i;

	i = -1;
	while (mat[++i])
		ft_bzero(mat[i], sizeof(double) * 4);
}

/*
** Create a 4 x 4 Identity Matrix
*/

void		identity_matrix(double mat[4][4])
{
	int i;
	int j;

	i = -1;
	while (mat[++i])
	{
		j = -1;
		while (mat[i][++j])
			if (i == j)
				mat[i][j] = 1;
	}
}

void		translate_matrix(double mat[4][4], double tx, double ty, double tz)
{
	double translation_matrix[4][4];

	zero_matrix(translation_matrix);
	identity_matrix(translation_matrix);
	translation_matrix[3][0] = tx;
	translation_matrix[3][1] = ty;
	translation_matrix[3][2] = tz;
	ft_mult_mat_mat(mat, translation_matrix, mat);
}

void		scale_matrix(double mat_to_scale[4][4], double sx, double sy,
							double sz)
{
	double	scale_matrix[4][4];

	zero_matrix(scale_matrix);
	scale_matrix[0][0] = sx;
	scale_matrix[1][1] = sy;
	scale_matrix[2][2] = sz;
	scale_matrix[3][3] = 1;
	ft_mult_mat_mat(mat_to_scale, scale_matrix, mat_to_scale);
}

void		rotate_matrix(double matrix[4][4], double theta, double phi,
							double psi)
{
	double xmat[4][4];
	double ymat[4][4];
	double zmat[4][4];
	double mat1[4][4];
	double mat2[4][4];

	rotate_matrix_x(xmat, theta);
	rotate_matrix_y(ymat, phi);
	rotate_matrix_z(zmat, psi);
	ft_mult_mat_mat(matrix, ymat, mat1);
	ft_mult_mat_mat(mat1, xmat, mat2);
	ft_mult_mat_mat(mat2, zmat, matrix);
}
