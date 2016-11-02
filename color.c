/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 15:52:15 by dbourdon          #+#    #+#             */
/*   Updated: 2016/11/02 15:43:53 by dbourdon         ###   ########.fr       */
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

int		rgbtoi(int r, int g, int b)
{   
    return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}

int		*ft_hexctorgb(char *hex)
{
	int		i;
	int		j;
	int		*out;
	char	*rev;
	int		tmp;

	i = 0;
	j = 0;
	tmp = 0;
	out = ft_memalloc(3);
	ft_init_inttab(out, 3);
	if (!hex)
	{
		out[0] = 255;
		out[1] = 255;
		out[2] = 255;
		return (out);
	}
	rev = ft_revers(hex);
	while (i < 6)
	{
		tmp = ft_ishexa(rev[i]);
		if (tmp == 2)
			out[j] += (((int)rev[i] - 55) * (ft_pow(16, i % 2)));
		else if (tmp == 1)
			out[j] += (((int)rev[i] - 48) * (ft_pow(16, i % 2)));
		else
			return (0);
		i++;
		if (i % 2 == 0)
			j++;
	}
	free(rev);
	return (out);
}

int 	ft_degrade(int *p, int *tmp, int py)
{
	int		i;
	int		j;

	j = 0;
	if (!py)
		py = 0;
	while (tmp && tmp[j])
	{
		i = p[j + 2] - p[j + 7];
		if (i == 0)
			tmp[j] = p[j + 2];
		if (i > 0)
		{
			tmp[j] -= abs(i) / py;
			//printf("c1 | tmp | c2 = %d | %d | %d    i = %d py = %d\n", c1, *tmp, c2, i, py);
		}
		if (i < 0)
		{
			tmp[j] += abs(i) / py;
			//printf("c1 | tmp | c2 = %d | %d | %d    i = %d py = %d\n", c1, *tmp, c2, i, py);
		}
		j++;
	}
	return (rgbtoi(tmp[0], tmp[1], tmp[2]));
}

int		ft_col(int couleur)
{
	if (couleur  == 0)
		return (16777215);
	else
		return (couleur);
}
