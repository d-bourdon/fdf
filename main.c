/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 14:23:51 by dbourdon          #+#    #+#             */
/*   Updated: 2016/11/17 16:34:10 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	detecte_cle2(int cle, t_info *info)
{
	if (cle == 123)
		deplace(info->points, 'x', '-');
	else if (cle == 124)
		deplace(info->points, 'x', '+');
	else if (cle == 125)
		deplace(info->points, 'y', '+');
	else if (cle == 126)
		deplace(info->points, 'y', '-');
	else if (cle == 81)
		ft_visionplus(info->points);
	else if (cle == 75)
		ft_visionmoins(info->points);
	else
		return ;
}

int			detecte_cle(int cle, t_info *info)
{
	if (cle == 53)
		exit(0);
	mlx_clear_window(info->mlx, info->win);
	detecte_cle2(cle, info);
	if (cle == 69)
		zoom_point(info->points, 1.2);
	else if (cle == 78)
		zoom_point(info->points, 1 / 1.2);
	else if (cle == 76 || cle == 36)
	{
		clear_point(info->points);
		ft_matrice(info->points, info->vision,
			(info->winx - 500) / info->map->total_x);
	}
	mlx_destroy_image(info->mlx, info->img->ptr);
	info->img = init_img(*info);
	ft_boucle_draw(info->points, info->map, *info);
	mlx_put_image_to_window(info->mlx, info->win, info->img->ptr,
		info->origine[0], info->origine[1]);
	return (0);
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
	ft_putstr("- \033[0;30;43mesc\033[37;1;40m : Ferme le programe.\n\n");
	ft_putstr("- \033[0;30;43m+|-\033[37;1;40m : Zoom sur la structure\n\n");
	ft_putstr("- \033[0;30;43mflèches directionelles\033[37;1;40m : déplace");
	ft_putstr(" la structure \n\n");
	ft_putstr("- \033[0;30;43m=|/\033[37;1;40m : Augmente la hauteurs");
	ft_putstr(" des points\n\n- \033[0;30;43mret|enter\033[37;1;40m :");
	ft_putstr(" Remet à zero la map\n\n");
	ft_putstr("--------------------------------------------------\n\033[00m");
	ft_putstr("2016 - dbourdon\n\n");
}

int			main(int argc, char **argv)
{
	t_info	info;

	ft_bonjour();
	init_info(&info);
	info.img = init_img(info);
	info.vision = 36.39;
	info.map = init_map();
	info.points = ft_init_liste();
	if (parssing(info.map, info.points, argc, argv) == -1)
		ft_erreur("MAP - fichier invalide", 1);
	info.img->line = info.map->total_x;
	ft_matrice(info.points, info.vision, (info.winx - 500) / info.map->total_x);
	ft_boucle_draw(info.points, info.map, info);
	mlx_put_image_to_window(info.mlx, info.win, info.img->ptr, 0, 0);
	mlx_key_hook(info.win, detecte_cle, &info);
	mlx_loop(info.mlx);
	return (0);
}
