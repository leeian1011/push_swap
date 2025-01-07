/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brute_force_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialee <ialee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 00:16:05 by ialee             #+#    #+#             */
/*   Updated: 2025/01/07 01:00:00 by ialee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include <stdio.h>

int	set_top_a(t_stack *a, t_bfcol *bf, int idx, unsigned int a_idx)
{
  int counter;

  counter = bf->least;
	if (a_idx <= ((a->len / 2) + (a->len % 2)))
	{
		while (a->head->data != bf->relationships[idx])
		{
      if (--counter <= 0)
        return (0);
			rotate(a);
			stack_append(bf->temp_operations, ROTATE_A, 0);
		}
	}
	else
	{
		while (a->head->data != bf->relationships[idx])
		{
      if (--counter <= 0)
        return (0);
			reverse_rotate(a);
			stack_append(bf->temp_operations, REVERSE_R_A, 0);
		}
	}
  return (1);
}

int	set_top_b(t_stack *b, t_bfcol *bf, unsigned int idx)
{
  int counter;

  counter = bf->least;
	if (idx <= ((b->len / 2) + (b->len % 2)))
	{
		while (b->head->data != stack_at(bf->b, idx))
		{
      if (--counter <= 0)
        return (0);
			rotate(b);
			stack_append(bf->temp_operations, ROTATE_B, 0);
		}
	}
	else
	{
		while (b->head->data != stack_at(bf->b, idx))
		{
      if (--counter <= 0)
        return (0);
			reverse_rotate(b);
			stack_append(bf->temp_operations, REVERSE_R_B, 0);
		}
	}
  if (--counter <= 0)
    return (0);
  stack_append(bf->temp_operations, PUSH_A, 0);
  return (1);
}

void measure(t_bfcol *bf) {
  if (bf->least > bf->temp_operations->len)
  {
    bf->least = bf->temp_operations->len;
      if (bf->operations)
        free_stack(bf->operations);
    bf->operations = stack_clone(bf->temp_operations);
  }
}

int restart(t_bfcol *bf) {
    free_stack(bf->temp_operations);
    bf->temp_operations = malloc(sizeof(t_stack));
    bf->temp_operations->head = NULL;
    bf->temp_operations->tail = NULL;
    bf->temp_operations->len = 0;
  return (1);
}
