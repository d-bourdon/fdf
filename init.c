/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 16:41:35 by dbourdon          #+#    #+#             */
/*   Updated: 2016/11/05 14:29:54 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_init_inttab(int *tab, int valeur, int taille)
{
	int		i;

	i = 0;
	if (tab)
		while (i < taille)
			tab[i++] = valeur;
}