#include "../includes/libft/libft.h"
#include "stack/stack.h"
#include <limits.h>

static int is_unique(t_stack *stack)
{
  t_lstnode *itr;
  t_lstnode *ptr;

  ptr = stack->head;
  itr = stack->head->next;
  if (!itr)
    return (1);
  while (ptr)
  {
    while (itr)
    {
      if (ptr->data == itr->data)
        return (0);
      itr = itr->next;
    }
    ptr = ptr->next;
  }
  return (1);
}

int extract_str(char *nums, t_scol *scntr)
{
  char *iterator;
  long extracted_num;

  iterator = nums;
  while (*nums)
  {
    while (*nums == ' ')
      nums++;
    if (!*nums)
      break;
    extracted_num = ft_atol(nums);
    if (extracted_num > INT_MAX || extracted_num < INT_MIN)
      return (0);
    stack_append(scntr->a, extracted_num, 0);
    if (*nums == '-')
      nums++;
    while (ft_isdigit(*nums))
      nums++;
  }
  return (1);
}

static int sanity_check(char *input)
{
  int len;

  if (ft_strlen(input) == 0)
    return (0);
  while (*input)
    if (*input == '-' || *input == ' ' || ft_isdigit(*input))
      input++;
    else
      return (0);
  return (1);
}

int extract_vinput(char **input, int argc, t_scol *scntr)
{
  int i;
  long data;

  i = 0;
  while (i < argc)
  {
    if (!sanity_check(input[i]))
      return (0);
    if (ft_strchr(input[i], ' '))
    {
      if (!extract_str(input[i++], scntr))
        return (0);
    }
    else
    {
      data = ft_atol(input[i++]);
      if (data > INT_MAX || data < INT_MIN)
        return (0);
      stack_append(scntr->a, data, 0);
    }
  }
  scntr->sorted_values = stack_clone(scntr->a);
  stack_sort(scntr->sorted_values);
  return (is_unique(scntr->a));
}
