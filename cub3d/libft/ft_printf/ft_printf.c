/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 13:52:01 by mbaxmann          #+#    #+#             */
/*   Updated: 2019/12/18 15:09:42 by mbaxmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_return_arg(va_list *begin, t_printf_list *current)
{
	if (*(current->type) == 's')
	{
		current->s = va_arg(*begin, char *);
		if (!current->s)
			current->s = "(null)";
	}
	else if (*(current->type) == 'c')
		current->c = va_arg(*begin, int);
	else if (*(current->type) == 'i' ||
			*(current->type) == 'd' || *(current->type) == 'u')
		current->d = (va_arg(*begin, int));
	else if (*(current->type) == 'x' ||
				*(current->type) == 'X')
		current->x = va_arg(*begin, unsigned int);
	else if (*(current->type) == 'p')
		current->p = (va_arg(*begin, void *));
}

void	ft_check_star(t_printf_list *current, va_list *begin)
{
	if (current->pad == -1)
	{
		current->pad = va_arg(*begin, int);
		if (current->pad < 0)
		{
			current->pad = -(current->pad);
			current->flags = ft_strjoin(ft_strdup("-"), current->flags);
		}
	}
	if (current->accuracy == -1)
	{
		current->accuracy = va_arg(*begin, int);
		current->accuracy = (current->accuracy >= 0) ? current->accuracy : -2;
	}
}

int		ft_printf(const char *format, ...)
{
	va_list			begin;
	t_printf_list	*first;
	t_printf_list	*current;
	int				i;

	if (format == 0)
		return (0);
	first = NULL;
	ft_pr_getarg(format, &first);
	current = first;
	va_start(begin, format);
	while (current)
	{
		ft_check_star(current, &begin);
		ft_return_arg(&begin, current);
		current = current->next;
	}
	i = ft_display(first, format);
	ft_free_list(first);
	va_end(begin);
	return (i);
}
