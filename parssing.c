/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 15:34:42 by dbourdon          #+#    #+#             */
/*   Updated: 2016/11/22 15:34:01 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	st_set_valeur(t_liste *p, int i, int j, char **tab)
{
	p->x = i;
	p->ox = i;
	p->y = j;
	p->oy = j;
	p->z = ft_atoi(tab[0]);
	p->c = ft_hexctorgb(tab[1]);
	p->next = NULL;
}

int			ft_set_valeur(char **ligne, t_map *map, t_liste *points)
{
	int		i;
	int		j;
	t_liste	*p;
	char	**tab;

	i = 0;
	j = map->total_y;
	while (ligne[i])
	{
		p = (t_liste*)malloc(sizeof(t_liste));
		tab = ft_strsplit(ligne[i], ',');
		if (!ft_isnbr(tab[0]))
			return (0);
		st_set_valeur(p, i, j, tab);
		ft_lstaddend(&points, p);
		i++;
		free_tabtab(tab);
		tab[1] = NULL;
	}
	map->total_y = j + 1;
	if (map->total_x == i || map->total_x == 0)
		map->total_x = i;
	else
		return (0);
	return (1);
}

int			parssing(t_map *map, t_liste *points, int argc, char **argv)
{
	char	*tmp;
	char	**tmp2;
	int		fd;
	int		i;

	i = 1;
	argc++;
	if ((fd = open(argv[1], O_RDONLY)) != -1)
		while (i != 0 && i != -1)
		{
			tmp = NULL;
			i = get_next_line(fd, &tmp);
			if (i == -1)
				return (-1);
			if (i == 0)
				return (1);
			tmp2 = ft_strsplit(tmp, ' ');
			if (ft_set_valeur(tmp2, map, points) == 0)
				return (-1);
			free(tmp);
			free_tabtab(tmp2);
		}
	if (fd == -1)
		ft_erreur("MAP - fichier inexistant", 1);
	return (1);
}
