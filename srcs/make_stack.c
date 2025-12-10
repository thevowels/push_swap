/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 03:21:18 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/12/11 03:50:05 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"
#include <stdlib.h>

int	find_index(int *arr, int value, int size)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		if (arr[i] == value)
			return (i);
	}
	return (0);
}
// int array cannot be null terminated as zero itself is an integer.
// If I want a null terminated array, I should have int **arr
// arr would be pointer pointing to array of pointing to integers.
// if we do that, we can do null terminating int pointer array.

t_lst	*make_lst(t_stack *stack, int *arrays[], int size, int i)
{
	t_lst	*new_lst;
	t_lst	*temp_head;

	new_lst = malloc(sizeof(t_lst));
	if (!new_lst)
		free_list_and_exit(stack, arrays, i);
	if (i == 0)
	{
		new_lst->value = arrays[0][0];
		new_lst->index = find_index(arrays[1], new_lst->value, size);
		new_lst->prev = NULL;
	}
	else
	{
		temp_head = stack->head;
		while (temp_head->next != NULL)
			temp_head = temp_head->next;
		new_lst->value = arrays[0][i];
		new_lst->index = find_index(arrays[1], new_lst->value, size);
		temp_head->next = new_lst;
		new_lst->prev = temp_head;
	}
	stack->tail = new_lst;
	new_lst->next = NULL;
	return (new_lst);
}

// what is it ?
// it create a new lst (new node)
// if there is an error, exit
// if i is 0 ,
// it means we are at the start of the linked list so the prev would be null.
// if its not the start, we push to the stack. as we push a value into stack,
	// it becomes the head.
// wait someting is off.  if its not start,
	// we add the value at the end of the linked list,
// and it seems like the next of tail is NULL so there is no circular.
// what a pity. you make it circular on parent function

void	make_stack_a(t_stack *stack, int *unordered, int *sorted, int size)
{
	int	i;
	int	*arrays[2];

	stack->head = NULL;
	stack->tail = NULL;
	arrays[0] = unordered;
	arrays[1] = sorted;
	stack->head = make_lst(stack, arrays, size, 0);
	i = 0;
	while (++i < size)
		make_lst(stack, arrays, size, i);
	stack->tail->next = stack->head;
	stack->head->prev = stack->tail;
	stack->nodes = size;
}

// adding the lst (nodes) into the list to create a stack.
// unordered and ordered list to array to pas to other function with just one vairable
// create the head of the stack
// and then create wtf. you can do it within the loop with very little modification
// make the stack(linked list into circular) why?????
// set the stack's count.