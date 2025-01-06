/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialee <ialee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 00:42:26 by ialee             #+#    #+#             */
/*   Updated: 2025/01/07 00:43:06 by ialee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stack/stack.h"

static int	parse_simultaneous(t_scol *scol, char *x)
{
	if (ft_strncmp(x, "rr\n", ft_strlen(x)) == 0)
		record_operation(scol->operations, ROTATE_BOTH);
	else if (ft_strncmp(x, "rrr\n", ft_strlen(x)) == 0)
		record_operation(scol->operations, REVERSE_R_BOTH);
	else if (ft_strncmp(x, "ss\n", ft_strlen(x)) == 0)
		record_operation(scol->operations, SWAP_BOTH);
	else
		return (0);
	return (1);
}

static int	parse_op(char *x, t_scol *scol)
{
	if (ft_strncmp(x, "pa\n", ft_strlen(x)) == 0)
		record_operation(scol->operations, PUSH_A);
	else if (ft_strncmp(x, "pb\n", ft_strlen(x)) == 0)
		record_operation(scol->operations, PUSH_B);
	else if (ft_strncmp(x, "sa\n", ft_strlen(x)) == 0)
		record_operation(scol->operations, SWAP_A);
	else if (ft_strncmp(x, "sb\n", ft_strlen(x)) == 0)
		record_operation(scol->operations, SWAP_B);
	else if (ft_strncmp(x, "ra\n", ft_strlen(x)) == 0)
		record_operation(scol->operations, ROTATE_A);
	else if (ft_strncmp(x, "rb\n", ft_strlen(x)) == 0)
		record_operation(scol->operations, ROTATE_B);
	else if (ft_strncmp(x, "rra\n", ft_strlen(x)) == 0)
		record_operation(scol->operations, REVERSE_R_A);
	else if (ft_strncmp(x, "rrb\n", ft_strlen(x)) == 0)
		record_operation(scol->operations, REVERSE_R_B);
	else
		return (parse_simultaneous(scol, x));
	return (1);
}

int	retrieve_op(t_scol *scol)
{
	char	*x;

	x = get_next_line(1);
	while (x)
	{
		if (!parse_op(x, scol))
		{
			free(x);
			return (0);
		}
		free(x);
		x = get_next_line(1);
	}
	return (1);
}

static int	handle_error(t_scol *scol)
{
	free_collection(scol);
	ft_putstr_fd("Error\n", 2);
	return (0);
}

int	main(int argc, char **argv)
{
	t_scol		*scol;

	if (argc == 1)
		return (0);
	scol = new_collection();
	if (!extract_vinput(++argv, --argc, scol))
		return (handle_error(scol));
	if (!retrieve_op(scol))
		return (handle_error(scol));
	if (list_issorted(scol->a->head) && scol->operations->len > 0)
	{
		free_collection(scol);
		ft_printf("KO\n");
		return (0);
	}
	run_op(scol);
	if (list_issorted(scol->a->head))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_collection(scol);
	return (0);
}
