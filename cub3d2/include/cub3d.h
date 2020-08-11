/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 09:27:20 by mbaxmann          #+#    #+#             */
/*   Updated: 2020/08/11 09:56:19 by mbaxmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#define A write(1, "A", 1);
#define B write(1, "B", 1);
#define CUBE_SIZE 32

typedef struct	s_dim
{
	int			x;
	int			y;
}				t_dim;

typedef struct	s_vector
{
	int			x;
	int			y;
	int			dir_x;
	int			dir_y;
	double		angle;
}				t_vector;

typedef	struct	s_mlx
{
	void	*ptr;
	void	*win;
}				t_mlx;

#include "../mlx/mlx.h"
#include "../libft/libft.h"
#include "ft_list.h"
#include "init.h"
#include "ft_event.h"
#include "ft_raycasting.h"
#include "ft_display.h"
#include <fcntl.h>
#include <stdio.h>
#include <math.h>

#endif
