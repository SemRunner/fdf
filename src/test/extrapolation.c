/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smight <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 13:59:50 by smight            #+#    #+#             */
/*   Updated: 2019/09/05 13:59:52 by smight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"

void	expand_point(t_fdf *fdf, t_point p, int line)
{
	double	x;
	double	y;
	int		i;

	x = p.x;
	y = p.y;
	i = -1;
	while (++i < fdf->matrix_size)
	{
		if (i % 2 == 1)
		{
			fdf->lin_matrix[line][i] = y;
			x *= p.x;
			y *= p.y;
		}
		else
			fdf->lin_matrix[line][i] = x;
	}
}

void	fill_matrix(t_fdf *fdf)
{
	int		i;

	i = -1;
	while (++i < fdf->matrix_size)//
		fdf->free_m[i] = fdf->points[i / fdf->column_count][i % fdf->column_count].number;
	i = -1;
	while (++i < fdf->matrix_size)
	{
		expand_point(fdf, fdf->points[i / fdf->column_count][i % fdf->column_count], i);
	}
}

void	extrapolation(t_fdf *fdf)
{
	int i;

//	if (fdf->is_no_square == 1 || fdf->column_count * fdf->line_count > 50)
//		return ;
	fdf->matrix_size = fdf->column_count * fdf->line_count;
	fdf->lin_matrix = ft_memalloc(sizeof(*(fdf->lin_matrix)) * fdf->matrix_size);//маллочу матрицу и массив свободных членов
	fdf->free_m = ft_memalloc(sizeof(*(fdf->free_m)) * fdf->matrix_size);
	fdf->polynom_coeffs = ft_memalloc(sizeof(*(fdf->polynom_coeffs)) * fdf->matrix_size);//массив коэффициентов при полиноме(решение системы ур-й)
	i = -1;
	while (++i < fdf->matrix_size)
		fdf->lin_matrix[i] = ft_memalloc(sizeof(**(fdf->lin_matrix)) * fdf->matrix_size);
	fill_matrix(fdf);//заполняю матрицу
	solve_matrix(fdf);
}
