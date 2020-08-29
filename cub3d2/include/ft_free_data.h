/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_data.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 09:54:12 by mbaxmann          #+#    #+#             */
/*   Updated: 2020/08/29 17:13:34 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FREE_DATA_H
# define FT_FREE_DATA_H

void	ft_free_map(char **map);
void	ft_free_texture(t_textur **texture);
void	ft_free_img(t_img **img);
void	ft_free_mlx(t_mlx *mlx);
void	ft_free_data(t_data *data);

#endif
