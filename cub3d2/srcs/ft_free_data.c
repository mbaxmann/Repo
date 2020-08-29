/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 09:54:12 by mbaxmann          #+#    #+#             */
/*   Updated: 2020/08/29 18:42:54 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void            ft_free_map(char **map)
{
	int i;

	i = 0;
	if (map)
	{
		while (map[i][0])
			free(map[i++]);
			free(map[i]);
			free(map);
	}
}

void		ft_free_texture(t_textur **texture)
{
	int i;

	i = 0;
	if (texture)
	{
		while (i < 5)
		{
			free(texture[i]->img);
			free(texture[i]);
			i++;
		}
		free(texture);
	}
}

void		ft_free_img(t_img **img)
{
	int i;

	i = 0;
	while (i < 2)
	{
		free(img[i]->img);
		free(img[i]);
		i++;
	}
	free(img);
}

void		ft_free_mlx(t_mlx *mlx)
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

void            ft_free_data(t_data *data)
{
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
