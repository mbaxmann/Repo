/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_function.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 10:28:24 by mbaxmann          #+#    #+#             */
/*   Updated: 2019/12/13 13:54:10 by mbaxmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_hexa_pow(int n)
{
	int i;

	i = 0;
	if (!n)
		return (0);
	while (n)
	{
		n /= 16;
		i++;
	}
	return (i);
}

int		ft_pow(int n)
{
	int i;

	i = 0;
	if (!n)
		return (1);
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

void	ft_hexa_init(char tab[16], char m)
{
	tab[0] = '0';
	tab[1] = '1';
	tab[2] = '2';
	tab[3] = '3';
	tab[4] = '4';
	tab[5] = '5';
	tab[6] = '6';
	tab[7] = '7';
	tab[8] = '8';
	tab[9] = '9';
	tab[10] = (m == 'x') ? 'a' : 'A';
	tab[11] = (m == 'x') ? 'b' : 'B';
	tab[12] = (m == 'x') ? 'c' : 'C';
	tab[13] = (m == 'x') ? 'd' : 'D';
	tab[14] = (m == 'x') ? 'e' : 'E';
	tab[15] = (m == 'x') ? 'f' : 'F';
}

void	ft_putnbr_u(unsigned int n)
{
	unsigned int	tr;

	tr = 0;
	if (n < 10)
	{
		n += '0';
		write(1, &n, 1);
	}
	else
	{
		tr = n / 10;
		n = n % 10;
		ft_putnbr_u(tr);
		ft_putnbr_u(n);
	}
}
