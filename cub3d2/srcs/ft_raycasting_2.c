/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 09:12:46 by mbaxmann          #+#    #+#             */
/*   Updated: 2020/08/24 16:09:42 by user42           ###   ########.fr       */
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
			ft_spot_player(data, i, j);
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

void		ft_init_pt(t_vector *pt, double alpha, t_data *data, int mode)
{
	if (!mode)
		ft_init_pt_mode_0(pt, alpha, data);
	else
		ft_init_pt_mode_1(pt, alpha, data);
}

int			ft_iswall(t_vector *pt, t_data *data)
{
	int i;
	int j;
	int k;

	if (pt->dir_y == 1)
		i = floor(floor(pt->y) / CUBE);
	else
		i = floor(ceil(pt->y) / CUBE);
	if (pt->dir_x == 1)
		j = floor(floor(pt->x) / CUBE);
	else
		j = floor(ceil(pt->x) / CUBE);
	k = 0;
	while (data->map[k][0])
		k++;
	if (i < 0 || i >= k)
		return (1);
	if (j < 0 || j >= (int)ft_strlen(data->map[i]) ||
		data->map[i][j] == '1')
		return (1);
	ft_check_sprite(data, i, j);
	return (0);
}

void		ft_init_vector(t_vector **pt_1, t_vector **pt_2, double alpha)
{
	*pt_1 = (t_vector *)malloc(sizeof(t_vector));
	*pt_2 = (t_vector *)malloc(sizeof(t_vector));
	(*pt_1)->angle = alpha;
	(*pt_2)->angle = alpha;
}
