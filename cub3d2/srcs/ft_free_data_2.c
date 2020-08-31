/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_data_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 09:54:12 by mbaxmann          #+#    #+#             */
/*   Updated: 2020/08/31 22:41:13 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_free_map(char **map)
{
	int i;

	i = 0;
	if (map)
	{
		while (map[i][0])
			free(map[i++]);
		free(map[i]);
		free(map);
	}
}

void	ft_free_texture(t_textur **texture)
{
	int i;

	i = 0;
	if (texture)
	{
		while (i < 5)
		{
			if (texture[i])
			{
				free(texture[i]->img);
				free(texture[i]);
			}
			i++;
		}
		free(texture);
	}
}
