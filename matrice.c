/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 15:33:06 by dbourdon          #+#    #+#             */
/*   Updated: 2016/10/27 18:41:05 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_matrice(t_liste *points, int vision, int espace)
{
	t_liste	*p;

	p = points;
	while (p)
	{
		p->x *= espace;
		p->y *= espace;
		p->x += (p->x * cos(vision)) - (p->y * sin(vision));
		p->y += (p->x * sin(vision)) + (p->y * cos(vision));
		p->x -= p->z;
		p->y -= p->z;
		p = p->next;
	}
	printf("Bye bye matrice\n");
}