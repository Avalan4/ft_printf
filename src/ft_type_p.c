/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstannis <cstannis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 04:09:46 by cstannis          #+#    #+#             */
/*   Updated: 2021/02/02 06:08:02 by cstannis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

static char	*ft_fill_spaces_p(char *str_nb, t_list *list)
{
	int					len_str;
	char				*str;

	len_str = ft_strlen(str_nb) + 2;
	if (list->acc == 0 && ft_cmpstr(str_nb, "0") == 1)
		len_str = 2;
	if (list->acc == -1 && ft_cmpstr(str_nb, "0") == 1)
		len_str = 3;
	if (len_str < list->width)
		len_str = list->width;
	str = (char *)malloc(sizeof(char) * len_str + 1);
	if (str == NULL)
	{
		list->err = 1;
		return (NULL);
	}
	ft_memset(str, ' ', (size_t)len_str);
	*(str + len_str) = '\0';
	return (str);
}

static void	ft_fill_addr(char *str, char *str_nb, t_list *list)
{
	int						i;
	int						j;
	int						len_str;

	i = 0;
	j = 0;
	len_str = ft_strlen(str);
	if (list->dash == 0)
		i = len_str - (int)ft_strlen(str_nb) - 2;
	if (list->dash == 0 && ft_cmpstr(str_nb, "0") == 1 && list->acc == 0)
		i++;
	if (i < 0)
		i = 0;
	*(str + i) = '0';
	*(str + i + 1) = 'x';
	i = i + 2;
	while (*(str_nb + j) != '\0')
	{
		if (!(ft_cmpstr(str_nb, "0") == 1 && list->acc == 0))
			*(str + i) = *(str_nb + j);
		i++;
		j++;
	}
}

void		ft_type_p(va_list args, t_list *list)
{
	unsigned long long	addr;
	char				*str_nb;
	char				*str;

	addr = va_arg(args, unsigned long long);
	str_nb = ft_ultoa_hex(addr);
	if (str_nb == NULL)
	{
		list->err = 1;
		return ;
	}
	str = ft_fill_spaces_p(str_nb, list);
	if (list->err == 1)
		return ;
	list->ret = ft_strlen(str);
	ft_fill_addr(str, str_nb, list);
	ft_putstr_fd(str, 1);
	free(str_nb);
	free(str);
}
