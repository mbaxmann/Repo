/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 09:17:58 by mbaxmann          #+#    #+#             */
/*   Updated: 2020/09/01 15:00:14 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# define CUBE 64
# define SPEED 16
# define R_SPEED 80

typedef struct	s_dim
{
	int	x;
	int	y;
}				t_dim;

typedef struct	s_vector
{
	double	x;
	double	y;
	int		dir_x;
	int		dir_y;
	double	angle;
}				t_vector;

typedef struct	s_mlx
{
	void	*ptr;
	void	*win;
}				t_mlx;

typedef struct	s_textur
{
	void		*img;
	char		*addr;
	int			height;
	int			width;
}				t_textur;

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

typedef struct	s_data
{
	char		*line;
	char		**map;
	t_textur	**texture;
	int			floor;
	int			ceil;
	t_dim		*res;
	t_player	*player;
	t_player	*stock;
	t_img		**img;
	t_mlx		*mlx;
	t_list		*sprite;
	int			mov[6];
}				t_data;

t_data			*ft_init(char *path, t_mlx *mlx);
t_textur		*ft_load_t(t_data *data, char *path, void *mlx_ptr, int fd);
void			ft_init_data(t_data *data);
void			ft_get_map(t_data *data, int fd);
void			ft_get_map2(t_data *data, int fd, t_list *first);
void			ft_sort(t_data *data, int fd, t_mlx *mlx);
void			ft_sort_2(t_data *data, int fd, t_mlx *mlx);
void			ft_sort_3(t_data *data, int fd, t_mlx *mlx);
void			ft_set_res(t_dim *dim, char *res);
void			ft_init_player(t_data *data, t_player **player);
int				ft_get_rgb(t_data *data, char *nb, int fd);
int				ft_check_data(t_data *data);
int				ft_check_map(char **map);
int				ft_check_char(char **map);
int				ft_check_char2(char **map, int i, int j);
int				ft_check_down(char **map, int i, int j);
int				ft_check_up(char **map, int i, int j);
int				ft_check_hole(char **map, int i, int j);

#endif
