/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 14:18:27 by dbourdon          #+#    #+#             */
/*   Updated: 2016/11/04 16:10:51 by dbourdon         ###   ########.fr       */
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
	int				*c;
	int				ox;
	int				oy;
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

/*
** parssing.c
*/
int					ft_set_valeur(char **ligne, t_map *map, t_liste *points);
int					parssing(t_map *map, t_liste *points, int argc,
						char **argv);
/*
** ft_lstaddend.c
*/
void				ft_lstaddend(t_liste **liste, t_liste *ajout);
/*
** ft_erreur.c
*/
void				ft_erreur(char *s, int mode);
/*
** color.c
*/
int					ft_ishexa(int c);
int					*ft_hexctorgb(char	*hex);
int 				ft_degrade(int *p, int *tmp, int py);
int					rgbtoi(int r, int g, int b);
/*
** ligne.c
*/
void				trace_ligneg(int *dir, int *p, int *d, t_info info);
void				trace_ligned(int *dir, int *p, int *d, t_info info);
void				ft_ligne(int *point, t_info info);
void				ft_dessine(t_liste *p1, t_liste *p2, t_info info);
void				ft_boucle_draw(t_liste *p, t_map *m, t_info info);
/*
** matrice.c
*/
void				ft_matrice(t_liste *points, int vision, int espace);
/*
** init.c
*/
void				ft_init_inttab(int *tab, int taille);
#endif
