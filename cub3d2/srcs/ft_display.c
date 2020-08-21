/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 09:10:34 by mbaxmann          #+#    #+#             */
/*   Updated: 2020/08/18 10:56:23 by mbaxmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void		ft_init_img(t_data *data)
{
	data->img = (t_img *)malloc(sizeof(t_img));
	data->img->bpp = 32;
	data->img->line = data->res->x * 4;
	data->img->endian = 0;
	data->img->img = mlx_new_image(data->mlx->ptr, data->res->x, data->res->y);
	data->img->pt = mlx_get_data_addr(data->img->img,
	&data->img->bpp, &data->img->line, &data->img->endian);
}

int		ft_choose_textur(t_data *data)
{
	if (data->stock->x)
	{
		if (data->stock->angle <= M_PI)
			return (0);
		else
			return (1);
	}
	else
	{
		if (data->stock->angle >= M_PI_2 &&
		data->stock->angle <= 3 * M_PI_2)
			return (2);
		else
			return (3);
	}
}

void		ft_calculate_xpm_offset(int *tab, t_data *data, int size)
{
	int	i;
	int	j;

	i = (tab[0] * data->texture[tab[2]]->height) / size;
	if (data->stock->x)
		j = (int)round(data->stock->x) % CUBE;
	else
		j = (int)round(data->stock->y) % CUBE;
	j = (j * data->texture[tab[2]]->width) / CUBE;
	tab[1] = 4 * (data->texture[tab[2]]->width * i + j);
}

void		ft_put_pixel(char *img, char *xpm, int i, int j)
{
	*(unsigned int *)(img + i) = *(unsigned int *)(xpm + j);
}

void		ft_load_ray(t_data *data, int size, int offset)
{
	int 		tab[4];
	int		i;
	long long	offset_2;

	tab[0] = 0;
	tab[1] = 0;
	i = 0;
	offset_2 = 0;
	if (size > data->res->y)
	{
		tab[0] = (size - data->res->y) / 2;
		size -= 2 * tab[0];
	}
	offset_2 = offset * 4 + data->res->x * 4 * ((data->res->y - size) / 2);
	tab[2] = ft_choose_textur(data);
	tab[3] = 0;
	i = tab[0];
	size += 2 * tab[0];
	while (tab[0] < size - i)
	{
		ft_put_pixel(data->img->pt, data->texture[tab[2]]->addr, offset_2, tab[1]);
		offset_2 += data->res->x * 4;
		ft_calculate_xpm_offset(tab, data, size);
		tab[0]++;
	}
}
