/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialee <ialee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 00:20:24 by ialee             #+#    #+#             */
/*   Updated: 2025/01/07 00:21:15 by ialee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

void	sort_3(t_scol *stack)
{
	t_lstnode	*itr;
	t_lstnode	*mid;
	t_lstnode	*end;

	itr = stack->a->head;
	mid = itr->next;
	end = stack->a->tail;
	if (list_issorted(itr))
		return ;
	if (itr->data > mid->data && itr->data > end->data)
	{
		perform_operation(stack, ROTATE_A);
		if (stack->a->head->data > stack->a->head->next->data)
			perform_operation(stack, SWAP_A);
	}
	else if (itr->data > mid->data && itr->data < end->data)
		perform_operation(stack, SWAP_A);
	else if (itr->data < mid->data && itr->data > end->data)
		perform_operation(stack, REVERSE_R_A);
	else if (itr->data < mid->data && itr->data < end->data)
	{
		perform_operation(stack, SWAP_A);
		perform_operation(stack, ROTATE_A);
	}
}

void	sort_4(t_scol *stack)
{
	t_lstnode	*itr;
	int			min;
	int			is_4;

	itr = stack->a->head;
	is_4 = stack->a->len == 4;
	if (is_4)
	{
		min = stack_min(stack->a);
		if (stack_find(stack->a, min) > 2)
		{
			while (stack->a->head->data != min)
				perform_operation(stack, REVERSE_R_A);
			perform_operation(stack, PUSH_B);
		}
		else
		{
			while (stack->a->head->data != min)
				perform_operation(stack, ROTATE_A);
			perform_operation(stack, PUSH_B);
		}
	}
	sort_3(stack);
	if (is_4)
		perform_operation(stack, PUSH_A);
}

static void	handle_5(t_scol *stack, int is_5)
{
	if (is_5)
	{
		perform_operation(stack, PUSH_A);
		perform_operation(stack, ROTATE_A);
	}
}

void	sort_5(t_scol *stack)
{
	t_lstnode	*itr;
	int			max;
	int			is_5;

	itr = stack->a->head;
	max = stack_max(stack->a);
	is_5 = stack->a->len == 5;
	if (is_5)
	{
		if (stack_find(stack->a, max) > 3)
		{
			while (stack->a->head->data != max)
				perform_operation(stack, REVERSE_R_A);
			perform_operation(stack, PUSH_B);
		}
		else
		{
			while (stack->a->head->data != max)
				perform_operation(stack, ROTATE_A);
			perform_operation(stack, PUSH_B);
		}
	}
	sort_4(stack);
	handle_5(stack, is_5);
}
