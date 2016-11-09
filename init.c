/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 16:41:35 by dbourdon          #+#    #+#             */
/*   Updated: 2016/11/09 19:03:47 by dbourdon         ###   ########.fr       */
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
void	init_img(t_info info, t_img *img)
{
	const double    width = info.winx;
    const double    height = info.winy;
    const int        buffer = (int)(width * height * 4.);
    printf("BLOP\n");
    img->ptr = mlx_new_image(info.mlx, 850, 850);
    printf("BLOP\n");
    img->imgx = width;
    printf("BLOP\n");
    img->imgy = height;
    printf("BLOP %p\n", &(img->line));
    img->data = mlx_get_data_addr(img->ptr, &(img->bpp), &(img->line), &(img->endian));
    printf("BLOP\n");
    ft_bzero(img->data, buffer);
}
