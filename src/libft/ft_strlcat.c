/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 18:11:53 by aurlic            #+#    #+#             */
/*   Updated: 2017/11/15 16:54:47 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t src_length;
	size_t dst_length;

	dst_length = ft_strlen(dst);
	src_length = ft_strlen(src);
	i = 0;
	if (size <= dst_length)
		return (src_length + size);
	while (dst[i] && i < size - 1)
		i++;
	while (i < size - 1 && *src)
	{
		dst[i] = *src;
		i++;
		src++;
	}
	dst[i] = '\0';
	return (dst_length + src_length);
}
