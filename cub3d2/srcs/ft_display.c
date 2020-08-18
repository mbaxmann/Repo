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

void		ft_load_textur(t_data *data)
{
	t_textur	**tab;
	int			i;

	i = 0;
	tab = (t_textur **)malloc(sizeof(t_textur *) * 5);
	while (i < 4)
	{
		A
		printf("%d\n", i);
		tab[i] = (t_textur *)malloc(sizeof(t_textur));
		tab[i]->img = mlx_xpm_file_to_image(data->mlx->ptr,
		data->texture[i], &(tab[i]->width), &(tab[i]->height));
		if (!(tab[i]->img))
		{
			ft_printf("Error: Could not load %s texture\n", data->texture[i]);
			exit(1);
		}
		i++;
	}
	while (i)
		free(data->texture[--i]);
	free(data->texture);
	data->texture = (void **)tab;
	//free(tab);
}

void		ft_load_ray(t_data *data, int size, int offset)
{
	int i;
	long long offset_2;

	i = 0;
	offset_2 = 0;
	size = (size > data->res->y) ? data->res->y - 1: size;
	offset_2 = (offset + 1) * 4 + data->res->x * 4 * ((data->res->y - size) / 2);
	ft_load_textur(data);
	/*while (i < 0)
	{
		printf("%p\n%d\n%d\n\n", ((t_textur **)data->texture)[i]->img,
		((t_textur **)data->texture)[i]->width, ((t_textur **)data->texture)[i]->height);
		i++;
	}*/
	i = 0;
	while (i < size)
	{
		*(unsigned int *)(data->img->pt + offset_2) = 100;
		offset_2 += data->res->x * 4;
		i++;
	}
}
