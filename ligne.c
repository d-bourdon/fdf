/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ligne.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 17:41:13 by dbourdon          #+#    #+#             */
/*   Updated: 2016/11/01 14:38:48 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	trace_ligned(int *dir, int *p, int *d, t_info info)
{
	int		cumul;
	int		i;
	int		py;
	int		tmp;

	py = hypot(abs(p[0] - p[3]), abs(p[1] - p[4]));
	tmp = p[2];
	cumul = d[0] / 2;
	i = 1;
	printf("TMP1 = %d p1 = %d,%d p2 = %d,%d c = %d-%d\n", tmp, p[0], p[1], p[3], p[4], p[2], p[5]);
	while (i <= d[0])
	{
		p[0] += dir[0];
		cumul += d[1];
		if (cumul >= d[0])
		{
			cumul -= d[0];
			p[1] += dir[1];
		}
		mlx_pixel_put(info.mlx, info.win, p[0] + 100, p[1] + 500, ft_degrade(p[2], p[5], &tmp, py));
		i++;
	}
}

void	trace_ligneg(int *dir, int *p, int *d, t_info info)
{
	int		cumul;
	int		i;
	int		py;
	int		tmp;

	py = hypot(abs(p[0] - p[3]), abs(p[1] - p[4]));
	tmp = ft_col(p[2]);
	cumul = d[1] / 2;
	printf("TMP2 = %d p1 = %d,%d p2 = %d,%d c = %d-%d\n", tmp, p[0], p[1], p[3], p[4], p[2], p[5]);
	i = 1;
	while (i <= d[1])
	{
		p[1] += dir[1];
		cumul += d[0];
		if (cumul >= d[1])
		{
			cumul -= d[1];
			p[0] += dir[0];
		}
		mlx_pixel_put(info.mlx, info.win, p[0] + 100, p[1] + 500, ft_degrade(p[2], p[5], &tmp, py));
		i++;
	}
}

void	ft_ligne(int *pos1, int *pos2, t_info info)
{
	int		d[2];
	int		dir[2];
	int		point[6];

	point[0]= pos1[0];
	point[1]= pos1[1];
	point[2]= pos1[2];
	point[3]= pos2[0];
	point[4]= pos2[1];
	point[5]= pos2[2];
	d[0] = pos2[0] - pos1[0];
	d[1] = pos2[1] - pos1[1];
	dir[0] = -1;
	dir[1] = -1;
	if (d[0] > 0)
		dir[0] = 1;
	if (d[1] > 0)
		dir[1] = 1;
	d[0] = abs(d[0]);
	d[1] = abs(d[1]);
	mlx_pixel_put(info.mlx, info.win, pos1[0] + 100, pos1[1] + 500, ft_col(point[2]));
	if (d[0] > d[1])
		trace_ligned(dir, point, d, info);
	else
		trace_ligneg(dir, point, d, info);
}

void	ft_dessine(t_liste *p1, t_liste *p2, t_info info)
{
	int		pos1[3];
	int		pos2[3];
	pos1[0] = p1->x;
	pos1[1] = p1->y;
	pos1[2] = 0;
	if (p1->c != 0)
		pos1[2] = p1->c;
	pos2[0] = p2->x;
	pos2[1] = p2->y;
	pos2[2] = 0;
	if (p2->c != 0)
		pos2[2] = p2->c;
	ft_ligne(pos1, pos2, info);
}


void	ft_boucle_draw(t_liste *p, t_map *m, t_info info)
{
	t_liste *p1;
	t_liste *p2;
	int		i;

	p1 = p;
	i = 0;
	while (p1)
	{
		p2 = p1;
		if (p1 && p1->next && p1->next->oy == p1->oy)
			ft_dessine(p1, p1->next, info);
		while (p2 && p2->next && i < m->total_x)
		{
			//printf("            On Boucle poy : %d - %d\n", p2->oy, m->total_x);
			p2 = p2->next;
			i++;
		}
		i = 0;
		if (p2 && p2->oy > p1->oy)
		{
			//printf("            On draw !!!");
			ft_dessine(p1, p2, info);
		}
		p1 = p1->next;
	}
}














