/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstannis <cstannis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 04:09:10 by cstannis          #+#    #+#             */
/*   Updated: 2021/02/02 06:25:04 by cstannis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

int		ft_set_list(const char *str_type, t_list *list, va_list args)
{
	int	step;
	int	acc_return;

	step = 0;
	list->dash = 0;
	list->zero = 0;
	list->acc = -1;
	list->width = 0;
	list->err = 0;
	list->ret = 0;
	list->spec = '\0';
	step += ft_set_flags(str_type, list);
	step += ft_set_width(str_type + step, list, args);
	if (list->err == 1)
		return (-1);
	acc_return = ft_set_acc(str_type + step, list, args);
	if (acc_return == -1)
	{
		list->err = 1;
		return (-1);
	}
	step += acc_return;
	step += ft_set_spec(str_type + step, list);
	ft_set_excep(list);
	return (step);
}

int		ft_set_flags(const char *str_type, t_list *list)
{
	int i;

	i = 0;
	while (*(str_type + i) == '-' || *(str_type + i) == '0')
	{
		if (*(str_type + i) == '-')
			list->dash = 1;
		if (*(str_type + i) == '0')
			list->zero = 1;
		i++;
	}
	return (i);
}

int		ft_set_width(const char *str_type, t_list *list, va_list args)
{
	int		i;
	char	*width;

	i = 0;
	if (*(str_type + i) == '*')
	{
		list->width = va_arg(args, int);
		return (1);
	}
	while (ft_isdigit(*(str_type + i)) > 0)
		i++;
	width = ft_substr(str_type, 0, i);
	if (width == NULL)
	{
		list->err = 1;
		return (-1);
	}
	list->width = ft_atoi(width);
	free(width);
	return (i);
}

int		ft_set_acc(const char *str_type, t_list *list, va_list args)
{
	int		i;
	int		j;
	char	*acc;

	i = 0;
	j = 0;
	if (*(str_type + j) == '.')
		j++;
	else
		return (0);
	if (*(str_type + i + j) == '*')
	{
		list->acc = va_arg(args, int);
		return (2);
	}
	while (ft_isdigit(*(str_type + j + i)) > 0)
		i++;
	acc = ft_substr(str_type + j, 0, i);
	if (acc == NULL)
		return (-1);
	list->acc = ft_atoi(acc);
	free(acc);
	return (i + j);
}

int		ft_set_spec(const char *str_type, t_list *list)
{
	list->spec = *(str_type + 0);
	return (1);
}
