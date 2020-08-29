/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 09:17:33 by mbaxmann          #+#    #+#             */
/*   Updated: 2020/08/29 18:03:19 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_textur	*ft_load_t(char *path, void *mlx_ptr)
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
		ft_printf("Error: Could not load %s\n", path);
		free(path);
		exit(1);
	}
	size_line = textur->width * 4;
	textur->addr = mlx_get_data_addr(textur->img, &bpp, &size_line, &endian);
	free(path);
	return (textur);
}

void		ft_sort(t_data *data, char *line, int fd, void *mlx_ptr)
{
	char	*s;
	while (!ft_check_data(data) && get_next_line(fd, &line))
	{
		if (ft_strncmp(line, "", 2))
		{
			s = line;
			line = ft_strtrim(s, " ");
			free(s);
			if (line[0] == 'S' && line[1] == 'O')
				data->texture[1] = ft_load_t(ft_strtrim(line, " SO"), mlx_ptr);
			else if (line[0] == 'N')
				data->texture[0] = ft_load_t(ft_strtrim(line, " NO"), mlx_ptr);
			else if (line[0] == 'W')
				data->texture[2] = ft_load_t(ft_strtrim(line, " WE"), mlx_ptr);
			else if (line[0] == 'E')
				data->texture[3] = ft_load_t(ft_strtrim(line, " EA"), mlx_ptr);
			else if (line[0] == 'S')
				data->texture[4] = ft_load_t(ft_strtrim(line, " S"), mlx_ptr);
			else if (line[0] == 'F')
				data->floor = ft_get_rgb(ft_strtrim(line, " F"));
			else if (line[0] == 'C')
				data->ceil = ft_get_rgb(ft_strtrim(line, " C"));
			else if (line[0] == 'R')
				ft_set_res(data->res, ft_strtrim(line, " R"));
		}
		free(line);
	}
}

void		ft_get_map(t_data *data, char *line, int fd)
{
	t_list	*first;

	get_next_line(fd, &line);
	while (!ft_strncmp(line, "", 2))
	{
		free(line);
		get_next_line(fd, &line);
	}
	first = ft_newlst(ft_strdup(line));
	free(line);
	while (get_next_line(fd, &line) && ft_strncmp(line, "", 2))
	{
		ft_add_list(first, ft_newlst(ft_strdup(line)));
		free(line);
	}
	free(line);
	ft_get_map2(data, line, fd, first);
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
	data->floor = 0;
	data->ceil = 0;
	data->res = (t_dim *)malloc(sizeof(t_dim));
	data->res->x = 0;
	data->res->y = 0;
	data->player = NULL;
	data->img = (t_img **)malloc(sizeof(t_img *) * 2);
	data->mlx = NULL;
	data->mov[0] = 0;
	data->mov[1] = 0;
	data->mov[2] = 0;
	data->mov[3] = 0;
}

t_data		*ft_init(char *path, void *mlx_ptr)
{
	char	*line;
	t_data	*map;
	int		fd;

	line = NULL;
	map = NULL;
	fd = 0;
	map = (t_data *)malloc(sizeof(t_data));
	ft_init_data(map);
	fd = open(path, O_RDONLY);
	ft_sort(map, line, fd, mlx_ptr);
	if (!ft_check_data(map))
	{
		ft_printf("Error: Incomplete file\n");
		exit(1);
	}
	ft_get_map(map, line, fd);
	close(fd);
	if (ft_check_map(map->map))
	{
		ft_printf("Error: Invalid map\n");
		exit(1);
	}
	ft_init_player(map, &map->player);
	return (map);
}
