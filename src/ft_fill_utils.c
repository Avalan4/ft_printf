/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstannis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 04:07:33 by cstannis          #+#    #+#             */
/*   Updated: 2021/01/31 04:07:36 by cstannis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_fill_minus(char *str, t_list *list, long nb)
{
	int i;

	i = 0;
	while (ft_isdigit(*(str + i)) == 0 && nb < 0 && list->dash == 0)
		i++;
	i--;
	if (i < 0)
		i = 0;
	if (nb < 0 && list->dash == 0)
		*(str + i) = '-';
}

void	ft_fill_number(char *str, char *str_nb, t_list *list, long nb)
{
	int i;
	int j;

	if (nb < 0 && list->dash == 1)
		*(str + 0) = '-';
	i = ft_strlen(str) - 1;
	j = ft_strlen(str_nb) - 1;
	if (i < 0)
		i = 0;
	while (i >= 0 && *(str + i) == ' ' && list->dash == 1)
		i--;
	while (j >= 0 && *(str_nb + j) != '-')
	{
		if (*str == '\0' || (list->acc == 0 && nb == 0))
			break ;
		*(str + i) = *(str_nb + j);
		i--;
		j--;
	}
}

char	*ft_fill_spaces(long nb, t_list *list, int len_nb)
{
	int		len_str;
	char	*str;

	if (len_nb >= list->acc)
		len_str = len_nb;
	else
		len_str = list->acc;
	if (len_str < list->width)
		len_str = list->width;
	if (nb == 0 && list->acc == 0)
		len_str = list->width;
	if (nb < 0 && list->acc >= len_nb && list->acc >= list->width)
		len_str++;
	str = (char *)malloc(sizeof(char) * len_str + 1);
	if (str == NULL)
	{
		list->err = 1;
		return (NULL);
	}
	if (list->zero == 0)
		ft_memset(str, ' ', (size_t)len_str);
	else
		ft_memset(str, '0', (size_t)len_str);
	*(str + len_str) = '\0';
	return (str);
}

void	ft_fill_zeros(char *str, t_list *list, long nb, int base)
{
	int i;
	int j;
	int	acc;

	acc = list->acc;
	if (list->acc == -1)
		acc = 0;
	if (list->dash == 0)
		i = ft_strlen(str) - acc;
	else
	{
		if (nb < 0)
			i = 1;
		else
			i = 0;
	}
	j = 0;
	while (*(str + i) != '\0' && (j < acc || j < ft_nblen(nb, base)))
	{
		*(str + i) = '0';
		i++;
		j++;
	}
}

void	ft_set_excep(t_list *list)
{
	if (list->acc < -1)
		list->acc = -1;
	if (list->acc != -1)
	{
		if (list->spec != '%')
			list->zero = 0;
	}
	if (list->width < 0)
	{
		list->width = list->width * -1;
		list->dash = 1;
	}
	if (list->dash == 1)
		list->zero = 0;
}
