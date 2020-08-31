/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 09:27:20 by mbaxmann          #+#    #+#             */
/*   Updated: 2020/08/31 22:25:44 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#define CUBE 64
#define SPEED 16
#define R_SPEED 130

typedef struct	s_dim
{
	int			x;
	int			y;
}				t_dim;

typedef struct	s_vector
{
	double			x;
	double			y;
	int			dir_x;
	int			dir_y;
	double		angle;
}				t_vector;

typedef	struct	s_mlx
{
	void	*ptr;
	void	*win;
}				t_mlx;

#include "../mlx_linux/mlx.h"
#include "../libft/libft.h"
#include "ft_list.h"
#include "init.h"
#include "ft_event.h"
#include "ft_raycasting.h"
#include "ft_display.h"
#include "ft_load_sprite.h"
#include "ft_free_data.h"
#include "ft_loop.h"
#include "ft_save_img.h"
#include <fcntl.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

void	ft_valid_arg(int ac, char **av);
void	ft_open_window(t_mlx **mlx, t_data *data);
void	ft_error(t_data *data, char *err, int fd);
void	ft_error_2(char *err);

#endif
