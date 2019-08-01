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

int		get_line_len(char *str)
{
	int res;

	res = 0;
	while (str && *str != '\n')
	{
		if ((ft_isdigit(*str) || ft_strchr("abcdefABCDEF", *str)) &&\
		(*(str + 1) == ' ' || *(str + 1) == '\n'))
			res++;
		str++;
	}
	return (res);
}

int		read_int(char *str)
{
	long int	res;

	res = 0;
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
		return (res);
	}
	else
		return (ft_atoi(str));
}

int		get_line_count(t_fdf *fdf)
{
	char	*tmp;
	int 	res;

	tmp = fdf->source_map;
	res = 0;
	while (*tmp != 0)
	{
		if (*tmp == '\n')
			res++;
		tmp++;
	}
	return (res + 1);
}

t_point	*get_line(char **str)
{
	int		len;
	int		i;
	t_point	*res;

	len = get_line_len(*str);
	if (!(res = ft_memalloc(sizeof(t_point) * len)))
		return (NULL);
	res->len = len;
	i = -1;
	while (++i < len)
	{
		res[i].value = read_int(*str);
		while (*str && (**str == ' ' || **str == '\n'))//skip to next
			*str += 1;
	}
	return (res);
}

int		read_map(t_fdf *fdf, char *filename)
{
	int		fd;
	char	*tmp;
	int		i;

	fdf->source_map = NULL;
	fd = open(filename, O_RDONLY);
	if (read(fd, NULL, 0) == -1)
		return (0);
	while (read(fd, &fdf->buff[0], B_SIZE))
	{
		fdf->source_map = ft_strjoin(fdf->source_map, fdf->buff);
		ft_bzero(fdf->buff, B_SIZE);
	}
	ft_printf("%s", fdf->source_map);//for test
	fdf->size_line = WIDTH;
	fdf->points = ft_memalloc(sizeof(t_point*) * get_line_count(fdf));
	i = -1;
	tmp = fdf->source_map;
	while (*tmp != 0)
		fdf->points[++i] = get_line(&tmp);
	//print_map(fdf);
	return (1);
}
