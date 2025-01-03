/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialee <ialee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 20:27:43 by ialee             #+#    #+#             */
/*   Updated: 2024/11/12 22:10:17 by ialee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// Iterator over `lst` applying `fn` on each
/// `lst->content` produced.
/// RETURN(s):
/// Nothing.
void	ft_lstiter(t_list *lst, void (*fn)(void *))
{
	while (lst)
	{
		fn(lst->content);
		lst = lst->next;
	}
}
