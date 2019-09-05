/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smight <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 15:27:14 by smight            #+#    #+#             */
/*   Updated: 2019/09/05 15:27:15 by smight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"

void	get_rectangle_zero(t_fdf *fdf, int column, int hight)
{
	int		top;
	int 	i;
	double	topCoeff;
	double lineCoeff;

	top = fdf->matrix_size - hight - 1;
	if (fdf->lin_matrix[top][column] < 0)
		matrix_mult_to_const(fdf, top, -1.0);
	topCoeff = fdf->lin_matrix[top][column];
	i = fdf->matrix_size - 1;
	while (i > top)
	{
		if (fdf->lin_matrix[i][column] < 0)
			matrix_mult_to_const(fdf, i, -1.0);
		lineCoeff = fdf->lin_matrix[i][column];
		matrix_mult_to_const(fdf, i, topCoeff);
		matrix_addition_lines(fdf, i, top, -lineCoeff);
		i--;
	}
}

void	get_matrix_triangular(t_fdf *fdf)
{
	int hight;
	int column;

	column = 0;
	hight = fdf->matrix_size;
	while (hight > 0)
	{
		get_rectangle_zero(fdf, column, hight);
		hight--;
		column++;
	}
}

void	solve_matrix(t_fdf *fdf)
{
	get_matrix_triangular(fdf);
}
