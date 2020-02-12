/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_itoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 11:38:42 by mbaxmann          #+#    #+#             */
/*   Updated: 2019/12/18 15:26:30 by mbaxmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convert_hexa(char *res, unsigned int nbr, int pow, char m)
{
	int					i;
	char				tab[16];

	i = 0;
	ft_hexa_init(tab, m);
	while (pow)
	{
		res[i] = tab[nbr % 16];
		nbr /= 16;
		i++;
		pow--;
	}
	res[i] = '\0';
	ft_reverse_tab(res);
}

int		ft_p_pow(unsigned int tr2)
{
	int pow;

	pow = 0;
	while (tr2)
	{
		tr2 /= 16;
		pow++;
	}
	return (pow);
}

char	*ft_hexa_itoa(unsigned int n, char m)
{
	int					i;
	int					pow;
	char				*res;

	i = 0;
	pow = 0;
	if (n == 0)
	{
		if (!(res = (char *)malloc(sizeof(char) * 2)))
			return (NULL);
		res[0] = '0';
		res[1] = '\0';
		return (res);
	}
	pow = ft_p_pow(n);
	if (!(res = (char *)malloc(sizeof(char) * (pow + 1))))
		return (NULL);
	ft_convert_hexa(res, n, pow, m);
	return (res);
}
