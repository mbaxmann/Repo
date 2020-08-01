/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 09:55:23 by mbaxmann          #+#    #+#             */
/*   Updated: 2020/08/01 10:10:33 by mbaxmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		ft_button_event(int keycode, void *param)
{
	if (keycode == 53)
	{
		mlx_destroy_window(((t_mlx *)param)->ptr, ((t_mlx *)param)->win);
		exit(0);
	}
	return (1);
}

int		ft_close(void *param)
{
	mlx_destroy_window(((t_mlx *)param)->ptr, ((t_mlx *)param)->win);
	exit(0);
	return (1);
}

void	ft_event(t_mlx *mlx)
{
	mlx_hook(mlx->win, 2, 1L << 0, &ft_button_event, mlx);
	mlx_hook(mlx->win, 17, 1L << 17, &ft_close, mlx);
}
