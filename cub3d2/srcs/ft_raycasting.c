/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 10:18:48 by mbaxmann          #+#    #+#             */
/*   Updated: 2020/08/15 09:57:50 by mbaxmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int			ft_calculate_slice(t_data *data, t_vector *pt_1, t_vector *pt_2)
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
	}
	else
	{
		size_2 *= cos(data->player->angle - pt_2->angle);
		res = ((double)CUBE * ((data->res->x / 2) / tan(M_PI / 6))) / size_2;
	}
	return ((int)floor(res));
}

int			ft_calculate_ray(t_data *data, double alpha)
{
	t_vector	*pt_1;
	t_vector	*pt_2;

	ft_init_vector(&pt_1, &pt_2, alpha);
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
	return (ft_calculate_slice(data, pt_1, pt_2));
}

void		ft_modulo_pi(double *angle)
{
	while ((*angle) >= 2 * M_PI)
		(*angle) -= 2 * M_PI;
	while ((*angle) < 0)
		(*angle) += 2 * M_PI;
}

int			ft_raycasting(t_data *data)
{
	int		i;
	int		size;
	double	angle;

	i = 0;
	angle = data->player->angle + (M_PI / 6);
	ft_init_img(data);
	while (i < data->res->x)
	{
		ft_modulo_pi(&angle);
		size = ft_calculate_ray(data, angle);
		angle -= ((M_PI / 3) / data->res->x);
		ft_load_ray(data, size, i);
		i++;
	}
	mlx_put_image_to_window(data->mlx->ptr,
	data->mlx->win, data->img->img, 0, 0);
	return (0);
}
