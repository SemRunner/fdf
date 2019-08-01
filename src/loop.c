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

int		deal_key(int key, void *param)
{
	if (key == ESC)
	{
		mlx_destroy_window(((t_fdf*)param)->mlx_ptr, ((t_fdf*)param)->win_ptr);
		end_mlx(param);
	}
	else if (key == PUT)
		mlx_put_image_to_window(((t_fdf*)param)->mlx_ptr, ((t_fdf*)param)->win_ptr, ((t_fdf*)param)->img_ptr, 0, 0);
	ft_printf("test\n");
	return (0);
}

void	loop(t_fdf *fdf)
{
	mlx_hook(fdf->win_ptr, 2, 0, deal_key, fdf);//ловлю с клавы esc
	mlx_loop(fdf->mlx_ptr);
}
