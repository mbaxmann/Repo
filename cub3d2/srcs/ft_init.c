/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 09:17:33 by mbaxmann          #+#    #+#             */
/*   Updated: 2020/07/29 10:59:35 by mbaxmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void		ft_sort(t_data *data, char *line, int fd)
{
	while (get_next_line(fd, &line) && !ft_check_data(data))
	{
		if (ft_strncmp(line, "", 2))
		{
			line = ft_strtrim(line, " ");
			if (line[0] == 'S' && line[1] == 'O')
				data->texture[1] = ft_strdup(ft_strtrim(line, " SO"));
			else if (line[0] == 'N')
				data->texture[0] = ft_strdup(ft_strtrim(line, " NO"));
			else if (line[0] == 'W')
				data->texture[2] = ft_strdup(ft_strtrim(line, " WE"));
			else if (line[0] == 'E')
				data->texture[3] = ft_strdup(ft_strtrim(line, " EA"));
			else if (line[0] == 'S')
				data->sprite = ft_strdup(ft_strtrim(line, " S"));
			else if (line[0] == 'F')
				data->floor = ft_get_rgb(ft_strtrim(line, " F"));
			else if (line[0] == 'C')
				data->ceil = ft_get_rgb(ft_strtrim(line, " C"));
			else if (line[0] == 'R')
				ft_set_res(data->res, ft_strtrim(line, " R"));
			free(line);
		}
	}
}

void		ft_get_map(t_data *data, char *line, int fd)
{
	t_list	*first;
	t_list	*current;
	int		i;

	i = 0;
	get_next_line(fd, &line);
	while (!ft_strncmp(line, "", 2))
	{
		free(line);
		get_next_line(fd, &line);
	}
	first = ft_newlst(line);
	current = first;
	while (get_next_line(fd, &line) && ft_strncmp(line, "", 2))
	{
		ft_add_list(first, ft_newlst(ft_strdup(line)));
		free(line);
	}
	/*while (get_next_line(fd, &line))
	{
		if (ft_strncmp(line, "", 2))
		{
			ft_printf("Error: map is split and/or not at the end of file\n");
			exit(1);
		}
		free(line);
	}
	data->map = (char **)malloc(sizeof(char *) * (ft_list_len(first) + 1));
	while (current->next)
	{
		data->map[i++] = current->data;
		current = current->next;
	}
	data->map[i++] = current->data;
	data->map[i] = ft_strdup("");*/
	ft_get_map2(data, line, fd, first, current);
}

void		ft_init_data(t_data *data)
{
	data->map = NULL;
	data->texture = (char **)malloc(sizeof(char *) * 4);
	data->texture[0] = NULL;
	data->texture[1] = NULL;
	data->texture[2] = NULL;
	data->texture[3] = NULL;
	data->sprite = NULL;
	data->floor = 0;
	data->ceil = 0;
	data->res->x = 0;
	data->res->y = 0;
}

t_data		*ft_init(char *path)
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
	ft_sort(map, line, fd);
	if (!ft_check_data(map))
	{
		ft_printf("Error: Incomplete file\n");
		exit(1);
	}
	ft_get_map(map, line, fd);
	if (ft_check_map(map->map))
	{
		ft_printf("Error: Invalid map\n");
		exit(1);
	}
	return (map);
}

int main()
{
	t_data *data = NULL;
	data = ft_init("map2.cub");
	ft_printf("%s\n%s\n%s\n%s\n", data->texture[0], data->texture[1], data->texture[2], data->texture[3]);
	ft_printf("%s\n", data->sprite);
	ft_printf("c : %d\nf : %d\n", data->ceil, data->floor);
	ft_printf("x : %d	y : %d\n", data->res->x, data->res->y);
	int i = 0;
	while (data->map[i][0])
	{
		ft_printf("%s\n", data->map[i]);
		i++;
	}
	return (0);
}
