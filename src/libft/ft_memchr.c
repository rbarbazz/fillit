/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:48:22 by aurlic            #+#    #+#             */
/*   Updated: 2017/11/09 10:18:37 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *ss;
	unsigned char ch;

	ch = (unsigned char)c;
	ss = (unsigned char *)s;
	while (n--)
	{
		if (*ss == ch)
			return (ss);
		if (n)
			ss++;
	}
	return (NULL);
}
