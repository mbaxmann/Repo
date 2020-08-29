/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 09:10:34 by mbaxmann          #+#    #+#             */
/*   Updated: 2020/08/29 17:17:49 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_init_tab(int tab[5])
{
	int i;

	i = 0;
	while (i < 5)
		tab[i++] = 0;
}

void	ft_coloring(t_data *data, long long i, long long j, int mode)
{
	unsigned int	color;
	char			*img;

	img = data->img[0]->pt;
	if (mode)
		color = (unsigned int)data->ceil;
	else
		color = (unsigned int)data->floor;
	while (i < j)
	{
		(*(unsigned int *)(img + i)) = color;
		i += 4 * data->res->x + color - color;
	}
}
