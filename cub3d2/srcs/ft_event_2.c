/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 09:23:59 by mbaxmann          #+#    #+#             */
/*   Updated: 2020/08/24 16:08:17 by user42           ###   ########.fr       */
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

void	ft_move_part_1(t_data *data, int keycode)
{
	if (keycode == 122)
	{
		data->player->y -= 8 * sin(data->player->angle);
		data->player->x += 8 * cos(data->player->angle);
		if (ft_hitbox(data->player, data))
			ft_move_player(data, 115);
	}
	else if (keycode == 115)
	{
		data->player->y += 8 * sin(data->player->angle);
		data->player->x -= 8 * cos(data->player->angle);
		if (ft_hitbox(data->player, data))
			ft_move_player(data, 122);
	}
}

void	ft_move_part_2(t_data *data, int keycode)
{
	if (keycode == 113)
	{
		data->player->y -= sin(data->player->angle + M_PI_2) * 8;
		data->player->x += cos(data->player->angle + M_PI_2) * 8;
		if (ft_hitbox(data->player, data))
			ft_move_player(data, 100);
	}
	else if (keycode == 100)
	{
		data->player->y -= sin(data->player->angle - M_PI_2) * 8;
		data->player->x += cos(data->player->angle - M_PI_2) * 8;
		if (ft_hitbox(data->player, data))
			ft_move_player(data, 113);
	}
}
