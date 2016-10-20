/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 14:23:51 by dbourdon          #+#    #+#             */
/*   Updated: 2016/10/20 18:06:32 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	t_map	*map;
	t_liste	*points;
	void	*mlx;
	void	*win;
	int		y;
	int		x;

	y = 0;
	x = 0;
	map = (t_map*)malloc(sizeof(t_map));
	map->total_y = 0;
	map->total_x = 0;
	points = (t_liste*)malloc(sizeof(t_liste));
	points->x = 0;
	points->y = 0;
	points->z = 0;
	points->c = 0;
	points->next = NULL;
	if (parssing(map, points, argc, argv) == -1)
		ft_erreur("Map invalide", 1);
	mlx = mlx_init();
	win = mlx_new_window(mlx, 450, 450, "mlx 42 blop");
	while (y <= map->total_y * 20)
	{
		while (x <= map->total_x * 20)
		{
			if (x % 20 == 0 || y % 20 == 0)
			{
				mlx_pixel_put(mlx, win, x, y, 0x00FF0000);
				printf("put pixel %d - %d\n", x, y);
			}
			if (points && (y == points->y * 20))
			{
				mlx_pixel_put(mlx, win, x, y, 16777215 - (points->z * 500));
			}
			if (points && (x % 20 == 0 && y % 20 == 0 && points->y * 20 == y))
			{
				printf("On change - Valeur : %d - %d - %d - %d\n", points->x, points->y, x, y);
				points = points->next;
				//if (points && points->y != y)
				//	x = 400;
			}
			x++;
		}
		x = 0;
		y++;
	}
	mlx_loop(mlx);
	return (1);
}
