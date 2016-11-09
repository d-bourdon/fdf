/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 14:23:51 by dbourdon          #+#    #+#             */
/*   Updated: 2016/11/08 16:41:11 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_bonjour(void)
{
	ft_putstr("\033[1;34m**************************************************\n");
	ft_putstr("*   ______ _ _      ______      ______           *\n");
	ft_putstr("*   |  ___(_) |     |  _  \\     |  ___|          *\n");
	ft_putstr("*   | |_   _| |___  | | | |___  | |_ ___ _ __    *\n");
	ft_putstr("*   |  _| | | / __| | | | / _ \\ |  _/ _ \\ '__|   *\n");
	ft_putstr("*   | |   | | \\__ \\ | |/ /  __/ | ||  __/ |      *\n");
	ft_putstr("*   \\_|   |_|_|___/ |___/ \\___| \\_| \\___|_|      *\n");
	ft_putstr("*                                                *\n");
	ft_putstr("**************************************************\033[00m\n\n");
	ft_putstr("\033[01m------------------ Utilisation -------------------\n");
	ft_putstr("- \033[30;43mesc\033[37;1;40m : Ferme le programe.\n\n");
	ft_putstr("- \033[30;43m+/-\033[37;1;40m : Zoom sur la structure\n\n");
	ft_putstr("- \033[30;43mflèches directionelles\033[37;1;40m : déplace la");
	ft_putstr(" structure \n\n");
	ft_putstr("--------------------------------------------------\n\033[00m");
	ft_putstr("2016 - dbourdon\n\n");
}

int			main(int argc, char **argv)
{
	t_map	*map;
	t_liste	*points;
	t_info	info;
	int		vision;
	int c,d;
	c = 4;
	d = 1;
	ft_bonjour();
	vision = 30;
	map = (t_map*)malloc(sizeof(t_map));
	map->total_y = 0;
	map->total_x = 0;
	info.data = (int*)malloc(sizeof(int) * 722500);
	points = ft_init_liste();
	if (parssing(map, points, argc, argv) == -1)
		ft_erreur("MAP - fichier invalide", 1);
	info.mlx = mlx_init();
	info.win = mlx_new_window(info.mlx, 850, 850, "mlx 42 - dbourdon");
	info.img = mlx_new_image(info.mlx, 850, 850);
	//info.data = (int*)mlx_get_data_addr(info.img, &c, &(map->total_x), &d);
	ft_bzero(info.data, 850*850*4);
	ft_matrice(points, vision, 20);
	ft_boucle_draw(points, map, info);
	
	//mlx_put_image_to_window(info.mlx, info.win, info.img, 0, 0);
	mlx_loop(info.mlx);
	return (1);
}
