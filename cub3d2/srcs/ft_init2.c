/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 10:34:49 by mbaxmann          #+#    #+#             */
/*   Updated: 2020/09/05 13:59:59 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_cub3d.h"

int			ft_check_data(t_data *data)
{
	int i;

	i = 0;
	if (data->texture[0] && data->texture[1])
		i++;
	if (data->texture[2] && data->texture[3])
		i++;
	if (data->texture[4])
		i++;
	if (data->ceil != -1 && data->floor != -1)
		i++;
	if (data->res->x && data->res->y)
		i++;
	if (i == 5)
		return (1);
	else
		return (0);
}

int			ft_get_rgb(t_data *data, char *nb, int fd)
{
	int		tab[3];
	char	*stock;

	tab[0] = ft_atoi(nb);
	stock = nb;
	while (*nb != ',' && *nb)
		nb++;
	tab[1] = ft_atoi(++nb);
	while (*nb != ',' && *nb)
		nb++;
	if (!(*nb) || !(*(nb + 1)))
	{
		free(stock);
		ft_error(data, "rgb_inv", fd);
	}
	tab[2] = ft_atoi(++nb);
	if (tab[0] < 0 || tab[1] < 0 || tab[2] < 0 ||
	tab[0] > 255 || tab[1] > 255 || tab[2] > 255)
	{
		free(stock);
		ft_error(data, "rgb_ran", fd);
	}
	free(stock);
	return ((tab[0] << 16) | (tab[1] << 8) | tab[2]);
}

void		ft_set_res(t_data *data, char *res)
{
	int i;
	int max_x;
	int max_y;

	i = 0;
	max_x = 0;
	max_y = 0;
	mlx_get_screen_size(data->mlx->ptr, &max_x, &max_y);
	data->res->x = ft_atoi(res);
	data->res->x = (data->res->x > max_x) ? max_x : data->res->x;
	data->res->x = (data->res->x < 510) ? 510 : data->res->x;
	while (res[i] && res[i] != ' ')
		i++;
	data->res->y = ft_atoi(res + i);
	data->res->y = (data->res->y > max_y) ? max_y : data->res->y;
	data->res->y = (data->res->y < 254) ? 254 : data->res->y;
	free(res);
}

void		ft_get_map2(t_data *data, int fd, t_list *first)
{
	int		i;
	t_list	*current;

	i = 0;
	current = first;
	free(data->line);
	ft_get_map3(data, fd, first);
	free(data->line);
	data->line = NULL;
	data->map = (char **)malloc(sizeof(char *) * (ft_list_len(first) + 1));
	if (!data->map)
		ft_error(data, "malloc", fd);
	while (current)
	{
		data->map[i++] = ft_strdup(current->data);
		current = current->next;
	}
	data->map[i] = ft_strdup("");
	ft_free_lst(first);
}
