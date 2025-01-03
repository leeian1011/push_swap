#include "sort.h"
#include <limits.h>
#include <stdio.h>

static t_bfcol *new_brute_force(t_scol *stack)
{
  t_bfcol *bf;
  int count;
  int i;

  i = 0;
  count = stack->b->len;
  bf = malloc(sizeof(t_bfcol));
  bf->a = stack_clone(stack->a);
  bf->b = stack_clone(stack->b);
  bf->relationships = malloc(sizeof(int) * count);
  bf->rlen = count;
  bf->operations = malloc(sizeof(t_stack *) * count);
  while (i < count)
  {
    bf->relationships[i] = 0;
    bf->operations[i] = malloc(sizeof(t_stack));
    bf->operations[i]->len = 0;
    bf->operations[i]->head = NULL;
    bf->operations[i++]->tail = NULL;
  }
  bf->least = 0;
  bf->least_idx = 0;
  return (bf);
}

void fill_closest(t_bfcol *bf)
{
  t_lstnode *itr;
  long b_data;
  int i;
  long smallest_diff;

  i = 0;
  itr = bf->a->head;
  while (i < bf->b->len)
  {
    b_data = stack_at(bf->b, i);
    smallest_diff = UINT_MAX;
    while (itr)
    {
      if ((itr->data - b_data) > 0 && (itr->data - b_data) < smallest_diff)
      {
        bf->relationships[i] = itr->data;
        smallest_diff = itr->data - b_data;
      }
      itr = itr->next;
    }
    itr = bf->a->head;
    i++;
  }
}

    // if (a_index <= (bf->a->len / 2 + bf->a->len % 2))
    // {
    //   while (a_copy->head->data != bf->relationships[i])
    //   {
    //     rotate(a_copy);
    //     record_operation(bf->operations[i], ROTATE_A);
    //   }
    // }
    // else
    // {
    //   while (a_copy->head->data != bf->relationships[i])
    //   {
    //     reverse_rotate(a_copy);
    //     record_operation(bf->operations[i], REVERSE_R_A);
    //   }
    // }
    // if (i <= ((bf->b->len / 2) + (bf->b->len % 2)))
    // {
    //   while (b_copy->head->data != stack_at(bf->b, i))
    //   {
    //     rotate(b_copy);
    //     record_operation(bf->operations[i], ROTATE_B);
    //   }
    // }
    // else
    // {
    //   while (b_copy->head->data != stack_at(bf->b, i))
    //   {
    //     reverse_rotate(b_copy);
    //     record_operation(bf->operations[i], REVERSE_R_B);
    //   }
    // }
void fill_operations(t_bfcol *bf)
{
  int i;
  int a_index;
  long b_data;
  t_stack *a_copy;
  t_stack *b_copy;

  i = 0;
  while (i < bf->rlen)
  {
    a_copy = stack_clone(bf->a);
    b_copy = stack_clone(bf->b);
    a_index = stack_find(bf->a, bf->relationships[i]);
    set_top_a(a_copy, bf, i, a_index);
    set_top_b(b_copy, bf, i);
    record_operation(bf->operations[i], PUSH_A);
    i++;
    free_stack(a_copy);
    free_stack(b_copy);
  }
}

static void free_bf(t_bfcol *bf)
{
  int i;

  i = 0;
  while (i < bf->rlen)
    free_stack(bf->operations[i++]);
  free(bf->operations);
  free_stack(bf->a);
  free_stack(bf->b);
  free(bf->relationships);
  free(bf);
}

t_stack *brute_force_pairs(t_scol *stack)
{
  t_bfcol *bf;
  t_stack *cheapest;
  int i;

  i = 0;
  bf = new_brute_force(stack);
  fill_closest(bf);
  fill_operations(bf);
  cheapest = bf->operations[0];
  while (i < bf->b->len)
  {
    if (cheapest->len > bf->operations[i]->len)
      cheapest = bf->operations[i];
    i++;
  }
  cheapest = stack_clone(cheapest);
  free_bf(bf);
  return (cheapest);
}
