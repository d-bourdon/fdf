/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ligne.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 17:41:13 by dbourdon          #+#    #+#             */
/*   Updated: 2016/12/14 12:42:09 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	limite_win(int x, int y, t_info info)
{
	if (x > (info.winx - 1) || x < 0)
		return (0);
	if (y > (info.winy - 1) || y < 0)
		return (0);
	return (1);
}

void		trace_ligned(int *dir, int *p, int *d, t_info info)
{
	int		cumul;
	int		i;
	long	py;
	int		tmp[3];

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
		if (limite_win(p[0] + (info.winx / 2), p[1] + (info.winy / 2), info))
			info.img->data[((p[1] + (info.winy / 2)) * info.winy) + p[0] +
				(info.winx / 2)] = ft_degrade(p, tmp, py);
	}
}

void		trace_ligneg(int *dir, int *p, int *d, t_info info)
{
	int		cumul;
	int		i;
	int		py;
	int		tmp[3];

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
		if (limite_win(p[0] + (info.winx / 2), p[1] + (info.winy / 2), info))
			info.img->data[((p[1] + (info.winy / 2)) * info.winy) + p[0] +
				(info.winx / 2)] = ft_degrade(p, tmp, py);
	}
}

void		ft_ligne(int *p, t_info info)
{
	int		d[2];
	int		dir[2];

	d[0] = p[5] - p[0];
	d[1] = p[6] - p[1];
	dir[0] = -1;
	dir[1] = -1;
	if (d[0] > 0)
		dir[0] = 1;
	if (d[1] > 0)
		dir[1] = 1;
	d[0] = abs(d[0]);
	d[1] = abs(d[1]);
	if (limite_win(p[0] + (info.winx / 2), p[1] + (info.winy / 2), info))
		info.img->data[((p[1] + (info.winy / 2)) * info.winy) + p[0] +
			(info.winx / 2)] = rgbtoi(p[2], p[3], p[4]);
	if (d[0] > d[1])
		trace_ligned(dir, p, d, info);
	else
		trace_ligneg(dir, p, d, info);
}

void		ft_dessine(t_liste *p1, t_liste *p2, t_info info)
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
