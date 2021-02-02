/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstannis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 19:49:50 by cstannis          #+#    #+#             */
/*   Updated: 2020/12/10 23:30:06 by cstannis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_getstart(const char *s1, const char *set)
{
	size_t		len;
	size_t		i;

	len = ft_strlen(s1);
	i = 0;
	while (i < len)
	{
		if (!(ft_strchr(set, s1[i])))
			break ;
		i++;
	}
	return (i);
}

int			ft_getend(const char *s1, const char *set)
{
	size_t		len;
	size_t		i;

	len = ft_strlen(s1);
	i = 0;
	while (i < len)
	{
		if (!(ft_strchr(set, s1[len - i - 1])))
			break ;
		i++;
	}
	return (len - i);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int			start;
	int			end;
	char		*newstr;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	start = ft_getstart(s1, set);
	end = ft_getend(s1, set);
	if (start >= end)
		return (ft_strdup(""));
	if (!(newstr = (char *)malloc(sizeof(char) * (end - start) + 1)))
		return (NULL);
	ft_strlcpy(newstr, s1 + start, end - start + 1);
	return (newstr);
}
