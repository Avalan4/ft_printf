/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstannis <cstannis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 04:07:48 by cstannis          #+#    #+#             */
/*   Updated: 2021/02/02 05:52:44 by cstannis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

static int		ft_parser(const char *format, va_list args, t_list *list)
{
	int		i;
	int		step;
	int		count;

	i = 0;
	count = 0;
	while (*(format + i) != '\0')
	{
		if (*(format + i) == '%')
		{
			step = ft_set_list(format + i + 1, list, args);
			if (step == -1)
				return (-1);
			i += (step + 1);
			ft_type(args, list);
			if (list->err == 1)
				return (-1);
			count += list->ret;
			continue ;
		}
		write(1, format + i, 1);
		count++;
		i++;
	}
	return (count);
}

int				ft_printf(const char *format, ...)
{
	va_list		args;
	t_list		list;
	int			ret;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	ret = ft_parser(format, args, &list);
	va_end(args);
	return (ret);
}
