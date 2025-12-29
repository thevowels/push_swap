/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 13:26:00 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/12/30 03:09:49 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Prints all values in a stack in a single line
 * 
 * Traverses the stack from head to tail and prints each node's value
 * separated by commas. Optionally prints a message prefix before the values.
 * 
 * @param stack Pointer to the stack to print
 * @param message Optional message to print before the stack values (can be NULL)
 */
void	print_stack(t_stack *stack, char *message)
{
	t_node	*node;

	node = stack->head;
	if (message)
		ft_printf("%s : ", message);
	while (node)
	{
		ft_printf("%i", node->value);
		if (!node->next)
			break ;
		ft_printf(", ");
		node = node->next;
	}
	ft_printf("\n");
}

/**
 * @brief Prints detailed information about each node from head to tail
 * 
 * Displays comprehensive debugging information for each node in the stack,
 * including memory addresses, values, and pointer relationships. Also prints
 * the head and tail information of the stack.
 * 
 * @param stack Pointer to the stack to analyze and print
 */ 
void	head_to_tail(t_stack *stack)
{
	t_node	*node;
	int		i;

	node = stack->head;
	if (stack->head)
	{
		ft_printf("Head: %p %d\n", stack->head, stack->head->value);
		ft_printf("Tail: %p %d\n", stack->tail, stack->tail->value);
	}
	i = 0;
	while (node)
	{
		ft_printf("Index : %d is address: %p , value: %d, next: %p, prev: %p\n",
			i, node, node->value, node->next, node->prev);
		node = node->next;
		i++;
	}
}

/**
 * @brief Prints stack information traversing from tail to head
 * 
 * Similar to head_to_tail but traverses the stack in reverse order using
 * the prev pointers. Useful for verifying the bidirectional linking of
 * the doubly linked list structure.
 * 
 * @param stack Pointer to the stack to traverse in reverse
 */
void	tail_to_head(t_stack *stack)
{
	t_node *node;
	int i;
	node = stack->tail;

	if (stack->head)
	{
		ft_printf("Head: %p %d\n", stack->head, stack->head->value);
		ft_printf("Tail: %p %d\n", stack->tail, stack->tail->value);
	}

	i = 0;
	while (node)
	{
		ft_printf("Index : %d is address: %p , value: %d\n", i, node,
			node->value);
		node = node->prev;
		i++;
	}
}