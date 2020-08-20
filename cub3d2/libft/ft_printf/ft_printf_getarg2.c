/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_getarg2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 13:12:22 by mbaxmann          #+#    #+#             */
/*   Updated: 2019/12/18 15:06:54 by mbaxmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_get_pad2(char *fl, int *i, t_printf_list *current)
{
	if (fl[*i] && fl[*i] == '.')
	{
		(*i)++;
		while (fl[*i] == '0')
			(*i)++;
		current->accuracy = ft_atoi(&fl[*i]);
		if (fl[*i] == '*')
			current->accuracy = -1;
		(*i) += ft_pow(current->accuracy);
	}
	else if (fl[*i])
	{
		current->pad = ft_atoi(&fl[*i]);
		if (fl[*i] == '*')
			current->pad = -1;
		(*i) += ft_pow(current->pad);
	}
}

void	ft_get_pad(t_printf_list **first)
{
	int				i;
	int				len;
	char			*fl;
	t_printf_list	*current;

	current = *first;
	while (current)
	{
		i = 0;
		fl = current->flags;
		len = ft_strlen(fl);
		while (i < len)
		{
			while (fl[i] && (fl[i] > '9' || fl[i] < '1')
						&& fl[i] != '.' && fl[i] != '*')
				i++;
			ft_get_pad2(fl, &i, current);
		}
		current = current->next;
	}
}

void	ft_pr_getflags2(char **tab, const char *format, char *flags_tab, int i)
{
	int j;
	int flags_nbr;
	int r;

	j = 0;
	flags_nbr = 0;
	while (format[++i])
	{
		r = 1;
		if (format[i] == '%' && format[i + 1])
		{
			while (format[i + 1 + flags_nbr] &&
			(r = ft_is_flags(flags_tab, format[i + 1 + flags_nbr], r)))
			{
				r = (r == 2) ? 0 : 1;
				flags_nbr++;
			}
			tab[j] = (char *)malloc(sizeof(char) * (flags_nbr + 1));
			tab[j][flags_nbr] = '\0';
			ft_memmove(tab[j], &format[i + 1], flags_nbr);
			j++;
			if (format[i + 1] == '%')
				i++;
			flags_nbr = 0;
		}
	}
}

void	ft_pr_getflags(char **tab, const char *format)
{
	char	*flags_tab;

	ft_flagstab_init(&flags_tab);
	ft_pr_getflags2(tab, format, flags_tab, -1);
	free(flags_tab);
}
