/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 10:09:31 by mbaxmann          #+#    #+#             */
/*   Updated: 2019/12/18 15:09:27 by mbaxmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_get_str(t_printf_list *current)
{
	char *str;

	if (*(current->type) == 's')
		return (ft_strdup(current->s));
	else if (*(current->type) == 'c')
	{
		str = (char *)malloc(sizeof(char) * 2);
		str[0] = (char)(current->c);
		str[1] = '\0';
		return (str);
	}
	else if (*(current->type) == 'd' || *(current->type) == 'i')
		return (ft_itoa((current->d), 'd'));
	else if (*(current->type) == 'u')
		return (ft_itoa((current->d), 'u'));
	else if (*(current->type) == 'p')
		return (ft_p_itoa(current->p));
	else if (*(current->type) == 'x' || *(current->type) == 'X')
		return (ft_hexa_itoa((current->x), *(current->type)));
	else if (*(current->type) == '%')
		return (ft_strdup("%"));
	return (str);
}

char			*ft_display_arg(t_printf_list *current, unsigned char *d_case)
{
	char *str;

	str = ft_get_str(current);
	if (*(current->type) == 'c' && (current->c) == 0)
	{
		current->pad--;
		if ((*d_case | 128) == *d_case)
			write(1, "\0", 1);
	}
	ft_pad_flags(current, d_case, &str);
	ft_putstr_fd(str, 1, 0);
	if (*(current->type) == 'c' && (current->c) == 0
				&& (*d_case | 128) != *d_case)
		write(1, "\0", 1);
	return (str);
}

unsigned char	ft_get_case(t_printf_list *current)
{
	int				i;
	unsigned char	d_case;
	char			*fl;

	i = 0;
	d_case = 0;
	fl = current->flags;
	while (fl[i])
	{
		d_case = d_case | ft_check_flags(fl, i);
		i++;
	}
	return (d_case);
}

int				ft_return(char *str)
{
	return (ft_strlen(str));
}
