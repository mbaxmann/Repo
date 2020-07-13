/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_itoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 13:57:52 by mbaxmann          #+#    #+#             */
/*   Updated: 2019/12/18 15:26:00 by mbaxmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_pt_pow(void *p)
{
	int					i;
	unsigned long int	tr;

	i = 0;
	tr = (unsigned long int)p;
	while (tr)
	{
		tr = tr / 16;
		i++;
	}
	return (i);
}

void	ft_convert_hexa_pt(char *res, void *p, int pow)
{
	int					i;
	unsigned long	int	tr;
	char				tab[16];

	i = 0;
	ft_hexa_init(tab, 'x');
	tr = (unsigned long int)p;
	while (pow)
	{
		res[i] = tab[tr % 16];
		tr /= 16;
		i++;
		pow--;
	}
	res[i] = '\0';
	ft_reverse_tab(res);
}

char	*ft_p_itoa(void *p)
{
	int					i;
	int					pow;
	char				*res;

	i = 0;
	pow = 0;
	if (p == 0)
	{
		if (!(res = (char *)malloc(sizeof(char) * 2)))
			return (NULL);
		res[0] = '0';
		res[1] = '\0';
		return (res);
	}
	pow = ft_pt_pow(p);
	if (!(res = (char *)malloc(sizeof(char) * (pow + 1))))
		return (NULL);
	ft_convert_hexa_pt(res, p, pow);
	return (res);
}
