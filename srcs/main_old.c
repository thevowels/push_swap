/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 12:26:51 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/12/13 17:41:28 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
int main(int argc, char **argv)
{

	t_stack *stack_a;
	t_stack	*stack_b;
	t_node	*node;
	int		i;

	int arr[] = {1,2,3,4,5,6};
	stack_a = init_stack(arr, 6);
	stack_b = get_stack();
	print_stack(stack_a, "Stack A");
	print_stack(stack_b, "Stack B");
	swap(stack_a, "sa");
	pop_push(stack_a,stack_b,"b");
	print_stack(stack_a, "Stack A");
	print_stack(stack_b, "Stack B");

	// head_to_tail(stack);
	// tail_to_head(stack);
	// ft_printf("asdfasdf");
	// rotate(stack, "ra");
	// head_to_tail(stack);
	// tail_to_head(stack);
	// reverse_rotate(stack, "rra");
	// head_to_tail(stack);
	// tail_to_head(stack);

	return (0);
}