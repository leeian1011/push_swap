/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_collection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialee <ialee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 23:50:41 by ialee             #+#    #+#             */
/*   Updated: 2025/01/06 23:51:26 by ialee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static void	init_stack(t_stack *stack)
{
	stack->head = NULL;
	stack->tail = NULL;
	stack->len = 0;
}

t_scol	*new_collection(void)
{
	t_scol	*collection;

	collection = malloc(sizeof(t_scol));
	collection->a = malloc(sizeof(t_stack));
	init_stack(collection->a);
	collection->b = malloc(sizeof(t_stack));
	init_stack(collection->b);
	collection->operations = malloc(sizeof(t_stack));
	init_stack(collection->operations);
	collection->sorted_values = NULL;
	collection->max_data = 0;
	collection->min_data = 0;
	return (collection);
}

void	free_collection(t_scol *collection)
{
	free_stack(collection->a);
	free_stack(collection->b);
	free_stack(collection->operations);
	if (collection->sorted_values)
		free_stack(collection->sorted_values);
	free(collection);
}
