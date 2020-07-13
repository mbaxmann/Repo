/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 14:35:00 by mbaxmann          #+#    #+#             */
/*   Updated: 2020/02/12 15:09:26 by mbaxmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int			i;
	int			minus;
	long int	res;

	i = 0;
	minus = 1;
	res = 0;
	while (str[i])
	{
		while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
			i++;
		if (str[i] == '-' || str[i] == '+')
			minus = (str[i++] == '-') ? -minus : minus;
		while (str[i] >= '0' && str[i] <= '9' && res * 10 < 2147483648)
			res = res * 10 + (str[i++] - '0');
		if (str[i] >= '0' && str[i] <= '9' && minus == -1)
			return (0);
		if (str[i] >= '0' && str[i] <= '9' && minus == 1)
			return (-1);
		return (res * minus);
	}
	return (res * minus);
}
