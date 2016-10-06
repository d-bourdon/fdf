/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 15:34:42 by dbourdon          #+#    #+#             */
/*   Updated: 2016/10/06 17:50:58 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_set_valeur(char **ligne, t_map *map, t_liste *points)
{
	int		i;
	int		j;
	t_liste	p;

	i = 0;
	j = map->total_y;
	while(ligne[i])
	{
		p.x = i;
		p.y = j;
		p.z = ft_atoi(ligne[i]);
		printf("point: %d - %d - %d\n", p.x, p.y, p.z);
		ft_lstaddend(&points, &p);
	}
	map->total_y = j + 1;
	//ft_freetabtab(ligne);
	if (map->total_x == i || map->total_x == 0)
		map->total_x = i;
	else
		return (0);
	return (1);
}

int		parssing(t_map *map, t_liste *points, int argc, char **argv)
{
	char	**tmp;
	char	**tmp2;
	FILE	*fd;

	argc++;
	tmp = NULL;
	printf("ARGV %s\n", argv[1]);
	if ((fd = fopen(argv[1], "r")) != NULL)
	{
		printf("IN\n");
		while (get_next_line((int)fd, tmp))
		{
			printf("IN2\n");
			tmp2 = ft_strsplit(tmp[0], ' ');
			if (ft_set_valeur(tmp2, map, points) == 0)
				return (0);
		}
	}
	printf("BLOP\n");
	return (1);
}