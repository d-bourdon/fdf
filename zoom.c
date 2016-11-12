/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 16:30:05 by dbourdon          #+#    #+#             */
/*   Updated: 2016/11/12 18:19:22 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	printf("On a ++\n");
}