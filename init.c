/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 16:41:35 by dbourdon          #+#    #+#             */
/*   Updated: 2016/11/05 15:59:48 by dbourdon         ###   ########.fr       */
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
