/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corozco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 22:29:43 by corozco           #+#    #+#             */
/*   Updated: 2020/02/11 23:29:22 by corozco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdlib.h>
#include <string.h>

/*
void			print_tex(t_data *d)
{
	int			i;
	int			j;

	i = -1;
//	printf("\n\npos X [%f], por Y [%f]\n\n\n", d->pl.posx, d->pl.posy);
	ft_printf("(parametros del parcing)\n");
	ft_printf("display ->x = %d, ->y = %d\n", d->res.r_x, d->res.r_y);
//	printf("display ->x = %f, ->y = %f\n", d->pl.planex, d->pl.planey);
	ft_printf("-no =%s\n", d->tex.north);
	ft_printf("-so =%s\n", d->tex.south);
	ft_printf("-we =%s\n", d->tex.west);
	ft_printf("-ea =%s\n", d->tex.east);
	ft_printf("-sp =%s\n", d->tex.sprite);
	ft_printf("-fl =%s\n", d->tex.floor);
	ft_printf("-mo =%s\n", d->tex.sky);
	ft_printf("Numero de sprites %d\n", d->sprcount);
	//while (++i < d->sprcount)
		//printf("%f - %f\n", d->sprite[i].x, d->sprite[i].y);
	i = -1;
	ft_printf("x del mapa = %d y del mapa = %d\n", d->map.x, d->map.y);//borrar
	while (++i < d->map.y)
	{
		j = -1;
		while (++j < d->map.x)
			ft_printf("[%d]", d->map.map[i][j]);
		ft_printf("\n");
	}
}
*/

int				error_management(int ac, char **av)
{
	if (ft_strlen(av[1]) < 5)
		return (-2);
	if (ft_strncmp(&av[1][ft_strlen(av[1]) - 4], ".cub", 4))
		return (-2);
	if (ac == 3)
		if (ft_strncmp(av[2], "-save", 5) != 0)
			return (-1);
	return (0);
}

int				main(int ac, char **av)
{
	t_data		data;

	if (ac != 2 && ac != 3)
		ft_ms_error(ac, (void *)0, (void *)0);
	if ((data.tmps.i_tmp = error_management(ac, av)) != 0)
		ft_ms_error(data.tmps.i_tmp, (void *)0, (void *)0);
	ft_init_map(av[1], &data);
	init(&data);
//	print_tex(&data); //borrar
	mlx_loop_hook(data.mlx_ptr, raycasting, &data);
	ft_press(&data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
