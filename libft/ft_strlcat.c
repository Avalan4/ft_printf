/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstannis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 17:40:33 by cstannis          #+#    #+#             */
/*   Updated: 2020/12/11 00:18:43 by cstannis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t len)
{
	size_t	i;
	size_t	dst_size;
	size_t	src_size;

	i = 0;
	dst_size = ft_strlen(dst);
	src_size = ft_strlen(src);
	if (len < dst_size + 1)
		return (len + src_size);
	if (len > dst_size + 1)
	{
		while (src[i] != '\0' && dst_size + 1 + i < len)
		{
			dst[dst_size + i] = src[i];
			i++;
		}
	}
	dst[i + dst_size] = '\0';
	return (dst_size + src_size);
}
