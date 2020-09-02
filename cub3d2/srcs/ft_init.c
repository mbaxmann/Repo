/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 09:17:33 by mbaxmann          #+#    #+#             */
/*   Updated: 2020/09/02 11:00:21 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_cub3d.h"

t_textur	*ft_load_t(t_data *data, char *path, void *mlx_ptr, int fd)
{
	int			bpp;
	int			endian;
	int			size_line;
	t_textur	*textur;

	bpp = 32;
	endian = 1;
	textur = (t_textur *)malloc(sizeof(t_textur));
	textur->img = mlx_xpm_file_to_image(mlx_ptr, path,
	&(textur->width), &(textur->height));
	if (!textur->img)
	{
		free(textur->img);
		free(textur);
		free(path);
		ft_error(data, "texture", fd);
	}
	size_line = textur->width * 4;
	textur->addr = mlx_get_data_addr(textur->img, &bpp, &size_line, &endian);
	free(path);
	return (textur);
}

void		ft_get_map(t_data *data, int fd)
{
	t_list	*first;
	char	*tmp;

	tmp = ft_strtrim(data->line, " ");
	while (!ft_strncmp(tmp, "", 2))
	{
		free(tmp);
		free(data->line);
		get_next_line(fd, &(data->line));
		tmp = ft_strtrim(data->line, " ");
	}
	ft_check_line(data, fd);
	first = ft_newlst(ft_strdup(data->line));
	free(tmp);
	free(data->line);
	while (get_next_line(fd, &(data->line)) && ft_strncmp(data->line, "", 1))
	{
		ft_add_list(first, ft_newlst(ft_strdup(data->line)));
		free(data->line);
	}
	ft_get_map2(data, fd, first);
}

void		ft_init_data(t_data *data)
{
	data->map = NULL;
	data->sprite = NULL;
	data->texture = (t_textur **)malloc(sizeof(t_textur *) * 5);
	data->texture[0] = NULL;
	data->texture[1] = NULL;
	data->texture[2] = NULL;
	data->texture[3] = NULL;
	data->texture[4] = NULL;
	data->stock = (t_player *)malloc(sizeof(t_player));
	data->floor = -1;
	data->ceil = -1;
	data->res = (t_dim *)malloc(sizeof(t_dim));
	data->res->x = 0;
	data->res->y = 0;
	data->player = NULL;
	data->img = (t_img **)malloc(sizeof(t_img *) * 2);
	data->img[0] = NULL;
	data->img[1] = NULL;
	data->mlx = NULL;
	data->mov[0] = 0;
	data->mov[2] = 0;
	data->mov[4] = 0;
	data->line = NULL;
}

t_data		*ft_init(char *path, t_mlx *mlx)
{
	t_data	*map;
	int		fd;

	map = NULL;
	fd = 0;
	map = (t_data *)malloc(sizeof(t_data));
	ft_init_data(map);
	map->mlx = mlx;
	if ((fd = open(path, O_RDONLY)) <= 0)
		ft_error(map, "path", 0);
	ft_sort(map, fd, mlx);
	if (!ft_check_data(map))
		ft_error(map, "file", fd);
	ft_get_map(map, fd);
	close(fd);
	if (ft_check_map(map->map))
		ft_error(map, "map", 0);
	ft_init_player(map, &map->player);
	return (map);
}
