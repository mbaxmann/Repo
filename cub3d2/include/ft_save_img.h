/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_img.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 09:54:12 by mbaxmann          #+#    #+#             */
/*   Updated: 2020/08/30 18:14:33 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SAVE_IMG_H
# define FT_SAVE_IMG_H

void		ft_save_img(t_data *data);
void		ft_write_bmp(t_data *data, int fd);
void		ft_wimg_header(t_data *data, int fd);
void		ft_wfile_header(t_data *data, int fd);

#endif
