/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_sprite_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 10:18:48 by mbaxmann          #+#    #+#             */
/*   Updated: 2020/09/01 12:04:48 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_cub3d.h"

void		ft_calculate_sprite_dist(t_data *data, t_list *sprite)
{
	double		dist;
	t_list		*current;
	t_vector	*temp;

	dist = 0;
	current = sprite;
	while (current)
	{
		temp = current->data;
		temp->angle = hypot(((CUBE * temp->x) - data->player->x),
		((CUBE * temp->y) - data->player->y));
		current = current->next;
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
	t_vector	temp;
	t_list		*current;

	while (sprite)
	{
		current = sprite->next;
		while (current)
		{
			if (((t_vector *)current->data)->angle >
			((t_vector *)sprite->data)->angle)
			{
				ft_copy_data(&temp, sprite->data);
				ft_copy_data(sprite->data, current->data);
				ft_copy_data(current->data, &temp);
			}
			current = current->next;
		}
		sprite = sprite->next;
	}
}
