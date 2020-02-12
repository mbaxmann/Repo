/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 16:05:28 by mbaxmann          #+#    #+#             */
/*   Updated: 2020/02/12 15:08:11 by mbaxmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

double		ft_modulo_pi(double nb)
{
	if (nb < 0)
		return (2 * M_PI + nb);
	else if (nb >= 2 * M_PI)
		return (nb - 2 * M_PI);
	else
		return (nb);
}

double		ft_set_angle(double angle)
{
	if (angle > M_PI_2 && angle <= M_PI)
		return (M_PI - angle);
	else if (angle > M_PI && angle <= 3 * M_PI_2)
		return (angle - M_PI);
	else if (angle > 3 * M_PI_2 && angle < 2 * M_PI)
		return (2 * M_PI - angle);
	else
		return (angle);
}

int		ft_isok(t_position *pt, char **map)
{
	int i;

	i = 0;
	while (map[i])
		i++;
	i--;
	if ((int)floor(pt->y) / CUBE_SIZE < 0)
		return (0);
	else if ((int)floor(pt->y) / CUBE_SIZE > i)
		return (0);
	if ((int)floor(pt->x) / CUBE_SIZE < 0)
		return (0);
	if ((int)floor(pt->x) / CUBE_SIZE > ft_strlen(map[(int)floor(pt->y) / CUBE_SIZE]) - 1)
		return (0);
	return (1);
}

void	ft_check_horizontaly(t_position *player, char **map, t_position *O, double angle, double dir)
{
	if ((dir >= 0 && dir <= M_PI_2) ||
			(dir >= 3 * M_PI_2 && dir < 2 * M_PI))
		O->x = floor(player->x / CUBE_SIZE) * CUBE_SIZE + CUBE_SIZE;
	else
		O->x = floor(player->x / CUBE_SIZE) * CUBE_SIZE - 1;
	if (dir >= 0 && dir <= M_PI)
		O->y = player->y - fabs(player->x - O->x) * (tan(angle));
	else
		O->y = player->y + fabs(player->x - O->x) * (tan(angle));
	while (ft_isok(O, map) && map[((int)floor(O->y) / CUBE_SIZE)][((int)floor(O->x) / CUBE_SIZE)] != '1')
	{
		if ((dir >= 0 && dir <= M_PI_2) ||
		(dir >= (3 * M_PI_2) && dir < 2 * M_PI))
			O->x += CUBE_SIZE;
		else
			O->x -= CUBE_SIZE;
		if (dir >= 0 && dir <= M_PI)
			O->y -= CUBE_SIZE  * (tan(angle));
		else
			O->y += CUBE_SIZE * (tan(angle));
	}
}

void	ft_check_verticaly(t_position *player, char **map, t_position *C, double angle, double dir)
{
	if (dir >= 0 && dir <= M_PI)
		C->y = floor(player->y / CUBE_SIZE) * CUBE_SIZE - 1;
	else
		C->y = floor(player->y / CUBE_SIZE) * CUBE_SIZE + CUBE_SIZE;
	if ((dir >= 0 && dir <= M_PI_2) || (dir >= 3 * M_PI_2 && dir < 2 * M_PI))
		C->x = player->x + (fabs(player->y - C->y) / (tan(angle)));
	else
		C->x = player->x - (fabs(player->y - C->y) / (tan(angle)));
	while (ft_isok(C, map) && map[((int)floor(C->y) / CUBE_SIZE)][((int)floor(C->x) / CUBE_SIZE)] != '1')
	{
		if (dir >= 0 && dir <= M_PI)
			C->y -= CUBE_SIZE;
		else
			C->y += CUBE_SIZE;
		if ((dir >= 0 && dir <= M_PI_2) || (dir >= 3 * M_PI_2 && dir < 2 * M_PI))
			C->x += CUBE_SIZE  / (tan(angle));
		else
			C->x -= CUBE_SIZE / (tan(angle));
	}
}

int	ft_calculate_slice_size(t_position *player, t_position *C, t_position *O, double angle)
{
	double	size_1;
	double	size_2;
	double	res;

	size_1 = hypot((O->x - player->x), (O->y - player->y));
	size_2 = hypot((C->x - player->x), (C->y - player->y));
	if (size_1 <= size_2)
	{
		size_1 *= cos(player->angle - angle);
		res = (CUBE_SIZE * (960 / tan(M_PI / 6))) / size_1;
	}
	else
	{
		size_2 *= cos(player->angle - angle);
		res = (CUBE_SIZE * (960 / tan(M_PI / 6))) / size_2;
	}
	res = (res < 0)? -res : res;
	return ((int)round(res));
}

void	ft_fill_image(void *img, int size, int i, t_win_dim *win)
{
	char *pixel;
	int bpp;
	int size_line;
	int j = 0;

	bpp = 32;
	size_line = bpp * win->x;
	pixel = mlx_get_data_addr(img, &bpp, &size_line, 0);
	pixel += 300;
	while (j < 10000)
	{
		pixel[0] = 0;
		pixel[1] = -126;
		pixel[2] = 0;
		pixel[3] = 0;
		j += size_line;
		pixel += j;
	}
}

void	ft_display_cub(t_position *player, char **map, t_data *data, void *img)
{
	t_position O;
	t_position C;
	double angle;
	int	i;
	int	size;

	angle = player->angle - (M_PI / 6);
	i = 1920;
	while (i)
	{
		angle = ft_modulo_pi(angle);
		ft_check_verticaly(player, map, &C, ft_set_angle(angle), angle);
		ft_check_horizontaly(player, map, &O, ft_set_angle(angle), angle);
		size = ft_calculate_slice_size(player, &C, &O, angle);
		//ft_fill_image(img, size, i, data->dim);
		i--;
		angle += (M_PI / 3) / 1920;
	}
}


void	ft_algo(char *path, t_data *data, char ***map)
{
	char **tab;
	void *img;
	int i;
	int j;

	i = 0;
	j = 0;
	img = mlx_new_image(data->mlx, 1920, 1080);
	data->img = img;
	ft_init(path, map, &tab, data);
	ft_display_cub(data->player, *map, data, img);
	mlx_put_image_to_window(data->mlx, data->win, img, 200, 200);
}