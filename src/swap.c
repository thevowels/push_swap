/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 18:21:50 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/12/04 18:25:05 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **head)
{
	t_stack *tmp;
	if(!*head || (*head)->next == NULL)
		return;
	tmp = (*head)->next;
	(*head)->next;
	tmp->next = *head;
	*head = tmp;
}

void swap_a(t_stack **head)
{
	swap(head);
	ft_putstr("sa\n");
}

void swap_b(t_stack **head)
{
	swap(head);
	ft_putstr("sb\n");
}

void swap_ab(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_putstr("ss\n");
}
