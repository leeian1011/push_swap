/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brute_force.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialee <ialee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 00:14:06 by ialee             #+#    #+#             */
/*   Updated: 2025/01/07 00:59:09 by ialee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include <limits.h>
#include <stdio.h>

static t_bfcol	*new_brute_force(t_scol *stack)
{
	t_bfcol	*bf;
	int		count;
	int		i;

	i = 0;
	count = stack->b->len;
	bf = malloc(sizeof(t_bfcol));
	bf->a = stack_clone(stack->a);
	bf->b = stack_clone(stack->b);
	bf->relationships = malloc(sizeof(int) * count);
	bf->rlen = count;
	bf->operations = malloc(sizeof(t_stack));
  bf->operations->head = NULL;
  bf->operations->tail = NULL;
  bf->operations->len = 0;
	bf->temp_operations = malloc(sizeof(t_stack));
  bf->temp_operations->head = NULL;
  bf->temp_operations->tail = NULL;
  bf->temp_operations->len = 0;
	while (i < count)
		bf->relationships[i++] = -1;
	bf->least = 0;
	return (bf);
}

void	fill_closest(t_bfcol *bf)
{
	t_lstnode		*itr;
	long			b_data;
	unsigned int	i;
	long			smallest_diff;

	i = 0;
	itr = bf->a->head;
	while (i < bf->b->len)
	{
		b_data = stack_at(bf->b, i);
		smallest_diff = UINT_MAX;
		while (itr)
		{
			if ((itr->data - b_data) > 0
				&& (itr->data - b_data) < smallest_diff)
			{
				bf->relationships[i] = itr->data;
				smallest_diff = itr->data - b_data;
			}
			itr = itr->next;
		}
		itr = bf->a->head;
		i++;
	}
}

void	fill_operations(t_bfcol *bf)
{
	int		i;
	int		a_index;
	t_stack	*a_copy;
	t_stack	*b_copy;

	i = 0;
  bf->least = INT_MAX;
	while (i < bf->rlen)
	{
		a_copy = stack_clone(bf->a);
		b_copy = stack_clone(bf->b);
		a_index = stack_find(a_copy, bf->relationships[i]);
    if (set_top_a(a_copy, bf, i, a_index))
      if (set_top_b(b_copy, bf, i))
        measure(bf);
    restart(bf);
		i++;
		free_stack(a_copy);
		free_stack(b_copy);
	}
}

static void	free_bf(t_bfcol *bf)
{
  free_stack(bf->temp_operations);
	free_stack(bf->operations);
	free_stack(bf->a);
	free_stack(bf->b);
	free(bf->relationships);
	free(bf);
}

t_stack	*brute_force_pairs(t_scol *stack)
{
	t_bfcol				*bf;
	t_stack				*cheapest;

	bf = new_brute_force(stack);
	fill_closest(bf);
	fill_operations(bf);
	cheapest = stack_clone(bf->operations);
	free_bf(bf);
	return (cheapest);
}
