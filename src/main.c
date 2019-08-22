/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smight <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 00:19:42 by smight            #+#    #+#             */
/*   Updated: 2019/08/01 00:19:44 by smight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int		error(int param)
{
	if (param == 1)
		ft_fprintf(1, "usage: filename\n");
	else if (param == 2)
		ft_fprintf(2, "read error\n");
	return (1);
}

void	initialize_mlx(t_fdf *fdf, char *name)
{
	int a = 1;

	fdf->mlx_ptr = mlx_init();//создаю основу
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, WIDTH, HIGHT, name);//создаю окно
	fdf->img_ptr = mlx_new_image(fdf->mlx_ptr, WIDTH, HIGHT);//создаю имейдж
	fdf->mlx_map = (int*)mlx_get_data_addr(fdf->img_ptr, &a, &fdf->size_line, &fdf->endian);
}

void	end_mlx(t_fdf *fdf)
{
	mlx_destroy_image(fdf->mlx_ptr, fdf->img_ptr);//чищу имейдж
	//mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);//чищу окно ????почему сега????
	exit(0);
}

int		main(int c, char **v)
{
	t_fdf	fdf;

	if (c != 2)
		return (error(1));
	if (!read_map(&fdf, v[1]))//читаю мапу и заполняю массив double
		return (error(2));
	initialize_mlx(&fdf, v[1]);
	loop(&fdf);
	end_mlx(&fdf);
	//ft_memdel((void**)&fdf.source_map);
	return (0);
}
