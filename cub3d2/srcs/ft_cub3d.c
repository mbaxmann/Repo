/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 09:54:12 by mbaxmann          #+#    #+#             */
/*   Updated: 2020/09/01 12:02:45 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_cub3d.h"

void		ft_error_2(char *err)
{
	if (!ft_strncmp(err, "path", 5))
		ft_putendl_fd("Error\nCould not open .cub file", 1);
	else if (!ft_strncmp(err, "file", 5))
		ft_putendl_fd("Error\nIncomplete file", 1);
	else if (!ft_strncmp(err, "map", 4))
		ft_putendl_fd("Error\nInvalid map", 1);
	else if (!ft_strncmp(err, "texture", 8))
		ft_putendl_fd("Error\nCould not load texture or/and sprite", 1);
	else if (!ft_strncmp(err, "split", 6))
		ft_putendl_fd("Error\nMap is split and/or not at the end of file", 1);
	else if (!ft_strncmp(err, "rgb_inv", 8))
		ft_putendl_fd("Error\nInvalid RGB color", 1);
	else if (!ft_strncmp(err, "rgb_ran", 8))
		ft_putendl_fd("Error\nInvalid RGB range", 1);
	else if (!ft_strncmp(err, "bmp", 8))
		ft_putendl_fd("Error\nCould not load save.bmp", 1);
}

void		ft_error(t_data *data, char *err, int fd)
{
	if (!ft_strncmp(err, "win", 4))
		ft_putendl_fd("Error\nmlx window failed", 1);
	else if (!ft_strncmp(err, "arg", 4))
		ft_putendl_fd("Error\nIncorrect number of argument", 1);
	else if (!ft_strncmp(err, "cub", 4))
		ft_putendl_fd("Error\nInvalid map extension", 1);
	else if (!ft_strncmp(err, "save", 5))
		ft_putendl_fd("Error\nInvalid argument", 1);
	else if (!ft_strncmp(err, "mlx", 4))
		ft_putendl_fd("Error\nmlx init failed", 1);
	ft_error_2(err);
	ft_free_data(data, fd);
	exit(1);
}

void		ft_open_window(t_mlx **mlx, t_data *data)
{
	if (((*mlx)->win = mlx_new_window((*mlx)->ptr,
		data->res->x, data->res->y, "cub3d")) == NULL)
		ft_error(data, "win", 0);
}

void		ft_valid_arg(int ac, char **av)
{
	if (ac == 1)
		ft_error(NULL, "arg", 0);
	else if (ac < 4)
	{
		if (ft_strncmp(av[1] + (ft_strlen(av[1]) - 4), ".cub", 4))
			ft_error(NULL, "cub", 0);
		if (ac == 3 && ft_strncmp(av[2], "--save", 7)
		&& ft_strncmp(av[2], "-save", 6))
			ft_error(NULL, "save", 0);
	}
	else
		ft_error(NULL, "arg", 0);
}

int			main(int ac, char **av)
{
	t_data			*data;
	t_mlx			*mlx;
	static short	b;

	b = 1;
	data = NULL;
	ft_valid_arg(ac, av);
	mlx = (t_mlx *)malloc(sizeof(t_mlx));
	mlx->win = NULL;
	if ((mlx->ptr = mlx_init()) == NULL)
		ft_error(data, "mlx", 0);
	data = ft_init(av[1], mlx);
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
