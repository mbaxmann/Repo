/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 09:58:49 by mbaxmann          #+#    #+#             */
/*   Updated: 2020/09/01 11:10:48 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EVENT_H
# define FT_EVENT_H

int		ft_button_event(int keycode, void *param);
int		ft_button_event_2(int keycode, void *param);
int		ft_close(void *param);
int		ft_hitbox(t_player *player, t_data *data);
void	ft_sethitbox(int hitbox[8]);
void	ft_event(t_data *data);
void	ft_move_player(t_data *data, int keycode);
void	ft_move_part_1(t_data *data, int keycode);
void	ft_move_part_2(t_data *data, int keycode);

#endif
