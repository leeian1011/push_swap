/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialee <ialee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 23:54:57 by ialee             #+#    #+#             */
/*   Updated: 2025/01/06 23:55:19 by ialee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "stack.h"

int	list_issorted_desc(t_lstnode *lst)
{
	int	num;

	if (!lst)
		return (0);
	num = lst->data;
	while (lst != NULL)
	{
		if (lst->data <= num)
		{
			num = lst->data;
			lst = lst->next;
		}
		else
			return (0);
	}
	return (1);
}

int	list_issorted(t_lstnode *lst)
{
	int	num;

	if (!lst)
		return (0);
	num = lst->data;
	while (lst != NULL)
	{
		if (lst->data >= num)
		{
			num = lst->data;
			lst = lst->next;
		}
		else
			return (0);
	}
	return (1);
}

// Bubble sort used to sort the linked list.
void	sort_list(t_lstnode **head)
{
	t_lstnode	*tmp;
	t_lstnode	*iterator;

	iterator = *head;
	while (!list_issorted(*head))
	{
		if (iterator == NULL || iterator->next == NULL)
			iterator = *head;
		if (iterator->data > iterator->next->data)
		{
			tmp = iterator->next;
			iterator->next = tmp->next;
			if (tmp->next != NULL)
				tmp->next->prev = iterator;
			tmp->prev = iterator->prev;
			if (tmp->prev == NULL)
				*head = tmp;
			else
				iterator->prev->next = tmp;
			iterator->prev = tmp;
			tmp->next = iterator;
		}
		else
			iterator = iterator->next;
	}
}
