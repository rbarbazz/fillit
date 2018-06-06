/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 15:45:28 by aurlic            #+#    #+#             */
/*   Updated: 2017/11/13 11:11:56 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*begin;
	t_list	*it;

	if (!lst)
		return (NULL);
	it = f(lst);
	if (!(new = ft_lstnew(it->content, it->content_size)))
		return (NULL);
	begin = new;
	lst = lst->next;
	while (lst)
	{
		it = f(lst);
		if (!(new->next = ft_lstnew(it->content, it->content_size)))
			return (NULL);
		new = new->next;
		lst = lst->next;
	}
	return (begin);
}
