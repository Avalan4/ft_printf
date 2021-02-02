/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstannis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 19:55:04 by cstannis          #+#    #+#             */
/*   Updated: 2020/12/10 23:31:36 by cstannis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_word_len(const char *s, char c)
{
	int		i;

	i = 0;
	while (s[i] && (s[i] != c))
		i++;
	return (i);
}

static int		ft_word_count(const char *s, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[j])
	{
		while ((s[j] == c) && s[j])
			j++;
		if (!s[j])
			break ;
		i++;
		while ((s[j] != c) && s[j])
			j++;
	}
	return (i);
}

static void		ft_clearsplit(char **str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

static char		**ft_fill(char **str, char *s, char ch, int len)
{
	int		i;
	int		g;

	i = 0;
	while (i < len)
	{
		while (*s == ch && *s)
			s++;
		g = ft_word_len(s, ch);
		str[i] = ft_substr(s, 0, g);
		if (!str[i])
		{
			ft_clearsplit(str);
			return (NULL);
		}
		while (*s != ch && *s)
			s++;
		i++;
	}
	str[i] = NULL;
	return (str);
}

char			**ft_split(char const *s, char c)
{
	int		len;
	char	**res;
	char	*d;

	d = (char *)s;
	if (!d)
		return (NULL);
	len = ft_word_count(d, c);
	if (!(res = (char**)malloc(sizeof(char*) * (len + 1))))
		return (NULL);
	res = ft_fill(res, d, c, len);
	return (res);
}
