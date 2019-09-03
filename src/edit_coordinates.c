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

void	rotation_update(t_fdf *fdf, t_point *p)
{
	p->x -= WIDTH / 2;
	p->y -= HIGHT / 2;
	p->y = p->y * cos(RT_STEP * fdf->x_rotation) + p->z * sin(RT_STEP * fdf->x_rotation);
	p->z = -p->y * sin(RT_STEP * fdf->x_rotation) + p->z * cos(RT_STEP * fdf->x_rotation);
	p->x = p->x * cos(RT_STEP * fdf->y_rotation) + p->z * sin(RT_STEP * fdf->y_rotation);
	p->z = -p->x * sin(RT_STEP * fdf->y_rotation) + p->z * cos(RT_STEP * fdf->y_rotation);
	p->x = p->x * cos(RT_STEP * fdf->z_rotation) - p->y * sin(RT_STEP * fdf->z_rotation);
	p->y = p->x * sin(RT_STEP * fdf->z_rotation) + p->y * cos(RT_STEP * fdf->z_rotation);
	p->x += WIDTH / 2;
	p->y += HIGHT / 2;
}

void	iso_projection_update(t_fdf *fdf, t_point *p)
{
	int old_x;
	int	old_y;

	old_x = p->x;
	old_y = p->y;
	p->x = (old_x - old_y) * cos(0.523599);
	p->y = -p->number * RATE + (old_x + old_y) * sin(0.523599);
	p->x += 600;
	p->y -= 200;
}

void	edit_coordinates(t_fdf *fdf, t_point *p1, t_point *p2)
{
	if (fdf->projection == ISO)
	{
		iso_projection_update(fdf, p1);
		iso_projection_update(fdf, p2);
	}
	rotation_update(fdf, p1);
	rotation_update(fdf, p2);
	p1->x += fdf->width_shift;
	p2->x += fdf->width_shift;
	p1->y += fdf->hight_shift;
	p2->y += fdf->hight_shift;
}
