/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 09:23:59 by mbaxmann          #+#    #+#             */
/*   Updated: 2020/09/01 12:03:20 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_cub3d.h"

void	ft_sethitbox(int hitbox[8])
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
		pos[1] = floor((player->x + hitbox[n + 1]) / CUBE);
		while (data->map[k][0])
			k++;
		if (pos[0] < 0 || pos[0] >= k)
			return (1);
		if (pos[1] < 0 || pos[1] >= (int)ft_strlen(data->map[pos[0]]) ||
		data->map[pos[0]][pos[1]] == '1')
			return (1);
		n += 2;
	}
	return (0);
}

void	ft_move_part_1(t_data *data, int keycode)
{
	if (keycode == UP)
	{
		data->player->y -= SPEED * sin(data->player->angle);
		data->player->x += SPEED * cos(data->player->angle);
		if (ft_hitbox(data->player, data))
			ft_move_player(data, DOWN);
	}
	else if (keycode == DOWN)
	{
		data->player->y += SPEED * sin(data->player->angle);
		data->player->x -= SPEED * cos(data->player->angle);
		if (ft_hitbox(data->player, data))
			ft_move_player(data, UP);
	}
}

void	ft_move_part_2(t_data *data, int keycode)
{
	if (keycode == LEFT)
	{
		data->player->y -= sin(data->player->angle + M_PI_2) * SPEED;
		data->player->x += cos(data->player->angle + M_PI_2) * SPEED;
		if (ft_hitbox(data->player, data))
			ft_move_player(data, RIGHT);
	}
	else if (keycode == RIGHT)
	{
		data->player->y -= sin(data->player->angle - M_PI_2) * SPEED;
		data->player->x += cos(data->player->angle - M_PI_2) * SPEED;
		if (ft_hitbox(data->player, data))
			ft_move_player(data, LEFT);
	}
}
