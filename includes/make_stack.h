#ifndef MAKE_STACK_H
# define MAKE_STACK_H

# include "push_swap.h"

int		find_index(int *arr, int value, int size);
t_lst	*make_lst(t_stack *stack, int *arrays[], int size, int i);
void	make_stack_a(t_stack *stack, int *unordered, int *sorted, int size);

#endif   /* MAKE_STACK_H */
