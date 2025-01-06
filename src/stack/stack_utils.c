/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialee <ialee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 23:38:23 by ialee             #+#    #+#             */
/*   Updated: 2025/01/07 00:46:14 by ialee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack	*stack_clone(t_stack *ori)
{
	t_stack		*copy;
	t_lstnode	*itr;

	itr = ori->head;
	copy = malloc(sizeof(t_stack));
	copy->head = NULL;
	copy->tail = NULL;
	copy->len = 0;
	while (itr)
	{
		stack_append(copy, itr->data, itr->index);
		itr = itr->next;
	}
	itr = copy->head;
	while (itr->next != NULL)
		itr = itr->next;
	copy->tail = itr;
	return (copy);
}

long	stack_find(t_stack *stack, long data)
{
	long		i;
	t_lstnode	*itr;

	i = 1;
	itr = stack->head;
	while (itr)
	{
		if (itr->data == data)
			return (i);
		itr = itr->next;
		i++;
	}
	return (i);
}

void	stack_sort(t_stack *stack)
{
	t_lstnode	*itr;
	int			index;

	index = 1;
	sort_list(&stack->head);
	itr = stack->head->next;
	if (!itr)
		return ;
	while (itr->next != NULL)
	{
		itr->index = index++;
		itr = itr->next;
	}
	itr->index = index;
	stack->tail = itr;
}

void	perform_operation(t_scol *scntr, long op)
{
	if (op == PUSH_A)
		push(&scntr->b, &scntr->a);
	else if (op == PUSH_B)
		push(&scntr->a, &scntr->b);
	else if (op == ROTATE_A)
		rotate(scntr->a);
	else if (op == ROTATE_B)
		rotate(scntr->b);
	else if (op == SWAP_A)
		swap(scntr->a);
	else if (op == SWAP_B)
		swap(scntr->b);
	else if (op == REVERSE_R_A)
		reverse_rotate(scntr->a);
	else if (op == REVERSE_R_B)
		reverse_rotate(scntr->b);
	record_operation(scntr->operations, op);
}

void	free_stack(t_stack *stack)
{
	free_list(stack->head);
	free(stack);
}
