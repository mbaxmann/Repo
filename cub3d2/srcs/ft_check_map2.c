/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 10:36:53 by mbaxmann          #+#    #+#             */
/*   Updated: 2020/07/29 09:51:13 by mbaxmann         ###   ########.fr       */
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
