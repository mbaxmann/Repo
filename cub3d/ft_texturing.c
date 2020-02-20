/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texturing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 13:47:29 by mbaxmann          #+#    #+#             */
/*   Updated: 2020/02/20 15:58:51 by mbaxmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_load_textur(t_data *data)
{
	static int i = 0;
	void *textur;
	static char *pixel;
	int w = 64;
	int h = 64;
	int edian = 0;

	if (!i)
	{
		textur = mlx_xpm_file_to_image(data->mlx, "./textur/greystone.xpm", &w, &h);
		pixel = mlx_get_data_addr(textur, &w, &h, &edian);
		i = 1;
	}
	return (pixel);
}

void	ft_texturing(t_data *data, char *img, int size, int size_line)
{
	char *pixel;
	int i;
	void *textur;
	int j;
	int edian;
	clock_t t;

	i = 64;
	j = 64;
	edian = 0;
	pixel = ft_load_textur(data);
	i = 8;
	j = 64;
	if ((int)data->pt->x % CUBE_SIZE != 0)
		pixel += ((int)data->pt->x % CUBE_SIZE);
	else
		pixel += ((int)data->pt->y % CUBE_SIZE);
	j = 0;
	i = 0;
	t = clock();
	while (j < size * size_line)
	{
		img[j] = pixel[i];
		img[j + 1] = pixel[i + 1];
		img[j + 2] = pixel[i + 2];
		j += size_line;
		i =  (floor((j / size_line) / (size / CUBE_SIZE))) * CUBE_SIZE * 4;
	}
	printf("tmp : %lu\n", clock() - t);
}
