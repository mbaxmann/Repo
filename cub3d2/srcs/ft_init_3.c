/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 09:17:33 by mbaxmann          #+#    #+#             */
/*   Updated: 2020/09/02 10:00:32 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_cub3d.h"

int		ft_sort_3(t_data *data, int fd, t_mlx *mlx)
{
	if (data->line[0] == 'E')
	{
		if (data->texture[3])
			ft_error(data, "cor_file", fd);
		data->texture[3] =
		ft_load_t(data, ft_strtrim(data->line, " EA"), mlx->ptr, fd);
		return (1);
	}
	else if (data->line[0] == 'N')
	{
		if (data->texture[0])
			ft_error(data, "cor_file", fd);
		data->texture[0] =
		ft_load_t(data, ft_strtrim(data->line, " NO"), mlx->ptr, fd);
		return (1);
	}
	return (0);
}

void	ft_sort_4(t_data *data, int fd)
{
	if (data->line[0] == 'F')
	{
		if (data->floor != -1)
			ft_error(data, "cor_file", fd);
		data->floor = ft_get_rgb(data, ft_strtrim(data->line, " F"), fd);
	}
	else if (data->line[0] == 'C')
	{
		if (data->ceil != -1)
			ft_error(data, "cor_file", fd);
		data->ceil = ft_get_rgb(data, ft_strtrim(data->line, " C"), fd);
	}
	else if (data->line[0] == 'R')
	{
		if (data->res->x)
			ft_error(data, "cor_file", fd);
		ft_set_res(data, ft_strtrim(data->line, " R"));
	}
	else if (ft_strncmp(data->line, "", 1))
		ft_error(data, "cor_file", fd);
}

int		ft_sort_2(t_data *data, int fd, t_mlx *mlx)
{
	if (data->line[0] == 'S' && data->line[1] == 'O')
	{
		if (data->texture[1])
			ft_error(data, "cor_file", fd);
		data->texture[1] =
		ft_load_t(data, ft_strtrim(data->line, " SO"), mlx->ptr, fd);
		return (1);
	}
	else if (data->line[0] == 'S')
	{
		if (data->texture[4])
			ft_error(data, "cor_file", fd);
		data->texture[4] =
		ft_load_t(data, ft_strtrim(data->line, " S"), mlx->ptr, fd);
		return (1);
	}
	else if (data->line[0] == 'W')
	{
		if (data->texture[2])
			ft_error(data, "cor_file", fd);
		data->texture[2] =
		ft_load_t(data, ft_strtrim(data->line, " WE"), mlx->ptr, fd);
		return (1);
	}
	return (0);
}

void	ft_sort(t_data *data, int fd, t_mlx *mlx)
{
	char	*s;
	int		i;

	i = 0;
	while (get_next_line(fd, &(data->line)) && !ft_check_data(data))
	{
		if (ft_strncmp(data->line, "", 2))
		{
			s = data->line;
			data->line = ft_strtrim(s, " ");
			free(s);
			i = ft_sort_2(data, fd, mlx);
			if (!i)
				if (!(i = ft_sort_3(data, fd, mlx)))
					ft_sort_4(data, fd);
		}
		free(data->line);
	}
}
