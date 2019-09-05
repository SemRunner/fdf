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

void		matrix_swap_lines(t_fdf *fdf, int l1, int l2)
{
	double	*tmp;

	tmp = fdf->lin_matrix[l1];
	fdf->lin_matrix[l1] = fdf->lin_matrix[l2];
	fdf->lin_matrix[l2] = tmp;
}

static int	compare_lines(t_fdf *fdf, double *l1, double *l2)//если в l1 слева нулей больше, return 1
{
	int	i;
	int j;

	i = 0;
	while (i < fdf->matrix_size && l1[i] == 0)
		i++;
	j = 0;
	while (j < fdf->matrix_size && l2[j] == 0)
		j++;
	return (i < j);
}

void		q_sort(t_fdf *fdf, int start, int end)
{
	double	*middle;
	int 	left;
	int 	right;

	middle = fdf->lin_matrix[(end + start) / 2];
	left = start;
	right = end;
	while (left <= right)
	{
		while (compare_lines(fdf, fdf->lin_matrix[left], middle))
			left++;
		while (compare_lines(fdf, middle, fdf->lin_matrix[right]))
			right--;
		if (left <= right)
			matrix_swap_lines(fdf, left++, right--);
	}
	if (right > start)
		q_sort(fdf, start, right);
	if (left < end)
		q_sort(fdf, left, end);
}

void		sort_matrix(t_fdf *fdf)
{
	q_sort(fdf, 0, fdf->matrix_size - 1);
}

void		matrix_mult_to_const(t_fdf *fdf, int line, double coeff)
{
	int	i;

	i = -1;
	while (++i < fdf->matrix_size)
		fdf->lin_matrix[line][i] *= coeff;
	fdf->free_m[line] *= coeff;
}

void		matrix_addition_lines(t_fdf *fdf, int l1, int l2, double coeff)
{
	int i;

	i = -1;
	while (++i < fdf->matrix_size)
	{
		fdf->lin_matrix[l1][i] += fdf->lin_matrix[l2][i] * coeff;
	}
	fdf->free_m[l1] += fdf->free_m[l2] * coeff;
}
