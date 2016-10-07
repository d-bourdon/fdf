/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 15:34:42 by dbourdon          #+#    #+#             */
/*   Updated: 2016/10/07 15:48:18 by dbourdon         ###   ########.fr       */
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
	printf("avant while, valeur de j %d\n", j);
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
	char	*tmp;
	char	**tmp2;
	int		fd;
	int		i;

	i = 1;
	argc++;
	tmp = NULL;
	printf("ARGV %s\n", argv[1]);
	if ((fd = open(argv[1], O_RDONLY)) != -1)
	{
		printf("IN fd = %d\n", fd);
		while (i != 0 && i != -1)
		{
			i = get_next_line(fd, &tmp);
				if (i == -1)
				{
					printf("Erreur de lecture - exit\n");
					exit (-1);
				}
			printf("retour gnl : %d\n", i);
			tmp2 = ft_strsplit(tmp, ' ');
			if (ft_set_valeur(tmp2, map, points) == 0)
				return (0);
		}
	}
	printf("BLOP\n");
	return (1);
}