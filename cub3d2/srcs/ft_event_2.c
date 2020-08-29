/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 09:23:59 by mbaxmann          #+#    #+#             */
/*   Updated: 2020/08/29 18:25:59 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void		ft_sethitbox(int hitbox[8])
{
	hitbox[0] = CUBE / 4;
	hitbox[1] = CUBE / 4;
	hitbox[2] = -CUBE / 4;
	hitbox[3] = -CUBE / 4;
	hitbox[4] = -CUBE / 4;
	hitbox[5] = CUBE / 4;
	hitbox[6] = CUBE / 4;
	hitbox[7] = -CUBE / 4;
}

int		ft_hitbox(t_player *player, t_data *data)
{
	int pos[2];
	int hitbox[8];
	int k;
	int n;

	ft_sethitbox(hitbox);
	k = 0;
	n = 0;
	while (n < 8)
	{
		pos[0] = floor((player->y + hitbox[n]) / CUBE);
        	pos[1] = floor((player->x + hitbox[n + 1])/ CUBE);
		while (data->map[k][0])
			k++;
		if (pos[0] < 0 || pos[0] >= k)
			return (1);
		if (pos[1] < 0 || pos[1] >= (int)ft_strlen(data->map[pos[0]]) ||
		data->map[pos[0]][pos[1]] == '1' || data->map[pos[0]][pos[1]] == '2')
			return (1);
		n += 2;
	}
	return (0);
}

void	ft_move_part_1(t_data *data, int keycode)
{
	if (keycode == 122)
	{
		data->player->y -= SPEED * sin(data->player->angle);
		data->player->x += SPEED * cos(data->player->angle);
		if (ft_hitbox(data->player, data))
			ft_move_player(data, 115);
	}
	else if (keycode == 115)
	{
		data->player->y += SPEED * sin(data->player->angle);
		data->player->x -= SPEED * cos(data->player->angle);
		if (ft_hitbox(data->player, data))
			ft_move_player(data, 122);
	}
}

void	ft_move_part_2(t_data *data, int keycode)
{
	if (keycode == 113)
	{
		data->player->y -= sin(data->player->angle + M_PI_2) * SPEED;
		data->player->x += cos(data->player->angle + M_PI_2) * SPEED;
		if (ft_hitbox(data->player, data))
			ft_move_player(data, 100);
	}
	else if (keycode == 100)
	{
		data->player->y -= sin(data->player->angle - M_PI_2) * SPEED;
		data->player->x += cos(data->player->angle - M_PI_2) * SPEED;
		if (ft_hitbox(data->player, data))
			ft_move_player(data, 113);
	}
}
