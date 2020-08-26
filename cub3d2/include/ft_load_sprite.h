/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_sprite.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 10:18:48 by mbaxmann          #+#    #+#             */
/*   Updated: 2020/08/26 12:23:44 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LOAD_SPRITE_H
# define FT_LOAD_SPRITE_H

int	ft_load_sprite(t_data *data, double *stock);
void	ft_sort_sprite(t_list *sprite);
void	ft_copy_data(t_vector *dest, t_vector *second);
void	ft_calculate_sprite_dist(t_data *data, t_list * sprite);
void	ft_setup_spritedisp(t_data *data, int offset[2], int var[5]);
void	ft_spritedisp_loop(t_data *data, double *cmp[2], int offset[2], int var[5]);

#endif
