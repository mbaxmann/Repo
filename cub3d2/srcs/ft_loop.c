/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 09:54:12 by mbaxmann          #+#    #+#             */
/*   Updated: 2020/08/29 18:26:24 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_loop(t_data *data)
{
	if (data->mov[0])
		ft_move_player(data, data->mov[1]);
	if (data->mov[2])
	{
		if (data->mov[3] == 65363)
			data->player->angle -= M_PI / R_SPEED;
		else
			data->player->angle += M_PI / R_SPEED;
		ft_modulo_pi(&data->player->angle);
	}
	ft_raycasting(data);
	return (0);
}
