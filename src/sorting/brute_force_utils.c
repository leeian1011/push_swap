/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brute_force_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialee <ialee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 00:16:05 by ialee             #+#    #+#             */
/*   Updated: 2025/01/07 00:16:05 by ialee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

void	set_top_a(t_stack *a, t_bfcol *bf, int idx, int a_idx)
{
	if (a_idx <= ((bf->a->len / 2) + (bf->a->len % 2)))
	{
		while (a->head->data != bf->relationships[idx])
		{
			rotate(a);
			stack_append(bf->operations[idx], ROTATE_A, 0);
		}
	}
	else
	{
		while (a->head->data != bf->relationships[idx])
		{
			reverse_rotate(a);
			stack_append(bf->operations[idx], REVERSE_R_A, 0);
		}
	}
}

void	set_top_b(t_stack *b, t_bfcol *bf, int idx)
{
	if (idx <= ((bf->b->len / 2) + (bf->b->len % 2)))
	{
		while (b->head->data != stack_at(bf->b, idx))
		{
			rotate(b);
			stack_append(bf->operations[idx], ROTATE_B, 0);
		}
	}
	else
	{
		while (b->head->data != stack_at(bf->b, idx))
		{
			reverse_rotate(b);
			stack_append(bf->operations[idx], REVERSE_R_B, 0);
		}
	}
}
