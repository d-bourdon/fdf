/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 15:52:15 by dbourdon          #+#    #+#             */
/*   Updated: 2016/12/14 12:42:11 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_ishexa(int c)
{
	if (c <= '9' && c >= '0')
		return (1);
	else if (c >= 'A' && c <= 'F')
		return (2);
	return (0);
}

int			rgbtoi(int r, int g, int b)
{
	return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}

static int	hexa2(int hex, int rev, int i)
{
	if (hex == 2)
		return (((rev - 55) * (ft_pow(16, i % 2))));
	else if (hex == 1)
		return (((rev - 48) * (ft_pow(16, i % 2))));
	else
		ft_erreur("MAP - couleur incorecte", 1);
	return (0);
}

int			*ft_hexctorgb(char *hex)
{
	int		i;
	int		j;
	int		*out;
	char	*rev;

	i = 0;
	j = 2;
	out = ft_memalloc(3);
	ft_init_inttab(out, 0, 3);
	if (!hex)
	{
		ft_init_inttab(out, 255, 3);
		return (out);
	}
	rev = ft_revers(hex);
	while (i < 6)
	{
		out[j] += hexa2(ft_ishexa(rev[i]), rev[i], i);
		if (++i % 2 == 0)
			j--;
	}
	free(rev);
	return (out);
}

int			ft_degrade(int *p, int *tmp, long py)
{
	int		i;
	int		j;

	j = 0;
	while (j < 3)
	{
		i = p[j + 2] - p[j + 7];
		if (i == 0)
		{
			tmp[j] = p[j + 2];
		}
		if (i > 0)
		{
			tmp[j] -= abs(i) / py;
		}
		if (i < 0)
		{
			tmp[j] += abs(i) / py;
		}
		j++;
		i = 0;
	}
	return (rgbtoi(tmp[0], tmp[1], tmp[2]));
}
