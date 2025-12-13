/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 12:32:16 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/12/13 17:19:40 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack) * 1);
	if (!stack)
		error_exit();
	stack->head = NULL;
	stack->tail = NULL;
	stack->count = 0;
	return (stack);
}
// need to find  a way to get the index
t_node	*get_node(int val)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node) * 1);
	node->value = val;
	node->next = NULL;
	node->prev = NULL;
	node->index = 42;
	return (node);
}

t_node	*find_last_node(t_stack *stack)
{
	t_node	*temp;

	if (!stack)
		error_exit();
	temp = stack->head;
	while (temp->next)
	{
		temp = temp->next;
	}
	return (temp);
}
// find_last_node two times. can optimize it but we've only 25 lines
// t_stack	*init_stack(int *arr, int arr_len)
// {
// 	t_stack	*stack;
// 	t_node	*node;
// 	int		i;

// 	i = 0;
// 	node = NULL;
// 	stack = get_stack();
// 	while (i < arr_len)
// 	{
// 		node = get_node(arr[i]);
// 		if (stack->head)
// 			{
// 				node->prev = find_last_node(stack);
// 				find_last_node(stack)->next = node;
// 			}
// 		else
// 			stack->head = node;
// 		stack->tail = node;
// 		i++;
// 	}
// 	return (stack);
// }

#include <stdio.h>

t_stack	*init_stack(int *arr, int arr_len)
{
	t_stack	*stack;
	t_node	*node;
	int		i;

	i = 0;
	node = NULL;
	stack = get_stack();

	while (i < arr_len)
	{

		node = get_node(arr[i]);
		push_stack(stack,node);
		i++;
	}

	return (stack);
}
