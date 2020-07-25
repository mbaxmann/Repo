/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 10:34:49 by mbaxmann          #+#    #+#             */
/*   Updated: 2020/07/25 10:36:08 by mbaxmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int			ft_check_data(t_data *data)
{
	int i;

	i = 0;
	if (data->texture[0] && data->texture[1])
		i++;
	if (data->texture[2] && data->texture[3])
		i++;
	if (data->sprite)
		i++;
	if (data->ceil && data->floor)
		i++;
	if (data->res->x && data->res->y)
		i++;
	if (i == 5)
		return (1);
	else
		return (0);
}

int			ft_get_rgb(char *nb)
{
	int		r;
	int		g;
	int		b;

	r = 0;
	g = 0;
	b = 0;
	r = ft_atoi(nb);
	g = ft_atoi(nb + 4);
	b = ft_atoi(nb + 8);
	r = (r << 16) | (g << 8) | b;
	return (r);
}

void		ft_set_res(t_dim *dim, char *res)
{
	int i;

	i = 0;
	dim->x = ft_atoi(res);
	while (res[i] != ' ')
		i++;
	dim->y = ft_atoi(res + i);
}
