/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 14:23:51 by dbourdon          #+#    #+#             */
/*   Updated: 2016/11/12 18:19:39 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		detecte_cle(int cle,t_info *info)
{
	if (cle == 53)
		exit(0);
	mlx_clear_window(info->mlx, info->win);
	if (cle == 123)
		info->origine[0] -=20;
	else if (cle == 124)
		info->origine[0] +=20;
	else if (cle == 125)
		info->origine[1] +=20;
	else if (cle == 126)
		info->origine[1] -=20;
	else if (cle == 69)
	{
		printf("EHO\n");
		zoom_point(info->points, 1.5);
		printf("LOL %p\n", &(info->mlx));
		mlx_destroy_image(info->mlx, info->img->ptr);
		printf("on destroy\n");
		info->img = init_img(*info);
		printf("On reset\n");
		ft_boucle_draw(info->points, info->map, *info);
		printf("on a boucle draw\n");
	}
	printf("on va put %p - %p - %p\n", info->mlx, info->win, info->img->ptr);
	mlx_put_image_to_window(info->mlx, info->win, info->img->ptr, info->origine[0], info->origine[1]);
	printf("On a put windozs\n");
	return (1);
}

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
	t_info	info;
	int		vision;

	ft_bonjour();
	init_info(&info);
	info.img = init_img(info);
	vision = 30;
	info.map = init_map();
	info.points = ft_init_liste();
	if (parssing(info.map, info.points, argc, argv) == -1)
		ft_erreur("MAP - fichier invalide", 1);
	info.img->line = info.map->total_x;
	ft_matrice(info.points, vision, 20);
	ft_boucle_draw(info.points, info.map, info);
	mlx_put_image_to_window(info.mlx, info.win, info.img->ptr, 0, 0);
	mlx_key_hook(info.win, detecte_cle, &info);
	mlx_loop(info.mlx);
	return (1);
}
