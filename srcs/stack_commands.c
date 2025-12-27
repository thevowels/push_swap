/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 23:20:38 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/12/27 22:59:54 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stack_aux.h"
#include "stack_primitives.h"

/**
 * @brief Executes swap operation on one or two stacks
 *
 * Performs the swap operation on the first stack and optionally on a second stack.
 * This function implements the push_swap swap commands:
 * - sa: swap a (swap first 2 elements at the top of stack a)
 * - sb: swap b (swap first 2 elements at the top of stack b)
 * - ss: swap both stacks a and b simultaneously
 *
 * @param first Pointer to the first stack to swap (required)
 * @param second Pointer to the second stack to swap (NULL for single stack operations)
 * @param command String representation of the command to print (e.g., "sa", "sb", "ss")
 *
 * @note If second is NULL, only the first stack is swapped
 * @note The command string is printed to stdout after execution
 * @note Does nothing if the stack has fewer than 2 elements
 */
void	swap_command(t_stack *first, t_stack *second, char *command)
{
	swap(first);
	if (second)
		swap(second);
	ft_printf("%s\n", command);
}

/**
 * @brief Executes push operation from one stack to another
 *
 * Pops the top element from the source stack and pushes it to the destination stack.
 * This function implements the push_swap push commands:
 * - pa: push a (take first element at the top of b and put it at the top of a)
 * - pb: push b (take first element at the top of a and put it at the top of b)
 *
 * @param from Pointer to the source stack from which to pop the element
 * @param to Pointer to the destination stack to which to push the element
 * @param command String representation of the command to print (e.g., "pa", "pb")
 *
 * @note Does nothing if the source stack is empty
 * @note The command string is printed to stdout after execution
 * @note The operation is atomic: pop and push happen together
 */
void	push_command(t_stack *from, t_stack *to, char *command)
{
	t_node	*node;

	node = pop(from);
	push(to, node);
	ft_printf("%s\n", command);
}

/**
 * @brief Executes rotate operation on one or two stacks
 *
 * Performs the rotate operation on the first stack and optionally on a second stack.
 * Rotate shifts all elements up by 1, making the first element become the last.
 * This function implements the push_swap rotate commands:
 * - ra: rotate a (shift up all elements of stack a by 1)
 * - rb: rotate b (shift up all elements of stack b by 1)
 * - rr: rotate both stacks a and b simultaneously
 *
 * @param first Pointer to the first stack to rotate (required)
 * @param second Pointer to the second stack to rotate (NULL for single stack operations)
 * @param command String representation of the command to print (e.g., "ra", "rb", "rr")
 *
 * @note If second is NULL, only the first stack is rotated
 * @note The command string is printed to stdout after execution
 * @note Does nothing if the stack is empty or has only one element
 */
void	rotate_command(t_stack *first, t_stack *second, char *command)
{
	rotate(first);
	if (second)
		rotate(second);
	ft_printf("%s\n", command);
}

/**
 * @brief Executes reverse rotate operation on one or two stacks
 *
 * Performs the reverse rotate operation on the first stack and optionally on a second stack.
 * Reverse rotate shifts all elements down by 1, making the last element become the first.
 * This function implements the push_swap reverse rotate commands:
 * - rra: reverse rotate a (shift down all elements of stack a by 1)
 * - rrb: reverse rotate b (shift down all elements of stack b by 1)
 * - rrr: reverse rotate both stacks a and b simultaneously
 *
 * @param first Pointer to the first stack to reverse rotate (required)
 * @param second Pointer to the second stack to reverse rotate (NULL for single stack operations)
 * @param command String representation of the command to print (e.g., "rra", "rrb", "rrr")
 *
 * @note If second is NULL, only the first stack is reverse rotated
 * @note The command string is printed to stdout after execution
 * @note Does nothing if the stack is empty or has only one element
 */
void	reverse_rotate_command(t_stack *first, t_stack *second, char *command)
{
	reverse_rotate(first);
	if (second)
		reverse_rotate(second);
	ft_printf("%s\n", command);
}