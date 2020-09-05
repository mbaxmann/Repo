/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 09:55:23 by mbaxmann          #+#    #+#             */
/*   Updated: 2020/09/05 14:27:03 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_cub3d.h"

void	ft_move_player(t_data *data, int keycode)
{
	ft_move_part_1(data, keycode);
	ft_move_part_2(data, keycode);
}

int		ft_button_event(int keycode, void *param)
{
	if (keycode == ESC)
	{
		ft_free_data((t_data *)param, 0);
		exit(0);
	}
	else if (keycode == T_LEFT || keycode == T_RIGHT)
	{
		((t_data *)param)->mov[2] = 1;
		((t_data *)param)->mov[3] = keycode;
	}
	else if (keycode == UP || keycode == DOWN)
	{
		((t_data *)param)->mov[0] = 1;
		((t_data *)param)->mov[1] = keycode;
	}
	else if (keycode == LEFT || keycode == RIGHT)
	{
		((t_data *)param)->mov[4] = 1;
		((t_data *)param)->mov[5] = keycode;
	}
	return (1);
}

int		ft_button_event_2(int keycode, void *param)
{
	if (keycode == T_LEFT || keycode == T_RIGHT)
		((t_data *)param)->mov[2] = 0;
	else if (keycode == UP || keycode == DOWN)
		((t_data *)param)->mov[0] = 0;
	else if (keycode == LEFT || keycode == RIGHT)
		((t_data *)param)->mov[4] = 0;
	return (1);
}

int		ft_close(void *param)
{
	ft_free_data((t_data *)param, 0);
	exit(0);
	return (1);
}

void	ft_event(t_data *data)
{
	mlx_hook(data->mlx->win, 2, 1L << 0, &ft_button_event, data);
	mlx_hook(data->mlx->win, 3, 1L << 1, &ft_button_event_2, data);
	mlx_hook(data->mlx->win, 17, 1L << 17, &ft_close, data);
}
