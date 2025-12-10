/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 23:22:33 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/12/11 03:50:30 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"
#include "push_swap.h"
#include "stack_actions.h"
#include "utils.h"
#include <stdlib.h>

void	swap_stack(t_stack *stack, char *action)
{
	int	temp;

	ft_printf("%s\n", action);
	temp = stack->head->value;
	stack->head->value = stack->head->next->value;
	stack->head->next->value = temp;
	temp = stack->head->index;
	stack->head->index = stack->head->next->index;
	stack->head->next->index = temp;
}

// instead of changing the values, I'm gonna swap the nodes.
// now it seems normal as we have only value and index but
// for linked lists, we should change the node instead of the values of node.
// void swap_stack (t_stack *stack, char *action)
// {
// 	t_lst *temp_prev;
// 	t_lst *temp_next;

// 	t_lst *node_a;
// 	t_lst *node_b;

// 	ft_printf("%s\n", action);

// 	node_a = stack->head;
// 	node_b = stack->head->next;

// 	temp_prev = node_a->prev;
// 	temp_next = node_a->next;

// 	node_a->next = node_b->next;
// 	node_a->prev = node_b->prev;

// 	node_b->next = temp_next;
// 	node_b->prev = temp_prev;
// }

void	rotate_stack(t_stack *stack, char *action)
{
	if (stack->nodes <= 1)
		return ;
	ft_printf("%s\n", action);
	stack->head = stack->head->next;
	stack->tail = stack->tail->next;
}

// I don't like the circular linked list 
// as we've to change extra value when we swap
// void rotate_stack(t_stack *stack, char *action)
// {
// 	t_lst *temp;

// 	if(stack->nodes <= 1)
// 	ft_printf("%s\n", action);
// 	temp = stack->head;
// 	stack->head = temp->next;
// 	stack->tail->next = temp;
// }

void	reverse_rotate_stack(t_stack *stack, char *action)
{
	ft_printf("%s\n", action);
	stack->head = stack->head->prev;
	stack->tail = stack->tail->prev;
}

// I won't use circular linked list so I've to change this one too.

// void	reverse_rotate_stack(t_stack *stack, char *action)
// {
// 	t_lst *temp;

// 	ft_printf("%s\n", action);

// 	temp = stack->tail;
// 	stack->tail = stack->tail->prev;
// 	stack->head->prev = temp;
// 	temp->prev = NULL;
// 	temp->next = stack->head;
// 	stack->head = temp;
// }

void	push_stack(t_stack *from, t_stack *to, char *action)
{
	t_lst	*new_lst;

	new_lst = malloc(sizeof(t_lst));
	if (!new_lst)
		error_message("Error\n");
	++to->nodes;
	new_lst->value = from->head->value;
	new_lst->index = from->head->index;
	if (to->head == NULL)
	{
		new_lst->next = NULL;
		new_lst->prev = NULL;
		to->head = new_lst;
		to->tail = new_lst;
	}
	else
	{
		new_lst->next = to->head;
		new_lst->prev = to->tail;
		to->head->prev = new_lst;
		to->head = new_lst;
		to->tail->prev = to->head;
	}
	push_stack_2(from, action);
}

void	push_stack_2(t_stack *from, char *action)
{
	if (from->nodes == 1)
	{
		free(from->head);
		from->head = NULL;
		from->tail = NULL;
	}
	else if (from->nodes == 2)
	{
		from->tail->next = NULL;
		from->tail->prev = NULL;
		free(from->head);
		from->head = from->tail;
	}
	else
	{
		from->head->next->prev = from->tail;
		from->tail->next = from->head->next;
		free(from->head);
		from->head = from->tail->next;
	}
	--from->nodes;
	ft_printf("%s\n", action);
}

// bullshit.
// You have two linked list but you are creating new nodes.
// You can easily just swap the memory addresses.
