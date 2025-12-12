#ifndef SORTINGS_H
# define SORTINGS_H

# include "push_swap.h"

void	double_sort(int *unordered, int *sorted);
void	triple_sort(t_stack *stack_a);
void	fourple_sort(t_stack *stack_a, t_stack *stack_b, int size);
void	fiveple_sort(t_stack *stack_a, t_stack *stack_b, int size);
void	forbbiden_sorting(int size, t_stack *stack_a, t_stack *stack_b);

#endif   /* SORTINGS_H */
