/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_sprite_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 10:18:48 by mbaxmann          #+#    #+#             */
/*   Updated: 2020/08/29 17:18:37 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		ft_spritesize(t_data *data, t_vector *pt)
{
	int size;
	int size_max;

	size = (int)floor(((double)CUBE * ((data->res->x / 2) / tan(M_PI / 6))) / pt->dir_x);
	size_max = (int)floor(((double)CUBE * ((data->res->x / 2) / tan(M_PI / 6))) / (CUBE / 2));
	if (size > size_max)
		return (size_max);
	return (size);
}

int             ft_spritestocked(t_list *first, int i, int j)
{
        t_vector *tmp;

        while (first)
        {
                tmp = first->data;
                if (tmp->x - 0.5 == j && tmp->y - 0.5 == i)
                        return (1);
                first = first->next;
        }
        return (0);
}

void	ft_setup_spritedisp(t_data *data, int offset[2], int var[5])
{
	int height;

	height = (var[4] > data->res->y) ? data->res->y : var[4];
	var[1] = 0;
	var[2] = 0;
        var[3] -= (var[4] / 2);
        var[0] = (var[3] < 0) ? 0 : var[3];
        offset[0] = 4 * (((data->res->y - height) / 2) * data->res->x + var[0]);
        offset[1] = 0;
	var[0] = 0;
        if (data->res->y < var[4])
		var[0] = (var[4] - data->res->y) / 2;
        if (var[4] + var[3] >= data->res->x)
                var[2] = data->res->x - (var[3] + var[4]);
        var[1] = (var[3] < 0) ? var[1] - var[3] : var[1];
        var[3] = (var[3] < 0) ? 0 : var[3];
}

void	ft_spritedisp_loop(t_data *data, double *cmp[2], int offset[2], int var[5])
{
	int i;
	int j;

	i = var[1];
	j = 0;
	//printf("var[1]: %d	var[2]: %d	var[4]: %d\n", var[1], var[2], var[4]);
	while (i <= var[4] + var[2] && j < data->res->x)
	{
		offset[1] += 4 * ((i * data->texture[4]->width) / var[4]);
		if ((cmp[0][var[3]] > cmp[1][0]) &&
		*(unsigned int*)(data->texture[4]->addr + offset[1]))
		{
			*(unsigned int *)(data->img[0]->pt + offset[0]) =
			*(unsigned int *)(data->texture[4]->addr + offset[1]);
		}
		offset[0] += 4;
		offset[1] -= 4 * ((i * data->texture[4]->width) / var[4]);
		i++;
		j++;
		var[3]++;
	}
	var[3] -= j;
	offset[0] += 4 * (data->res->x - j);
}
