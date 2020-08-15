/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 09:58:49 by mbaxmann          #+#    #+#             */
/*   Updated: 2020/08/15 10:22:47 by mbaxmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EVENT_H
# define FT_EVENT_H

int		ft_button_event(int keycode, void *param);
int		ft_close(void *param);
void	ft_event(t_data *data);
void	ft_move_player(t_data *data, int keycode);

#endif
