/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialee <ialee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 00:27:05 by ialee             #+#    #+#             */
/*   Updated: 2025/01/07 00:55:57 by ialee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

static void	handle_simultaneous(int op)
{
	if (op == SWAP_BOTH)
		ft_printf("ss\n");
	else if (op == ROTATE_BOTH)
		ft_printf("rr\n");
	else if (op == REVERSE_R_BOTH)
		ft_printf("rrr\n");
}

void	print_operations(t_stack *stack)
{
	t_lstnode	*lst;

	lst = stack->head;
	while (lst != NULL)
	{
		if (lst->data == PUSH_A)
			ft_printf("pa\n");
		else if (lst->data == PUSH_B)
			ft_printf("pb\n");
		else if (lst->data == SWAP_A)
			ft_printf("sa\n");
		else if (lst->data == SWAP_B)
			ft_printf("sb\n");
		else if (lst->data == ROTATE_A)
			ft_printf("ra\n");
		else if (lst->data == ROTATE_B)
			ft_printf("rb\n");
		else if (lst->data == REVERSE_R_A)
			ft_printf("rra\n");
		else if (lst->data == REVERSE_R_B)
			ft_printf("rrb\n");
		else
			handle_simultaneous(lst->data);
		lst = lst->next;
	}
}

static int	handle_argv(int argc, char **argv, t_scol **scntr)
{
	if (argc == 1)
		return (0);
	else
		return (extract_vinput(++argv, --argc, *scntr));
	return (1);
}

int	main(int argc, char **argv)
{
	t_scol	*s_cntr;

	s_cntr = new_collection();
	if (!handle_argv(argc, argv, &s_cntr))
	{
		free_collection(s_cntr);
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	s_cntr->min_data = s_cntr->sorted_values->head->data;
	s_cntr->max_data = s_cntr->sorted_values->tail->data;
	sort(s_cntr);
	print_operations(s_cntr->operations);
	free_collection(s_cntr);
}
