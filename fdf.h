/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 14:18:27 by dbourdon          #+#    #+#             */
/*   Updated: 2016/10/06 15:26:20 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "mlx/mlx.h"
# include "mlx/mlx_int.h"
# include "mlx_new_windows.h"
# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct		s_list
{
	int				x;
	int				y;
	int				z;
	struct s_list	*next;
}					t_list;

typedef struct		s_map
{
	int				total_x;
	int				total_y;
}					t_map;


#endif
