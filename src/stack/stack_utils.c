#include "stack.h"
#include <limits.h>
#include <stdio.h>

int stack_mean(t_stack *stack)
{
  int i = 0;
  t_lstnode *itr;

  itr = stack->head;
  while (itr != NULL)
  {
    i += itr->data;
    itr = itr->next;
  }
  return (i / stack->len);
}

int stack_max(t_stack *stack)
{
  int i;
  t_lstnode *itr;

  itr = stack->head;
  i = itr->data;
  while (itr != NULL)
  {
    if (i < itr->data)
      i = itr->data;
    itr = itr->next;
  }
  return (i);
}

int stack_min(t_stack *stack)
{
  int i;
  t_lstnode *itr;

  itr = stack->head;
  i = itr->data;
  while (itr != NULL)
  {
    if (i > itr->data)
      i = itr->data;
    itr = itr->next;
  }
  return (i);
}

t_stack *stack_clone(t_stack *ori)
{
  t_stack *copy;
  t_lstnode *itr;

  itr = ori->head;
  copy = malloc(sizeof(t_stack));
  copy->head = NULL;
  copy->tail = NULL;
  copy->len = 0;
  while (itr)
  {
    stack_append(copy, itr->data, itr->index);
    itr = itr->next;
  }
  itr = copy->head;
  while (itr->next != NULL)
    itr = itr->next;
  copy->tail = itr;
  return (copy);
}

long stack_find(t_stack *stack, long data)
{
  long i;
  t_lstnode *itr;

  i = 1;
  itr = stack->head;
  while(itr)
  {
    if (itr->data == data)
      return (i);
    itr = itr->next;
    i++;
  }
  return (i);
}

/// Unsafe if index > stack->len.
long stack_at(t_stack *stack, int index)
{
  t_lstnode *tmp;

  tmp = stack->head;
  if (!stack->head)
    return (0);
  if (index == 0)
      return (tmp->data);
  while (--index > 0)
    tmp = tmp->next;
  return (tmp->data);
}

long stack_set_index(t_stack *stack, long data, long index)
{
  t_lstnode *tmp;

  tmp = stack->head;
  while (tmp->data != data)
    tmp = tmp->next;
  if (!tmp)
    return (-1);
  tmp->index = index;
  return (0);
}

void stack_sort(t_stack *stack)
{
  t_lstnode *itr;
  int index = 1;

  sort_list(&stack->head);
  itr = stack->head->next;
  if (!itr)
    return ;
  while (itr->next != NULL)
  {
    itr->index = index++;
    itr = itr->next;
  }
  itr->index = index;
  stack->tail = itr;
}

void free_stack(t_stack *stack)
{
  free_list(stack->head);
  free(stack);
}
