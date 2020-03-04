/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 16:26:15 by mbaxmann          #+#    #+#             */
/*   Updated: 2020/03/04 16:34:09 by mbaxmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include <math.h>
#include <fcntl.h>
#include <mlx.h>
#include "libft/libft.h"
#include <time.h>
#include <stdio.h>

# define CUBE_SIZE 64
# define A write(1, "A", 1);
# define B write(1, "B", 1);

typedef struct s_win_dim
{
	int x;
	int y;
}		t_win_dim;

typedef struct 	s_list
{
	char *data;
	struct s_list	*next;
}		t_list;

typedef struct s_position
{
	double x;
	double y;
	double angle;
}		t_position;

typedef	struct s_data
{
	void *mlx;
	void *win;
	void *img;
	t_position *player;
	t_position *pt;
	char **map;
	char *path;
	char **tab;
	char **tab2;
	t_win_dim *dim;
}		t_data;

void	ft_free_lst(t_list *first);
t_list	*ft_newlst(char *data);
void	ft_add_list(t_list *first, t_list *to_add);
int	ft_list_len(t_list *first);
t_list	*ft_get_list(t_list *first, int number);
char	**ft_get_map(int fd);
void	ft_find_player(t_position *player, char **map);
void	ft_set_player_position(t_position *player, int i, int j, char c);
void	ft_init(char *path, char ***map, char ***tab, t_data *data);
char	**ft_get_texture(int fd);
void	ft_file_texture_tab(char **tab, char *line);
void	ft_file_data_tab(char **tab, char *line);
void	ft_algo(char *path, t_data *data, char ***map);
void	ft_display_cub(t_position *player, t_data *data, void *img);
int	ft_calculate_slice_size(t_data *data, t_position *C, t_position *O, double angle);
void	ft_check_verticaly(t_position *play, char **map, t_position *C, double angle, double dir);
void	ft_check_horizontaly(t_position *player, char **map, t_position *O, double angle, double dir);
void	ft_put_ray(t_data data, int l, int res1, int res2);
void	ft_update_player_position(t_position *player, int keycode, char **map);
double	ft_modulo_pi(double nb);
void	ft_check_wall_collision(t_position *player, char **map, int keycode);
int	ft_isok(t_position *pt, char **map);
void	ft_texturing(t_data *data, char *img, int size, int size_line);
char	**ft_load_textur(t_data *data);
void	ft_fill_up(char *pixel, int start, int end, t_data *data);
int		ft_offset(int size, t_data *data);
unsigned int	ft_get_color(t_data *data, int start);

#endif
