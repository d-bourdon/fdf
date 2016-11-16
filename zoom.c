/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 16:30:05 by dbourdon          #+#    #+#             */
/*   Updated: 2016/11/16 18:27:06 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	deplace(t_liste *points, char xy, char mp)
{
	t_liste *tmp;

	tmp = points;
	while (tmp)
	{	
		if (xy == 'x')
		{
			if (mp == '+')
				tmp->x += 20;
			else
				tmp->x -=20;
		}
		else if (xy == 'y')
		{
			if (mp == '+')
				tmp->y += 20;
			else
				tmp->y -=20;
		}
		tmp = tmp->next;
	}
}

void	zoom_point(t_liste *points, float zoom)
{
	t_liste *tmp;

	tmp = points;
	while (tmp)
	{
		tmp->x *= zoom;
		tmp->y *= zoom;
		tmp = tmp->next;
	}
	//printf("On a ++\n");
}