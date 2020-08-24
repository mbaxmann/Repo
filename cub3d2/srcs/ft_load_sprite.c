/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_sprite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 10:18:48 by mbaxmann          #+#    #+#             */
/*   Updated: 2020/08/24 17:21:05 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void		ft_calculate_sprite_dist(t_data *data, t_list *sprite)
{
	double dist;
	t_list *current;
	t_vector *temp;

	dist = 0;
	current = sprite;
	while (current->next)
	{
		current = current->next;
		temp = current->data;
		temp->angle = hypot((temp->x - data->player->x), (temp->y - data->player->y));
	}
}

void		ft_copy_data(t_vector *dest, t_vector *second)
{
	dest->x = second->x;
	dest->y = second->y;
	dest->angle = second->angle;
}

void		ft_sort_sprite(t_list *sprite)
{
	t_vector temp;
	t_list *current;

	sprite = sprite->next;
	while (sprite)
	{
		current = sprite->next;
		while (current)
		{
			if (((t_vector *)current->data)->angle > ((t_vector *)sprite->data)->angle)
			{
				ft_copy_data(&temp, sprite->data);
				ft_copy_data(sprite->data, current->next->data);
				ft_copy_data(current->next->data, &temp);
			}
			current = current->next;
		}
		sprite = sprite->next;
	}
}

int		ft_load_sprite(t_data *data, double *stock)
{
	if (!stock)
		A
	if (!data->sprite->next)
		return (0);
	ft_calculate_sprite_dist(data, data->sprite);
	ft_sort_sprite(data->sprite);
	return (0);
}
