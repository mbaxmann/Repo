/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 09:17:33 by mbaxmann          #+#    #+#             */
/*   Updated: 2020/09/05 12:15:54 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_cub3d.h"

void		ft_init_data(t_data *data)
{
	data->map = NULL;
	data->sprite = NULL;
	data->texture = (t_textur **)malloc(sizeof(t_textur *) * 5);
	if (!data->texture)
		ft_error(data, "malloc", 0);
	data->texture[0] = NULL;
	data->texture[1] = NULL;
	data->texture[2] = NULL;
	data->texture[3] = NULL;
	data->texture[4] = NULL;
	data->stock = (t_player *)malloc(sizeof(t_player));
	if (!data->stock)
		ft_error(data, "malloc", 0);
	data->floor = -1;
	data->ceil = -1;
	ft_id_2(data);
}

void		ft_id_2(t_data *data)
{
	data->res = (t_dim *)malloc(sizeof(t_dim));
	if (!data->res)
		ft_error(data, "malloc", 0);
	data->res->x = 0;
	data->res->y = 0;
	data->player = NULL;
	data->img = (t_img **)malloc(sizeof(t_img *) * 2);
	if (!data->img)
		ft_error(data, "malloc", 0);
	data->img[0] = NULL;
	data->img[1] = NULL;
	data->mlx = NULL;
	data->mov[0] = 0;
	data->mov[2] = 0;
	data->mov[4] = 0;
	data->line = NULL;
}

void		ft_get_map3(t_data *data, int fd, t_list *first)
{
	while (get_next_line(fd, &(data->line)))
	{
		if (ft_strncmp(data->line, "", 1))
		{
			ft_free_lst(first);
			ft_error(data, "split", fd);
		}
		free(data->line);
	}
}
