/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 09:54:12 by mbaxmann          #+#    #+#             */
/*   Updated: 2020/07/30 10:57:54 by mbaxmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void		ft_open_window(t_mlx **mlx, t_data *data)
{
	*mlx = (t_mlx *)malloc(sizeof(t_mlx));
	if (((*mlx)->ptr = mlx_init()) == NULL)
	{
		ft_printf("mlx init failed");
		exit(1);
	}
	if (((*mlx)->win = mlx_new_window((*mlx)->ptr, data->res->x, data->res->y, "cub3d")) == NULL)
	{
		ft_printf("mlx window failed");
		exit(1);
	}
}

void	ft_valid_arg(int ac, char **av)
{
	if (ac == 1)
	{
		ft_printf("Error: Not enough argument\n");
		exit(1);
	}
	else if (ac < 4)
	{
		if (ft_strncmp(av[1] + (ft_strlen(av[1]) - 4), ".cub", 4))
		{
			ft_printf("Error: Invalid map extension\n");
			exit(1);
		}
		if (ac == 3 && ft_strncmp(av[2], "--save", ft_strlen(av[2])))
		{
			ft_printf("Error: Invalid argument\n");
			exit(1);
		}
	}
	else
	{
		ft_printf("Error: Too much argument\n");
		exit(1);
	}
}

int		ft_event(int keycode, void *param)
{
	if (keycode == 53)
	{
		mlx_destroy_window(((t_mlx *)param)->ptr, ((t_mlx *)param)->win);
		exit(0);
	}
	return (1);
}

int		main(int ac, char **av)
{
	t_data	*data;
	t_mlx	*mlx;

	ft_valid_arg(ac, av);
	data = ft_init(av[1]);
	ft_open_window(&mlx, data);
	mlx_hook(mlx->win, 2, 1L << 0, &ft_event, mlx);
	mlx_loop(mlx->ptr);
	return (0);
}
