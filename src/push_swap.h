/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialee <ialee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 00:43:30 by ialee             #+#    #+#             */
/*   Updated: 2025/01/07 01:01:14 by ialee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "stack/stack.h"
# include "sorting/sort.h"
# include "../includes/libft/libft.h"

int		extract_input(char *input, t_scol *scntr);
int		extract_vinput(char **input, int argc, t_scol *scntr);
void	print_operations(t_stack *stack);
void	run_op(t_scol *scol);
#endif
