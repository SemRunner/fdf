/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smight <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 02:33:37 by smight            #+#    #+#             */
/*   Updated: 2019/08/01 02:33:39 by smight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	update_coordinates(t_fdf *fdf)
{
	int	width_diff;
	int	hight_diff;
	int i;
	int j;

	width_diff = (WIDTH - 600) / fdf->column_count;
	hight_diff = 0;
	i = -1;
	while (++i < fdf->line_count)
	{
		j = 0;
		fdf->points[i][0].x += 300;
		fdf->points[i][0].y += 250 + hight_diff;
		while (++j < fdf->column_count)
		{
			fdf->points[i][j].x = fdf->points[i][j - 1].x + width_diff;
			fdf->points[i][j].y = 250 + hight_diff;
		}
		hight_diff += (HIGHT - 500) / fdf->line_count;
	}
}

int 	point_count(char **tables, t_fdf *fdf)
{
	int	i;

	i = 0;
	while (tables[i])
		i++;
	fdf->column_count == 0 ? fdf->column_count = i : 0;
	return (i);
}

int 	malloc_table(t_fdf *fdf, char *filename)
{
	fdf->fd = open(filename, O_RDONLY);
	if (read(fdf->fd, NULL, 0) == -1)
		return (0);
	fdf->buff = NULL;
	fdf->column_count = 0;
	fdf->line_count = 0;
	while (get_next_line(fdf->fd, &fdf->buff) > 0)
	{
		ft_memdel((void**)&fdf->buff);
		fdf->line_count++;
	}
	ft_memdel((void**)&table[fdf->fd]);
	if (!(fdf->points = ft_memalloc(sizeof(t_point*) * fdf->line_count)))
		return (0);
	close(fdf->fd);
	fdf->fd = open(filename, O_RDONLY);
	return (1);
}

void	print_map(t_fdf *fdf)
{
	int		i;
	int 	j;

	i = -1;
	while (++i < fdf->line_count)
	{
		j = -1;
		while (++j < fdf->points[i][0].line_len)
			ft_printf("%2d ", (int)fdf->points[i][j].number);
		ft_printf("\n");
	}
}

int		read_map(t_fdf *fdf, char *filename)
{
	char	**tmp;
	int		i;
	int		j;

	if (!malloc_table(fdf, filename))
		return (0);
	i = -1;
	while (get_next_line(fdf->fd, &fdf->buff) > 0 && (tmp = ft_strsplit(fdf->buff, ' ')))
		if ((fdf->points[++i] = ft_memalloc(sizeof(t_point) * point_count(tmp, fdf))))
		{
			ft_memdel((void**)&fdf->buff);
			j = -1;
			while (tmp[++j])
				fdf->points[i][j].number = ft_atoi(tmp[j]);
			fdf->points[i][0].line_len = j;
			ft_clear_table(tmp, j);
		}
	close(fdf->fd);
	ft_memdel((void**)&table[fdf->fd]);
	update_coordinates(fdf);
	print_map(fdf);
	return (1);
}
