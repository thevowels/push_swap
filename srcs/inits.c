/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 23:57:30 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/12/30 03:14:04 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// init operations

#include "push_swap.h"
#include "stack_aux.h"
#include "stack_primitives.h"

/**
 * @brief Initializes an empty stack
 * 
 * Allocates memory for a new stack structure and initializes all fields
 * to their default values (NULL pointers, zero count).
 * 
 * @return t_stack* Pointer to the newly created stack, or NULL if allocation fails
 */
t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->head = NULL;
	stack->tail = NULL;
	stack->count = 0;
	return (stack);
}

/**
 * @brief Initializes a new node with the given value
 * 
 * Allocates memory for a new node and sets its value. The index is set to 42
 * as a default value, and next/prev pointers are initialized to NULL.
 * 
 * @param value The integer value to store in the node
 * @return t_node* Pointer to the newly created node
 */
t_node	*init_node(int value)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	node->index = 42;
	node->value = value;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

/**
 * @brief Creates a stack from an array of integers
 * 
 * Takes an array of integers and creates a stack by pushing each element
 * onto the stack in order.
 * 
 * @param arr Array of integers to add to the stack
 * @param arr_len Length of the array
 * @return t_stack* Pointer to the newly created stack with all elements added
 */
t_stack	*init_stack_from_arr(int *arr, int arr_len)
{
	t_stack	*stack;
	t_node	*node;
	int		i;

	i = 0;
	node = NULL;
	stack = init_stack();
	while (i < arr_len)
	{
		node = init_node(arr[i]);
		push(stack, node);
		i++;
	}
	return (stack);
}

/**
 * @brief Checks if a stack contains a specific value
 * 
 * Searches through the stack to determine if it already contains
 * the specified value. Used for duplicate detection.
 * 
 * @param stack The stack to search in
 * @param value The value to search for
 * @return bool true if the value exists in the stack, false otherwise
 */
bool	is_contain(t_stack *stack, int value)
{
	t_node	*node;

	node = stack->head;
	while (node)
	{
		if (node->value == value)
			return (true);
		node = node->next;
	}
	return (false);
}

/**
 * @brief Converts a command line argument to a node and adds it to the stack
 * 
 * Parses a string argument as an integer and adds it to the end of the stack.
 * Performs validation to ensure the argument is a valid integer and not a duplicate.
 * 
 * @param stack The stack to add the node to
 * @param argv The string argument to parse and add
 * @return bool true if successfully added, false if parsing failed or duplicate found
 */
bool	arg_to_stack(t_stack *stack, char *argv)
{
	int		i;
	t_node	*node;

	if (!ft_safe_atoi(argv, &i) || is_contain(stack, i))
		return (false);
	node = init_node(i);
	if (!node)
		return (false);
	push_end(stack, node);
	return (true);
}

/**
 * @brief Initializes a stack from command line arguments
 * 
 * Creates a new stack and populates it with values from command line arguments.
 * Exits with success if no arguments provided, or exits with error if any
 * argument is invalid or if stack allocation fails.
 * 
 * @param argc Number of command line arguments
 * @param argv Array of command line argument strings
 * @return t_stack* Pointer to the newly created and populated stack
 */
t_stack	*init_stack_from_args(int argc, char **argv)
{
	t_stack *stack;

	if (argc == 1)
		exit(EXIT_SUCCESS);
	stack = init_stack();
	if (!stack)
		error_exit();

	while (*(++argv))
	{
		if (!arg_to_stack(stack, *argv))
		{
			stack_free(stack);
			error_exit();
		}
	}
	return (stack);
}