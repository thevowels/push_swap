/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 13:13:39 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/12/12 13:49:15 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack, char *command)
{
	t_node	*node_a;
	t_node	*node_b;
	t_node	*temp;

	if (!stack->head || !stack->head->next)
	{
		ft_printf("Swaping the stack without atleast two nodes");
		error_exit();
	}
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
	ft_printf("%s\n", command);
}
/*
1
2
3
4

2
3
4
1
*/


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
	ft_printf("%s\n", command);
}