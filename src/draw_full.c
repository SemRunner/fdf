/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_full.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smight <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 18:31:19 by smight            #+#    #+#             */
/*   Updated: 2019/09/04 18:31:21 by smight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	calc_angle_params(t_fdf *fdf)
{
	fdf->cos_x = cos(RT_STEP * fdf->x_rotation);
	fdf->sin_x = sin(RT_STEP * fdf->x_rotation);
	fdf->cos_y = cos(RT_STEP * fdf->y_rotation);
	fdf->sin_y = sin(RT_STEP * fdf->y_rotation);
	fdf->cos_z = cos(RT_STEP * fdf->z_rotation);
	fdf->sin_z = sin(RT_STEP * fdf->z_rotation);
}
