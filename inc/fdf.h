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
# include "../minilibx_macos/mlx.h"
# include <stdio.h>
# include <fcntl.h>
# include <math.h>

# define WIDTH 2000
# define HIGHT 1200
# define SHIFT 50
# define ESC 53
# define PUT 76
# define ISO 1
# define RATE 5
# define PARALLEL 0
# define RT_STEP M_PI / 8

typedef struct	s_point
{
	int 		number;
	double		color;
	int			x;
	int 		y;
	int 		z;
	int 		len;
	int			line_len;
}				t_point;

typedef struct	s_fdf
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	int			*mlx_map;
	char		*buff;
	int			size_line;
	int 		line_count;
	int			endian;
	int 		column_count;
	int			fd;
	int 		width_shift;
	int 		hight_shift;
	char		projection;
	int 		x_rotation;
	int 		y_rotation;
	int 		z_rotation;
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
void	edit_coordinates(t_fdf *fdf, t_point *p1, t_point *p2);
int 	abs_f(int a);
void	draw_menu(t_fdf *fdf);
void	rotation_update(t_fdf *fdf, t_point *p);

#endif
