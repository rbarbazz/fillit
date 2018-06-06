/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 13:37:19 by aurlic            #+#    #+#             */
/*   Updated: 2017/11/11 19:00:54 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	start;
	size_t	len;

	start = 0;
	if (!s)
		return (NULL);
	while ((ft_iswhitespace(s, start) == 1))
		start++;
	if (s[start] == '\0')
		return (ft_strdup(s + start));
	len = ft_strlen(s) - 1;
	while ((ft_iswhitespace(s, len) == 1) && len > 0)
		len--;
	return (ft_strsub(s, start, len - start + 1));
}
