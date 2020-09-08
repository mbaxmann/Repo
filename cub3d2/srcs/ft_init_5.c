/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 10:34:49 by mbaxmann          #+#    #+#             */
/*   Updated: 2020/09/08 15:50:15 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_cub3d.h"

void		ft_rgb_pass(char **nb, char *stock, int fd, t_data *data)
{
	while (ft_isdigit(**nb))
		*nb += 1;
	while (**nb == ' ')
		*nb += 1;
	if (**nb == ',')
		*nb += 1;
	while (**nb == ' ')
		*nb += 1;
	if (!ft_isdigit(**nb))
	{
		free(stock);
		ft_error(data, "rgb_inv", fd);
	}
}

void		ft_free_rgb(t_data *data, char *stock, int fd)
{
	free(stock);
	ft_error(data, "rgb_inv", fd);
}
