#include "push_swap.h"
#include "stack/stack.h"
#include <stdio.h>

static void print_operations(t_stack *stack)
{
  t_lstnode *lst;

  lst = stack->head;
  while (lst)
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
    lst = lst->next;
  }
}

static void run_op(t_scol *scol)
{
  t_lstnode *itr;

  itr = scol->operations->head;
  while (itr)
  {
    if (itr->data == PUSH_A)
      push(&scol->b, &scol->a);
    else if (itr->data == PUSH_B)
      push(&scol->a, &scol->b);
    else if (itr->data == SWAP_A)
      swap(scol->a);
    else if (itr->data == SWAP_B)
      swap(scol->b);
    else if (itr->data == ROTATE_A)
      rotate(scol->a);
    else if (itr->data == ROTATE_B)
      rotate(scol->b);
    else if (itr->data == REVERSE_R_A)
      reverse_rotate(scol->a);
    else if (itr->data == REVERSE_R_B)
      reverse_rotate(scol->b);
    else if (itr->data == SWAP_BOTH)
    {
      swap(scol->a);
      swap(scol->b);
    }
    else if (itr->data == ROTATE_BOTH)
    {
      rotate(scol->a);
      rotate(scol->b);
    }
    else if (itr->data == REVERSE_R_BOTH)
    {
      reverse_rotate(scol->a);
      reverse_rotate(scol->b);
    }
    itr = itr->next;
  }
}

static int handle_error(t_scol *scol)
{
  free_collection(scol);
  ft_putstr_fd("Error\n", 2);
  return (0);
}

static int parse_op(char *x, t_scol *scol)
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
  else if (ft_strncmp(x, "rr\n", ft_strlen(x)) == 0)
    record_operation(scol->operations, ROTATE_BOTH);
  else if (ft_strncmp(x, "rrr\n", ft_strlen(x)) == 0)
    record_operation(scol->operations, REVERSE_R_BOTH);
  else if (ft_strncmp(x, "ss\n", ft_strlen(x)) == 0)
    record_operation(scol->operations, SWAP_BOTH);
  else
    return (0);
  return (1);
}

int retrieve_op(t_scol *scol)
{
  char *x;

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

int main(int argc, char **argv)
{
  t_scol *scol;
  t_lstnode *itr;

  scol = new_collection();
  if (argc == 1)
    return (0);
  if (!extract_vinput(++argv, --argc, scol))
    return (handle_error(scol));
  if (!retrieve_op(scol))
    return (handle_error(scol));
  if (list_issorted(scol->a->head) && scol->operations->len > 0)
  {
    ft_printf("KO\n");
    return (0);
  }
  run_op(scol);
  if (list_issorted(scol->a->head))
    ft_printf("OK\n");
  else
    ft_printf("KO\n");
  free_collection(scol);
}
