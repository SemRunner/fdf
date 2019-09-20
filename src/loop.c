/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smight <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 02:10:30 by smight            #+#    #+#             */
/*   Updated: 2019/08/01 02:10:31 by smight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	get_shift(int key, t_fdf *fdf)
{
	if (key == 123)//left
		fdf->width_shift -= SHIFT;
	else if (key == 124)//right
		fdf->width_shift += SHIFT;
	else if (key == 125)//down
		fdf->hight_shift += SHIFT;
	else//up
		fdf->hight_shift -= SHIFT;
}

void	to_start(t_fdf *fdf)
{
	fdf->width_shift = 0;
	fdf->hight_shift = 0;
	fdf->x_rotation = 0;
	fdf->y_rotation = 0;
	fdf->z_rotation = 0;
	fdf->height_coeff = 1;
}

void	write_rotation(t_fdf *fdf, int key)
{
	if (key == 92)
		fdf->x_rotation = (fdf->x_rotation + 1);
	else if (key == 88)
		fdf->x_rotation = (fdf->x_rotation - 1);
	else if (key == 91)
		fdf->y_rotation = (fdf->y_rotation + 1);
	else if (key == 87)
		fdf->y_rotation = (fdf->y_rotation - 1);
	else if (key == 89)
		fdf->z_rotation = (fdf->z_rotation + 1);
	else if (key == 86)
		fdf->z_rotation = (fdf->z_rotation - 1);
}

int		deal_key(int key, void *param)
{
	if (key == ESC)
	{
		mlx_destroy_window(((t_fdf*)param)->mlx_ptr, ((t_fdf*)param)->win_ptr);

		end_mlx(param);
	}
	else if (key == PUT)
		mlx_put_image_to_window(((t_fdf*)param)->mlx_ptr, ((t_fdf*)param)->win_ptr, ((t_fdf*)param)->img_ptr, 0, 0);
	else if (key >= 123 && key <= 126)
		get_shift(key, param);
	else if (key == 83)
		((t_fdf*)param)->projection = ISO;
	else if (key == 84)
		((t_fdf*)param)->projection = PARALLEL;
	else if (key == 49)
		to_start(param);
	else if (key == 92 || key == 88 || key == 91 || key == 87 || key == 89 || key == 86)
		write_rotation(param, key);
	else if (key == 69)
		((t_fdf*)param)->height_coeff *= 2;
	else if (key == 78)
		((t_fdf*)param)->height_coeff /= 2;
	draw_map((t_fdf*)param);//каждый раз после кнопок рисую мапу
	mlx_put_image_to_window(((t_fdf*)param)->mlx_ptr, ((t_fdf*)param)->win_ptr,\
	((t_fdf*)param)->img_ptr, 0, 0);
	draw_menu(param);
	return (0);
}

void	loop(t_fdf *fdf)
{
	fdf->projection = PARALLEL;
	to_start(fdf);
	draw_map(fdf);
	mlx_hook(fdf->win_ptr, 2, 0, deal_key, fdf);//ловлю с клавы esc
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img_ptr, 0, 0);
	draw_menu(fdf);
	mlx_loop(fdf->mlx_ptr);
}
