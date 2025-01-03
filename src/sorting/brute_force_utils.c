#include "sort.h"

void set_top_a(t_stack *a, t_bfcol *bf, int idx, int a_idx)
{
    if (a_idx <= ((bf->a->len / 2) + (bf->a->len % 2)))
    {
      while (a->head->data != bf->relationships[idx])
      {
        rotate(a);
        record_operation(bf->operations[idx], ROTATE_A);
      }
    }
    else
    {
      while (a->head->data != bf->relationships[idx])
      {
        reverse_rotate(a);
        record_operation(bf->operations[idx], REVERSE_R_A);
      }
    }
}

void set_top_b(t_stack *b, t_bfcol *bf, int idx)
{
    if (idx <= ((bf->b->len / 2) + (bf->b->len % 2)))
    {
      while (b->head->data != stack_at(bf->b, idx))
      {
        rotate(b);
        record_operation(bf->operations[idx], ROTATE_B);
      }
    }
    else
    {
      while (b->head->data != stack_at(bf->b, idx))
      {
        reverse_rotate(b);
        record_operation(bf->operations[idx], REVERSE_R_B);
      }
    }

}
