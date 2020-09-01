/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 09:27:20 by mbaxmann          #+#    #+#             */
/*   Updated: 2020/09/01 12:34:20 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define UP 122
# define DOWN 115
# define RIGHT 100
# define LEFT 113
# define T_RIGHT 65361
# define T_LEFT 65363
# define ESC 65307

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include "ft_list.h"
# include "ft_init.h"
# include "ft_event.h"
# include "ft_raycasting.h"
# include "ft_display.h"
# include "ft_load_sprite.h"
# include "ft_free_data.h"
# include "ft_loop.h"
# include "ft_save_img.h"
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include <time.h>
# include <stdio.h>

void			ft_valid_arg(int ac, char **av);
void			ft_open_window(t_mlx **mlx, t_data *data);
void			ft_error(t_data *data, char *err, int fd);
void			ft_error_2(char *err);

#endif
