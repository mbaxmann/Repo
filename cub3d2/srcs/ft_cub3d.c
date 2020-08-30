/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 09:54:12 by mbaxmann          #+#    #+#             */
/*   Updated: 2020/08/30 18:23:31 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void		ft_open_window(t_mlx **mlx, t_data *data)
{
	if (((*mlx)->win = mlx_new_window((*mlx)->ptr,
		data->res->x, data->res->y, "cub3d")) == NULL)
	{
		ft_putendl_fd("Error\nmlx window failed", 1);
		exit(1);
	}
}

void		ft_valid_arg(int ac, char **av)
{
	if (ac == 1)
	{
		ft_putendl_fd("Error\nNot enough argument", 1);
		exit(1);
	}
	else if (ac < 4)
	{
		if (ft_strncmp(av[1] + (ft_strlen(av[1]) - 4), ".cub", 4))
		{
			ft_putendl_fd("Error\nInvalid map extension", 1);
			exit(1);
		}
		if (ac == 3 && ft_strncmp(av[2], "--save", 7) && ft_strncmp(av[2], "-save", 6))
		{
			ft_putendl_fd("Error\nInvalid argument", 1);
			exit(1);
		}
	}
	else
	{
		ft_putendl_fd("Error\nToo much argument", 1);
		exit(1);
	}
}

int			main(int ac, char **av)
{
	t_data	*data;
	t_mlx	*mlx;
	static short b;

	b = 1;
	ft_valid_arg(ac, av);
	mlx = (t_mlx *)malloc(sizeof(t_mlx));
	if ((mlx->ptr = mlx_init()) == NULL)
	{
		ft_putendl_fd("Error\nmlx init failed", 1);
		exit(1);
	}
	data = ft_init(av[1], mlx->ptr);
	data->mlx = mlx;
	ft_init_img(data);
	if (ac == 3 && b)
	{
		ft_save_img(data);
		b = 0;
	}
	ft_open_window(&mlx, data);
	ft_event(data);
	mlx_loop_hook(mlx->ptr, &ft_loop, data);
	mlx_loop(mlx->ptr);
	return (0);
}
