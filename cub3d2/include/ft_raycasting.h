/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 10:23:29 by mbaxmann          #+#    #+#             */
/*   Updated: 2020/08/12 09:45:31 by mbaxmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RAYCASTING_H
# define FT_RAYCASTING_H

int			ft_calculate_ray(t_data *data, double alpha);
int			ft_iswall(t_vector *pt, t_data *data);
int			ft_raycasting(t_data *data, t_mlx *mlx);
int			ft_calculate_slice(t_data *data, t_vector *pt_1, t_vector *pt_2, double angle);
void		ft_init_pt(t_vector *pt, double aplha, t_data *data, int mode);
void		ft_set_angle(double *angle, t_vector *pt_1, t_vector *pt_2);
void		ft_init_player(t_data *data, t_player **player);
void		ft_init_vector(t_vector **pt_1, t_vector **pt_2, double alpha);
void		ft_modulo_pi(double *angle);

#endif
