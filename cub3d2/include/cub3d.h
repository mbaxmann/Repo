/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 09:27:20 by mbaxmann          #+#    #+#             */
/*   Updated: 2020/07/14 10:15:45 by mbaxmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#define t_dim t_coord

typedef struct	s_dim
{
	int			x;
	int			y;
}				t_dim;

#include "init.h"
#include "../mlx/mlx.h"
#include "../libft/libft.h"
#include <fcntl.h>
#include <stdio.h>

#endif
