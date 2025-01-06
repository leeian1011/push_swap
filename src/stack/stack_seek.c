/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_seek.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialee <ialee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 23:49:15 by ialee             #+#    #+#             */
/*   Updated: 2025/01/07 00:46:02 by ialee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	stack_mean(t_stack *stack)
{
	int			i;
	t_lstnode	*itr;

	i = 0;
	itr = stack->head;
	while (itr != NULL)
	{
		i += itr->data;
		itr = itr->next;
	}
	return (i / stack->len);
}

int	stack_max(t_stack *stack)
{
	int			i;
	t_lstnode	*itr;

	itr = stack->head;
	i = itr->data;
	while (itr != NULL)
	{
		if (i < itr->data)
			i = itr->data;
		itr = itr->next;
	}
	return (i);
}

int	stack_min(t_stack *stack)
{
	int			i;
	t_lstnode	*itr;

	itr = stack->head;
	i = itr->data;
	while (itr != NULL)
	{
		if (i > itr->data)
			i = itr->data;
		itr = itr->next;
	}
	return (i);
}

/// Unsafe if index > stack->len.
long	stack_at(t_stack *stack, int index)
{
	t_lstnode	*tmp;

	tmp = stack->head;
	if (!stack->head)
		return (0);
	if (index == 0)
		return (tmp->data);
	while (--index > 0)
		tmp = tmp->next;
	return (tmp->data);
}
