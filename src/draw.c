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

void	get_min_int_map(t_fdf *fdf)
{
	int	i;
	int len;

	i = -1;
	len = WIDTH * HIGHT;
	while (++i < len)
		fdf->mlx_map[i] = INT8_MIN;
}

int 	get_color(int hight, t_fdf *fdf, int old)
{
//	if (hight >= 5)
//		return (0x8f0306);//red
//	else
//		return (0x2ed952);//green
	int	color;

	color = 0x800000;
	if (hight >= 0)
		color |= ((hight *  256 / fdf->max_height) << 2);
//	else if (hight < 0)
//		color |= (hight * 250 / -fdf->min_height);
	if (old > color)
		return old;
	return color;
}

int 	abs_f(int a)
{
	return (a >= 0 ? a : -a);
}

void	draw_to_x(t_fdf *fdf, t_point p1, t_point p2)//p1.x <= p2.x всегда
{
	int dx;
	int dy;
	int error;
	int	dir_y;

	error = 0;
	dir_y = p2.y - p1.y >= 0 ? 1 : -1;
	dx = abs_f(p2.x - p1.x);
	dy = abs_f(p2.y - p1.y);
	while (p1.x < p2.x)
	{
		if (p1.x >= 0 && p1.x < WIDTH && p1.y >= 0 && p1.y < HIGHT)//если координата реальна
			fdf->mlx_map[WIDTH * p1.y + p1.x] =
					get_color((abs_f(p1.z) + abs_f(p2.z)) / 2, fdf, fdf->mlx_map[WIDTH * p1.y + p1.x]);
		error += dy;
		if (2 * error >= dx)
		{
			p1.y += dir_y;
			error -= dx;
		}
		p1.x++;
	}
}

void	draw_to_y(t_fdf *fdf, t_point p1, t_point p2)//p1.y <= p2.y всегда
{
	int dx;
	int dy;
	int error;
	int	dir_x;

	error = 0;
	dir_x = p2.x - p1.x >= 0 ? 1 : -1;
	dx = abs_f(p2.x - p1.x);
	dy = abs_f(p2.y - p1.y);
	while (p1.y < p2.y)
	{
		if (p1.x >= 0 && p1.x < WIDTH && p1.y >= 0 && p1.y < HIGHT)//если координата реальна
			fdf->mlx_map[WIDTH * p1.y + p1.x] =
					get_color((abs_f(p1.z) + abs_f(p2.z)) / 2, fdf, fdf->mlx_map[WIDTH * p1.y + p1.x]);
		error += dx;
		if (2 * error >= dy)
		{
			p1.x += dir_x;
			error -= dy;
		}
		p1.y++;
	}
}

void	draw_line(t_fdf *fdf, t_point p1, t_point p2)
{
	int dx;
	int dy;

	edit_coordinates(fdf, &p1, &p2);
	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
	if (abs_f(dx) >= abs_f(dy))//if dx >= dy
	{
		if (p1.x <= p2.x)
			draw_to_x(fdf, p1, p2);
		else
			draw_to_x(fdf, p2, p1);
	}
	else
	{
		if (p1.y <= p2.y)
			draw_to_y(fdf, p1, p2);
		else
			draw_to_y(fdf, p2, p1);
	}
}

void	draw_map(t_fdf *fdf)
{
	int	i;
	int j;

	i = -1;
	get_black(fdf);
	if (fdf->projection == ISO)
		iso_projection_update(fdf);
	//extrapolation(fdf);
	calc_angle_params(fdf);
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
