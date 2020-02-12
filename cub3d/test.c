/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 14:40:20 by mbaxmann          #+#    #+#             */
/*   Updated: 2020/02/12 16:18:02 by mbaxmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <mlx.h>
#include <fcntl.h>
#include "cub3d.h"
#include <stdio.h>

int	ft_test(int keycode, void *param)
{
	t_data *param2;
	param2 = param;
	void *img;
	if (keycode == 53)
		mlx_destroy_window(param2->mlx, param2->win);
	if (keycode == 124)
	{
		param2->player->angle -= (2 * M_PI) / 360;
	}
	if (keycode == 123)
	{
		param2->player->angle += (2 * M_PI) / 360;
	}
	mlx_clear_window(param2->mlx, param2->win);
	img = mlx_new_image(param2->mlx, 1920, 1080);
	ft_display_cub(param2->player, param2->map, param2, img);
	return (0);
}

/*void	ft_update_player_position(t_position *player)
{
	int x;
	int y;

	x = 0;
	y = 0;
}*/

void	ft_put_ray(t_data data, int l, int res1, int res2)
{
	int x = 0;
	int y = 0;

	x = res1;
	y = ((res2 - l) / 2) - 1;
	//printf("le l = %d\ntest : x = %d,	y = %d\n", l, x, y);
	while (l)
	{
		mlx_pixel_put(data.mlx, data.win, x, y, 248);
		y++;
		l--;
	}
}

int main(int ac, char **av)
{
	void *mlx_ptr;
	void *win_ptr;
	char **map;
	t_win_dim *win_dim;
	t_position player;

	int  i = 0;
	t_data *data;
	data->path = ft_strdup(av[1]);
	data->player = &player;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1920, 1080, "cub3d");
	mlx_do_key_autorepeaton(mlx_ptr);
	data->mlx = mlx_ptr;
	data->win = win_ptr;
	data->dim = win_dim;
	//ft_put_ray(data, 200, 512, 576);
	ft_algo(data->path, data, &map);
	data->map = map;
	mlx_hook(win_ptr, 2, 1L << 0, &ft_test, data);
	mlx_loop(mlx_ptr);
	return (0);
}
