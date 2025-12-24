/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 23:57:30 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/12/25 00:04:53 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// init operations

#include "push_swap.h"
#include "stack_primitives.h"

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
		node = get_node(arr[i]);
		push(stack, node);
		i++;
	}
	return (stack);
}


t_stack *init_stack_from_args(int argc, char **argv)
{
	return;
}