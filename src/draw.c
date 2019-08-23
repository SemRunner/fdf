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

int 	get_color(int hight)
{
	if (hight >= 5)
		return (0x8f0306);//red
	else
		return (0x2ed952);//green
}

void	draw_to_x(t_fdf *fdf, t_point p1, t_point p2)//p1.x <= p2.x всегда
{
	int 	x;
	int 	y;
	double	diff;
	double	step;

	edit_coordinates(fdf, &p1, &p2);
	x = p1.x;
	y = p1.y;
	diff = 0;
	step = (double)(p2.y - p1.y) / (double)(p2.x - p1.x);
	while (x <= p2.x)
	{
		if (step > 0 && diff >= 0.5)
		{
			y++;
			diff = 0;
		}
		else if (step < 0 && diff <= -0.5)
		{
			y--;
			diff = 0;
		}
		if (x >= 0 && x < WIDTH && y >= 0 && y < HIGHT)//если координата реальна
			fdf->mlx_map[WIDTH * y + x] = get_color((ABS(p1.number) + ABS(p2.number)) / 2);
		x++;
		diff += step;
	}
}

void	draw_to_y(t_fdf *fdf, t_point p1, t_point p2)//p1.y <= p2.y всегда
{
	int 	x;
	int 	y;
	double	diff;
	double	step;

	edit_coordinates(fdf, &p1, &p2);
	y = p1.y;
	x = p1.x;
	diff = 0;
	step = (double)(p2.x - p1.x) / (double)(p2.y - p1.y);
	while (y <= p2.y)
	{
		if (step > 0 && diff >= 0.5)
		{
			x++;
			diff = 0;
		}
		else if (step < 0 && diff <= -0.5)
		{
			x--;
			diff = 0;
		}
		if (x >= 0 && x < WIDTH && y >= 0 && y < HIGHT)//если координата реальна
			fdf->mlx_map[WIDTH * y + x] = get_color((ABS(p1.number) + ABS(p2.number)) / 2);
		y++;
		diff += step;
	}
}

void	draw_line(t_fdf *fdf, t_point p1, t_point p2)
{
	if (ABS(p2.x - p1.x) >= ABS(p2.y - p1.y))//if dx >= dy
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
