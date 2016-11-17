/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 15:33:06 by dbourdon          #+#    #+#             */
/*   Updated: 2016/11/17 16:47:44 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_matrice(t_liste *points, float vision, int espace)
{
	t_liste	*p;

	p = points;
	while (p)
	{
		p->x *= espace;
		p->y *= espace;
		p->x += (p->x * cos(vision)) - (p->y * sin(vision));
		p->y += (p->x * sin(vision)) + (p->y * cos(vision));
		p->x -= p->z * 2;
		p->y -= p->z * 2;
		p = p->next;
	}
}

void	ft_visionplus(t_liste *points)
{
	t_liste	*p;

	p = points;
	while (p)
	{
		p->x -= p->z;
		p->y -= p->z;
		p = p->next;
	}
}

void	ft_visionmoins(t_liste *points)
{
	t_liste	*p;

	p = points;
	while (p)
	{
		p->x += p->z;
		p->y += p->z;
		p = p->next;
	}
}

void	ft_boucle_draw(t_liste *p, t_map *m, t_info info)
{
	t_liste *p1;
	t_liste *p2;
	int		i;

	p1 = p;
	i = 0;
	while (p1)
	{
		p2 = p1;
		if (p1 && p1->next && p1->next->oy == p1->oy)
			ft_dessine(p1, p1->next, info);
		while (p2 && p2->next && i < m->total_x)
		{
			p2 = p2->next;
			i++;
		}
		i = 0;
		if (p2 && p2->oy > p1->oy)
			ft_dessine(p1, p2, info);
		p1 = p1->next;
	}
}
