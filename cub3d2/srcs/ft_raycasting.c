/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 10:18:48 by mbaxmann          #+#    #+#             */
/*   Updated: 2020/09/05 12:11:14 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_cub3d.h"

int		ft_calc_sl(t_data *data, t_vector *pt_1, t_vector *pt_2, double *stock)
{
	double	size_1;
	double	size_2;
	double	res;

	size_1 = hypot((pt_1->x - data->player->x), (pt_1->y - data->player->y));
	size_2 = hypot((pt_2->x - data->player->x), (pt_2->y - data->player->y));
	if (size_1 <= size_2)
	{
		size_1 *= cos(data->player->angle - pt_1->angle);
		res = ((double)CUBE * ((data->res->x / 2) / tan(M_PI / 6))) / size_1;
		data->stock->x = 0;
		data->stock->y = pt_1->y;
		*stock = size_1;
	}
	else
	{
		size_2 *= cos(data->player->angle - pt_2->angle);
		res = ((double)CUBE * ((data->res->x / 2) / tan(M_PI / 6))) / size_2;
		data->stock->x = pt_2->x;
		data->stock->y = 0;
		*stock = size_2;
	}
	data->stock->angle = pt_1->angle;
	return ((int)floor(res));
}

int		ft_calculate_ray(t_data *data, double alpha, double *stock)
{
	t_vector	*pt_1;
	t_vector	*pt_2;
	int			size;

	ft_in_vec(&pt_1, &pt_2, alpha, data);
	ft_set_angle(&alpha, pt_1, pt_2);
	ft_init_pt(pt_1, alpha, data, 1);
	ft_init_pt(pt_2, alpha, data, 0);
	while (!ft_iswall(pt_1, data))
	{
		pt_1->x += CUBE * pt_1->dir_x;
		pt_1->y += (CUBE * tan(alpha)) * pt_1->dir_y;
	}
	while (!ft_iswall(pt_2, data))
	{
		pt_2->x += (CUBE / tan(alpha)) * pt_2->dir_x;
		pt_2->y += CUBE * pt_2->dir_y;
	}
	size = ft_calc_sl(data, pt_1, pt_2, stock);
	free(pt_1);
	free(pt_2);
	return (size);
}

void	ft_modulo_pi(double *angle)
{
	while ((*angle) >= 2 * M_PI)
		(*angle) -= 2 * M_PI;
	while ((*angle) < 0)
		(*angle) += 2 * M_PI;
}

void	ft_swp_img(t_data *data)
{
	t_img *tmp;

	tmp = data->img[0];
	data->img[0] = data->img[1];
	data->img[1] = tmp;
}

int		ft_raycasting(t_data *data)
{
	int		i;
	int		size;
	double	angle;
	double	*stock;

	i = 0;
	angle = data->player->angle + (M_PI / 6);
	stock = (double *)malloc(sizeof(double) * (data->res->x));
	if (!stock)
		ft_error(data, "malloc", 0);
	while (i < data->res->x)
	{
		ft_modulo_pi(&angle);
		size = ft_calculate_ray(data, angle, &stock[i]);
		angle -= ((M_PI / 3) / data->res->x);
		ft_load_ray(data, size, i);
		i++;
	}
	ft_load_sprite(data, stock);
	return (0);
}
