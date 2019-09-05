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
	int temp;

	p->x -= WIDTH / 2;
	p->y -= HIGHT / 2;
	p->number *= fdf->height_coeff;
	temp = p->y;
	p->y = p->y * fdf->cos_x + p->number * fdf->sin_x;
	p->number = -temp * fdf->sin_x + p->number * fdf->cos_x;
	temp = p->x;
	p->x = p->x * fdf->cos_y + p->number * fdf->sin_y;
	p->number = -temp * fdf->sin_y + p->number * fdf->cos_y;
	temp = p->x;
	p->x = p->x * fdf->cos_z - p->y * fdf->sin_z;
	p->y = temp * fdf->sin_z + p->y * fdf->cos_z;
	p->x += WIDTH / 2;
	p->y += HIGHT / 2;
}

void	iso_projection_update(t_fdf *fdf)
{
	fdf->x_rotation = -0.615472907;
	fdf->y_rotation = -0.785398;
	fdf->z_rotation = 0;
}

void	edit_coordinates(t_fdf *fdf, t_point *p1, t_point *p2)
{
	rotation_update(fdf, p1);
	rotation_update(fdf, p2);
	p1->x += fdf->width_shift;
	p2->x += fdf->width_shift;
	p1->y += fdf->hight_shift;
	p2->y += fdf->hight_shift;
}
