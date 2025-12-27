/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_aux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 18:03:28 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/12/27 23:01:57 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stack_primitives.h"

/**
 * @brief Moves the top element from one stack to another
 * 
 * This auxiliary function combines the pop and push operations to transfer
 * the top element from the source stack to the destination stack in a single
 * operation. This is commonly used in push_swap operations.
 * 
 * @param from Pointer to the source stack to pop from
 * @param to Pointer to the destination stack to push to
 * @return true if the operation was successful (element was transferred)
 * @return false if the operation failed (source stack was empty)
 */
bool	put(t_stack *from, t_stack *to)
{
	t_node	*node;

	node = pop(from);
	if (node)
		push(to, node);
	else
		return (false);
	return (true);
}

/**
 * @brief Rotates the stack upward (first element becomes last)
 * 
 * Takes the top element of the stack and moves it to the bottom.
 * This is equivalent to the "ra" or "rb" operations in push_swap.
 * Does nothing if the stack is NULL, empty, or has only one element.
 * 
 * @param stack Pointer to the stack to rotate
 */
void	rotate(t_stack *stack)
{
	t_node	*node;

	if (!stack || !stack->head || !stack->head->next)
		return ;
	node = pop(stack);
	push_end(stack, node);
}

/**
 * @brief Rotates the stack downward (last element becomes first)
 * 
 * Takes the bottom element of the stack and moves it to the top.
 * This is equivalent to the "rra" or "rrb" operations in push_swap.
 * Does nothing if the stack is NULL, empty, or has only one element.
 * 
 * @param stack Pointer to the stack to reverse rotate
 */
void	reverse_rotate(t_stack *stack)
{
	t_node	*node;

	if (!stack || !stack->head || !stack->head->next)
		return ;
	node = pop_end(stack);
	push(stack, node);
}

/**
 * @brief Swaps the top two elements of the stack
 * 
 * Exchanges the positions of the first and second elements at the top
 * of the stack. This is equivalent to the "sa" or "sb" operations in push_swap.
 * Does nothing if the stack is NULL, empty, or has only one element.
 * 
 * @param stack Pointer to the stack whose top elements should be swapped
 */
void	swap(t_stack *stack)
{
	t_node *first;
	t_node *second;

	if (!stack || !stack->head || !stack->head->next)
		return ;

	first = pop(stack);
	second = pop(stack);

	push(stack, first);
	push(stack, second);
}