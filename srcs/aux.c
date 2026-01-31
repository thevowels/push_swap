/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 02:14:06 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/02/01 02:52:28 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "turk.h"

/*

1 2 3 => do nothing			
1 3 2 => rra sa			a < b	b > c	c > a

2 3 1 => rra			a < b	b > c	c < a
2 1 3 => sa				a > b	b < c	c > a .

3 2 1 => sa rra			a > b	b > c	c < a .
3 1 2 => ra				a > b	b < c	c < a .

1. 3 2 1
2. 3 1 2
3. 2 1 3
4. a < b < c
*/

static int fixed_solutions(t_stack *stack)
{
	int a;
	int b;
	int c;
	
	a = stack->head->value;
	b = stack->head->next->value;
	c = stack->tail->value;
	
	if(a > b)
	{
		if(b > c)
			ft_printf("sa\nrra\n");
		else if(a > c)
			ft_printf("ra\n");
		else
			ft_printf("sa\n");
	}else
	{
		if(a < c)
			ft_printf("rra\nsa\n");
		else
			ft_printf("rra\n");
	}
	exit(EXIT_SUCCESS);
}
void aux_sort(t_stack *stack)
{
	if(is_sorted(stack))
		exit(EXIT_SUCCESS);
	fixed_solutions(stack);
}
