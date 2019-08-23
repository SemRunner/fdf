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
/*
void	draw_line(t_fdf *fdf, t_point p1, t_point p2)//p2 правее p1
{
	int		x;
	int 	current_y;
	double	real_y;
	double	p;

	x = p1.x;
	current_y = p1.y;
	real_y = (double)p1.y;
	p = (double)(p2.y - p1.y) / (double)(p2.x - p1.x);
	while (x < p2.x)
	{
		if (p >= 0 && real_y > (double)current_y && real_y >= ((int)real_y + 0.5))
			current_y++;
		else if (p < 0 && real_y < (double)current_y && real_y < ((int)real_y + 0.5))
			current_y--;
		fdf->mlx_map[WIDTH * current_y + x] = 0x8f0306;
		x++;
		real_y += p;
	}
}*/

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
	double	real_y;
	double	step;

	x = p1.x;
	y = p1.y;
	real_y = (double)p1.y;
	step = (double)(p2.y - p1.y) / (double)(p2.x - p1.x);
	while (x < p2.x)
	{
		if (step >= 0 && real_y > (double)y && real_y >= (int)real_y + 0.5)
			y++;
		else if (step <= 0 && real_y < (double)y && real_y < (int)real_y + 0.5)
			y--;
		if (WIDTH * y + x >= 0 && WIDTH * y + x < WIDTH * HIGHT)//если координата реальна
			fdf->mlx_map[WIDTH * y + x] = get_color((ABS(p1.number) + ABS(p2.number)) / 2);
		x++;
		real_y += step;
	}
}

void	draw_to_y(t_fdf *fdf, t_point p1, t_point p2)//p1.y <= p2.y всегда
{
	int 	x;
	int 	y;
	double	real_x;
	double	step;

	x = p1.x;
	y = p1.y;
	real_x = (double)p1.x;
	step = (double)(p2.x - p1.x) / (double)(p2.y - p1.y);
	while (y < p2.y)
	{
		if (step >= 0 && real_x > (double)x && real_x >= (int)real_x + 0.5)
			x++;
		else if (step <= 0 && real_x < (double)x && real_x < (int)real_x + 0.5)
			x--;
		if (WIDTH * y + x >= 0 && WIDTH * y + x < WIDTH * HIGHT)//если координата реальна
			fdf->mlx_map[WIDTH * y + x] = get_color((ABS(p1.number) + ABS(p2.number)) / 2);
		y++;
		real_x += step;
	}
}

void	draw_line(t_fdf *fdf, t_point p1, t_point p2)
{
	if (ABS(p2.x - p1.x) >= ABS(p2.y - p1.y))
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
