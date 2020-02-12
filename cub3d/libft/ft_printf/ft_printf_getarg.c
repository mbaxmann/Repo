/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_getarg.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 15:39:39 by mbaxmann          #+#    #+#             */
/*   Updated: 2019/12/18 15:03:26 by mbaxmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				ft_flagstab_init(char **flags_tab)
{
	*flags_tab = (char *)malloc(sizeof(char) * 15);
	flags_tab[0][0] = '-';
	flags_tab[0][1] = '0';
	flags_tab[0][2] = '.';
	flags_tab[0][3] = '*';
	flags_tab[0][4] = ' ';
	flags_tab[0][5] = 'c';
	flags_tab[0][6] = 's';
	flags_tab[0][7] = 'p';
	flags_tab[0][8] = 'd';
	flags_tab[0][9] = 'i';
	flags_tab[0][10] = 'u';
	flags_tab[0][11] = 'x';
	flags_tab[0][12] = 'X';
	flags_tab[0][13] = '%';
	flags_tab[0][14] = '\0';
}

int					ft_is_flags(char *flags_tab, char c, int r)
{
	int i;
	int j;

	i = 0;
	j = 5;
	while (flags_tab[i] && r)
	{
		if (flags_tab[i] == c || (c >= '0' && c <= '9'))
		{
			while (flags_tab[j])
			{
				if (flags_tab[j] == c)
					return (2);
				j++;
			}
			j = 4;
			return (1);
		}
		i++;
	}
	i = 0;
	return (0);
}

int					ft_pr_getnbr(const char *format, int *nbr, char ***tab)
{
	int		i;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
			(*nbr)++;
		i++;
	}
	if (!(*tab = (char **)malloc(sizeof(char *) * ((*nbr) + 1))))
		return (-1);
	(*tab)[*nbr] = NULL;
	i = 0;
	ft_pr_getflags(*tab, format);
	return (0);
}

void				ft_fill_lst(char **tab, t_printf_list **first, int nbr)
{
	int				i;
	int				len;
	t_printf_list	*current;

	i = 1;
	if (nbr--)
	{
		len = ft_strlen(tab[0]);
		*first = ft_pr_newlst(tab[0], ft_strdup(&tab[0][len - 1]));
		tab[0][len - 1] = '\0';
		if (*((*first)->type) == '%')
			nbr--;
		current = *first;
		while (nbr-- > 0)
		{
			len = ft_strlen(tab[i]);
			current = ft_pr_newlst(tab[i], ft_strdup(&tab[i][len - 1]));
			tab[i][len - 1] = '\0';
			ft_pr_add_list(*first, current);
			if (*(current->type) == '%')
				nbr--;
			i++;
		}
		ft_get_pad(first);
	}
}

void				ft_pr_getarg(const char *format, t_printf_list **first)
{
	int		nbr;
	char	**tab;

	nbr = 0;
	tab = NULL;
	ft_pr_getnbr(format, &nbr, &tab);
	ft_fill_lst(tab, first, nbr);
	if (tab)
		free(tab);
}
