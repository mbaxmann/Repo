/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 09:55:23 by mbaxmann          #+#    #+#             */
/*   Updated: 2020/08/27 16:37:35 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_move_player(t_data *data, int keycode)
{
	ft_move_part_1(data, keycode);
	ft_move_part_2(data, keycode);
}

int		ft_button_event(int keycode, void *param)
{
	if (keycode == 65307)
	{
		ft_free_data((t_data *)param);
		exit(0);
	}
	if (keycode == 65363)
		((t_data *)param)->player->angle -= M_PI / 80;
	if (keycode == 65361)
		((t_data *)param)->player->angle += M_PI / 80;
	ft_move_player((t_data *)param, keycode);
	ft_modulo_pi(&((t_data *)param)->player->angle);
	ft_raycasting(param);
	return (1);
}

int		ft_close(void *param)
{
	ft_free_data((t_data *)param);
	exit(0);
	return (1);
}

void	ft_event(t_data *data)
{
	mlx_hook(data->mlx->win, 2, 1L << 0, &ft_button_event, data);
	mlx_hook(data->mlx->win, 17, 1L << 17, &ft_close, data);
}
