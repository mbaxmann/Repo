/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 09:54:12 by mbaxmann          #+#    #+#             */
/*   Updated: 2020/08/30 20:21:26 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void		ft_wfile_header(t_data *data, int fd)
{
	unsigned int val;
	short val2;

	write(fd, "BM", 2);
	val = data->res->x * data->res->y * 4 + 54;
	write(fd, &val, 4);
	val2 = 0;
	write(fd, &val2, 2);
	write(fd, &val2, 2);
	val = 54;
	write(fd, &val, 4);
}

void		ft_wimg_header(t_data *data, int fd)
{
	unsigned int val;
	short val2;

	val = 40;
	write(fd, &val, 4);
	val = data->res->x;
	write(fd, &val, 4);
	val = data->res->y;
	write(fd, &val, 4);
	val2 = 1;
	write(fd, &val2, 2);
	val2 = 32;
	write(fd, &val2, 2);
	val = 0;
	write(fd, &val, 4);
	val = data->res->x * data->res->y;
	write(fd, &val, 4);
	val = 900;
	write(fd, &val, 4);
	write(fd, &val, 4);
	val = 0;
	write(fd, &val, 4);
	write(fd, &val, 4);
}

void		ft_write_bmp(t_data *data, int fd)
{
	int i;
	int offset;
	int tab[2];
	unsigned int rgb;

	i = 0;
	ft_wfile_header(data, fd);
	ft_wimg_header(data, fd);
	while (i < data->res->x * data->res->y)
	{
		tab[0] = i / data->res->x;
		tab[1] = i % data->res->x;
		offset = 4 * ((data->res->x * (data->res->y - tab[0] - 1)) + tab[1]);
		rgb = *(unsigned int *)(data->img[1]->pt + offset);
		write(fd, &rgb, 4);
		i++;
	}
	close(fd);
}

void		ft_save_img(t_data *data)
{
	int fd;

	if ((fd = open("save.bmp", O_CREAT | O_TRUNC | O_RDWR)) <= 0)
		ft_error(data, "bmp");
	else
	{
		ft_raycasting(data);
		ft_write_bmp(data, fd);
		ft_free_data(data);
		exit(0);
	}
}
