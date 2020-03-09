/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 17:17:19 by mbaxmann          #+#    #+#             */
/*   Updated: 2020/03/09 12:34:02 by mbaxmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft/libft.h"

void	ft_set_player_position(t_position *player, int i, int j, char c)
{
	player->x = (j * CUBE_SIZE) + (CUBE_SIZE / 2);
	player->y = (i * CUBE_SIZE) + (CUBE_SIZE / 2);
	if (c == 'N')
		player->angle = M_PI_2;
	else if (c == 'E')
		player->angle = 0;
	else if (c == 'S')
		player->angle = 3 * M_PI_2;
	else if (c == 'W')
		player->angle = M_PI;
}

void	ft_find_player(t_position *player, char **map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == 'E' || map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'W')
				ft_set_player_position(player, i, j, map[i][j]);
			j++;
		}
		j = 0;
		i++;
	}
}

void	ft_file_texture_tab(char **tab, char *line)
{
	int i;

	i = 0;
	if (line[0] == 'N')
	{
		while (line[i] != '.')
			i++;
		tab[1] = ft_strdup(&line[i]);
	}
	else if (line[0] == 'S' && line[1] == 'O')
	{
		while (line[i] != '.')
			i++;
		tab[2] = ft_strdup(&line[i]);
	}
	else if (line[0] == 'E')
	{
		while (line[i] != '.')
			i++;
		tab[3] = ft_strdup(&line[i]);
	}
	else if (line[0] == 'W')
	{
		while (line[i] != '.')
			i++;
		tab[4] = ft_strdup(&line[i]);
	}
}

void	ft_file_data_tab(char **tab, char *line)
{
	int i;

	i = 0;
	if (line[0] == 'R')
	{
		while (line[i] > '9' || line[i] < '0')
			i++;
		tab[0] = ft_strdup(&line[i]);
	}
	else if (line[0] == 'F')
	{
		while (line[i] > '9' || line[i] < '0')
			i++;
		tab[5] = ft_strdup(&line[i]);
	}
	else if (line[0] == 'C')
	{
		while (line[i] > '9' || line[i] < '0')
			i++;
		tab[6] = ft_strdup(&line[i]);
	}
	else if (line[0] == 'S' && line[1] != 'O')
	{
		while (line[i] != '.')
			i++;
		tab[7] = ft_strdup(&line[i]);
	}
}

char	**ft_get_texture(int fd)
{
	char *line;
	int	i;
	int	j;
	char	**texture_tab;

	i = 0;
	j = 0;
	texture_tab = (char **)malloc(sizeof(char *) * 8);
	while (j < 8)
	{
		get_next_line(fd, &line);
		if (line[0] >= '0' && line[0] <= '9')
		{
			return (NULL);
		}
		while (line[i] && line[i] == ' ')
			i++;
		ft_file_texture_tab(texture_tab, &line[i]);
		ft_file_data_tab(texture_tab, &line[i]);
		if (line[0])
			j++;
		free(line);
		i = 0;
	}
	return (texture_tab);
}

char	**ft_get_map(int fd)
{
	char *line;
	char **map;
	t_list *first;
	int i;

	i = 1;
	get_next_line(fd, &line);
	while (line[0] != '1')
	{
		if (!i)
			return (NULL);
		free(line);
		i = get_next_line(fd, &line);
	}
	i = 0;
	first = ft_newlst(ft_strdup(line));
	free(line);
	while (get_next_line(fd, &line))
	{
		ft_add_list(first, ft_newlst(ft_strdup(line)));
		free(line);
	}
	map = (char **)malloc(sizeof(char *) * (ft_list_len(first) + 1));
	i = ft_list_len(first);
	fd = 0;
	while (i--)
	{
		map[fd++] = first->data;
		first = first->next;
	}
	map[fd] = NULL;
	return (map);
}

void	ft_init(char *path, char ***map, char ***tab, t_data *data)
{
	int fd;
	int i;
	t_position *pt;

	fd = 0;
	i = 0;
	fd = open(path, O_RDONLY);
	*tab = ft_get_texture(fd);
	*map = ft_get_map(fd);
	data->dim = (t_win_dim *)malloc(sizeof(t_win_dim));
	data->dim->x = ft_atoi(tab[0][0]);
	while (tab[0][0][i] >= '0' && tab[0][0][i] <= '9')
		i++;
	data->dim->y = ft_atoi(&tab[0][0][i]);
	ft_find_player(data->player, *map);
	data->map = *map;
	data->tab = *tab;
	pt = (t_position *)malloc(sizeof(t_position));
	data->pt = pt;
	data->tab2 = ft_load_textur(data);
}

/*int main(int ac, char **av)
{
	char **tab;
	char **map;
	ft_init(av[1], &map, &tab);
	int i = 0;
	if (tab)
	{
	while (i < 8)
	{
		ft_printf("%s\n", tab[i]);
		i++;
	}
	i = 0;
	while (map[i])
	{
		ft_printf("%s\n", map[i]);
		i++;
	}
	}
	else
		ft_printf("error\n");
	return (0);
}*/
