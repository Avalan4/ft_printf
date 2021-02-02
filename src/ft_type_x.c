/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstannis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 04:10:12 by cstannis          #+#    #+#             */
/*   Updated: 2021/01/31 04:10:21 by cstannis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

static void	ft_put_x(char *str_result, char *str_nb)
{
	ft_putstr_fd(str_result, 1);
	free(str_nb);
	free(str_result);
}

void		ft_type_x(va_list args, t_list *list)
{
	unsigned int	nb;
	int				len_nb;
	char			*str_nb;
	char			*str_result;

	nb = va_arg(args, unsigned int);
	str_nb = ft_ultoa_hex(nb);
	if (str_nb == NULL)
	{
		list->err = 1;
		return ;
	}
	len_nb = (int)ft_strlen(str_nb);
	str_result = ft_fill_spaces(nb, list, len_nb);
	if (list->err == 1)
		return ;
	list->ret = ft_strlen(str_result);
	ft_fill_zeros(str_result, list, nb, 16);
	ft_fill_number(str_result, str_nb, list, nb);
	if (nb == 0 && list->acc == 0)
		ft_memset(str_result, ' ', ft_strlen(str_result));
	if (list->spec == 'X')
		ft_toupper_str(str_result);
	ft_put_x(str_result, str_nb);
}
