/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_sprite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 10:18:48 by mbaxmann          #+#    #+#             */
/*   Updated: 2020/08/25 17:57:40 by user42           ###   ########.fr       */
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
		temp->angle = hypot(((CUBE * temp->x) - data->player->x),
		((CUBE * temp->y) - data->player->y));
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
				ft_copy_data(sprite->data, current->data);
				ft_copy_data(current->data, &temp);
			}
			current = current->next;
		}
		sprite = sprite->next;
	}
}

int		ft_calculate_sp_angle(t_data *data, t_vector *pt)
{
	double angle;
	int	res;

	angle = acos(fabs((CUBE * pt->x) - data->player->x) / pt->angle);
	pt->dir_x = (CUBE * pt->x > data->player->x) ? 1: -1;
	pt->dir_y = (CUBE * pt->y > data->player->y) ? 1: -1;
	angle = (pt->dir_x == 1) ? angle : (M_PI - angle);
	angle = (pt->dir_y == -1) ? angle : (2 * M_PI - angle);
	pt->angle *= cos(data->player->angle - angle);
	angle = (M_PI / 3) - ((M_PI / 6) - (data->player->angle - angle));
	res = (int)round((angle / ((M_PI / 3) / data->res->x)));
	return (res);
}

void		ft_display_sprite(t_data *data, double *stock, t_vector *pt, int i)
{
	int	size;
	int	j;
	int	k;
	int	l;
	int	r;
	int	offset_1;
	int	offset_2;

	k = 0;
	r = 0;
	stock++;
	size = (int)floor(((double)CUBE * ((data->res->x / 2) / tan(M_PI / 6))) / pt->angle);
	i -= size / 2;
	j = (i < 0) ? 0 : i;
	offset_1 = 4 * (((data->res->y - size) / 2) * data->res->x + j);
	offset_2 = 0;
	j = 0;
	l = 0;
	if (size + i >= data->res->x)
		l = data->res->x - (i + size);
	r = (i < 0) ? i : 0;
	i = (i < 0) ? 0 : i;
	while (j < size)
	{
		offset_2 = data->texture[4]->width * 4 * (j * data->texture[4]->height / size);
		while (k < size + r + l && stock[i] > pt->angle)
		{
			offset_2 += 4 * (((k - r) *data->texture[4]->width) / size);
			*(unsigned int *)(data->img->pt + offset_1) =
			*(unsigned int *)(data->texture[4]->addr + offset_2);
			offset_1 += 4;
			offset_2 -= 4 * (((k - r) *data->texture[4]->width) / size);
			k++;
		}
		offset_1 += 4 * (data->res->x - k);
		k = 0;
		j++;
	}
}

int		ft_load_sprite(t_data *data, double *stock)
{
	t_list	*current;
	int	i;

	if (!stock)
		A
	if (!data->sprite->next)
		return (0);
	current = data->sprite->next;
	ft_calculate_sprite_dist(data, data->sprite);
	ft_sort_sprite(data->sprite);
	while (current)
	{
		i = ft_calculate_sp_angle(data, current->data);
		ft_display_sprite(data, stock, current->data, i);
		current = current->next;
	}
	ft_free_lst(data->sprite->next);
	data->sprite->next = NULL;
	free(stock);
	return (0);
}
