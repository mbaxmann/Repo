/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 09:17:33 by mbaxmann          #+#    #+#             */
/*   Updated: 2020/08/31 23:05:48 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_sort_3(t_data *data, int fd, t_mlx *mlx)
{
	if (data->line[0] == 'E')
	{
		data->texture[3] =
		ft_load_t(data, ft_strtrim(data->line, " EA"), mlx->ptr, fd);
	}
	else if (data->line[0] == 'N')
	{
		data->texture[0] =
		ft_load_t(data, ft_strtrim(data->line, " NO"), mlx->ptr, fd);
	}
	else if (data->line[0] == 'F')
		data->floor = ft_get_rgb(data, ft_strtrim(data->line, " F"), fd);
	else if (data->line[0] == 'C')
		data->ceil = ft_get_rgb(data, ft_strtrim(data->line, " C"), fd);
	else if (data->line[0] == 'R')
		ft_set_res(data->res, ft_strtrim(data->line, " R"));
}

void	ft_sort_2(t_data *data, int fd, t_mlx *mlx)
{
	if (data->line[0] == 'S' && data->line[1] == 'O')
	{
		data->texture[1] =
		ft_load_t(data, ft_strtrim(data->line, " SO"), mlx->ptr, fd);
	}
	else if (data->line[0] == 'S')
	{
		data->texture[4] =
		ft_load_t(data, ft_strtrim(data->line, " S"), mlx->ptr, fd);
	}
	else if (data->line[0] == 'W')
	{
		data->texture[2] =
		ft_load_t(data, ft_strtrim(data->line, " WE"), mlx->ptr, fd);
	}
}

void	ft_sort(t_data *data, int fd, t_mlx *mlx)
{
	char	*s;

	while (get_next_line(fd, &(data->line)) && !ft_check_data(data))
	{
		if (ft_strncmp(data->line, "", 2))
		{
			s = data->line;
			data->line = ft_strtrim(s, " ");
			free(s);
			ft_sort_2(data, fd, mlx);
			ft_sort_3(data, fd, mlx);
		}
		free(data->line);
	}
}
