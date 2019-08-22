/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smight <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 04:24:23 by smight            #+#    #+#             */
/*   Updated: 2019/08/01 04:24:24 by smight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	get_black(t_fdf *fdf)
{
	int	i;
	int len;

	i = -1;
	len = WIDTH * HIGHT;
	while (++i < len)
		fdf->mlx_map[i] = 0x000000;
}

void	draw_line(t_fdf *fdf, t_point p1, t_point p2)
{
	int	dx;
	int dy;
	int x;
	int y;
	int p;

	dx = ABS(p1.x - p2.x);
	dy = ABS(p1.y - p2.y);
	x = p1.x;
	y = p1.y;
	p = 2 * dy - dx;
	while (x < p2.x)
	{
		if (p >= 0)
		{
			fdf->mlx_map[y * WIDTH + x] = 0x8f0306;
			y++;
			p = p + 2 * dy - 2 * dx;
		}
		else
		{
			fdf->mlx_map[y * WIDTH + x] = 0x8f0306;
			p = p + 2 * dy;
		}
		x++;
	}
}

void	draw_map(t_fdf *fdf)
{
	int	i;
	int j;

	i = -1;
	get_black(fdf);
	while (++i < fdf->line_count)
	{
		j = -1;
		while (++j < fdf->column_count)
		{
			if (j < fdf->column_count - 1)//по горизонтали
				draw_line(fdf, fdf->points[i][j], fdf->points[i][j + 1]);
			if (i < fdf->line_count - 1)//по вертикали
				draw_line(fdf, fdf->points[i][j], fdf->points[i + 1][j]);
		}
	}
}
