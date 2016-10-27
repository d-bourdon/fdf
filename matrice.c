/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 15:33:06 by dbourdon          #+#    #+#             */
/*   Updated: 2016/10/27 17:56:06 by dbourdon         ###   ########.fr       */
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
		p->x += ((p->x * cos(vision + (p->z / 10))) - (p->y * sin(vision + (p->z / 10))));
		p->y += ((p->x * sin(vision + (p->z / 10))) + (p->y * cos(vision + (p->z / 10))));
		p = p->next;
	}
	printf("Bye bye matrice\n");
}