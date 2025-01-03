#ifndef SORTING_H
#define SORTING_H
# include "../stack/stack.h"

typedef struct s_bfcol {
  t_stack **operations;
  t_stack *a;
  t_stack *b;
  long least;
  int least_idx;
  int *relationships;
  int rlen;
} t_bfcol;

void sort_3(t_scol *scntr);
void sort_5(t_scol *scntr);

void reverse_sort(t_scol *scntr);

void sort(t_scol *scntr);

t_stack *brute_force_pairs(t_scol *stack);
void set_top_a(t_stack *a, t_bfcol *bf, int idx, int a_idx);
void set_top_b(t_stack *b, t_bfcol *bf, int idx);
#endif
