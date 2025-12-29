/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 03:22:45 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/12/30 03:30:50 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "turk_moves.h"
#include "stack_commands.h"
# include "turk.h"


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
 * @brief Executes simultaneous upward rotations on both stacks
 *
 * Performs the optimal number of combined rotations (rr), then completes
 * any remaining rotations needed on the individual stacks.
 *
 * @param stack_a First stack to rotate
 * @param stack_b Second stack to rotate
 * @param cheapest Structure containing movement indices
 */
void	do_op_up(t_stack *stack_a, t_stack *stack_b, t_cheapest *cheapest)
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
void	do_op_down(t_stack *stack_a, t_stack *stack_b, t_cheapest *cheapest)
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
void	do_op_a_up_b_down(t_stack *stack_a, t_stack *stack_b,
		t_cheapest *cheapest)
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
void	do_op_a_down_b_up(t_stack *stack_a, t_stack *stack_b,
		t_cheapest *cheapest)
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
