/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texturing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 13:47:29 by mbaxmann          #+#    #+#             */
/*   Updated: 2020/03/09 11:42:33 by mbaxmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**ft_load_textur(t_data *data)
{
	char **img;
	void *textur;
	int util[3];
	int i;

	util[2] = 0;
	i = 0;
	img = (char **)malloc(sizeof(char *) * 4);
	while (i < 4)
	{
		A
		util[1] = 64;
		util[0] = 64;
		printf("test : %s\n", data->tab[1]);
		textur = mlx_xpm_file_to_image(data->mlx, data->tab[i + 1], util, util + 1);
		util[0] = 32;
		util[1] = 4 * CUBE_SIZE;
		img[i] = mlx_get_data_addr(textur, util, util + 1, util + 2);
		i++;
	}
	return (img);
}

unsigned int	ft_get_color(t_data *data, int start)
{
	unsigned int i;
	int j;

	i = 0;
	j = 0;
	start = (!start) ? 6 : 5;
	i = ft_atoi(&data->tab[start][0]) << 16;
	while (data->tab[start][j] != ',')
		j++;
	j++;
	i += ft_atoi(&data->tab[start][j]) << 8;
	while (data->tab[start][j] != ',')
		j++;
	j++;
	i += ft_atoi(&data->tab[start][j]);
	return (i);
}

void	ft_fill_up(char *pixel, int start, int end, t_data *data)
{
	unsigned int i;

	i = ft_get_color(data, start);
	if (start >= 0 && end < data->dim->y * 4 * data->dim->x && end >= 0)
	{
		pixel += start;
		while (start < end)
		{
			*(unsigned int *)pixel = i;
			pixel += 4 * data->dim->x;
			start += 4 *data->dim->x;
		}
	}
}

char	*ft_choose_textur(t_data *data)
{
	char *pixel;

	//printf("%f	%f\n", data->pt->x, data->pt->y);
	if (data->pt->x)
	{
		if (data->pt->angle >= 0 && data->pt->angle <= M_PI)
			pixel = data->tab2[0];
		else
			pixel = data->tab2[1];
		pixel += ((int)data->pt->x % (CUBE_SIZE)) * 4;
	}
	else
	{
		if (data->pt->angle >= M_PI_2 && data->pt->angle <= 3 * M_PI_2)
			pixel = data->tab2[2];
		else
			pixel = data->tab2[3];
		pixel += ((int)data->pt->y % (CUBE_SIZE)) * 4;
	}
	return (pixel);
}

void	ft_pixel_put(char *img, int j, char *pixel, int i)
{
	char *dst;
	char *dst2;

	dst2 = pixel + i;
	dst = img + j;
	*(unsigned int *)dst = (*(unsigned int *)dst2);
}

int		ft_offset(int size, t_data *data)
{
	int res;

	res = 0;
	if (size > data->dim->y)
		res = ((size - data->dim->y) / 2) * 4 * data->dim->x;
	return (res);
}

void	ft_texturing(t_data *data, char *img, int size, int size_line)
{
	char *pixel;
	void *textur;
	int tab[4];

	pixel = ft_choose_textur(data);
	tab[0] = 0;
	tab[1] = 0;
	tab[2] = size;
	size = (size > 1079) ? 1079 : size;
	tab[3] = ft_offset(tab[2], data);
	static int k = 0;
	k = (k + 1) % 1920;
	//printf("test : %d	i : %d		size : %d\n", tab[3], k, tab[2]);
	while (tab[0] < size * size_line)
	{
		ft_pixel_put(img, tab[0], pixel, tab[1]);
		tab[0] += size_line;
		tab[1] = ((((tab[0] + tab[3]) / size_line) * CUBE_SIZE) / tab[2]) * CUBE_SIZE * 4;
		//i = (size > 1079) ? i + (((size % 1079) / 2) * CUBE_SIZE * 4) : i;
	}
}
