/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialee <ialee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 23:52:47 by ialee             #+#    #+#             */
/*   Updated: 2025/01/06 23:52:48 by ialee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_lstnode	*list_new(long data, long index, void *next, void *prev)
{
	t_lstnode	*node;

	node = malloc(sizeof(t_lstnode));
	if (!node)
		return (NULL);
	node->data = data;
	node->index = index;
	node->next = next;
	node->prev = prev;
	return (node);
}

void	*list_append(t_lstnode **tail, t_lstnode **head, t_lstnode *node)
{
	if (!*tail)
	{
		*tail = node;
		*head = node;
	}
	else
	{
		while ((*tail)->next != NULL)
			tail = &(*tail)->next;
		(*tail)->next = node;
		*tail = node;
	}
	return (node);
}

void	*list_prepend(t_lstnode **head, t_lstnode **tail, t_lstnode *node)
{
	if (!*head)
	{
		*head = node;
		*tail = node;
	}
	else
	{
		(*head)->prev = node;
		*head = (*head)->prev;
	}
	return (node);
}

void	*list_pop(t_lstnode **head, unsigned int direction)
{
	t_lstnode	*tmp;

	tmp = *head;
	if (tmp->prev)
		tmp->prev->next = tmp->next;
	if (tmp->next)
		tmp->next->prev = tmp->prev;
	if (direction == POP_LEFT)
		*head = tmp->next;
	else if (direction == POP_RIGHT)
		*head = tmp->prev;
	return (tmp);
}

void	free_list(t_lstnode *head)
{
	t_lstnode	*tmp;

	tmp = head;
	while (tmp)
	{
		head = head->next;
		free(tmp);
		tmp = head;
	}
}
