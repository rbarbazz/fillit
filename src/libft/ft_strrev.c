/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 13:43:11 by aurlic            #+#    #+#             */
/*   Updated: 2017/11/11 13:45:13 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		nbrcar;
	int		j;
	char	k;

	nbrcar = 0;
	j = 0;
	k = 0;
	while (str[nbrcar] != '\0')
	{
		nbrcar++;
	}
	while (j < nbrcar / 2)
	{
		k = str[j];
		str[j] = str[nbrcar - j - 1];
		str[nbrcar - j - 1] = k;
		j++;
	}
	return (str);
}
