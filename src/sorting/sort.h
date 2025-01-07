/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialee <ialee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 00:21:55 by ialee             #+#    #+#             */
/*   Updated: 2025/01/07 11:24:01 by ialee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H
# include "../stack/stack.h"

typedef struct s_bfcol {
	t_stack	*temp_operations;
	t_stack	*operations;
	t_stack	*a;
	t_stack	*b;
	long	least;
	int		*relationships;
	int		rlen;
}	t_bfcol;

void	sort_3(t_scol *scntr);
void	sort_5(t_scol *scntr);

void	reverse_sort(t_scol *scntr);

void	sort(t_scol *scntr);

t_stack	*brute_force_pairs(t_scol *stack);
int		set_top_a(t_stack *a, t_bfcol *bf, int idx, unsigned int a_idx);
int		set_top_b(t_stack *b, t_bfcol *bf, unsigned int idx);
int		restart(t_bfcol *bf);
void	measure(t_bfcol *bf);
#endif
