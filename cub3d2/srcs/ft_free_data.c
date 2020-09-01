/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 09:54:12 by mbaxmann          #+#    #+#             */
/*   Updated: 2020/09/01 12:03:46 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_cub3d.h"

void	ft_free_img(t_img **img)
{
	int i;

	i = 0;
	if (img)
	{
		while (i < 2)
		{
			if (img[i])
			{
				free(img[i]->img);
				free(img[i]);
			}
			i++;
		}
		free(img);
	}
}

void	ft_free_mlx(t_mlx *mlx)
{
	if (mlx)
	{
		if (mlx->ptr)
			free(mlx->ptr);
		if (mlx->win)
			free(mlx->win);
		free(mlx);
	}
}

void	ft_free_line(t_data *data, int fd)
{
	if (data->line)
	{
		free(data->line);
		if (fd)
		{
			while (get_next_line(fd, &(data->line)))
				free(data->line);
			free(data->line);
		}
	}
}

void	ft_free_data(t_data *data, int fd)
{
	if (data)
	{
		ft_free_line(data, fd);
		ft_free_map(data->map);
		ft_free_texture(data->texture);
		if (data->res)
			free(data->res);
		if (data->player)
			free(data->player);
		if (data->stock)
			free(data->stock);
		ft_free_img(data->img);
		ft_free_mlx(data->mlx);
		if (data->sprite)
			ft_free_lst(data->sprite);
		free(data);
	}
}
