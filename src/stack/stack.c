/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialee <ialee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 23:56:37 by ialee             #+#    #+#             */
/*   Updated: 2025/01/06 23:57:12 by ialee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <unistd.h>

static t_stack	*new_stack(long data, t_stack *next, t_stack *prev)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	stack->head = NULL;
	stack->tail = NULL;
	return (stack);
}

void	*stack_append(t_stack *stack, long data, long index)
{
	void		*result;
	t_lstnode	*node;

	stack->len++;
	node = list_new(data, index, NULL, stack->tail);
	result = list_append(&stack->tail, &stack->head, node);
	if (!result)
		stack->len--;
	return (result);
}

void	*stack_prepend(t_stack *stack, long data, long index)
{
	void		*result;
	t_lstnode	*node;

	stack->len++;
	node = list_new(data, index, stack->head, NULL);
	result = list_prepend(&stack->head, &stack->tail, node);
	if (!result)
		stack->len--;
	return (result);
}

void	*stack_pop_left(t_stack *stack)
{
	void	*result;

	if (stack->len == 0)
		return (NULL);
	stack->len--;
	result = list_pop(&(stack)->head, POP_LEFT);
	if (stack->head == NULL)
		stack->tail = NULL;
	return (result);
}

void	*stack_pop_right(t_stack *stack)
{
	void	*result;

	if (stack->len == 0)
		return (NULL);
	stack->len--;
	result = list_pop(&(stack)->tail, POP_RIGHT);
	if (stack->tail == NULL)
		stack->head = NULL;
	return (result);
}
