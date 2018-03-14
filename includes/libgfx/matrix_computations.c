/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_computations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 20:13:20 by ysibous           #+#    #+#             */
/*   Updated: 2018/03/13 23:46:32 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgfx.h"

/*
** Copy a matrix from source to destination.
*/ 
void	ft_cp_matrix(float src[4][4], float dst[4][4])
{
	int i;
	int j;

	i = 0;
	while (src[i])
	{
		j = 0;
		while (src[i][j])
		{
			dst[i][j] = src[i][j];
			j++;
		}
		i++;
	}
}

/*
** This function multiplies a 4 x 4 matrix with a 4 x 1.
*/
void	ft_mult_mat_vec(float mat[4][4], t_3d_pixel *src, t_3d_pixel *dst)
{
	dst->x = src->x * mat[0][0] +
				src->y * mat[1][0] +
				src->z * mat[2][0] +
				mat[3][0];
	dst->y = src->x * mat[0][1] +
				src->y * mat[1][1] +
				src->z * mat[2][1] +
				mat[3][1];
	dst->z = src->x * mat[0][2] +
				src->y * mat[1][2] +
				src->z * mat[2][2] +
				mat[3][2];
}

/*
** This function computes the multiplication of two matrices, and saves the result
**
*/
void	ft_mult_mat_mat(float mat1[4][4], float mat2[4][4], float dest[4][4])
{
	int		x;
	int		y;

	x = 0;
	while (dest[x])
	{
		y = 0;
		while (dest[x][y])
		{
			dest[x][y] = mat1[x][0] * mat2[0][y]
						+ mat1[x][1] * mat2[1][y]
						+ mat1[x][2] * mat2[2][y]
						+ mat1[x][3] * mat2[3][y];
			y++;
		}
		x++;
	}
}
