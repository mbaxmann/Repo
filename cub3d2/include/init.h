/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 09:17:58 by mbaxmann          #+#    #+#             */
/*   Updated: 2020/08/18 10:19:57 by mbaxmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

typedef struct	s_textur
{
	void		*img;
	char		*addr;
	int		height;
	int		width;
}		t_textur;

typedef struct	s_player
{
	double		x;
	double		y;
	double		angle;
}				t_player;

typedef struct	s_img
{
	int			bpp;
	int			line;
	int			endian;
	void		*img;
	char		*pt;
}				t_img;

typedef struct s_data
{
	char		**map;
	t_textur	**texture;
	char		*sprite;
	int			floor;
	int			ceil;
	t_dim		*res;
	t_player	*player;
	t_player	*stock;
	t_img		*img;
	t_mlx		*mlx;
}				t_data;

t_data		*ft_init(char *path, void *mlx_ptr);
t_textur	*ft_load_t(char *path, void *mlx_ptr);
void		ft_init_data(t_data *data);
void		ft_get_map(t_data *data, char *line, int fd);
void		ft_get_map2(t_data *data, char *line, int fd, t_list *first);
void		ft_sort(t_data *data, char *line, int fd, void *mlx_ptr);
void		ft_set_res(t_dim *dim, char *res);
void		ft_init_player(t_data *data, t_player **player);
int			ft_get_rgb(char *nb);
int			ft_check_data(t_data *data);
int			ft_check_map(char **map);
int			ft_check_char(char **map);
int			ft_check_char2(char **map, int i, int j);
int			ft_check_down(char **map, int i, int j);
int			ft_check_up(char **map, int i, int j);
int			ft_check_hole(char **map, int i, int j);

#endif
