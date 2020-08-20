/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 10:28:50 by mbaxmann          #+#    #+#             */
/*   Updated: 2020/07/29 10:36:05 by mbaxmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		ft_check_hole(char **map, int i, int j)
{
	if (!j || map[i][j - 1] == ' ')
		return (0);
	if (map[i][j + 1] == ' ' || !map[i][j + 1])
		return (0);
	if (ft_check_down(map, i, j))
		return (0);
	if (ft_check_up(map, i, j))
		return (0);
	return (1);
}

int		ft_check_char2(char **map, int i, int j)
{
	if (map[i][j] == '1' || map[i][j] == ' ')
		return (1);
	else if (map[i][j] == 'N' || map[i][j] == 'S'
		|| map[i][j] == 'W' || map[i][j] == 'E')
		return (2);
	else if (map[i][j] == '0' || map[i][j] == '2')
		return (ft_check_hole(map, i, j));
	return (0);
}

int		ft_check_char(char **map)
{
	int i;
	int j;
	int k;

	i = -1;
	j = -1;
	k = 0;
	while (map[++i][0])
	{
		while (map[i][++j])
		{
			if (k == 4)
				return (1);
			if (!ft_check_char2(map, i, j))
				return (1);
			else
				k += ft_check_char2(map, i, j);
			if (k == 1 || k == 3)
				k--;
		}
		j = -1;
	}
	if (k != 2)
		return (1);
	return (0);
}

int		ft_check_map(char **map)
{
	if (ft_check_char(map))
		return (1);
	return (0);
}
