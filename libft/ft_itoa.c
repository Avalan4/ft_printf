/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstannis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 19:50:56 by cstannis          #+#    #+#             */
/*   Updated: 2020/12/10 23:38:22 by cstannis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_num_len(int n)
{
	size_t			len;
	long long		n1;

	n1 = n;
	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n1 = n1 * -1;
		len++;
	}
	while (n1 > 0)
	{
		n1 = n1 / 10;
		len++;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	size_t			i;
	char			*result;
	long long int	n1;

	n1 = (long long int)n;
	i = ft_num_len(n1);
	result = (char*)malloc(sizeof(char) * i + 1);
	if (!result)
		return (NULL);
	result[i--] = '\0';
	if (n1 == 0)
		result[0] = '0';
	if (n1 < 0)
	{
		result[0] = '-';
		n1 = n1 * -1;
	}
	while (n1 > 0)
	{
		result[i--] = (n1 % 10) + '0';
		n1 = n1 / 10;
	}
	return (result);
}
