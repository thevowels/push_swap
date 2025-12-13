/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 13:13:39 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/12/13 17:19:56 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_stack(t_stack *stack, t_node *node)
{
	node->next = stack->head;
	if(stack->head)
		stack->head->prev = node;
	stack->head = node;
	if(stack->tail == NULL)
		stack->tail = node;
	stack->count += 1;
}

t_node *pop_stack(t_stack *stack)
{
	t_node *node;
	
	node = stack->head;
	stack->head = node->next;
	stack->count -=1;
	node->next = NULL;

	return (node);
}

void pop_push(t_stack *from , t_stack *to, char *command)
{
	t_node *node;

	node = pop_stack(from);
	push_stack(to, node);

	if(command)
		ft_printf("%s\n", command);

}



void	swap(t_stack *stack, char *command)
{
	t_node	*node_a;
	t_node	*node_b;
	t_node	*temp;

	if (stack->head && stack->head->next)
	{
		node_a = stack->head;
		node_b = node_a->next;
		temp = node_a;
		if (stack->tail == node_b)
			stack->tail = node_a;
		// TODO: we've to chage head, tail
		//  prev and next of each node
		stack->head = node_b;
		node_b->next->prev = node_a;
		node_a->next = node_b->next;
		node_b->next = temp;
		node_b->prev = NULL;
		node_a->prev = node_b;	

	}
	if(command)
		ft_printf("%s\n", command);
}

void	rotate(t_stack *stack, char *command)
{
	t_node *temp;
	
	if(stack->head && stack->head->next)
	{
		temp = stack->head;
		stack->head = temp->next;
		stack->head->prev = NULL;
		temp->next=NULL;
		temp->prev= stack->tail;
		stack->tail->next = temp;
		stack->tail = temp;
	}
	if(command)
		ft_printf("%s\n", command);
}

void reverse_rotate(t_stack *stack, char *command)
{
	t_node *temp;

	if(stack->head && stack->head->next)
	{
		temp = stack->tail;
		stack->tail = stack->tail->prev;
		stack->tail->next = NULL;
		temp->prev = NULL;
		temp->next = stack->head;
		stack->head->prev = temp;
		stack->head = temp;
	}
	if(command)
		ft_printf("%s\n", command);
}