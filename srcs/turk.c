/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 00:36:39 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/12/30 03:31:06 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "costs.h"
#include "ft_maths.h"
#include "push_swap.h"
#include "stack_commands.h"
#include "turk.h"
#include "turk_moves.h"

/**
 * @brief Finds the target position in stack A for inserting a node from stack B
 *
 * Determines where a node from stack B should be inserted in stack A to
 * maintain sorted order. First tries to find the smallest larger value,
 * then falls back to the smallest value (wrap-around case).
 *
 * @param stack_a Stack to find insertion position in
 * @param current Node from stack B to find position for
 * @param basics Structure to store the target index
 * @return t_node* Pointer to the target node where insertion should occur
 */
t_node	*find_target(t_stack *stack_a, t_node *current, t_basic *basics)
{
	t_node	*target;

	if (!stack_a || !stack_a->head || !current)
		return (NULL);
	target = find_smallest_larger(stack_a, current, basics);
	if (!target)
		target = find_smallest(stack_a, basics);
	return (target);
}

/**
 * @brief Moves all elements from stack B back to stack A in sorted order
 *
 * This is the second phase of the Turk sort algorithm. For each element
 * in stack B, it calculates the cheapest way to position both stacks
 * for optimal insertion, executes the movements, and pushes the element
 * back to stack A.
 *
 * @param stack_a Destination stack
 * @param stack_b Source stack
 */
void	move_back(t_stack *stack_a, t_stack *stack_b)
{
	t_basic		basics;
	t_cheapest	cheapest;

	while (stack_b->head)
	{
		basics.index = 0;
		cheapest = calculate_cheapest_node(stack_a, stack_b, &basics);
		if (cheapest.cost == -1)
			break ;
		if (cheapest.move == 0)
			do_op_up(stack_a, stack_b, &cheapest);
		else if (cheapest.move == 1)
			do_op_a_up_b_down(stack_a, stack_b, &cheapest);
		else if (cheapest.move == 2)
			do_op_a_down_b_up(stack_a, stack_b, &cheapest);
		else if (cheapest.move == 3)
			do_op_down(stack_a, stack_b, &cheapest);
		push_command(stack_b, stack_a, "pa");
	}
}

/**
 * @brief Checks if a stack is sorted in ascending order
 *
 * Traverses the stack from head to tail checking if each element
 * is smaller than or equal to the next element.
 *
 * @param stack_a Stack to check for sorted order
 * @return bool true if sorted in ascending order, false otherwise
 */
bool	is_sorted(t_stack *stack_a)
{
	t_node	*node;

	node = stack_a->head;
	while (node->next)
	{
		if (node->next->value < node->value)
			return (false);
		node = node->next;
	}
	return (true);
}

/**
 * @brief Main Turk sort algorithm implementation
 *
 * Implements the complete Turk sort algorithm for push_swap:
 * 1. Checks if sorting is needed
 * 2. Moves elements to stack B (except last 2)
 * 3. Moves elements back to stack A in sorted order
 * 4. Rotates stack A so smallest element is at the top
 *
 * The algorithm is optimized to minimize the total number of operations
 * by calculating costs for different movement strategies.
 *
 * @param stack_a Main stack containing numbers to sort
 * @param stack_b Auxiliary stack used during sorting process
 */
void	turk_sort(t_stack *stack_a, t_stack *stack_b)
{
	t_basic	basics;
	int		i;

	i = 0;
	if (!stack_a || stack_a->count <= 1 || is_sorted(stack_a))
		return ;
	move_to_b(stack_a, stack_b);
	move_back(stack_a, stack_b);
	find_smallest(stack_a, &basics);
	if (basics.a_index < stack_a->count - basics.a_index)
	{
		while (i++ < basics.a_index)
		{
			rotate_command(stack_a, NULL, "ra");
		}
	}
	else
	{
		while (i++ < stack_a->count - basics.a_index)
		{
			reverse_rotate_command(stack_a, NULL, "rra");
		}
	}
}
