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
	draw_map((t_fdf*)param);//каждый раз после кнопок рисую мапу
	mlx_put_image_to_window(((t_fdf*)param)->mlx_ptr, ((t_fdf*)param)->win_ptr,\
	((t_fdf*)param)->img_ptr, 0, 0);
	ft_printf("%d\n", ((t_fdf*)param)->width_shift);
	return (0);
}

void	loop(t_fdf *fdf)
{
	//fdf->projection = ISO;
	draw_map(fdf);
	mlx_hook(fdf->win_ptr, 2, 0, deal_key, fdf);//ловлю с клавы esc
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img_ptr, 0, 0);
	mlx_loop(fdf->mlx_ptr);
}
