/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 09:55:23 by mbaxmann          #+#    #+#             */
/*   Updated: 2020/08/14 09:18:18 by mbaxmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		ft_button_event(int keycode, void *param)
{
	if (keycode == 53)
	{
		mlx_destroy_window(((t_data *)param)->mlx->ptr, ((t_data *)param)->mlx->win);
		exit(0);
	}
	if (keycode == 124)
		((t_data *)param)->player->angle -= M_PI / 120;
	if (keycode == 123)
		((t_data *)param)->player->angle += M_PI / 120;
	ft_modulo_pi(&((t_data *)param)->player->angle);
	ft_raycasting(param, ((t_data *)param)->mlx);
	return (1);
}

int		ft_close(void *param)
{
	mlx_destroy_window(((t_data *)param)->mlx->ptr, ((t_data *)param)->mlx->win);
	exit(0);
	return (1);
}

void	ft_event(t_data *data)
{
	mlx_hook(data->mlx->win, 2, 1L << 0, &ft_button_event, data);
	mlx_hook(data->mlx->win, 17, 1L << 17, &ft_close, data);
}
