/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 10:18:48 by mbaxmann          #+#    #+#             */
/*   Updated: 2020/08/13 10:56:36 by mbaxmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void		ft_init_player(t_data *data, t_player **player)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	*player = (t_player *)malloc(sizeof(t_player));
	while (data->map[++i][0])
	{
		while (data->map[i][++j])
		{
			if (data->map[i][j] == 'N' || data->map[i][j] == 'S' ||
				data->map[i][j] == 'E' || data->map[i][j] == 'W')
			{
				(*player)->x = (j + 0.5) * CUBE_SIZE;
				(*player)->y = (i + 0.5) * CUBE_SIZE;
			}
			if (data->map[i][j] == 'N')
				(*player)->angle = M_PI_2;
			else if (data->map[i][j] == 'S')
				(*player)->angle = 3 * M_PI_2;
			else if (data->map[i][j] == 'E')
				(*player)->angle = 0;
			else if (data->map[i][j] == 'W')
				(*player)->angle = M_PI;
		}
		j = 0;
	}
}

void		ft_set_angle(double *angle, t_vector *pt_1, t_vector *pt_2)
{
	pt_1->dir_x = 1;
	pt_1->dir_y = -1;
	if ((*angle) >= M_PI_2 && (*angle) < M_PI)
	{
		(*angle) = M_PI - (*angle);
		pt_1->dir_x = -1;
	}
	else if ((*angle) >= M_PI && (*angle) < 3 * M_PI_2)
	{
		(*angle) = (*angle) - M_PI;
		pt_1->dir_x = -1;
		pt_1->dir_y = 1;
	}
	else if ((*angle) >= 3 * M_PI_2 && (*angle) < 2 * M_PI)
	{
		(*angle) = 2 * M_PI - (*angle);
		pt_1->dir_y = 1;
	}
	pt_2->dir_x = pt_1->dir_x;
	pt_2->dir_y = pt_1->dir_y;
}

void		ft_init_pt(t_vector	*pt, double alpha, t_data *data, int mode)
{
	if (!mode)
	{
		if (pt->dir_y == 1)
			pt->y = (floor(data->player->y / CUBE_SIZE) * CUBE_SIZE) + CUBE_SIZE;
		else
			pt->y = (floor(data->player->y / CUBE_SIZE) * CUBE_SIZE) - 1;
		if (pt->dir_x == 1)
			pt->x = data->player->x + (fabs(data->player->y - pt->y) / tan(alpha));
		else
			pt->x = data->player->x - (fabs(data->player->y - pt->y) / tan(alpha));
		//printf("init x: %d		init y: %d\n", pt->x, pt->y);
	}
	else
	{
		if (pt->dir_x == 1)
			pt->x = (floor(data->player->x / CUBE_SIZE) * CUBE_SIZE) + CUBE_SIZE;
		else
			pt->x = (floor(data->player->x / CUBE_SIZE) * CUBE_SIZE) - 1;
		if (pt->dir_y == 1)
			pt->y = data->player->y + (fabs(data->player->x - pt->x) * tan(alpha));
		else
			pt->y = data->player->y - (fabs(data->player->x - pt->x) * tan(alpha));
	}
}

int			ft_iswall(t_vector *pt, t_data *data)
{
	int i;
	int j;
	int k;

	i = round(pt->y / CUBE_SIZE);
	j = round(pt->x / CUBE_SIZE);
	k = 0;
	while (data->map[k][0])
		k++;
	if (i < 0 || i >= k)
	{
		//printf("x: %d		y: %d\n", pt->x, pt->y);
		return (1);
	}
	if (j < 0 || j > ft_strlen(data->map[i]) ||
		data->map[i][j] != '0')
	{
		//printf("x: %d		y: %d\n", pt->x, pt->y);
		return (1);
	}
	printf("x: %d		y: %d	round x: %d		round y: %d\n", pt->x, pt->y, j, i);
	return (0);
}

void		ft_init_vector(t_vector **pt_1, t_vector **pt_2, double alpha)
{
	*pt_1 = (t_vector *)malloc(sizeof(t_vector));
	*pt_2 = (t_vector *)malloc(sizeof(t_vector));
	(*pt_1)->angle = alpha;
	(*pt_2)->angle = alpha;
}

int	ft_calculate_slice(t_data *data, t_vector *pt_1, t_vector *pt_2, double angle)
{
	double	size_1;
	double	size_2;
	double	res;

	size_1 = hypot(((pt_1->x) - data->player->x), ((pt_1->y) - data->player->y));
	size_2 = hypot(((pt_2->x) - data->player->x), ((pt_2->y) - data->player->y));
	//printf("size1 : %f		size2 : %f		", size_1, size_2);
	if (size_1 <= size_2)
	{
		//printf("size 1  selected\n");
		size_1 *= fabs(cos(data->player->angle - pt_1->angle));
		res = (CUBE_SIZE * ((data->res->x / 2) / tan(M_PI / 6))) / size_1;
	}
	else
	{
		//printf("size 2 selected\n");
		size_2 *= fabs(cos(data->player->angle - pt_2->angle));
		res = (CUBE_SIZE * ((data->res->x / 2) / tan(M_PI / 6))) / size_2;
	}
	return ((int)ceil(res));
}

int		ft_calculate_ray(t_data *data, double alpha)
{
	t_vector	*pt_1;
	t_vector	*pt_2;

	ft_init_vector(&pt_1, &pt_2, alpha);
	ft_set_angle(&alpha, pt_1, pt_2);
	ft_init_pt(pt_1, alpha, data, 1);
	ft_init_pt(pt_2, alpha, data, 0);
	while (!ft_iswall(pt_1, data))
	{
		pt_1->x += CUBE_SIZE * pt_1->dir_x;
		pt_1->y += (CUBE_SIZE * tan(alpha)) * pt_1->dir_y;
	}
	while (!ft_iswall(pt_2, data))
	{
		//printf("x: %d		y: %d\n", pt_2->x, pt_2->y);
		pt_2->x += (CUBE_SIZE / tan(alpha)) * pt_2->dir_x;
		pt_2->y += CUBE_SIZE * pt_2->dir_y;
	}
	//printf("\n\n\n");
	//printf("x1: %d		y1: %d\nx2: %d		y2: %d\n\n",pt_1->x, pt_1->y, pt_2->x, pt_2->y);
	return (ft_calculate_slice(data, pt_1, pt_2, alpha));
}

void	ft_modulo_pi(double *angle)
{
	while ((*angle) >= 2 * M_PI)
		(*angle) -= 2 * M_PI;
	while ((*angle) < 0)
		(*angle) += 2 * M_PI;
}

int			ft_raycasting(t_data *data, t_mlx *mlx)
{
	int		i;
	int		size;
	double	angle;

	i = 0;
	angle = data->player->angle + (M_PI / 6);
	ft_init_img(data);
	printf("AOOAOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO\n\n\n\n\n\n\n\n\n");
	while (i < data->res->x)
	{
		ft_modulo_pi(&angle);
		//printf("angle: %f\n", 360 * (data->player->angle / (2 * M_PI)));
		size = ft_calculate_ray(data, angle);
		angle -= ((M_PI / 3) / data->res->x);
		ft_load_ray(data, size, i);
		i++;
	}
	mlx_put_image_to_window(data->mlx->ptr, data->mlx->win, data->img->img, 0, 0);
	return (0);
}
