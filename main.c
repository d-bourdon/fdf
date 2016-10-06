/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 14:23:51 by dbourdon          #+#    #+#             */
/*   Updated: 2016/10/06 17:46:22 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	t_map	*map;
	t_liste	*points;
	void	*mlx;
	void	*win;
	int		x;
	int 	y;

	points = NULL;
	map = NULL;
	if (parssing(map, points, argc, argv) == 0)
	{
		printf("ERREUR\n");
		return (0);
	}
	while (points)
	{
		printf("point: %d - %d - %d\n", points->x, points->y, points->z);
		points = points->next;
	}
	mlx = mlx_init();
	win = mlx_new_window(mlx, 400, 400, "mlx 42 blop");
	y = 50;
	while (y < 150)
	{
		x = 50;
		while (x < 150)
		{
			mlx_pixel_put(mlx, win, x, y, 0x00FFFFFF);
			x ++;
		}
		y ++;
	}
	mlx_loop(mlx);
	return (1);
}
