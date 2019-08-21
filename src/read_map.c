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

int		read_color(char *str)
{
	long int	res;

	res = 0;
	while (str && *str != ' ')
		str++;
	if (!ft_strncmp(str, "0x", 2))
	{
		str += 2;
		while (*str != ' ' && *str != '\n' &&\
		res <= 2147483647 && res <= 2147483648)
		{
			if (ft_isdigit(*str))
				res = res * 16 + *str - '0';
			else if (ft_strchr("abcdef", *str))
				res = res * 16 + *str - 'a' + 10;
			else if (ft_strchr("ABCDEF", *str))
				res = res * 16 + *str - 'A' + 10;
			str++;
		}
	}
	return (res);
}

int 	point_count(char **table, t_fdf *fdf)
{
	int	i;

	i = 0;
	while (table[i])
		i++;
	return (i + 1);
}

int 	malloc_table(t_fdf *fdf, char *filename)
{
	fdf->fd = open(filename, O_RDONLY);
	if (read(fdf->fd, NULL, 0) == -1)
		return (0);
	fdf->line_count = 0;
	while (get_next_line(fdf->fd, &fdf->buff) > 0)
		fdf->line_count++;
	if (!(fdf->points = ft_memalloc(sizeof(t_point*) * fdf->line_count)))
		return (0);
	close(fdf->fd);
	return (1);
}

void	print_map(t_fdf *fdf)
{
	int		i;
	t_point	*points;

	i = -1;
	while (++i < fdf->line_count)
	{
		points = fdf->points[i];
		while (points)
			ft_printf("%d ", points->number++);
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
	fdf->fd = open(filename, O_RDONLY);
	i = -1;
	while (get_next_line(fdf->fd, &fdf->buff) > 0 && (tmp = ft_strsplit(fdf->buff, ' ')))
		if ((fdf->points[++i] = ft_memalloc(sizeof(t_point) * point_count(tmp, fdf))))
		{
			j = -1;
			while (tmp[++j])
				fdf->points[i][j].number = ft_atoi(tmp[j]);
			ft_printf("len:%d\n", j);
			ft_clear_table(tmp, j);
		}
	close(fdf->fd);
		//print_map(fdf);
	return (1);
}
