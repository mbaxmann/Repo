/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 09:54:12 by mbaxmann          #+#    #+#             */
/*   Updated: 2020/07/13 10:43:16 by mbaxmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "mlx/mlx.h"
#include <fcntl.h>
#include <stdio.h>

int		main(int ac, char **av)
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
	int fd = open(av[1], O_RDONLY);
	char *line = NULL;
	while (get_next_line(fd, &line))
	{
		write(1, "A", 1);
		ft_printf("%s\n", line);
		free(line);
	}
	mlx_loop(mlx_ptr);
}
