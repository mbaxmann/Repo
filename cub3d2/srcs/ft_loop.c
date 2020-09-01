/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 09:54:12 by mbaxmann          #+#    #+#             */
/*   Updated: 2020/09/01 12:05:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_cub3d.h"

int	ft_loop(t_data *data)
{
	if (data->mov[0])
		ft_move_player(data, data->mov[1]);
	if (data->mov[4])
		ft_move_player(data, data->mov[5]);
	if (data->mov[2])
	{
		if (data->mov[3] == T_LEFT)
			data->player->angle -= M_PI / R_SPEED;
		else
			data->player->angle += M_PI / R_SPEED;
		ft_modulo_pi(&data->player->angle);
	}
	ft_raycasting(data);
	mlx_put_image_to_window(data->mlx->ptr,
	data->mlx->win, data->img[0]->img, 0, 0);
	ft_swp_img(data);
	return (0);
}
