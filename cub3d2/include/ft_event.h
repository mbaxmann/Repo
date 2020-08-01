/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 09:58:49 by mbaxmann          #+#    #+#             */
/*   Updated: 2020/08/01 10:04:16 by mbaxmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EVENT_H
# define FT_EVENT_H

int		ft_button_event(int keycode, void *param);
int		ft_close(void *param);
void	ft_event(t_mlx *mlx);

#endif
