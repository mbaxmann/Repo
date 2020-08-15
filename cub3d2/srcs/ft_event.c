/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 09:55:23 by mbaxmann          #+#    #+#             */
/*   Updated: 2020/08/15 10:59:29 by mbaxmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		ft_hitbox(t_player *player, t_data *data)
{
	int i;
	int j;
	int k;

	i = floor(player->y / CUBE);
	j = floor(player->x / CUBE);
	k = 0;
	while (data->map[k][0])
		k++;
	if (i < 0 || i >= k)
		return (1);
	if (j < 0 || j >= (int)ft_strlen(data->map[i]) ||
		data->map[i][j] == '1')
		return (1);
	return (0);
}

void	ft_move_player(t_data *data, int keycode)
{
	if (keycode == 13)
	{
		data->player->y -= 8 * sin(data->player->angle);
		data->player->x += 8 * cos(data->player->angle);
		if (ft_hitbox(data->player, data))
			ft_move_player(data, 1);
	}
	else if (keycode == 1)
	{
		data->player->y += 8 * sin(data->player->angle);
		data->player->x -= 8 * cos(data->player->angle);
		if (ft_hitbox(data->player, data))
			ft_move_player(data, 13);
	}
	else if (keycode == 0)
	{
		data->player->y -= sin(data->player->angle + M_PI_2) * 8;
		data->player->x += cos(data->player->angle + M_PI_2) * 8;
		if (ft_hitbox(data->player, data))
			ft_move_player(data, 2);
	}
	else if (keycode == 2)
	{
		data->player->y -= sin(data->player->angle - M_PI_2) * 8;
		data->player->x += cos(data->player->angle - M_PI_2) * 8;
		if (ft_hitbox(data->player, data))
			ft_move_player(data, 0);
	}
}

int		ft_button_event(int keycode, void *param)
{
	if (keycode == 53)
	{
		mlx_destroy_window(((t_data *)param)->mlx->ptr, ((t_data *)param)->mlx->win);
		exit(0);
	}
	if (keycode == 124)
		((t_data *)param)->player->angle -= M_PI / 80;
	if (keycode == 123)
		((t_data *)param)->player->angle += M_PI / 80;
	ft_move_player((t_data *)param, keycode);
	ft_modulo_pi(&((t_data *)param)->player->angle);
	ft_raycasting(param);
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
