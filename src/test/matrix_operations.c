/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smight <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 15:33:18 by smight            #+#    #+#             */
/*   Updated: 2019/09/05 15:33:19 by smight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"

void	sort_matrix(t_fdf *fdf)
{

}

void	matrix_mult_to_const(t_fdf *fdf, int line, double coeff)
{
	int	i;

	i = -1;
	while (++i < fdf->matrix_size)
		fdf->lin_matrix[line][i] *= coeff;
	fdf->free_m[line] *= coeff;
}

void	matrix_addition_lines(t_fdf *fdf, int l1, int l2, double coeff)
{
	int i;

	i = -1;
	while (++i < fdf->matrix_size)
	{
		fdf->lin_matrix[l1][i] += fdf->lin_matrix[l2][i] * coeff;
	}
	fdf->free_m[l1] += fdf->free_m[l2] * coeff;
}
