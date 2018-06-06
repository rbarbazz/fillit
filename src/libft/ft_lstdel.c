/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 16:06:32 by aurlic            #+#    #+#             */
/*   Updated: 2017/11/11 16:07:00 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list*nxt;
	t_list*lst;

	lst = *alst;
	nxt = NULL;
	while (lst)
	{
		nxt = lst->next;
		del(lst->content, lst->content_size);
		free(lst);
		lst = nxt;
	}
	*alst = NULL;
}
