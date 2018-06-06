/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 11:05:00 by aurlic            #+#    #+#             */
/*   Updated: 2017/11/15 10:30:33 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*str;
	char	*tmp;
	long	l;

	if (!(str = ft_strnew(0)))
		return (NULL);
	if (!(tmp = ft_strnew(1)))
		return (NULL);
	l = (long)n;
	l = l < 0 ? -l : l;
	if (l == 0)
		str[0] = '0';
	while (l)
	{
		tmp[0] = (l % 10) + 48;
		if (!(str = ft_strjoin(tmp, str)))
			return (NULL);
		l = l / 10;
	}
	if (n < 0)
		if (!(str = ft_strjoin((char*)("-"), str)))
			return (NULL);
	return (str);
}
