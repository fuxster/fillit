/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuciu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 18:00:20 by psuciu            #+#    #+#             */
/*   Updated: 2017/01/08 22:17:34 by psuciu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*new_list;
	t_list	*last;

	if (lst && f)
	{
		last = ft_lstnew(lst->content, lst->content_size);
		if (!last)
			return (NULL);
		last = (*f)(lst);
		new_list = last;
		while (lst->next)
		{
			lst = lst->next;
			new = ft_lstnew(lst->content, lst->content_size);
			if (!new)
				return (NULL);
			new = (*f)(lst);
			last->next = new;
			last = new;
		}
		return (new_list);
	}
	return (NULL);
}
