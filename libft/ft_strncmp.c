/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstannis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 18:32:31 by cstannis          #+#    #+#             */
/*   Updated: 2020/12/11 00:43:16 by cstannis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t len)
{
	size_t			i;
	unsigned char	*d1;
	unsigned char	*d2;

	i = 0;
	d1 = (unsigned char *)s1;
	d2 = (unsigned char *)s2;
	if (d1 == 0 && d2 == 0)
		return (0);
	if (len == 0)
		return (0);
	while ((d1[i] != '\0') && (d2[i] != '\0') && i < (len - 1))
	{
		if (d1[i] != d2[i])
			break ;
		i++;
	}
	return (d1[i] - d2[i]);
}
