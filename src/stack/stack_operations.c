#include "stack.h"
#include <stdio.h>

void swap(t_stack *stack)
{
  t_lstnode *tmp1;
  t_lstnode *tmp2;

  if (stack->len < 2)
    return ;
  tmp1 = stack_pop_left(stack);
  tmp2 = stack_pop_left(stack);
  stack_prepend(stack, tmp1->data, tmp1->index);
  stack_prepend(stack, tmp2->data, tmp2->index);
  free(tmp1);
  free(tmp2);
}

void push(t_stack **from, t_stack **to)
{
  if (!(*from)->head)
    return ;
  stack_prepend(*to, (*from)->head->data, (*from)->head->index);
  free(stack_pop_left(*from));
}

void rotate(t_stack *stack)
{
  t_stack *tmp;

  if (!stack->head)
    return ;
  stack_append(stack, stack->head->data, stack->head->index);
  free(stack_pop_left(stack));
}

void reverse_rotate(t_stack *stack)
{
  t_lstnode *tmp;

  if (!stack->head)
    return ;
  stack_prepend(stack, stack->tail->data, stack->tail->index);
  free(stack_pop_right(stack));
}

void record_operation(t_stack *operations, long op)
{
  if (!operations->tail)
    stack_append(operations, op, 0);
  else if (op == ROTATE_A && operations->tail->data == ROTATE_B)
    operations->tail->data = ROTATE_BOTH;
  else if (op == ROTATE_B && operations->tail->data == ROTATE_A)
    operations->tail->data = ROTATE_BOTH;
  else if (op == SWAP_A && operations->tail->data == SWAP_B)
    operations->tail->data = SWAP_BOTH;
  else if (op == SWAP_B && operations->tail->data == SWAP_A)
    operations->tail->data = SWAP_BOTH;
  else if (op == REVERSE_R_A && operations->tail->data == REVERSE_R_B)
    operations->tail->data = REVERSE_R_BOTH;
  else if (op == REVERSE_R_B && operations->tail->data == REVERSE_R_A)
    operations->tail->data = REVERSE_R_BOTH;
  else
    stack_append(operations, op, 0);
}

void perform_operation(t_scol *scntr, long op)
{
  if (op == PUSH_A)
    push(&scntr->b, &scntr->a);
  else if (op == PUSH_B)
    push(&scntr->a, &scntr->b);
  else if (op == ROTATE_A)
    rotate(scntr->a);
  else if (op == ROTATE_B)
    rotate(scntr->b);
  else if (op == SWAP_A)
    swap(scntr->a);
  else if (op == SWAP_B)
    swap(scntr->b);
  else if (op == REVERSE_R_A)
    reverse_rotate(scntr->a);
  else if (op == REVERSE_R_B)
    reverse_rotate(scntr->b);
  record_operation(scntr->operations, op);
  // stack_append(scntr->operations, op, 0);
}
