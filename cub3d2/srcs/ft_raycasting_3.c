/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 09:53:56 by mbaxmann          #+#    #+#             */
/*   Updated: 2020/08/15 10:05:35 by mbaxmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void		ft_spot_player(t_data *data, int i, int j)
{
	if (data->map[i][j] == 'N' || data->map[i][j] == 'S' ||
		data->map[i][j] == 'E' || data->map[i][j] == 'W')
	{
		data->player->x = (j + 0.5) * CUBE;
		data->player->y = (i + 0.5) * CUBE;
	}
}

void		ft_init_pt_mode_0(t_vector *pt, double alpha, t_data *data)
{
	if (pt->dir_y == 1)
		pt->y = (floor(data->player->y / CUBE) * CUBE) + CUBE;
	else
		pt->y = (floor(data->player->y / CUBE) * CUBE) - 1;
	if (pt->dir_x == 1)
	{
		pt->x = data->player->x +
		(fabs(data->player->y - pt->y) / tan(alpha));
	}
	else
	{
		pt->x = data->player->x -
		(fabs(data->player->y - pt->y) / tan(alpha));
	}
}

void		ft_init_pt_mode_1(t_vector *pt, double alpha, t_data *data)
{
	if (pt->dir_x == 1)
		pt->x = (floor(data->player->x / CUBE) * CUBE) + CUBE;
	else
		pt->x = (floor(data->player->x / CUBE) * CUBE) - 1;
	if (pt->dir_y == 1)
	{
		pt->y = data->player->y +
		(fabs(data->player->x - pt->x) * tan(alpha));
	}
	else
	{
		pt->y = data->player->y -
		(fabs(data->player->x - pt->x) * tan(alpha));
	}
}
