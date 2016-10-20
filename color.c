/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 15:52:15 by dbourdon          #+#    #+#             */
/*   Updated: 2016/10/20 18:06:25 by dbourdon         ###   ########.fr       */
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

// int		ft_detect_coul(int *coul)
