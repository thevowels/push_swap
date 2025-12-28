/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 23:57:30 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/12/29 05:23:57 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// init operations

#include "push_swap.h"
#include "stack_primitives.h"
#include "stack_aux.h"

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		error_exit();
	stack->head = NULL;
	stack->tail = NULL;
	stack->count = 0;
	return (stack);
}

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
bool is_contain(t_stack *stack , int value)
{
	t_node *node;

	node = stack->head;
	while(node)
	{
		if(node->value == value)
			return (true);
		node = node->next;
	}
	return (false);
}

// if only 1 word, atoi and add to stack
// if more than 1 word, do ft_split and then atoi then add to stack
// now for simplicity, assume that the input are only one word for each
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