/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 09:55:23 by mbaxmann          #+#    #+#             */
/*   Updated: 2020/08/29 18:19:09 by user42           ###   ########.fr       */
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
	else if (keycode == 65363 || keycode == 65361)
	{
		((t_data *)param)->mov[2] = 1;
		((t_data *)param)->mov[3] = keycode;
	}
	else if (keycode == 122 || keycode == 115
	|| keycode == 113 || keycode == 100)
        {
                ((t_data *)param)->mov[0] = 1;
                ((t_data *)param)->mov[1] = keycode;
        }
	return (1);
}

int             ft_button_event_2(int keycode, void *param)
{
        if (keycode == 65363 || keycode == 65361)
                ((t_data *)param)->mov[2] = 0;
        else if (keycode == 122 || keycode == 115
        || keycode == 113 || keycode == 100)
                ((t_data *)param)->mov[0] = 0;
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
	mlx_hook(data->mlx->win, 3, 1L << 1, &ft_button_event_2, data);
	mlx_hook(data->mlx->win, 17, 1L << 17, &ft_close, data);
}
