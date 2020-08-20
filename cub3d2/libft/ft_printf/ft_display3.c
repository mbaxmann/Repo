/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 13:59:28 by mbaxmann          #+#    #+#             */
/*   Updated: 2019/12/18 15:29:22 by mbaxmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		ft_check_flags(char *s, int i)
{
	unsigned char ret;

	ret = 0;
	if (s[i] == '-')
		ret = 128;
	else if (s[i] == '0')
	{
		while (i >= 0)
		{
			if ((s[i] >= '1' && s[i] <= '9') || s[i] == '.')
			{
				return (0);
			}
			i--;
		}
		ret = 64;
	}
	else if (s[i] == '.')
		ret = 32;
	else if (s[i] == '*')
		ret = 0;
	else if (s[i] >= '0' && s[i] <= '9')
		ret = 0;
	return (ret);
}

int			ft_type(t_printf_list *current)
{
	if (*(current->type) == 'x' || *(current->type) == 'X')
		return (current->x);
	else if (*(current->type) == 'p')
		return ((long int)(current->p));
	else
		return (current->d);
}

void		ft_point_flags(t_printf_list *current, char **str)
{
	if (*(current->type) == 's' && (current->accuracy <
				(int)ft_strlen(*str)) && current->accuracy >= 0)
		str[0][current->accuracy] = '\0';
	if (*(current->type) != 's' && *(current->type) != 'c'
			&& *(current->type) != '%')
	{
		if (current->accuracy > (int)ft_strlen(*str))
		{
			current->accuracy -= ft_strlen(*str);
			while (current->accuracy > 0)
			{
				*str = ft_strjoin(ft_strdup("0"), *str);
				current->accuracy--;
			}
		}
		else if (!current->accuracy && !ft_type(current))
			str[0][0] = '\0';
	}
}

int			ft_isnbr(t_printf_list *current)
{
	if (*(current->type) == 'i' || *(current->type) == 'd'
		|| *(current->type) == 'x' || *(current->type) == 'X')
		return (1);
	return (0);
}

int			ft_isneg(t_printf_list *current)
{
	if (*(current->type) == 'x' || *(current->type) == 'X')
	{
		if ((current->x) < 0)
			return (1);
	}
	else if ((current->d) < 0)
		return (1);
	return (0);
}
