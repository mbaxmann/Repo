/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 15:54:57 by mbaxmann          #+#    #+#             */
/*   Updated: 2019/12/18 14:57:37 by mbaxmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				ft_free_list(t_printf_list *first)
{
	t_printf_list *stock;

	while (first)
	{
		stock = first;
		first = first->next;
		if (*(stock->type) == 's' || *(stock->type) == 'c' ||
		*(stock->type) == 'i' || *(stock->type) == 'd' || *(stock->type) == 'p'
		|| *(stock->type) == 'x' || *(stock->type) == 'X' ||
		*(stock->type) == '%' || *(stock->type) == 'u')
		{
			free(stock->type);
			free(stock->flags);
		}
		free(stock);
	}
}

t_printf_list		*ft_pr_newlst(char *flags, char *type)
{
	t_printf_list *new;

	if (!(new = (t_printf_list *)malloc(sizeof(t_printf_list))))
		return (NULL);
	new->type = type;
	new->flags = flags;
	new->pad = 0;
	new->accuracy = -2;
	new->next = NULL;
	return (new);
}

void				ft_pr_add_list(t_printf_list *first, t_printf_list *to_add)
{
	t_printf_list *current;

	current = first;
	if (first != to_add)
	{
		while (current->next != NULL)
			current = current->next;
		current->next = to_add;
	}
}

int					ft_pr_list_len(t_printf_list *first)
{
	t_printf_list	*current;
	int				count;

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

t_printf_list		*ft_pr_get_list(t_printf_list *first, int number)
{
	t_printf_list	*current;
	int				len;

	current = first;
	number--;
	len = ft_pr_list_len(first);
	len--;
	while (number && len)
	{
		current = current->next;
		number--;
		len--;
	}
	return (current);
}
