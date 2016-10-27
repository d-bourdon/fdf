/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 15:52:15 by dbourdon          #+#    #+#             */
/*   Updated: 2016/10/27 19:35:49 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_ishexa(int c)
{
	if (c < 58 || c > 47)
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
	printf("IN\n");
	if (!hex)
	{
		printf("fail ?\n");
		return (0);
	}
	printf("Before rev %s\n", hex);
	rev = ft_revers(hex);
	printf("After rev %s\n", rev);
	while (i < 6)
	{
		printf("On test : %c\n", rev[i]);
		if (ft_ishexa(rev[i]) == 2)
		{
			out += (((int)rev[i] - 55) * (ft_pow(16, i)));
			printf(" Lettre : %d - %d\n", out, ((int)rev[i] - 55) * (ft_pow(16, i)));
		}
		else if (ft_ishexa(hex[i]) == 1)
		{
			out += (((int)rev[i] - 48) * (ft_pow(16, i)));
			printf("Chiffre :%d - %d\n", out, ((int)rev[i] - 48) * (ft_pow(16, i)));
		}
		else
		{
			printf("Rien fail\n");
			return (0);
		}
		i++;
		printf("NEXT\n");
	}
	free(rev);
	printf("OUT\n");
	return (16711680);
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