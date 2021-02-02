/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstannis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 04:09:32 by cstannis          #+#    #+#             */
/*   Updated: 2021/01/31 04:09:34 by cstannis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

static char	*ft_fill_spaces_c(t_list *list)
{
	int		len_str;
	char	*str;

	if (list->width == 0)
		len_str = 1;
	else
		len_str = list->width;
	str = (char *)malloc(sizeof(char) * len_str + 1);
	if (str == NULL)
		return (NULL);
	*(str + len_str) = '\0';
	list->ret = len_str;
	ft_memset(str, ' ', (size_t)len_str);
	if (list->zero == 1)
		ft_memset(str, '0', (size_t)len_str);
	return (str);
}

static void	ft_exception_zero(unsigned char c, t_list *list)
{
	int		i;
	int		spaces;

	i = 0;
	if (list->width == 0 || list->width == 1)
		spaces = 0;
	else
		spaces = list->width - 1;
	if (list->dash == 1)
		ft_putchar_fd(c, 1);
	while (i < spaces)
	{
		ft_putchar_fd(' ', 1);
		i++;
	}
	if (list->dash == 0)
		ft_putchar_fd(c, 1);
	list->ret = spaces + 1;
}

void		ft_type_c(va_list args, t_list *list)
{
	unsigned char	c;
	char			*str;

	c = '%';
	if (list->spec != '%')
		c = va_arg(args, int);
	if (c == 0)
	{
		ft_exception_zero(c, list);
		return ;
	}
	str = ft_fill_spaces_c(list);
	if (str == NULL)
	{
		list->err = 1;
		return ;
	}
	if (list->dash == 0)
		*(str + ft_strlen(str) - 1) = c;
	else
		*(str + 0) = c;
	ft_putstr_fd(str, 1);
	free(str);
}
