/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iswhitespace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 13:43:27 by aurlic            #+#    #+#             */
/*   Updated: 2017/11/10 15:13:01 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_iswhitespace(const char *str, int index)
{
	if (str[index] == 32 || str[index] == 9 || str[index] == 10)
		return (1);
	if (str[index] == '\0')
		return (2);
	return (0);
}
