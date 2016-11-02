/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 14:23:51 by dbourdon          #+#    #+#             */
/*   Updated: 2016/11/02 11:23:58 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	t_map	*map;
	t_liste	*points;
	t_info	info;
	int		vision;

	vision = 30;
	map = (t_map*)malloc(sizeof(t_map));
	map->total_y = 0;
	map->total_x = 0;
	points = (t_liste*)malloc(sizeof(t_liste));
	points->x = 0;
	points->y = 0;
	points->z = 0;
	points->ox = 0;
	points->oy = 0;
	points->next = NULL;
	if (parssing(map, points, argc, argv) == -1)
		ft_erreur("Map invalide", 1);
	info.mlx = mlx_init();
	info.win = mlx_new_window(info.mlx, 850, 850, "mlx 42 blop");
	ft_matrice(points, vision, 20);
	ft_boucle_draw(points, map, info);
	mlx_loop(info.mlx);
	return (1);
}
