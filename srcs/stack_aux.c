/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_aux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 18:03:28 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/12/24 23:35:31 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stack_primitives.h"

bool	put(t_stack *from, t_stack *to)
{
	t_node	*node;

	node = pop(from);
	if (node)
		push(to, node);
	else
		return (false);
	return (true);
}

void	rotate(t_stack *stack)
{
	t_node	*node;

	if (!stack || !stack->head || !stack->head->next)
		return ;
	node = pop(stack);
	push_end(stack, node);
}

void	reverse_rotate(t_stack *stack)
{
	t_node	*node;

	if (!stack || !stack->head || !stack->head->next)
		return ;
	node = pop_end(stack);
	push(stack, node);
}

void	swap(t_stack *stack)
{
	t_node *first;
	t_node *second;

	if (!stack || !stack->head || !stack->head->next)
		return ;

	first = pop(stack);
	second = pop(stack);

	push(stack, first);
	push(stack, second);
}