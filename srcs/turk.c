/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 00:36:39 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/12/30 03:09:49 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_maths.h"
#include "push_swap.h"
#include "stack_commands.h"
#include "turk.h"

/**
 * @brief Moves all but the last 2 elements from stack A to stack B
 * 
 * This is the first phase of the Turk sort algorithm. It pushes elements
 * from stack A to stack B, leaving only 2 elements in stack A to serve
 * as a foundation for the sorting process.
 * 
 * @param stack_a Source stack to move elements from
 * @param stack_b Destination stack to move elements to
 */
void	move_to_b(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_a && stack_a->count > 2)
		push_command(stack_a, stack_b, "pb");
}

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
	basics->index = 0;
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
			// cheapest.a_node
			cheapest.b_node = current;
			cheapest.a_index = basics->a_index;
			cheapest.b_index = basics->index;
		}
		current = current->next;
		basics->index++;
	}
	return (cheapest);
}

/**
 * @brief Executes simultaneous upward rotations on both stacks
 * 
 * Performs the optimal number of combined rotations (rr), then completes
 * any remaining rotations needed on the individual stacks.
 * 
 * @param stack_a First stack to rotate
 * @param stack_b Second stack to rotate
 * @param cheapest Structure containing movement indices
 */
void	do_op_up(t_stack *stack_a, t_stack *stack_b,
		t_cheapest *cheapest)
{
	int	i;

	i = 0;
	while (i < ft_min(cheapest->b_index, cheapest->a_index))
	{
		rotate_command(stack_a, stack_b, "rr");
		i++;
	}
	if (cheapest->b_index > cheapest->a_index)
	{
		while (i < cheapest->b_index)
		{
			rotate_command(stack_b, NULL, "rb");
			i++;
		}
	}
	else
		while (i < cheapest->a_index)
		{
			rotate_command(stack_a, NULL, "ra");
			i++;
		}
}

/**
 * @brief Executes simultaneous downward rotations on both stacks
 * 
 * Performs the optimal number of combined reverse rotations (rrr), then
 * completes any remaining reverse rotations needed on individual stacks.
 * 
 * @param stack_a First stack to reverse rotate
 * @param stack_b Second stack to reverse rotate
 * @param cheapest Structure containing movement indices
 */
void	do_op_down(t_stack *stack_a, t_stack *stack_b,
		t_cheapest *cheapest)
{
	int	i;
	int	a_down;
	int	b_down;

	a_down = stack_a->count - cheapest->a_index;
	b_down = stack_b->count - cheapest->b_index;
	i = 0;
	while (i++ <= ft_min(a_down, b_down))
		reverse_rotate_command(stack_a, stack_b, "rrr");
	if (a_down > b_down)
	{
		while (i < a_down)
		{
			reverse_rotate_command(stack_a, NULL, "rra");
			i++;
		}
	}
	else
		while (i < b_down)
		{
			reverse_rotate_command(stack_b, NULL, "rrb");
			i++;
		}
}

/**
 * @brief Executes stack A upward rotation and stack B downward rotation
 * 
 * Rotates stack A upward while rotating stack B downward. This mixed
 * movement strategy is used when the optimal positions require opposite
 * rotation directions.
 * 
 * @param stack_a Stack to rotate upward
 * @param stack_b Stack to rotate downward  
 * @param cheapest Structure containing movement indices
 */
void	do_op_a_up_b_down(t_stack *stack_a, t_stack *stack_b, t_cheapest *cheapest)
{
	int	i;
	int	b_down;
	b_down = stack_b->count - cheapest->b_index;
	i = 0;
	while (i < cheapest->a_index)
	{
		rotate_command(stack_a, NULL, "ra");
		i++;
	}
	i = 0;
	while (i < b_down)
	{
		reverse_rotate_command(stack_b, NULL, "rrb");
		i++;
	}
}

/**
 * @brief Executes stack A downward rotation and stack B upward rotation
 * 
 * Rotates stack A downward while rotating stack B upward. This mixed
 * movement strategy is the opposite of do_op_a_up_b_down.
 * 
 * @param stack_a Stack to rotate downward
 * @param stack_b Stack to rotate upward
 * @param cheapest Structure containing movement indices
 */
void	do_op_a_down_b_up(t_stack *stack_a, t_stack *stack_b, t_cheapest *cheapest)
{
	int	i;
	int	a_down;

	a_down = stack_a->count - cheapest->a_index;
	i = 0;
	while (i < a_down)
	{
		reverse_rotate_command(stack_a, NULL, "rra");
		i++;
	}
	i = 0;
	while (i < cheapest->b_index)
	{
		rotate_command(stack_b, NULL, "rb");
		i++;
	}
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
bool is_sorted(t_stack *stack_a)
{
	t_node *node;
	node = stack_a->head;
	while(node->next)
	{
		if(node->next->value < node->value)
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
