/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 03:15:10 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/12/30 03:32:36 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "costs.h"
# include "turk.h"
# include "turk_moves.h"

/**
 * @brief Finds the smallest element in stack A that is larger than current
 *
 * Searches through stack A to find the smallest value that is still larger
 * than the current node's value. This is used to determine the correct
 * insertion position for maintaining sorted order.
 *
 * @param stack_a Stack to search in
 * @param current Node whose value to compare against
 * @param basics Structure to store the index of the found target
 * @return t_node* Pointer to the target node, or NULL if not found
 */
t_node	*find_smallest_larger(t_stack *stack_a, t_node *current,
		t_basic *basics)
{
	t_node	*target;
	t_node	*temp;
	int		index;

	target = NULL;
	temp = stack_a->head;
	index = 0;
	while (temp)
	{
		if (temp->value > current->value)
		{
			if (!target || temp->value < target->value)
			{
				target = temp;
				basics->a_index = index;
			}
		}
		temp = temp->next;
		index++;
	}
	return (target);
}

/**
 * @brief Finds the smallest element in stack A
 *
 * Searches through stack A to find the node with the smallest value.
 * Used as a fallback when no larger value is found for insertion.
 *
 * @param stack_a Stack to search in
 * @param basics Structure to store the index of the smallest element
 * @return t_node* Pointer to the node with the smallest value
 */
t_node	*find_smallest(t_stack *stack_a, t_basic *basics)
{
	t_node	*target;
	t_node	*temp;
	int		index;

	target = stack_a->head;
	temp = stack_a->head;
	index = 0;
	basics->a_index = 0;
	while (temp)
	{
		if (temp->value < target->value)
		{
			target = temp;
			basics->a_index = index;
		}
		temp = temp->next;
		index++;
	}
	return (target);
}

/**
 * @brief Calculates the cost to position a target node in stack A
 *
 * Determines how many operations are needed to move the target node
 * to the top of stack A, considering both upward and downward rotations.
 *
 * @param stack_a Stack containing the target
 * @param current Node from stack B being processed
 * @param basics Structure to store calculated costs
 */
void	calc_a_cheapest(t_stack *stack_a, t_node *current, t_basic *basics)
{
	t_node	*target;

	target = find_target(stack_a, current, basics);
	if (!target || !stack_a)
		return ;
	basics->a_up = basics->a_index;
	basics->a_down = stack_a->count - basics->a_index;
}

/**
 * @brief Calculates all possible movement costs for positioning two nodes
 *
 * Computes the costs for four different movement strategies:
 * 1. Both stacks rotate up (same_up)
 * 2. Both stacks rotate down (same_down)
 * 3. Stack A up, Stack B down (mix_1)
 * 4. Stack A down, Stack B up (mix_2)
 * Selects the cheapest option.
 *
 * @param stack_a First stack
 * @param stack_b Second stack
 * @param current Current node being processed
 * @param basics Structure to store all calculated costs and optimal move
 */
void	get_basic_costs(t_stack *stack_a, t_stack *stack_b, t_node *current,
		t_basic *basics)
{
	calc_a_cheapest(stack_a, current, basics);
	basics->b_up = basics->index;
	basics->b_down = stack_b->count - basics->index;
	basics->costs.same_up = ft_max(basics->a_up, basics->b_up);
	basics->costs.same_down = ft_max(basics->a_down, basics->b_down);
	basics->costs.mix_1 = basics->a_up + basics->b_down;
	basics->costs.mix_2 = basics->a_down + basics->b_up;
	basics->costs.cheapest_cost = basics->costs.mix_1;
	basics->costs.cheapest_move = 1;
	if (basics->costs.mix_2 < basics->costs.cheapest_cost)
	{
		basics->costs.cheapest_cost = basics->costs.mix_2;
		basics->costs.cheapest_move = 2;
	}
	if (basics->costs.same_up <= basics->costs.cheapest_cost)
	{
		basics->costs.cheapest_cost = basics->costs.same_up;
		basics->costs.cheapest_move = 0;
	}
	if (basics->costs.same_down < basics->costs.cheapest_cost)
	{
		basics->costs.cheapest_cost = basics->costs.same_down;
		basics->costs.cheapest_move = 3;
	}
}

/**
 * @brief Finds the node in stack B with the lowest movement cost
 *
 * Iterates through all nodes in stack B, calculates movement costs for each,
 * and returns information about the node that requires the fewest operations
 * to correctly position both stacks for insertion.
 *
 * @param stack_a Destination stack
 * @param stack_b Source stack to analyze
 * @param basics Working structure for cost calculations

	* @return t_cheapest Structure containing the optimal node and movement strategy
 */
t_cheapest	calculate_cheapest_node(t_stack *stack_a, t_stack *stack_b,
		t_basic *basics)
{
	t_node		*current;
	t_cheapest	cheapest;

	current = stack_b->head;
	cheapest.cost = -1;
	if (!stack_b || !stack_b->head)
	{
		cheapest.cost = -1;
		return (cheapest);
	}
	while (current)
	{
		get_basic_costs(stack_a, stack_b, current, basics);
		if (cheapest.cost == -1 || basics->costs.cheapest_cost < cheapest.cost)
		{
			cheapest.cost = basics->costs.cheapest_cost;
			cheapest.move = basics->costs.cheapest_move;
			cheapest.b_node = current;
			cheapest.a_index = basics->a_index;
			cheapest.b_index = basics->index;
		}
		current = current->next;
		basics->index++;
	}
	return (cheapest);
}
