/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstannis <cstannis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 04:07:54 by cstannis          #+#    #+#             */
/*   Updated: 2021/02/02 06:30:56 by cstannis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft/libft.h"
# include <stdarg.h>

typedef struct	s_list
{
	int			dash;
	int			zero;
	int			acc;
	int			width;
	int			err;
	int			ret;
	char		spec;

}				t_list;

int				ft_printf(const char *format, ...);
int				ft_set_list(const char *str_conv, t_list *list, va_list args);
int				ft_set_flags(const char *str_conv, t_list *list);
int				ft_set_width(const char *str_conv, t_list *list, va_list args);
int				ft_set_acc(const char *str_conv, t_list *list, va_list args);
int				ft_set_spec(const char *str_conv, t_list *list);
void			ft_set_excep(t_list *list);
void			ft_type(va_list args, t_list *list);
void			ft_type_d(va_list args, t_list *list);
void			ft_type_u(va_list args, t_list *list);
void			ft_type_x(va_list args, t_list *list);
void			ft_type_c(va_list args, t_list *list);
void			ft_type_s(va_list args, t_list *list);
void			ft_type_p(va_list args, t_list *list);
char			*ft_fill_spaces(long nb, t_list *list, int len_nb);
void			ft_fill_zeros(char *str, t_list *list, long nb, int base);
void			ft_fill_number(char *str, char *str_nb, t_list *list, long nb);
void			ft_fill_minus(char *str, t_list *list, long nb);

#endif
