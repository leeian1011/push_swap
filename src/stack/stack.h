/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialee <ialee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 00:02:13 by ialee             #+#    #+#             */
/*   Updated: 2025/01/07 00:07:44 by ialee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# define PUSH_A 0
# define PUSH_B 1
# define SWAP_A 2
# define SWAP_B 3
# define ROTATE_A 4
# define ROTATE_B 5
# define REVERSE_R_A 6
# define REVERSE_R_B 7
# define SWAP_BOTH 8
# define ROTATE_BOTH 9
# define REVERSE_R_BOTH 10
# define POP_LEFT 0
# define POP_RIGHT 1
# include <stdlib.h>

/// A 'stack' struct that is represented with a doubly-linked list.
typedef struct s_lstnode {
	long				data;
	long				index;
	struct s_lstnode	*next;
	struct s_lstnode	*prev;
}	t_lstnode;

typedef struct s_stack {
	t_lstnode		*head;
	t_lstnode		*tail;
	unsigned int	len;
}	t_stack;

typedef struct s_scol {
	t_stack		*a;
	t_stack		*b;
	t_stack		*sorted_values;
	t_stack		*operations;
	long		max_data;
	long		min_data;
}	t_scol;

// Collection functions
t_scol		*new_collection(void);
void		free_collection(t_scol *collection);

// Stack operations
void		*stack_append(t_stack *stack, long data, long data_idx);
void		*stack_prepend(t_stack *stack, long data, long data_idx);
void		*stack_pop_left(t_stack *stack);
void		*stack_pop_right(t_stack *stack);
t_stack		*stack_clone(t_stack *stack);
long		stack_at(t_stack *stack, unsigned int index);
int			stack_mean(t_stack *stack);
int			stack_min(t_stack *stack);
int			stack_max(t_stack *stack);
long		stack_find(t_stack *stack, long data);
void		stack_sort(t_stack *stack);
void		free_stack(t_stack *stack);
void		record_operation(t_stack *operations, long op);
void		perform_operation(t_scol *scntr, long op);

// List operations
t_lstnode	*list_new(long data, long index, void *next, void *prev);
void		*list_append(t_lstnode **tail, t_lstnode **head, t_lstnode *node);
void		*list_prepend(t_lstnode **head, t_lstnode **tail, t_lstnode *node);
void		*list_pop(t_lstnode **head, unsigned int direction);
void		sort_list(t_lstnode **head);
int			list_issorted(t_lstnode *lst);
int			list_issorted_desc(t_lstnode *lst);
void		free_list(t_lstnode *lst);

// Operations
void		swap(t_stack *stack);
void		push(t_stack **from, t_stack **to);
void		reverse_rotate(t_stack *stack);
void		rotate(t_stack *stack);

#endif
