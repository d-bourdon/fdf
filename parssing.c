/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 15:34:42 by dbourdon          #+#    #+#             */
/*   Updated: 2016/10/06 15:47:05 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	parssing(t_map *map, t_list *points, int argc, char *argv)
{
	char	**tmp;
	int		fd;

	if ((fd = fopen(argv[1], "r")) != NULL)
	{
		while (getnextline(fd, tmp) == 1)
		{
			
		}
	}
}