/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 13:55:50 by mbaxmann          #+#    #+#             */
/*   Updated: 2019/12/18 15:13:25 by mbaxmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_strlen_free(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	free(str);
	return (i);
}

int		ft_display2(t_printf_list **current, const char *format,
			unsigned char *d_case, int *i)
{
	int count;

	count = 0;
	while (format[*i] && format[*i] != '%')
	{
		count++;
		ft_putchar_fd(format[(*i)++], 1);
	}
	if (format[(*i) + 1] == ' ' && ft_isnbr(*current)
				&& ((*current)->d) >= 0)
	{
		write(1, " ", 1);
		(*current)->pad--;
		count++;
	}
	(*i)++;
	if (*((*current)->type) == 'p')
		(*current)->pad -= 2;
	while (format[*i] != *((*current)->type))
		(*i)++;
	if (*((*current)->type) == 'c' && ((*current)->c) == 0)
		count++;
	count += ft_strlen_free(ft_display_arg(*current, d_case));
	*current = (*current)->next;
	return (count);
}

int		ft_display(t_printf_list *first, const char *format)
{
	unsigned char	d_case;
	t_printf_list	*current;
	int				i;
	int				count;

	i = 0;
	count = 0;
	current = first;
	while (current)
	{
		d_case = ft_get_case(current);
		count += ft_display2(&current, format, &d_case, &i);
		i++;
	}
	while (format[i] && format[i] != '%')
	{
		count++;
		ft_putchar_fd(format[i++], 1);
	}
	return (count);
}

void	ft_pad_flags2(t_printf_list *current, unsigned char *d_case,
				char **str, char *str2)
{
	if (ft_isnbr(current) && (*d_case | 64) != *d_case && ft_isneg(current))
		*str = ft_strjoin(ft_strdup("-"), *str);
	if ((*d_case | 64) != *d_case && *(current->type) == 'p')
		*str = ft_strjoin(ft_strdup("0x"), *str);
	if ((*d_case | 128) == *d_case)
		*str = ft_strjoin(*str, str2);
	else
		*str = ft_strjoin(str2, *str);
	if (ft_isnbr(current) && ft_isneg(current) && (*d_case | 64) == *d_case)
		*str = ft_strjoin(ft_strdup("-"), *str);
	if ((*d_case | 64) == *d_case && *(current->type) == 'p')
		*str = ft_strjoin(ft_strdup("0x"), *str);
}

void	ft_pad_flags(t_printf_list *current, unsigned char *d_case, char **str)
{
	char *pad;
	char *str2;

	str2 = NULL;
	if ((*d_case | 32) == *d_case)
		ft_point_flags(current, str);
	current->pad -= ft_strlen(*str);
	if ((*d_case | 64) == *d_case && ((*d_case | 128) == *d_case
				|| (current->accuracy) > -1))
		*d_case = *d_case & 191;
	if ((*d_case | 64) == *d_case)
		pad = "0";
	else
		pad = " ";
	if (ft_isnbr(current) && ft_isneg(current))
		current->pad--;
	while (current->pad > 0)
	{
		str2 = ft_strjoin(str2, ft_strdup(pad));
		(current->pad)--;
	}
	ft_pad_flags2(current, d_case, str, str2);
}
