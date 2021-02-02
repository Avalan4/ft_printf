/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstannis <cstannis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 04:09:23 by cstannis          #+#    #+#             */
/*   Updated: 2021/02/02 06:30:32 by cstannis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_type(va_list args, t_list *list)
{
	if (list->spec == 'd' || list->spec == 'i')
		ft_type_d(args, list);
	else if (list->spec == 'u')
		ft_type_u(args, list);
	else if (list->spec == 'x' || list->spec == 'X')
		ft_type_x(args, list);
	else if (list->spec == 'c' || list->spec == '%')
		ft_type_c(args, list);
	else if (list->spec == 's')
		ft_type_s(args, list);
	else if (list->spec == 'p')
		ft_type_p(args, list);
	else if (list->spec == '\0')
		return ;
	else
		list->err = 1;
}
