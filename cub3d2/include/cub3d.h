/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 09:27:20 by mbaxmann          #+#    #+#             */
/*   Updated: 2020/07/30 09:56:44 by mbaxmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#define t_dim t_coord
#define A write(1, "A", 1);
#define B write(1, "B", 1);

typedef struct	s_dim
{
	int			x;
	int			y;
}				t_dim;

typedef	struct	s_mlx
{
	void	*ptr;
	void	*win;
}				t_mlx;

#include "../mlx/mlx.h"
#include "../libft/libft.h"
#include "ft_list.h"
#include "init.h"
#include <fcntl.h>
#include <stdio.h>

#endif
