/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 15:53:44 by aurlic            #+#    #+#             */
/*   Updated: 2017/11/10 21:46:41 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		replace_with_zero(char *s, char c, size_t *adx, size_t *idx)
{
	*adx = 0;
	*idx = 0;
	if (!s)
		return ;
	while (*s)
		if (*s == c)
			*s++ = '\0';
		else
			++s;
}

char			**ft_strsplit(char const *s, char c)
{
	char	**split;
	char	*tmp;
	size_t	idx;
	size_t	adx;

	if (!s)
		return (NULL);
	if (!(tmp = ft_strdup(s)))
		return (NULL);
	replace_with_zero(tmp, c, &adx, &idx);
	if (!(split = (char **)malloc(sizeof(*split) * ft_strlen(s))))
		return (NULL);
	while (idx < ft_strlen(s) && s[idx] != '\0')
	{
		while (s[idx] == c)
			++idx;
		if (idx >= ft_strlen(s))
			break ;
		split[adx++] = ft_strdup(tmp + idx);
		while (tmp[idx] != '\0')
			++idx;
		++idx;
	}
	split[adx] = NULL;
	return (split);
}
