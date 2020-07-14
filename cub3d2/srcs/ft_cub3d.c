/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 09:54:12 by mbaxmann          #+#    #+#             */
/*   Updated: 2020/07/14 10:27:31 by mbaxmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		main()
{

	void	*mlx_ptr;
	void	*mlx_win;

	if ((mlx_ptr = mlx_init()) == NULL)
	{
		ft_printf("mlx init failed");
		return (1);
	}
	if ((mlx_win = mlx_new_window(mlx_ptr, 1080, 960, "cub3d")) == NULL)
	{
		ft_printf("mlx window failed");
		return (1);
	}
	mlx_loop(mlx_ptr);
}
