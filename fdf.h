/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 14:18:27 by dbourdon          #+#    #+#             */
/*   Updated: 2016/10/26 15:39:42 by dbourdon         ###   ########.fr       */
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
	int				c;
	struct s_liste	*next;
}					t_liste;

typedef struct		s_map
{
	int				total_x;
	int				total_y;
}					t_map;

typedef struct		s_info
{
	void			*mlx;
	void			*win;
}					t_info;


// parssing.c
int		ft_set_valeur(char **ligne, t_map *map, t_liste *points);
int		parssing(t_map *map, t_liste *points, int argc, char **argv);
// ft_lstaddend.c
void	ft_lstaddend(t_liste **liste, t_liste *ajout);
// ft_erreur.c
void	ft_erreur(char *s, int mode);
// color.c
int		ft_ishexa(int c);
int		ft_hexctoi(char	*hex);
int		ft_col(int couleur);
// ligne.c
void	trace_ligneg(int *dir, int *p, int *d, t_info info);
void	trace_ligned(int *dir, int *p, int *d, t_info info);
void	ft_ligne(int *pos1, int *pos2, t_info info);
#endif
