/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 14:18:27 by dbourdon          #+#    #+#             */
/*   Updated: 2016/12/14 12:42:32 by dbourdon         ###   ########.fr       */
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

/*
** TAILLE_WIN_X == TAILLE_WIN_Y
*/
# define TAILLE_WIN_X 1300
# define TAILLE_WIN_Y 1300

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

typedef struct		s_img
{
	void			*ptr;
	double			imgx;
	double			imgy;
	int				bpp;
	int				line;
	int				*data;
	int				endian;
}					t_img;

typedef struct		s_info
{
	void			*mlx;
	void			*win;
	int				pixel;
	int				line;
	int				winx;
	int				winy;
	int				origine[2];
	float			vision;
	t_img			*img;
	t_map			*map;
	t_liste			*points;
}					t_info;

/*
** free_tabtab.c
*/
void				free_tabtab(char **tab);
/*
** main.c
*/
int					detecte_cle(int cle, t_info *info);
/*
** zoom.c
*/
void				zoom_point(t_liste *points, float zoom);
void				deplace(t_liste *points, char xy, char mp);
void				clear_point(t_liste *points);
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
int					ft_degrade(int *p, int *tmp, long py);
int					rgbtoi(int r, int g, int b);
/*
** ligne.c
*/
void				trace_ligneg(int *dir, int *p, int *d, t_info info);
void				trace_ligned(int *dir, int *p, int *d, t_info info);
void				ft_ligne(int *p, t_info info);
void				ft_dessine(t_liste *p1, t_liste *p2, t_info info);
/*
** matrice.c
*/
void				ft_matrice(t_liste *points, float vision, t_map *map);
void				ft_visionplus(t_liste *points);
void				ft_visionmoins(t_liste *points);
void				ft_boucle_draw(t_liste *p, t_map *m, t_info info);
/*
** init.c
*/
void				ft_init_inttab(int *tab, int valeur, int taille);
t_liste				*ft_init_liste(void);
t_img				*init_img(t_info info);
void				init_info(t_info *info);
t_map				*init_map(void);
#endif
