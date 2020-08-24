/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_sprite.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 10:18:48 by mbaxmann          #+#    #+#             */
/*   Updated: 2020/08/24 17:20:03 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LOAD_SPRITE_H
# define FT_LOAD_SPRITE_H

int	ft_load_sprite(t_data *data, double *stock);
void	ft_sort_sprite(t_list *sprite);
void	ft_copy_data(t_vector *dest, t_vector *second);
void	ft_calculate_sprite_dist(t_data *data, t_list * sprite);

#endif
