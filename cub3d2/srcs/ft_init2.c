/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 10:34:49 by mbaxmann          #+#    #+#             */
/*   Updated: 2020/07/29 10:57:55 by mbaxmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int			ft_check_data(t_data *data)
{
	int i;

	i = 0;
	if (data->texture[0] && data->texture[1])
		i++;
	if (data->texture[2] && data->texture[3])
		i++;
	if (data->sprite)
		i++;
	if (data->ceil && data->floor)
		i++;
	if (data->res->x && data->res->y)
		i++;
	if (i == 5)
		return (1);
	else
		return (0);
}

int			ft_get_rgb(char *nb)
{
	int		r;
	int		g;
	int		b;

	r = 0;
	g = 0;
	b = 0;
	r = ft_atoi(nb);
	while (*nb != ',' && *nb)
		nb++;
	g = ft_atoi(++nb);
	while (*nb != ',' && *nb)
		nb++;
	if (!(*nb) || !(*(nb + 1)))
	{
		ft_printf("Error: Invalid RBG color\n");
		exit(1);
	}
	b = ft_atoi(++nb);
	if (r < 0 || g < 0 || b < 0 || r > 255 || g > 255 || b > 255)
	{
		ft_printf("Error: Invalid RGB range\n");
		exit(1);
	}
	return ((r << 16) | (g << 8) | b);
}

void		ft_set_res(t_dim *dim, char *res)
{
	int i;

	i = 0;
	dim->x = ft_atoi(res);
	while (res[i] && res[i] != ' ')
		i++;
	dim->y = ft_atoi(res + i);
}

void		ft_get_map2(t_data *data, char *line, int fd, t_list *first, t_list *current)
{
	int i;

	i = 0;
	while (get_next_line(fd, &line))
	{
		if (ft_strncmp(line, "", 2))
		{
			ft_printf("Error: map is split and/or not at the end of file\n");
			exit(1);
		}
		free(line);
	}
	data->map = (char **)malloc(sizeof(char *) * (ft_list_len(first) + 1));
	while (current->next)
	{
		data->map[i++] = current->data;
		current = current->next;
	}
	data->map[i++] = current->data;
	data->map[i] = ft_strdup("");
}
