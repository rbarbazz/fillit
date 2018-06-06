/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 09:44:17 by aurlic            #+#    #+#             */
/*   Updated: 2017/11/13 16:53:09 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*tmp;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (*needle == 0)
		return ((char *)haystack);
	while (haystack[j] && j < len)
	{
		tmp = (char *)(haystack + j);
		while (*tmp == needle[i] && (i + j) < (len - 1)
				&& *tmp && needle[i + 1])
		{
			tmp++;
			i++;
		}
		if (*tmp == needle[i] && (!needle[i] || needle[i + 1] == 0))
			return ((char *)(haystack + j));
		i = 0;
		j++;
	}
	return (NULL);
}
