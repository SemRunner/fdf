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

void	draw_map(t_fdf *fdf)
{
	get_black(fdf);

}
