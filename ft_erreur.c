/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_erreur.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 11:26:45 by dbourdon          #+#    #+#             */
/*   Updated: 2016/10/12 11:30:00 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_erreur(char *s, int mode)
{
	if (mode == 1)
	{
		ft_putstr("Erreur : ");
		ft_putstr(s);
		ft_putstr("\n");
		exit (666);
	}
}