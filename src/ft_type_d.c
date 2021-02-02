/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstannis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 04:09:38 by cstannis          #+#    #+#             */
/*   Updated: 2021/01/31 04:09:40 by cstannis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

void	ft_type_d(va_list args, t_list *list)
{
	int		nb;
	int		len_nb;
	char	*str_nb;
	char	*str;

	nb = va_arg(args, int);
	str_nb = ft_itoa(nb);
	if (str_nb == NULL)
	{
		list->err = 1;
		return ;
	}
	len_nb = ft_strlen(str_nb);
	str = ft_fill_spaces(nb, list, len_nb);
	if (list->err == 1)
		return ;
	list->ret = ft_strlen(str);
	ft_fill_zeros(str, list, nb, 10);
	ft_fill_number(str, str_nb, list, nb);
	ft_fill_minus(str, list, nb);
	if (nb == 0 && list->acc == 0)
		ft_memset(str, ' ', ft_strlen(str));
	ft_putstr_fd(str, 1);
	free(str);
	free(str_nb);
}
