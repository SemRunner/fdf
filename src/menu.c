/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smight <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 20:45:11 by smight            #+#    #+#             */
/*   Updated: 2019/09/03 20:45:13 by smight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void		draw_menu(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 30, 30, 0xf54242, "MENU:");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 30, 60, 0xf54242, "rotation along the x axis 6 - 9");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 30, 90, 0xf54242, "rotation along the y axis 5 - 8");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 30, 120, 0xf54242, "rotation along the z axis 4 - 7");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 30, 150, 0xf54242, "edit height diff + -");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 30, 180, 0xf54242, "select projection: 1 - iso");
}

static void	update_width(t_fdf *fdf)
{
	int	i;
	int	j;

	i = -1;
	while (++i < fdf->line_count)
	{
		j = -1;
		while (++j < fdf->column_count)
		{
			if (fdf->points[i][j].number > 0)
				fdf->points[i][j].number = (fdf->points[i][j].number * CONST_HIGHT) / fdf->max_height;
			else if (fdf->points[i][j].number < 0)
				fdf->points[i][j].number = (fdf->points[i][j].number * CONST_HIGHT) / fdf->min_height;
			fdf->points[i][j].z = fdf->points[i][j].number;
		}
	}
}

void		get_color_palette(t_fdf *fdf)
{
	int	i;
	int	j;

	i = -1;
	fdf->max_height = 1;
	fdf->min_height = -1;
	while (++i < fdf->line_count)
	{
		j = -1;
		while (++j < fdf->column_count)
		{
			if (fdf->points[i][j].number > fdf->max_height)
				fdf->max_height = fdf->points[i][j].number;
			else if (fdf->points[i][j].number < fdf->min_height)
				fdf->min_height = fdf->points[i][j].number;
		}
	}
	update_width(fdf);
}
