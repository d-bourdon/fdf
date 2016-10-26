/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ligne.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 17:41:13 by dbourdon          #+#    #+#             */
/*   Updated: 2016/10/26 16:33:02 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	trace_ligned(int *dir, int *p, int *d, t_info info)
{
	int		cumul;
	int		i;

	cumul = d[0] / 2;
	i = 1;
	while (i <= d[0])
	{
		p[0] += dir[0];
		cumul += d[1];
		if (cumul >= d[0])
		{
			cumul -= d[0];
			p[1] += dir[1];
		}
		mlx_pixel_put(info.mlx, info.win, p[0], p[1], ft_col(p[2]));
		i++;
	}
}

void	trace_ligneg(int *dir, int *p, int *d, t_info info)
{
	int		cumul;
	int		i;

	cumul = d[1] / 2;
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
		mlx_pixel_put(info.mlx, info.win, p[0], p[1], ft_col(p[2]));
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
	mlx_pixel_put(info.mlx, info.win, pos1[0], pos1[1], ft_col(point[2]));
	if (d[0] > d[1])
		trace_ligned(dir, point, d, info);
	else
		trace_ligneg(dir, point, d, info);
}