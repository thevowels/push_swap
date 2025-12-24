/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_primitives.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 23:14:18 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/12/24 23:41:10 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

/**
 * @brief Pushes a node to the top of the stack
 *
 * Adds a new node to the top (head) of the stack. The node becomes the new head
 * of the stack, and its next pointer is set to the previous head. If the stack
 * was empty, the node also becomes the tail. The stack count is incremented.
 *
 * @param stack Pointer to the stack structure where the node will be pushed
 * @param node Pointer to the node to be added to the stack
 *
 * @return true on successful push operation, false if parameters are invalid
 *
 * @note The node's prev pointer is set to NULL as it becomes the head
 * @note Function validates input parameters before performing operations
 */
bool	push(t_stack *stack, t_node *node)
{
	if (!stack || !node)
		return (false);
	node->prev = NULL;
	node->next = stack->head;
	if (stack->head)
		stack->head->prev = node;
	stack->head = node;
	if (stack->tail == NULL)
		stack->tail = node;
	stack->count += 1;
	return (true);
}

void	push_end(t_stack *stack, t_node *node)
{
	if (!stack || !node)
		return ;
	stack->tail->next = node;
	node->prev = stack->tail;
	node->next = NULL;
	stack->tail = node;
	stack->count += 1;
}

/**
 * @brief Removes and returns the top node from the stack
 *
 * Removes the head node from the stack and returns it. Updates the stack's
 * head pointer to the next node, decrements the count, and handles edge cases
 * for empty stacks and single-node stacks. The returned node's pointers are
 * cleaned up to prevent dangling references.
 *
 * @param stack Pointer to the stack structure from which to pop
 *
 * @return Pointer to the popped node on success,
	NULL if stack is empty or invalid
 *
 * @note The returned node's next and prev pointers are set to NULL
 * @note Caller is responsible for managing the memory of the returned node
 * @note Function validates input parameters before performing operations
 */

t_node	*pop(t_stack *stack)
{
	t_node	*temp;

	if (!stack || !stack->head)
		return (NULL);
	temp = stack->head;
	stack->head = temp->next;
	if (stack->head)
		stack->head->prev = NULL;
	else
		stack->tail = NULL;
	temp->next = NULL;
	stack->count -= 1;
	return (temp);
}

t_node	*pop_end(t_stack *stack)
{
	t_node	*node;

	if (!stack || !stack->head)
		return (NULL);
	if (!stack->head->next)
		return (pop(stack));
	node = stack->tail;
	stack->tail = stack->tail->prev;
	stack->tail->next = NULL;
	node->prev = NULL;
	stack->count -= 1;
	return (node);
}
