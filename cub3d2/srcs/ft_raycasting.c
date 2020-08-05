/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 10:18:48 by mbaxmann          #+#    #+#             */
/*   Updated: 2020/08/05 12:42:23 by mbaxmann         ###   ########.fr       */
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
				data->map[i][j] == 'E' || data->map[i][j] == 'w')
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

void		ft_set_angle(double *angle, int *dir_x, int *dir_y)
{
	*dir_x = 1;
	*dir_y = -1;
	if (*anlge >= M_PI_2 && *angle < M_PI)
	{
		*angle = M_PI - *angle;
		*dir_x = -1;
	}
	else if (*angle >= M_PI && *angle < 3 * M_PI_2)
	{
		*angle = *angle - M_PI;
		*dir_x = -1;
		*dir_y = 1;
	}
	else if (*angle >= 3 * M_PI_2 && *angle < 2 * M_PI)
	{
		*angle = 2 * M_PI - *angle;
		*dir_y = 1;
	}
}

int			ft_init_pt(t_vector	*pt, double alpha, t_data *data)
{
	if (pt->angle >= M_PI / 4 && pt->angle <= 3 * (M_PI / 4) ||
		(pt->angle >= 5 * (M_PI / 4) && pt->angle <= 7 * (M_PI / 4)))
	{
		if (pt->dir_y = 1)
			pt->y = floor(data->player->y / CUBE_SIZE) * CUBE_SIZE + CUBE_SIZE;
		else
			pt->y = floor(data->player->y / CUBE_SIZE) * CUBE_SIZE - 1;
		if (pt->dir_x = 1)
			pt->x = data->player->x + (fabs(data->player->x - pt->y) / tan(alpha));
		else
			pt->x = data->player->x - (fabs(data->player->x - pt->y) / tan(alpha));
		return (0);
	}
	else
	{
		if (pt->dir_x = 1)
			pt->x = floor(data->player->x / CUBE_SIZE) * CUBE_SIZE + CUBE_SIZE;
		else
			pt->x = floor(data->player->x / CUBE_SIZE) * CUBE_SIZE - 1;
		if (pt->dir_y = 1)
			pt->y = data->player->y + (fabs(data->player->y - pt->x) * tan(alpha));
		else
			pt->y = data->player->y - (fabs(data->player->y - pt->x) * tan(alpha));
		return (1);
	}
}

int			ft_iswall(t_coord *pt, t_data *data)
{
	int i;
	int j;

	i = pt->y / CUBE_SIZE;
	j = pt->x / CUBE_SIZE;
	if (data->map[i][j] == '1')
		return (1);
	return (0);
}

void		ft_calculate_ray(t_data *data, double alpha)
{
	t_vector	*pt;
	int			mode;

	pt = (t_vector *)malloc(sizeof(t_vector));
	pt->angle = alpha;
	ft_set_angle(&alpha, &(pt->dir_x), &(pt->dir_y));
	mode = ft_init_pt(pt, alpha, data);
	while (!ft_iswall(pt, data))
	{
		if (mode)
		{
			pt->x += CUBE_SIZE * pt->dir_x;
			pt->y += (CUBE_SIZE * tan(angle)) * pt->dir_y;
			mode = 0;
		}
		else
		{
			pt->x += (CUBE_SIZE / tan(angle)) * pt->dir_x;
			pt->y += CUBE_SIZE * pt->dir_y;
			mode = 1;
		}
	}
}


int			ft_raycasting(t_data *data, t_mlx *mlx)
{
	int		i;
	double	angle;

	i = 0;
	angle = data->player->angle + (M_PI / 6);
	while (i < data->res->x)
	{
		ft_calculate_ray(data, angle);
		i++;
	}
	return (0);
}
