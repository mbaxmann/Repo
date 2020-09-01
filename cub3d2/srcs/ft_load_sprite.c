/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_sprite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 10:18:48 by mbaxmann          #+#    #+#             */
/*   Updated: 2020/09/01 12:05:00 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_cub3d.h"

double		ft_calsp_angle_2(t_data *data, t_vector *pt, double angle)
{
	if (pt->dir_x == -1)
		angle = (M_PI / 3) - ((M_PI / 6) - (data->player->angle - angle));
	else
	{
		if (data->player->angle < M_PI && angle > M_PI)
		{
			angle -= 2 * M_PI;
			angle = (M_PI / 3) - ((M_PI / 6) - (data->player->angle - angle));
		}
		else if (data->player->angle > M_PI && angle < M_PI)
		{
			angle += 2 * M_PI;
			angle = (M_PI / 3) - ((M_PI / 6) - (data->player->angle - angle));
		}
		else
			angle = (M_PI / 3) - ((M_PI / 6) - (data->player->angle - angle));
	}
	return (angle);
}

int			ft_calculate_sp_angle(t_data *data, t_vector *pt)
{
	double	angle;
	int		res;

	angle = acos(fabs((CUBE * pt->x) - data->player->x) / pt->angle);
	pt->dir_x = (CUBE * pt->x > data->player->x) ? 1 : -1;
	pt->dir_y = (CUBE * pt->y > data->player->y) ? 1 : -1;
	angle = (pt->dir_x == 1) ? angle : (M_PI - angle);
	angle = (pt->dir_y == -1) ? angle : (2 * M_PI - angle);
	pt->angle *= cos(data->player->angle - angle);
	angle = ft_calsp_angle_2(data, pt, angle);
	pt->dir_x = (int)round(pt->angle);
	res = (int)round((angle / ((M_PI / 3) / data->res->x)));
	return (res);
}

void		ft_display_sprite(t_data *data, double *stock, t_vector *pt, int i)
{
	int		var[5];
	int		offset[2];
	int		j;
	double	*cmp[2];

	j = 0;
	var[3] = i;
	var[4] = ft_spritesize(data, pt);
	ft_setup_spritedisp(data, offset, var);
	cmp[0] = stock;
	cmp[1] = &(pt->angle);
	while (var[0] + j < var[4] && j < data->res->y)
	{
		offset[1] = data->texture[4]->width * 4 *
		((var[0] + j) * data->texture[4]->height / var[4]);
		ft_sprite_loop(data, cmp, offset, var);
		j++;
	}
}

int			ft_load_sprite(t_data *data, double *stock)
{
	t_list	*current;
	int		i;

	if (!data->sprite)
		return (0);
	current = data->sprite;
	ft_calculate_sprite_dist(data, data->sprite);
	ft_sort_sprite(data->sprite);
	while (current)
	{
		i = ft_calculate_sp_angle(data, current->data);
		ft_display_sprite(data, stock, current->data, i);
		current = current->next;
	}
	ft_free_lst(data->sprite);
	data->sprite = NULL;
	free(stock);
	return (0);
}
