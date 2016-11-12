/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 16:41:35 by dbourdon          #+#    #+#             */
/*   Updated: 2016/11/12 15:33:17 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_init_inttab(int *tab, int valeur, int taille)
{
	int		i;

	i = 0;
	if (tab)
		while (i < taille)
			tab[i++] = valeur;
}

t_liste	*ft_init_liste(void)
{
	t_liste *p;
	int		*out;

	out = ft_memalloc(3);
	ft_init_inttab(out, 0, 3);
	p = (t_liste*)malloc(sizeof(t_liste));
	p->x = 0;
	p->y = 0;
	p->z = 0;
	p->c = out;
	p->ox = 0;
	p->oy = 0;
	p->next = NULL;
	return (p);
}
t_img	*init_img(t_info info)
{
	t_img	*img;
	double	width;
    double	height;
    int		buffer;

	width = info.winx;
	height = info.winy;
	buffer = (int)(width * height * 4.);
    img = (t_img*)malloc(sizeof(t_img));
    img->bpp = 2;
	img->endian = 0;
    img->ptr = mlx_new_image(info.mlx, info.winx, info.winy);
    img->imgx = width;
    img->imgy = height;
    img->data = (int*)mlx_get_data_addr(img->ptr, &(img->bpp), &(img->line),
    	&(img->endian));
    ft_bzero(img->data, buffer);
    return (img);
}

void	init_info(t_info *info)
{
	info->winx = TAILLE_WIN_X;
	info->winy = TAILLE_WIN_Y;
	info->origine[0] = 0;
	info->origine[1] = 0;
	info->mlx = mlx_init();
	info->win = mlx_new_window(info->mlx, info->winx, info->winy,
		"mlx 42 - dbourdon");
}

t_map	*init_map(void)
{
	t_map	*map;

	map = (t_map*)malloc(sizeof(t_map));
	map->total_y = 0;
	map->total_x = 0;
	return (map);
}