/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 09:54:12 by mbaxmann          #+#    #+#             */
/*   Updated: 2020/09/05 18:24:54 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_cub3d.h"

void	ft_del_space(char **map)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (map[i][0])
	{
		while (map[i][j])
		{
			if (map[i][j] == ' ')
			{
				k = ft_strlen(&map[i][j + 1]) + 1;
				ft_memmove(&map[i][j], &map[i][j + 1], k);
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	ft_check_line(t_data *data, int fd)
{
	int i;

	i = 0;
	while (data->line[i])
	{
		if (data->line[i] != '0' && data->line[i] != '1'
		&& data->line[i] != '2' && data->line[i] != ' ')
			ft_error(data, "cor_file", fd);
		i++;
	}
	if (data->line[0] == ' ')
		ft_error(data, "map", fd);
}

int		ft_loop(t_data *data)
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
