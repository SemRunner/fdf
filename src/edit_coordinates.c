/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_coordinates.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smight <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 16:55:40 by smight            #+#    #+#             */
/*   Updated: 2019/08/23 16:55:42 by smight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	iso_projection_update(t_fdf *fdf, t_point *p)
{
	int old_x;
	int	old_y;

	old_x = p->x;
	old_y = p->y;
	p->x = (old_x - old_y) * cos(0.523599);
	p->y = -p->number + (old_x + old_y) * sin(0.523599);
}

void	edit_coordinates(t_fdf *fdf, t_point *p1, t_point *p2)
{
	if (fdf->projection == ISO)
	{
		iso_projection_update(fdf, p1);
		iso_projection_update(fdf, p2);
	}
	p1->x += fdf->width_shift;
	p2->x += fdf->width_shift;
	p1->y += fdf->hight_shift;
	p2->y += fdf->hight_shift;
}
