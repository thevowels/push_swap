/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 22:54:28 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/12/15 03:27:57 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_sort(t_stack *stack_a)
{
	t_stack	*stack_b;
	t_node	*node;

	stack_b = get_stack();
	while (stack_a->head)
	{
		prepare_stack(stack_b, stack_a->head->value);
		pop_push(stack_a, stack_b, "pb");
	}
	go_head_to_biggest(stack_b);
	while (stack_b->head)
	{
		pop_push(stack_b, stack_a, "pa");
	}
	// print_stack(stack_a, "Stack A");
}


void	go_head_to_biggest(t_stack *stack)
{
	t_node	*node;
	int		biggest;

	node = stack->head;
	biggest = node->value;
	while (node->next)
	{
		if (biggest < node->value)
			biggest = node->value;
		node = node->next;
	}
	while (stack->head->value != biggest)
	{
		rotate(stack, "rb");
	}
}

// find the node which has the biggest value but smaller than the value provided.
// if every node is bigger than the provided value, use the biggest value
int	find_biggest_smaller(t_stack *stack, int value)
{
	int		biggest;
	int		small_flag;
	t_node	*node;

	small_flag = 0;
	node = stack->head;
	biggest = node->value;
	while (node)
	{
		if (node->value < value)
			small_flag = 1;
		if (small_flag)
		{
			if ((node->value < value && node->value > biggest)
				|| (biggest > value))
				biggest = node->value;
		}
		else
		{
			if (node->value > biggest)
				biggest = node->value;
		}
		node = node->next;
	}
	return (biggest);
}

int	rotate_cost(t_stack *stack, int biggest_small)
{
	t_node	*node;
	int		cost;

	cost = 0;
	node = stack->head;
	while (node->value != biggest_small)
	{
		node = node->next;
		cost += 1;
	}
	return (cost);
}
int	rev_rotate_cost(t_stack *stack, int biggest_small)
{
	t_node	*node;
	int		cost;

	cost = 0;
	node = stack->tail;
	while (node->value != biggest_small)
	{
		node = node->prev;
		cost += 1;
	}
	return (cost);
}

void	prepare_stack(t_stack *stack, int value)
{
	int	biggest_small;
	
	if (stack->count < 2)
		return ;
	biggest_small = find_biggest_smaller(stack, value);
	
	if (rotate_cost(stack, biggest_small) < rev_rotate_cost(stack,
			biggest_small))
	{
		while (stack->head->value != biggest_small)
			rotate(stack, "rb");
	}
	else
	{
		while (stack->head->value != biggest_small)
			reverse_rotate(stack, "rrb");
	}
}

void	put_to_right_position(t_stack *stack, t_node *node)
{
	if (stack->head == NULL)
	{
		push_stack(stack, node);
	}
}