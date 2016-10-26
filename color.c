/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 15:52:15 by dbourdon          #+#    #+#             */
/*   Updated: 2016/10/25 19:21:21 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_ishexa(int c)
{
	if (ft_isdigit(c))
		return (1);
	if (c > 64 && c < 71)
		return (2);
	return (0);
}

int		ft_hexctoi(char *hex)
{
	int		i;
	int		out;
	char	*rev;

	i = 0;
	out = 0;
	if (!hex)
		return (0);
	rev = ft_revers(hex);
	while (i < 6)
	{
		if (ft_ishexa(rev[i]) == 2)
			out = out + (((int)rev[i] - 55) * (ft_pow(16, i)));
		else if (ft_ishexa(hex[i]) == 1)
			out = out + (((int)rev[i] - 48) * (ft_pow(16, i)));
		else
			return (0);
		i++;
	}
	free(rev);
	return (out);
}


int		ft_col(int couleur)
{
	if (couleur  == 0)
		return (16777215);
	else
		return (couleur);
}
// int		ft_detect_coul(char *lect)
// {
// 	char	**tab;

// 	tab = ft_strstr(lect, ',');

// 	set hauteur atoi tab0
// 	if tab1
// 		set couleur hexctoi tab1
// 	return 1

// }