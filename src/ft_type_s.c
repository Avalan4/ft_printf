/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstannis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 04:10:00 by cstannis          #+#    #+#             */
/*   Updated: 2021/01/31 04:10:02 by cstannis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

static char	*fill_spaces_s(const char *str, t_list *list)
{
	int		len_str;
	int		len_malloc;
	char	*str_malloc;

	len_str = (int)ft_strlen(str);
	if (list->acc >= len_str && list->acc != -1)
		len_malloc = len_str;
	else if (list->acc < len_str && list->acc != -1)
		len_malloc = list->acc;
	else
		len_malloc = len_str;
	if (len_malloc < list->width)
		len_malloc = list->width;
	str_malloc = (char *)malloc(sizeof(char) * len_malloc + 1);
	if (str_malloc == NULL)
		return (NULL);
	*(str_malloc + len_malloc) = '\0';
	ft_memset(str_malloc, ' ', (size_t)len_malloc);
	return (str_malloc);
}

static void	ft_fill_str(char *str_malloc, const char *str, t_list *list)
{
	int i;
	int	len_str;

	i = 0;
	len_str = ft_strlen(str);
	if (list->acc < len_str && list->acc != -1)
		len_str = list->acc;
	if (list->dash == 0)
		i = list->width - len_str;
	if (i < 0)
		i = 0;
	if (list->acc == -1)
		ft_memmove(str_malloc + i, str, ft_strlen(str));
	else
		ft_memmove(str_malloc + i, str, len_str);
}

void		ft_type_s(va_list args, t_list *list)
{
	const char	*str;
	char		*str_malloc;

	str = va_arg(args, const char *);
	if (str == NULL)
		str = "(null)";
	str_malloc = fill_spaces_s(str, list);
	if (str_malloc == NULL)
	{
		list->err = 1;
		return ;
	}
	list->ret = ft_strlen(str_malloc);
	ft_fill_str(str_malloc, str, list);
	ft_putstr_fd(str_malloc, 1);
	free(str_malloc);
}
