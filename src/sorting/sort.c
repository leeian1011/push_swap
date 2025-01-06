/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialee <ialee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 00:17:43 by ialee             #+#    #+#             */
/*   Updated: 2025/01/07 00:20:17 by ialee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include <stdio.h>

void	reverse_sort(t_scol *scntr)
{
	int	index;
	int	count;

	index = 0;
	count = scntr->a->len;
	while (index++ < count)
	{
		rotate(scntr->a);
		record_operation(scntr->operations, ROTATE_A);
	}
}

static void	split_a(t_scol *scntr)
{
	t_lstnode	*itr;
	int			mean;

	while (scntr->a->len > 5)
	{
		itr = scntr->a->head;
		mean = stack_mean(scntr->a);
		if (itr->data < mean)
			perform_operation(scntr, PUSH_B);
		else
			perform_operation(scntr, ROTATE_A);
	}
	sort_5(scntr);
}

static void	brute_force_b(t_scol *scntr)
{
	t_stack		*operations;
	t_lstnode	*itr;

	while (scntr->b->len)
	{
		operations = brute_force_pairs(scntr);
		itr = operations->head;
		while (itr)
		{
			perform_operation(scntr, itr->data);
			itr = itr->next;
		}
		free_stack(operations);
	}
}

void	sort(t_scol *scntr)
{
	int	min;

	if (list_issorted(scntr->a->head))
		return ;
	else if (scntr->a->len <= 5)
		return (sort_5(scntr));
	else if (list_issorted_desc(scntr->a->head))
		return (reverse_sort(scntr));
	else
	{
		split_a(scntr);
		brute_force_b(scntr);
		min = stack_find(scntr->a, scntr->min_data);
		if (min <= scntr->a->len / 2 + scntr->a->len % 2)
			while (scntr->a->head->data != scntr->min_data)
				perform_operation(scntr, ROTATE_A);
		else
			while (scntr->a->head->data != scntr->min_data)
				perform_operation(scntr, REVERSE_R_A);
	}
}
