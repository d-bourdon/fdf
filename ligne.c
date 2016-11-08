/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ligne.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 17:41:13 by dbourdon          #+#    #+#             */
/*   Updated: 2016/11/08 11:50:49 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	trace_ligned(int *dir, int *p, int *d, t_info info)
{
	int		cumul;
	int		i;
	int		py;
	int		tmp[3];
	int		*tmp2;

	tmp[0] = p[2];
	tmp[1] = p[3];
	tmp[2] = p[4];
	py = sqrt(pow(abs(p[0] - p[5]), 2) + pow(abs(p[1] - p[6]), 2));
	cumul = d[0] / 2;
	i = 1;
	while (i++ <= d[0])
	{
		p[0] += dir[0];
		cumul += d[1];
		if (cumul >= d[0])
		{
			cumul -= d[0];
			p[1] += dir[1];
		}
		tmp2 = tmp;
		//mlx_pixel_put(info.mlx, info.win, p[0] + 100, p[1] + 500,
		info.data[((p[1] + 500) * 850) + p[0] + 100] = (ft_degrade(p, tmp, py));
		printf("%d, %d, %d\n", p[0],p[1], ((p[1] + 500) * 850) + p[0] + 100);
	}
}

void	trace_ligneg(int *dir, int *p, int *d, t_info info)
{
	int		cumul;
	int		i;
	int		py;
	int		tmp[3];
	int		*tmp2;

	tmp[0] = p[2];
	tmp[1] = p[3];
	tmp[2] = p[4];
	py = sqrt(pow(abs(p[0] - p[5]), 2) + pow(abs(p[1] - p[6]), 2));
	cumul = d[1] / 2;
	i = 1;
	while (i++ <= d[1])
	{
		p[1] += dir[1];
		cumul += d[0];
		if (cumul >= d[1])
		{
			cumul -= d[1];
			p[0] += dir[0];
		}
		tmp2 = tmp;
		//mlx_pixel_put(info.mlx, info.win, p[0] + 100, p[1] + 500,
		info.data[((p[1] + 500) * 850) + p[0] + 100] = ft_degrade(p, tmp, py);
		printf("%d, %d, %d\n", p[0],p[1], ((p[1] + 500) * 850) + p[0] + 100);
	}
}

void	ft_ligne(int *point, t_info info)
{
	int		d[2];
	int		dir[2];

	d[0] = point[5] - point[0];
	d[1] = point[6] - point[1];
	dir[0] = -1;
	dir[1] = -1;
	if (d[0] > 0)
		dir[0] = 1;
	if (d[1] > 0)
		dir[1] = 1;
	d[0] = abs(d[0]);
	d[1] = abs(d[1]);
	//mlx_pixel_put(info.mlx, info.win, point[0] + 100, point[1] + 500,
	info.data[((point[1] + 500) * 850) + point[0] + 100] = rgbtoi(point[2], point[3], point[4]);
	if (d[0] > d[1])
		trace_ligned(dir, point, d, info);
	else
		trace_ligneg(dir, point, d, info);
}

void	ft_dessine(t_liste *p1, t_liste *p2, t_info info)
{
	int		point[10];

	point[0] = p1->x;
	point[1] = p1->y;
	point[2] = p1->c[0];
	point[3] = p1->c[1];
	point[4] = p1->c[2];
	point[5] = p2->x;
	point[6] = p2->y;
	point[7] = p2->c[0];
	point[8] = p2->c[1];
	point[9] = p2->c[2];
	ft_ligne(point, info);
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
			p2 = p2->next;
			i++;
		}
		i = 0;
		if (p2 && p2->oy > p1->oy)
			ft_dessine(p1, p2, info);
		p1 = p1->next;
	}
}
