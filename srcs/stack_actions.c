/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 00:30:15 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/12/10 17:01:13 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

void swap_stack(t_stack *stack, char *action)
{
	int temp;
	ft_putstr(action);
	ft_putstr("\n");
	temp = stack->head->value;
	stack->head->value = stack->head->next->value;
	stack->head->next->value = temp;
	temp = stack->head->index;
	stack->head->index = stack->head->next->index;
	stack->head->next->index =temp;
}

void rotate_stack(t_stack *stack, char *action)
{
	if(stack->nodes <= 1)
		return;
	ft_putstr(action);
	ft_putstr("\n");
	stack->head = stack->head->next;
	stack->tail = stack->tail->next;
}

void reverse_rotate_stack(t_stack *stack, char *action)
{
	ft_putstr(action);
	ft_putstr("\n");
	stack->head = stack->head->prev;
	stack->tail = stack->tail->prev;
}

void push_stack(t_stack *from , t_stack *to, char *action)
{
	t_lst *new_lst;
	
	new_lst = malloc(sizeof(t_lst));
	if(!new_lst)
		error_message("Error\n");
	++(to->nodes);
	new_lst->value = from->head->value;
	new_lst->index = from->head->index;
	if(to->head == NULL)
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
		to->tail->next = to->head;
	}
	push_stack_2(from, action);
}

void push_stack_2(t_stack *from , char *action)
{
	if(from->nodes == 1)
	{
		free(from->head);
		from->head = NULL;
		from->tail = NULL;
	}
	else if( from->nodes == 2)
	{
		from->tail->next = NULL;
		from->tail->prev = NULL;
		free(from->head);
		from->head = from->tail;
	}
	else
	{
		from->head->next->prev = from->tail;
		// wtf is that? next->prev = current one. nice trick to catch the copycats.
		from->tail->next = from->head->next;
		//tail->next you are using the circular so tail->next would be the head
		free(from->head);
		from->head = from->tail->next;
	}
	--(from->nodes);
	ft_putstr(action);
	ft_putstr("\n");
}
