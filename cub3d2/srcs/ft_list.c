/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 16:21:16 by mbaxmann          #+#    #+#             */
/*   Updated: 2020/09/01 12:04:27 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_cub3d.h"

void				ft_free_lst(t_list *first)
{
	t_list *stock;

	while (first)
	{
		stock = first;
		first = first->next;
		free(stock->data);
		free(stock);
	}
}

t_list				*ft_newlst(void *data)
{
	t_list *new;

	if (!(new = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	new->data = data;
	new->next = NULL;
	return (new);
}

void				ft_add_list(t_list *first, t_list *to_add)
{
	t_list *current;

	current = first;
	if (first != to_add)
	{
		if (first)
		{
			while (current->next != NULL)
				current = current->next;
			current->next = to_add;
		}
		else
			first = to_add;
	}
}

int					ft_list_len(t_list *first)
{
	t_list	*current;
	int		count;

	count = 0;
	if (first)
		count++;
	current = first;
	while (current->next != NULL)
	{
		current = current->next;
		count++;
	}
	return (count);
}

t_list				*ft_get_list(t_list *first, int number)
{
	t_list	*current;
	int		len;

	current = first;
	number--;
	len = ft_list_len(first);
	len--;
	while (number && len)
	{
		current = current->next;
		number--;
		len--;
	}
	return (current);
}
