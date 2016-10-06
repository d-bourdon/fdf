/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 14:23:51 by dbourdon          #+#    #+#             */
/*   Updated: 2016/10/06 15:47:07 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

int		main(int argc, char *argv)
{
	tmap	*map;
	t_list	*points
	void	*mlx;
	void	*win;
	int		x;
	int 	y;

	parssing(map, points, argc, argv);
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
