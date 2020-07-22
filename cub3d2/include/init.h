/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 09:17:58 by mbaxmann          #+#    #+#             */
/*   Updated: 2020/07/22 10:40:41 by mbaxmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

typedef struct s_data
{
	char		**map;
	char		**texture;
	char		*sprite;
	int			floor;
	int			ceil;
	t_dim		*res;
}				t_data;

t_data		*ft_init(char *path);
void		ft_init_data(t_data *data);
void		ft_get_map(t_data *data, char *line, int fd);
void		ft_sort(t_data *data, char *line, int fd);
void		ft_set_res(t_dim *dim, char *res);
int			ft_get_rgb(char *nb);
int			ft_check_data(t_data *data);
int			ft_check_map(char **map);
int			ft_check_char(char **map);
int			ft_check_char2(char **map, int i, int j);
int			ft_check_side_h(int j, char **map);
int			ft_check_side_l(int j, char **map);

#endif
