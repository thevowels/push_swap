/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 13:26:00 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/12/25 00:35:35 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack, char *message)
{
	t_node	*node;

	node = stack->head;
	if (message)
		ft_printf("%s : ", message);
	while (node)
	{
		ft_printf("%i", node->value);
		if (!node->next)
			break ;
		ft_printf(", ");
		node = node->next;
	}
	ft_printf("\n");
}
void	head_to_tail(t_stack *stack)
{
	t_node	*node;
	int		i;

	node = stack->head;
	if (stack->head)
	{
		ft_printf("Head: %p %d\n", stack->head, stack->head->value);
		ft_printf("Tail: %p %d\n", stack->tail, stack->tail->value);
	}
	i = 0;
	while (node)
	{
		ft_printf("Index : %d is address: %p , value: %d, next: %p, prev: %p\n",
			i, node, node->value, node->next, node->prev);
		node = node->next;
		i++;
	}
}

void	tail_to_head(t_stack *stack)
{
	t_node *node;
	int i;
	node = stack->tail;

	if (stack->head)
	{
		ft_printf("Head: %p %d\n", stack->head, stack->head->value);
		ft_printf("Tail: %p %d\n", stack->tail, stack->tail->value);
	}

	i = 0;
	while (node)
	{
		ft_printf("Index : %d is address: %p , value: %d\n", i, node,
			node->value);
		node = node->prev;
		i++;
	}
}