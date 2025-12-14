/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 22:54:28 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/12/15 05:21:42 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_cost(t_stack *stack, int target, int result[2])
{
	result[0] = rotate_cost(stack, target);
	result[1] = rev_rotate_cost(stack, target);
}

// get max
int	gmax(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int gmin(int a, int b)
{
	if(a < b)
		return (a);
	return (b);
}
// cost_a 0 for rotate 1 for rev_rotate
// cost_b for stack b
// best val 0 for value, 1 for cost(moves)

int	get_best_move(t_stack *stack_a, t_stack *stack_b)
{
	int		biggest_small;
	int		cost_a[2];
	int		cost_b[2];
	int		best_val[2];
	t_node	*node;
	
	best_val[1] = __INT_MAX__;
	node = stack_a->head;
	while (node)
	{
		get_cost(stack_a, node->value, cost_a);
		biggest_small = find_biggest_smaller(stack_b, node->value);
		get_cost(stack_b, biggest_small, cost_b);
		if (best_val[1] > gmin(gmax(cost_a[0], cost_b[0]), gmax(cost_a[1],
					cost_b[1])))
		{
			best_val[0] = node->value;
			best_val[1] = gmin(gmax(cost_a[0], cost_b[0]), gmax(cost_a[1],
						cost_b[1]));
		}
		node = node->next;
	}

	return best_val[0];
}

void	do_sort_optimized(t_stack *stack_a)
{
	t_stack	*stack_b;
	t_node	*node;
	int		best_val;

	stack_b = get_stack();
	while (stack_a->head)
	{
		if(stack_b->count >= 2)
		{
			best_val = get_best_move(stack_a, stack_b);
			move_head(stack_a,best_val);
			prepare_stack(stack_b, best_val);

		}
		pop_push(stack_a, stack_b, "pb");
	}
	go_head_to_biggest(stack_b);
	while (stack_b->head)
	{
		pop_push(stack_b, stack_a, "pa");
	}
}

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
void move_head(t_stack *stack, int value)
{
	if(rotate_cost(stack, value) < rev_rotate_cost(stack, value))
	{
		while(stack->head->value != value)
			rotate(stack,"ra");
	}
	else
	{
		while(stack->head->value != value)
			reverse_rotate(stack,"rra");
	}
}

void	prepare_stack_modified(t_stack *stack, int value,char s)
{
	int	biggest_small;

	if (stack->count < 2)
		return ;
	biggest_small = find_biggest_smaller(stack, value);
	if (rotate_cost(stack, biggest_small) < rev_rotate_cost(stack,
			biggest_small))
	{
		while (stack->head->value != biggest_small)
		{
			if(s == 'a')
				rotate(stack, "ra");
			else
				rotate(stack,"rb");
		}
	}
	else
	{
		while (stack->head->value != biggest_small)
		{
			if(s == 'a')
				reverse_rotate(stack, "rra");
			else
				reverse_rotate(stack, "rrb");
		}
	}
}

void	put_to_right_position(t_stack *stack, t_node *node)
{
	if (stack->head == NULL)
	{
		push_stack(stack, node);
	}
}