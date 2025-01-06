/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialee <ialee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 00:08:05 by ialee             #+#    #+#             */
/*   Updated: 2025/01/07 00:46:35 by ialee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	swap(t_stack *stack)
{
	t_lstnode	*tmp1;
	t_lstnode	*tmp2;

	if (stack->len < 2)
		return ;
	tmp1 = stack_pop_left(stack);
	tmp2 = stack_pop_left(stack);
	stack_prepend(stack, tmp1->data, tmp1->index);
	stack_prepend(stack, tmp2->data, tmp2->index);
	free(tmp1);
	free(tmp2);
}

void	push(t_stack **from, t_stack **to)
{
	if (!(*from)->head)
		return ;
	stack_prepend(*to, (*from)->head->data, (*from)->head->index);
	free(stack_pop_left(*from));
}

void	rotate(t_stack *stack)
{
	t_stack	*tmp;

	if (!stack->head)
		return ;
	stack_append(stack, stack->head->data, stack->head->index);
	free(stack_pop_left(stack));
}

void	reverse_rotate(t_stack *stack)
{
	t_lstnode	*tmp;

	if (!stack->head)
		return ;
	stack_prepend(stack, stack->tail->data, stack->tail->index);
	free(stack_pop_right(stack));
}

void	record_operation(t_stack *operations, long op)
{
	if (!operations->tail)
		stack_append(operations, op, 0);
	else if (op == ROTATE_A && operations->tail->data == ROTATE_B)
		operations->tail->data = ROTATE_BOTH;
	else if (op == ROTATE_B && operations->tail->data == ROTATE_A)
		operations->tail->data = ROTATE_BOTH;
	else if (op == SWAP_A && operations->tail->data == SWAP_B)
		operations->tail->data = SWAP_BOTH;
	else if (op == SWAP_B && operations->tail->data == SWAP_A)
		operations->tail->data = SWAP_BOTH;
	else if (op == REVERSE_R_A && operations->tail->data == REVERSE_R_B)
		operations->tail->data = REVERSE_R_BOTH;
	else if (op == REVERSE_R_B && operations->tail->data == REVERSE_R_A)
		operations->tail->data = REVERSE_R_BOTH;
	else
		stack_append(operations, op, 0);
}
