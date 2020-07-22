/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 09:09:51 by mbaxmann          #+#    #+#             */
/*   Updated: 2020/07/22 10:58:48 by mbaxmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		ft_check_side_h(int j, char **map)
{
	int h;
	int l;

	h = 0;
	l = 0;
	while (map[h][l] == ' ')
		l++;
	if (j)
		while (map[h][l] == '1')
			l++;
	while (map[h + 1][0])
	{
		while (l <= ft_strlen(map[h + 1]) &&
			   	map[h + 1][l] == '1')
			h++;
		if (l && map[h][l - 1] == '1')
			while (l && map[h][l - 1] == '1')
				l--;
		else
			while (map[h][l + 1] == '1')
				l++;
		if (!(l <= ft_strlen(map[h + 1]) && map[h + 1][l] == '1') &&
				!(l && map[h][l - 1] == '1') &&
				!(map[h][l + 1] == '1'))
			return (1);
	}
	return (0);
}

int		ft_check_side_l(int j, char **map)
{
	int h;
	int l;

	h = 0;
	l = 0;
	while (map[h][l] == ' ')
		h++;
	if (j)
		while (map[h + 1] && map[h][l] == '1')
			h++;
	while (map[h][l + 1])
	{
		ft_printf("h: %d	l: %d\n", h, l);
		while (map[h][l + 1] == '1')
			l++;
		if (h && map[h - 1][l] == '1')
			while (h && map[h - 1][l] == '1')
				h--;
		else
			while (map[h + 1] && map[h + 1][l] == '1')
				h++;
		if ((map[h][l + 1] != '1') &&
				!(h && map[h - 1][l] == '1') &&
				!(map[h + 1] && map[h + 1][l] == '1'))
			return (1);
	}
	return (0);
}

int		ft_check_char2(char **map, int i, int j)
{
	int k;

	k = 0;
	if (map[i][j] == '0' || map[i][j] == '1'
		|| map[i][j] == '2')
		return (1);
	else if (map[i][j] == 'N' || map[i][j] == 'S'
		|| map[i][j] == 'W' || map[i][j] == 'E')
		return (2);
	else if (map[i][j] == ' ')
	{
		if (!i || map[i - 1][j] == '1')
			k++;
		if (!map[i + 1][0] ||
			(j <= ft_strlen(map[i + 1]) && map[i + 1][j] == '1'))
			k++;
		if (!j || map[i][j - 1] == '1')
			k++;
		if (map[i][j + 1] == '1' || !map[i][j + 1])
			k++;
		if (k == 4)
			return (1);
	}
	return (0);
}

int		ft_check_char(char **map)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (map[i][0])
	{
		while (map[i][j] == ' ')
			j++;
		while (map[i][j])
		{
			if (k == 4)
			{
				ft_printf("k: %d\n", k);
				return (1);
			}
			if (!(k += ft_check_char2(map, i , j)))
			{
				ft_printf("i: %d	j: %d\n", i, j);
				return (1);
			}
			if ((k % 2) + 1 == 1)
				k = 0;
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int		ft_check_map(char **map)
{
	int i;
	int j;

	if (ft_check_side_h(0, map))
		return (1);
	if (ft_check_side_h(1, map))
		return (1);
	if (ft_check_side_l(0, map))
		return (1);
	if (ft_check_side_l(1, map))
		return (1);
	if (ft_check_char(map))
		return (1);
	return (0);
}
