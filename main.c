/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 14:23:51 by dbourdon          #+#    #+#             */
/*   Updated: 2016/10/07 17:13:41 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	t_map	*map;
	t_liste	*points;
	void	*mlx;
	void	*win;

	map = (t_map*)malloc(sizeof(t_map));
	map->total_y = 0;
	map->total_x = 0;
	points = (t_liste*)malloc(sizeof(t_liste));
	points->x = 0;
	points->y = 0;
	points->z = 0;
	points->next = NULL;
	if (parssing(map, points, argc, argv) == -1)
	{
		printf("ERREUR map ecriture - printf\n");
		return (0);
	}
	mlx = mlx_init();
	win = mlx_new_window(mlx, 400, 400, "mlx 42 blop");
	while (points)
	{
		if (points->z > 0)
		{
			mlx_pixel_put(mlx, win, points->x + 150, points->y + 150, 0x00FFFFFF);
		}
		points = points->next;
	}
	mlx_loop(mlx);
	return (1);
}
