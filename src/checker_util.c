/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialee <ialee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 00:42:28 by ialee             #+#    #+#             */
/*   Updated: 2025/01/07 00:43:22 by ialee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	run_simultaneous(t_scol *scol, long data)
{
	if (data == SWAP_BOTH)
	{
		swap(scol->a);
		swap(scol->b);
	}
	else if (data == ROTATE_BOTH)
	{
		rotate(scol->a);
		rotate(scol->b);
	}
	else if (data == REVERSE_R_BOTH)
	{
		reverse_rotate(scol->a);
		reverse_rotate(scol->b);
	}
}

void	run_op(t_scol *scol)
{
	t_lstnode	*itr;

	itr = scol->operations->head;
	while (itr)
	{
		if (itr->data == PUSH_A)
			push(&scol->b, &scol->a);
		else if (itr->data == PUSH_B)
			push(&scol->a, &scol->b);
		else if (itr->data == SWAP_A)
			swap(scol->a);
		else if (itr->data == SWAP_B)
			swap(scol->b);
		else if (itr->data == ROTATE_A)
			rotate(scol->a);
		else if (itr->data == ROTATE_B)
			rotate(scol->b);
		else if (itr->data == REVERSE_R_A)
			reverse_rotate(scol->a);
		else if (itr->data == REVERSE_R_B)
			reverse_rotate(scol->b);
		else
			run_simultaneous(scol, itr->data);
		itr = itr->next;
	}
}
