/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialee <ialee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 20:28:47 by ialee             #+#    #+#             */
/*   Updated: 2024/11/12 22:12:26 by ialee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// Creates a new singly-linked-list, which value is created by
/// iterating `lst` and applying `fn` on produced `lst->content`.
/// RETURN(s):
/// `NULL` - on failure to allocate memory.
/// `t_list *` - (new linked list created) on success.
t_list	*ft_lstmap(t_list *lst, void *(*fn)(void *), void (*del_fn)(void *))
{
	t_list	*new_node;
	t_list	*new_lst;

	while (lst)
	{
		new_node = ft_lstnew(fn(lst->content));
		if (!new_node)
		{
			ft_lstclear(&new_lst, del_fn);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_node);
		lst = lst->next;
	}
	return (new_lst);
}
