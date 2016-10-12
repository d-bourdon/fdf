/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 14:18:27 by dbourdon          #+#    #+#             */
/*   Updated: 2016/10/12 11:32:33 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "mlx/mlx.h"
# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct		s_liste
{
	int				x;
	int				y;
	int				z;
	struct s_liste	*next;
}					t_liste;

typedef struct		s_map
{
	int				total_x;
	int				total_y;
}					t_map;


int		ft_set_valeur(char **ligne, t_map *map, t_liste *points);
int		parssing(t_map *map, t_liste *points, int argc, char **argv);

void	ft_lstaddend(t_liste **liste, t_liste *ajout);

void	ft_erreur(char *s, int mode);

#endif
