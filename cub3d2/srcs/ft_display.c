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

void		ft_put_pixel(char *img, char *xpm, int i, int j)
{
	*(unsigned int *)(img + i) = *(unsigned int *)(xpm + j);
}

void		ft_load_ray(t_data *data, int size, int offset)
{
	int 		tab[4];
	unsigned int	rgb;
	long long	offset_2;

	tab[0] = 0;
	tab[1] = size;
	offset_2 = 0;
	size = (size > data->res->y) ? data->res->y - 1: size;
	offset_2 = (offset + 1) * 4 + data->res->x * 4 * ((data->res->y - size) / 2);
	tab[2] = ft_choose_textur(data);
	tab[3] = 0;
	while (tab[0] < size)
	{
		ft_put_rgb(data->image->pt, data->texture[tab[2]], offsett_2, tab[1]);
		offset_2 += data->res->x * 4;
		tab[1] = 
		tab[0]++;
	}
}
