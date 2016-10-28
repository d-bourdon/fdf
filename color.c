/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 15:52:15 by dbourdon          #+#    #+#             */
/*   Updated: 2016/10/28 14:36:24 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_ishexa(int c)
{
	if (c <= '9' && c >= '0')
		return (1);
	else if (c >= 'A' && c <= 'F')
		return (2);
	return (0);
}

// int		ft_hexctoi(char *hex)
// {
// 	int		i;
// 	int		out;
// 	char	*rev;

// 	i = 0;
// 	out = 0;
// 	printf("IN\n");
// 	if (!hex)
// 	{
// 		printf("fail ?\n");
// 		return (0);
// 	}
// 	printf("Before rev %s\n", hex);
// 	rev = ft_revers(hex);
// 	printf("After rev %s\n", rev);
// 	while (i < 6)
// 	{
// 		printf("On test : %c\n", rev[i]);
// 		if (ft_ishexa(rev[i]) == 2)
// 		{
// 			out += (((int)rev[i] - 55) * (ft_pow(15, i)));
// 			printf(" Lettre : %d - %d\n", out, ((int)rev[i] - 55) * (ft_pow(15, i)));
// 		}
// 		else if (ft_ishexa(hex[i]) == 1)
// 		{
// 			out += (((int)rev[i] - 48) * (ft_pow(15, i)));
// 			printf("Chiffre :%d - %d\n", out, ((int)rev[i] - 48) * (ft_pow(15, i)));
// 		}
// 		else
// 		{
// 			printf("Rien fail\n");
// 			return (0);
// 		}
// 		i++;
// 		printf("NEXT\n");
// 	}
// 	free(rev);
// 	printf("%d\n", 0x0FFFFFF - 0x000FFFF);
// 	printf("OUT\n");
// 	return (out);
// }

int		ft_hexctoi(char *hex)
{
	int		i;
	int		out;
	char	*rev;
	int		tmp;

	i = 0;
	out = 0;
	tmp = 0;
	if (!hex)
		return (0);
	rev = ft_revers(hex);
	while (i < 6)
	{
		tmp = ft_ishexa(rev[i]);
		if (tmp == 2)
			out += (((int)rev[i] - 55) * (ft_pow(16, i)));
		else if (tmp == 1)
			out += (((int)rev[i] - 48) * (ft_pow(16, i)));
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