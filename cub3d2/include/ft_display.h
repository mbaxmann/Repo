/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 09:21:35 by mbaxmann          #+#    #+#             */
/*   Updated: 2020/08/21 13:35:32 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DISPLAY_H
# define FT_DISPLAY_H

void		ft_load_ray(t_data *data, int size, int offset);
void		ft_init_img(t_data *data);
void		ft_put_pixel(char *img, char *xpm, int i, int j);
void		ft_calculate_xpm_offset(int *tab, t_data *data, int size);
void		ft_coloring(t_data *data, long long i, long long j, int mode);
void		ft_init_tab(int tab[5]);
int		ft_choose_textur(t_data *data);

#endif
