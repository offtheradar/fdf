/************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_rotations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 20:48:54 by ysibous           #+#    #+#             */
/*   Updated: 2018/03/15 21:43:26 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgfx.h"

void		rotate_matrix_x(double matrix[4][4], double theta)
{
	zero_matrix(matrix);
	identity_matrix(matrix);
	matrix[1][1] = cos(theta);
	matrix[1][2] = sin(theta);
	matrix[2][1] = -sin(theta);
	matrix[2][2] = cos(theta);
}

void		rotate_matrix_y(double matrix[4][4], double phi)
{
	zero_matrix(matrix);
	identity_matrix(matrix);
	matrix[0][0] = cos(phi);
	matrix[0][2] = -sin(phi);
	matrix[2][0] = sin(phi);
	matrix[2][2] = cos(phi);
}

void		rotate_matrix_z(double matrix[4][4], double psi)
{
	zero_matrix(matrix);
	identity_matrix(matrix);
	matrix[0][0] = cos(psi);
	matrix[0][1] = sin(psi);
	matrix[1][0] = -sin(psi);
	matrix[1][1] = cos(psi);
}
