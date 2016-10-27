/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 14:23:51 by dbourdon          #+#    #+#             */
/*   Updated: 2016/10/27 18:19:09 by dbourdon         ###   ########.fr       */
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
	points->c = 0;
	points->ox = 0;
	points->oy = 0;
	points->next = NULL;
	if (parssing(map, points, argc, argv) == -1)
		ft_erreur("Map invalide", 1);
	info.mlx = mlx_init();
	info.win = mlx_new_window(info.mlx, 850, 850, "mlx 42 blop");
	ft_matrice(points, vision, 20);
	ft_boucle_draw(points, map, info);

	// while (y <= map->total_y * 20)
	// {
	// 	while (x <= map->total_x * 20)
	// 	{
	// 		if (x % 20 == 0 || y % 20 == 0)
	// 		{
	// 			mlx_pixel_put(mlx, win, x, y, 0x00FF0000);
	// 			printf("put pixel %d - %d\n", x, y);
	// 		}
	// 		if (points && (y == points->y * 20))
	// 		{
	// 			mlx_pixel_put(mlx, win, x, y, 16777215 - (points->z * 500));
	// 		}
	// 		if (points && (x % 20 == 0 && y % 20 == 0 && points->y * 20 == y))
	// 		{
	// 			printf("On change - Valeur : %d - %d - %d - %d\n", points->x, points->y, x, y);
	// 			points = points->next;
	// 			//if (points && points->y != y)
	// 			//	x = 400;
	// 		}
	// 		x++;
	// 	}
	// 	x = 0;
	// 	y++;
	// }

	/////////////////////////////////////////////////////////////
	//    DEMO
	/////////////////////////////////////////////////////////////

	// int xi,yi,xf,yf;
	// xi = 15;
	// yi = 2;
	// xf = 25;
	// yf = 30;
 //  int dx,dy,i,xinc,yinc,cumul,x,y ;
 //  x = xi ;
 //  y = yi ;
 //  dx = xf - xi ;
 //  dy = yf - yi ;
 //  xinc = ( dx > 0 ) ? 1 : -1 ;
 //  yinc = ( dy > 0 ) ? 1 : -1 ;
 //  dx = abs(dx) ;
 //  dy = abs(dy) ;
 //  mlx_pixel_put(mlx, win, x, y, 0x00FFFFFF) ;
 //    if ( dx > dy ) {
 //      cumul = dx / 2 ;
 //      for ( i = 1 ; i <= dx ; i++ ) {
 //      	x += xinc ;
 //      	cumul += dy ;
 //      	if ( cumul >= dx ) {
 //        		cumul -= dx ;
 //        		y += yinc ; }
 //      mlx_pixel_put(mlx, win, x, y, 0x00FFFFFF) ;
 //		 }
 //	   }
 //    else {
 //    cumul = dy / 2 ;
 //    for ( i = 1 ; i <= dy ; i++ ) {
 //      y += yinc ;
 //      cumul += dx ;
 //      if ( cumul >= dy ) {
 //        cumul -= dy ;
 //        x += xinc ; }
 //      mlx_pixel_put(mlx, win, x, y, 0x00FFFFFF) ; } }
	mlx_loop(info.mlx);
	return (1);
}
