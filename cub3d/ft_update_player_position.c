/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_player_position.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 13:33:09 by mbaxmann          #+#    #+#             */
/*   Updated: 2020/03/09 15:50:04 by mbaxmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_check_wall_collision(t_position *player, char **map, int keycode, t_data *data)
{
	while (!ft_isok(player, map, (data->player->angle - (M_PI / 6)), 2))
	{
		if (keycode == 13)
		{
			player->y += 8 * sin(player->angle);
			player->x -= 8 * cos(player->angle);
		}
		else if (keycode == 1)
		{
			player->y -= 8 * sin(player->angle);
			player->x += 8 * cos(player->angle);
		}
		else if (keycode == 0)
		{
			player->y += 8 * sin(player->angle + M_PI_2);
			player->x -= 8 * cos(player->angle + M_PI_2);
		}
		else if (keycode == 2)
		{
			player->y += 8 * sin(player->angle - M_PI_2);
			player->x -= 8 * cos(player->angle - M_PI_2);
		}
	}
}

void	ft_update_player_position(t_position *player, int keycode, char **map, t_data *data)
{
	player->angle = ft_modulo_pi(player->angle);
	if (keycode == 13)
	{
		player->y -= sin(player->angle) * 8;
		player->x += cos(player->angle) * 8;
	}
	else if (keycode == 1)
	{
		player->y += sin(player->angle) * 8;
		player->x -= cos(player->angle) * 8;
	}
	else if (keycode == 0)
	{
		player->y -= sin(player->angle + M_PI_2) * 8;
		player->x += cos(player->angle + M_PI_2) * 8;
	}
	else if (keycode == 2)
	{
		player->y -= sin(player->angle - M_PI_2) * 8;
		player->x += cos(player->angle - M_PI_2) * 8;
	}
	ft_check_wall_collision(player, map, keycode, data);
}
