/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 10:10:11 by mbaxmann          #+#    #+#             */
/*   Updated: 2020/08/28 17:27:01 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

typedef struct s_list
{
	void	*data;
	struct s_list *next;
}				t_list;

void		ft_free_lst(t_list *first);
t_list		*ft_newlst(void *data);
void		ft_add_list(t_list *first, t_list *to_add);
int			ft_list_len(t_list *first);
t_list		*ft_get_list(t_list *first, int number);

#endif
