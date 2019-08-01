/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smight <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 00:25:43 by smight            #+#    #+#             */
/*   Updated: 2019/08/01 00:26:39 by smight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include <stdio.h>
# include <fcntl.h>

# define WIDTH 2000
# define HIGHT 1200
# define ESC 53
# define PUT 49
# define B_SIZE 50000

typedef struct	s_point
{
	double		number;
	int			value;
	int 		len;
}				t_point;

typedef struct	s_fdf
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	int			*mlx_map;
	char		buff[B_SIZE];
	char		*source_map;
	int			size_line;
	int			endian;
	t_point		**points;
}				t_fdf;

int		ft_printf(char *str, ...);
int		ft_fprintf(int fd, char *str, ...);
void	loop(t_fdf *fdf);
void	end_mlx(t_fdf *fdf);
int		read_map(t_fdf *fdf, char *filename);
void	draw_map(t_fdf *fdf);
int		get_line_count(t_fdf *fdf);
void	print_map(t_fdf *fdf);

#endif
