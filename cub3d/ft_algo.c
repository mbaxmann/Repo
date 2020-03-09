/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 16:05:28 by mbaxmann          #+#    #+#             */
/*   Updated: 2020/03/09 15:50:02 by mbaxmann         ###   ########.fr       */
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

int		ft_isok(t_position *pt, char **map, double dir, int m)
{
	double (*tab[3])(double x) = {floor, ceil, round};
	int i;
	int j;

	i = 0;
	j = 0;
	if (m == 1&& ((dir >= 0 && dir <= M_PI_2) || (dir >= 3 * M_PI_2 && dir < 2 * M_PI)))
		j = 0;
	else if (m == 1)
		j = 1;
	if (!m && (dir >= 0 && dir <= M_PI))
		j = 1;
	else if (!m)
		j = 0;
	if (m == 2)
		j = 2;
	while (map[i])
		i++;
	i--;
	if ((int)tab[j](pt->y) / CUBE_SIZE < 0)
		return (0);
	else if ((int)tab[j](pt->y) / CUBE_SIZE > i)
		return (0);
	if ((int)tab[j](pt->x) / CUBE_SIZE < 0)
		return (0);
	if ((int)tab[j](pt->x) / CUBE_SIZE > ft_strlen(map[(int)tab[j](pt->y) / CUBE_SIZE]) - 1)
		return (0);
	if (map[((int)(tab[j])(pt->y) / CUBE_SIZE)][((int)(tab[j])(pt->x) / CUBE_SIZE)] == '1')
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
		O->y = player->y - (fabs(player->x - O->x) * (tan(angle)));
	else
		O->y = player->y + (fabs(player->x - O->x) * (tan(angle)));
	while (ft_isok(O, map, dir, 0)) 
	{
		if ((dir >= 0 && dir <= M_PI_2) ||
		(dir >= (3 * M_PI_2) && dir < 2 * M_PI))
			O->x += CUBE_SIZE;
		else
			O->x -= CUBE_SIZE;
		if (dir >= 0 && dir <= M_PI)
			O->y -= CUBE_SIZE * (tan(angle));
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
	while (ft_isok(C, map, dir, 1))
	{
		if (dir >= 0 && dir <= M_PI)
			C->y -= CUBE_SIZE;
		else
			C->y += CUBE_SIZE;
		if ((dir >= 0 && dir <= M_PI_2) || (dir >= 3 * M_PI_2 && dir < 2 * M_PI))
			C->x += CUBE_SIZE / (tan(angle));
		else
			C->x -= CUBE_SIZE / (tan(angle));
	}
}

int	ft_calculate_slice_size(t_data *data, t_position *C, t_position *O, double angle)
{
	double	size_1;
	double	size_2;
	double	res;

	size_1 = hypot(((O->x) - data->player->x), ((O->y) - data->player->y));
	size_2 = hypot(((C->x) - data->player->x), ((C->y) - data->player->y));
	if (size_1 <= size_2)
	{
		data->pt->y = O->y;
		data->pt->x = 0;
		size_1 *= cos(data->player->angle - angle);
		res = (CUBE_SIZE * (960 / tan(M_PI / 6))) / size_1;
	}
	else
	{
		data->pt->y = 0;
		data->pt->x = C->x;
		size_2 *= cos(data->player->angle - angle);
		res = (CUBE_SIZE * (960 / tan(M_PI / 6))) / size_2;
	}
	res = (res < 0)? -res : res;
	return ((int)round(res));
}

void	ft_fill_image(void *img, int size, int i, t_data *data)
{
	char *pixel;
	int bpp;
	int size_line;
	int j = 0;
	int edian;

	bpp = 32;
	edian = 0;
	size_line = 4 * data->dim->x;
	pixel = mlx_get_data_addr(img, &bpp, &size_line, &edian) + 4 * i;
	edian = (size > 1079) ? 1079 : size;
	ft_fill_up(pixel, 0, size_line * ((data->dim->y - edian) / 2), data);
	/*while (j < size * size_line)
	{
		pixel[0] = 0;
		pixel[1] = -126;
		pixel[2] = 0;
		pixel[3] = 0;
		j += size_line;
		pixel += size_line;
	}*/
	ft_fill_up(pixel, (edian + ((data->dim->y - edian) / 2)) * size_line,
	(data->dim->y - 1) * size_line, data);
	pixel += size_line * ((data->dim->y - edian) / 2);
	ft_texturing(data, pixel, size, size_line);
}

void	ft_display_cub(t_position *player, t_data *data, void *img)
{
	t_position O;
	t_position C;
	double angle;
	int	i;
	int	size;

	angle = player->angle - (M_PI / 6);
	i = 1920;
	clock_t t;
	while (i)
	{
		data->pt->angle = angle;
		angle = ft_modulo_pi(angle);
		ft_check_verticaly(player, data->map, &C, ft_set_angle(angle), angle);
		ft_check_horizontaly(player, data->map, &O, ft_set_angle(angle), angle);
		size = ft_calculate_slice_size(data, &C, &O, angle);
		ft_fill_image(img, size, i, data);
		i--;
		angle += ((M_PI / 3) / 1920);
	}
	mlx_put_image_to_window(data->mlx, data->win, img, 0, 0);
}


void	ft_algo(char *path, t_data *data, char ***map)
{
	char **tab;
	void *img;
	int i;
	int j;

	i = 0;
	j = 0;
	
	int k = 1080;
	int l = 1920;
	//mlx_put_image_to_window(data->mlx, data->win, img, 0, 0);
	img = mlx_new_image(data->mlx, 1920, 1080);
	data->img = img;
	data->tab = tab;
	ft_init(path, map, &tab, data);
	ft_display_cub(data->player, data, img);
}
