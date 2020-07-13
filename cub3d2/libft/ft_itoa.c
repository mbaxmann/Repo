/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 14:57:40 by mbaxmann          #+#    #+#             */
/*   Updated: 2019/12/10 14:10:49 by mbaxmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_reverse_tab(char *tab)
{
	int		i;
	int		size;
	char	tr[ft_strlen(tab) + 1];

	i = 0;
	size = ft_strlen(tab);
	while (tab[i])
	{
		tr[size - 1 - i] = tab[i];
		i++;
	}
	tr[size] = '\0';
	i = 0;
	while (tr[i])
	{
		tab[i] = tr[i];
		i++;
	}
	tab[i] = '\0';
}

void	ft_convert(char *res, int nbr, int pow, char m)
{
	int				i;
	unsigned int	tr;

	i = 0;
	if (m == 'd')
		tr = (nbr < 0) ? -nbr : nbr;
	else
		tr = (unsigned int)nbr;
	while (pow)
	{
		res[i] = (tr % 10) + 48;
		tr /= 10;
		i++;
		pow--;
	}
	if (nbr < 0 && m == '0')
	{
		res[i] = '-';
		res[i + 1] = '\0';
	}
	else
		res[i] = '\0';
	ft_reverse_tab(res);
}

int		ft_power(unsigned int tr)
{
	int pow;

	pow = 0;
	while (tr)
	{
		tr /= 10;
		pow++;
	}
	return (pow);
}

char	*ft_itoa(int n, char m)
{
	int				x;
	unsigned int	tr;
	int				pow;
	char			*res;

	if (m == 'd')
		tr = (n < 0) ? -n : n;
	else
		tr = (unsigned int)n;
	pow = 0;
	if (n == 0)
	{
		if (!(res = (char *)malloc(sizeof(char) * 2)))
			return (NULL);
		res[0] = '0';
		res[1] = '\0';
		return (res);
	}
	pow = ft_power(tr);
	x = (n < 0) ? 1 : 0;
	if (!(res = (char *)malloc(sizeof(char) * (pow + 1 + x))))
		return (NULL);
	ft_convert(res, n, pow, m);
	return (res);
}
