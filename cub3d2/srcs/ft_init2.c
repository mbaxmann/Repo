/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 09:09:51 by mbaxmann          #+#    #+#             */
/*   Updated: 2020/07/25 10:18:45 by mbaxmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		ft_check_down(char **map, int i, int j)
{
	if (i && j <= ft_strlen(map[i - 1]) && map[i - 1][j] == ' ')
		return (1);
	else if (!i || j > ft_strlen(map[i - 1]))
		return (1);
	else if (map[i - 1][j] && map[i - 1][j + 1] == ' ')
		return (1);
	else if (j && map[i - 1][j - 1] == ' ')
		return (1);
	return (0);
}

int		ft_check_up(char **map, int i, int j)
{
	if (map[i + 1][0] && j <= ft_strlen(map[i + 1])
		&& map[i + 1][j] == ' ')
		return (1);
	else if (!map[i + 1][0] || j > ft_strlen(map[i + 1]))
		return (1);
	else if (map[i + 1][j] && map[i + 1][j + 1] == ' ')
		return (1);
	else if (j && map[i + 1][j - 1] == ' ')
		return (1);
	return (0);
}
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
	int k;

	k = 0;
	if (map[i][j] == '1'
		|| map[i][j] == '2' || map[i][j] == ' ')
		return (1);
	else if (map[i][j] == 'N' || map[i][j] == 'S'
		|| map[i][j] == 'W' || map[i][j] == 'E')
		return (2);
	else if (map[i][j] == '0')
		return (ft_check_hole(map, i, j));
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
		while (map[i][j])
		{
			if (k == 4)
				return (1);
			if (!ft_check_char2(map, i , j))
				return (1);
			else
				k += ft_check_char2(map, i, j);
			if (k == 1 || k == 3)
				k--;
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int		ft_check_map(char **map)
{
	if (ft_check_char(map))
		return (1);
	return (0);
}
