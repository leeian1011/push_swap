#include "push_swap.h"
#include <stdio.h>

int main()
{
  char *x;

  x = get_next_line(1);
  while (x)
  {
    printf("read -> %s\n", x);
    x = get_next_line(1);
  }
}
