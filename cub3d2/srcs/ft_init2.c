/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 10:34:49 by mbaxmann          #+#    #+#             */
/*   Updated: 2020/09/08 15:52:44 by user42           ###   ########.fr       */
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

	stock = nb;
	while (*nb == ' ')
		nb++;
	if (!ft_isdigit(*nb))
		ft_free_rgb(data, stock, fd);
	tab[0] = ft_atoi(nb);
	nb += ft_nblen(tab[0]);
	ft_rgb_pass(&nb, stock, fd, data);
	tab[1] = ft_atoi(nb);
	nb += ft_nblen(tab[1]);
	ft_rgb_pass(&nb, stock, fd, data);
	tab[2] = ft_atoi(nb);
	nb += ft_nblen(tab[2]);
	while (*nb == ' ' || ft_isdigit(*nb))
		nb++;
	if (*nb)
		ft_free_rgb(data, stock, fd);
	if (tab[0] < 0 || tab[1] < 0 || tab[2] < 0 ||
	tab[0] > 255 || tab[1] > 255 || tab[2] > 255)
		ft_free_rgb(data, stock, fd);
	free(stock);
	return ((tab[0] << 16) | (tab[1] << 8) | tab[2]);
}

void		ft_set_res(t_data *data, char *res, int fd)
{
	int i;
	int max_x;
	int max_y;

	i = 0;
	max_x = 0;
	max_y = 0;
	mlx_get_screen_size(data->mlx->ptr, &max_x, &max_y);
	if (!(res[i] >= '0' && res[i] <= '9') && res[i] != ' ')
	{
		free(res);
		ft_error(data, "cor_file", fd);
	}
	data->res->x = ft_atoi(res);
	data->res->x = (data->res->x > max_x) ? max_x : data->res->x;
	data->res->x = (data->res->x < 510) ? 510 : data->res->x;
	while (res[i] && (res[i] >= '0' && res[i] <= '9'))
		i++;
	while (res[i] && res[i] == ' ')
		i++;
	ft_set_res_2(data, res, fd, i);
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
