/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 15:40:19 by mbaxmann          #+#    #+#             */
/*   Updated: 2020/01/24 13:57:01 by mbaxmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "../libft.h"

typedef struct	s_printf_list
{
	char					*s;
	int						c;
	int						d;
	void					*p;
	long int				x;
	char					*type;
	char					*flags;
	int						pad;
	int						accuracy;
	struct s_printf_list	*next;
}				t_printf_list;

int				ft_printf(const char *format, ...);
void			ft_free_list(t_printf_list *first);
int				ft_strlen_free(char *str);
t_printf_list	*ft_pr_newlst(char *flags, char *type);
void			ft_pr_add_list(t_printf_list *first, t_printf_list *to_add);
int				ft_pr_list_len(t_printf_list *first);
t_printf_list	*ft_pr_get_list(t_printf_list *first, int number);
void			ft_pr_getarg(const char *format, t_printf_list **first);
void			ft_fill_lst(char **tab, t_printf_list **first, int nbr);
int				ft_pr_getnbr(const char *format, int *nbr, char ***tab);
void			ft_pr_getflags(char **tab, const char *format);
void			ft_pr_getflags2(char **tab, const char *format,
				char *flags_tab, int i);
int				ft_is_flags(char *flags_tab, char c, int r);
void			ft_flagstab_init(char **flags_tab);
void			ft_get_pad(t_printf_list **first);
void			ft_get_pad2(char *fl, int *i, t_printf_list *current);
void			ft_putnbr_u(unsigned int n);
void			ft_hexa_init(char tab[16], char m);
int				ft_display(t_printf_list *first, const char *format);
int				ft_return(char *str);
unsigned char	ft_get_case(t_printf_list *current);
char			*ft_display_arg(t_printf_list *current, unsigned char *d_case);
char			*ft_get_str(t_printf_list *current);
void			ft_pad_flags2(t_printf_list *current, unsigned char *d_case,
				char **str, char *str2);
void			ft_pad_flags(t_printf_list *current,
				unsigned char *d_case, char **str);
void			ft_point_flags(t_printf_list *current, char **str);
char			ft_check_flags(char *s, int i);
int				ft_pow(int n);
int				ft_p_pow(unsigned int tr2);
char			*ft_hexa_itoa(unsigned int n, char m);
int				ft_display2(t_printf_list **current, const char *format,
				unsigned char *d_case, int *i);
void			ft_convert_hexa(char *res, unsigned int nbr, int pow, char m);
int				ft_isnbr(t_printf_list *current);
int				ft_isneg(t_printf_list *current);
int				ft_type(t_printf_list *current);
void			ft_check_star(t_printf_list *current, va_list *begin);
char			*ft_p_itoa(void *p);

#endif
