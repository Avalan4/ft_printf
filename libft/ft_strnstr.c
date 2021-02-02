/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstannis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 18:46:45 by cstannis          #+#    #+#             */
/*   Updated: 2020/12/11 00:44:34 by cstannis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *big, const char *small, size_t len)
{
	size_t		i;
	size_t		j;
	char		*b;
	char		*s;

	b = (char*)big;
	s = (char*)small;
	i = 0;
	if (ft_strlen(s) == '\0')
		return (b);
	while (i < len && b[i])
	{
		j = 0;
		while (i + j < len && b[i + j] == s[j] && s[j])
			j++;
		if (s[j] == '\0')
			return (b + i);
		i++;
	}
	return (NULL);
}
