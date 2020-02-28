/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texturing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 13:47:29 by mbaxmann          #+#    #+#             */
/*   Updated: 2020/02/28 13:20:53 by mbaxmann         ###   ########.fr       */
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

/*void	ft_fill_up(char *pixel, int l, t_data *data)
{
	int i;

	i = 0;
	while (i < l)
	{
		pixel[i] = 0;
		pixel[i + 1] = 127;
		pixel[i + 2] = 0;
		i += 4 * data->dim->x;
	}
}*/

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

void	ft_texturing(t_data *data, char *img, int size, int size_line)
{
	char *pixel;
	int i;
	void *textur;
	int j;
	int l;
	int len;

	pixel = ft_choose_textur(data);
	j = 0;
	i = 0;
	l = (size > 1079) ? ((size % 1079) / 2) * size_line : 0;
	len = (size > 1079) ? 1079 : size;
	while (j < len * size_line)
	{
		ft_pixel_put(img, j, pixel, i);
		j += size_line;
		i =  ((((j + l) / size_line) * CUBE_SIZE) / size) * CUBE_SIZE * 4;
		//i = (size > 1079) ? i + (((size % 1079) / 2) * CUBE_SIZE * 4) : i;
	}
}
