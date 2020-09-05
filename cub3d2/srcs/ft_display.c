/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 09:10:34 by mbaxmann          #+#    #+#             */
/*   Updated: 2020/09/05 12:05:16 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_cub3d.h"

void		ft_init_img(t_data *data)
{
	int i;

	i = 0;
	while (i < 2)
	{
		if (!(data->img[i] = (t_img *)malloc(sizeof(t_img))))
			ft_error(data, "malloc", 0);
		data->img[i]->bpp = 32;
		data->img[i]->line = data->res->x * 4;
		data->img[i]->endian = 0;
		data->img[i]->img = mlx_new_image(data->mlx->ptr,
		data->res->x, data->res->y);
		data->img[i]->pt = mlx_get_data_addr(data->img[i]->img,
		&data->img[i]->bpp, &data->img[i]->line, &data->img[i]->endian);
		i++;
	}
}

int			ft_choose_textur(t_data *data)
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
	int			tab[5];
	long long	offset_2;

	offset_2 = 0;
	ft_init_tab(tab);
	if (size > data->res->y)
	{
		tab[0] = (size - data->res->y) / 2;
		size -= 2 * tab[0];
	}
	offset_2 = offset * 4 + data->res->x * 4 * ((data->res->y - size) / 2);
	ft_coloring(data, 4 * offset, offset_2, 1);
	tab[2] = ft_choose_textur(data);
	tab[4] = tab[0];
	size += 2 * tab[0];
	while (tab[0] < size - tab[4])
	{
		ft_put_pixel(data->img[0]->pt,
		data->texture[tab[2]]->addr, offset_2, tab[1]);
		offset_2 += data->res->x * 4;
		ft_calculate_xpm_offset(tab, data, size);
		tab[0]++;
	}
	ft_coloring(data, offset_2, data->res->x * data->res->y * 4, 0);
}
