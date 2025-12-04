/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 18:25:25 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/12/04 18:29:18 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rotate_cw(t_stack **head)
{
	t_stack *tail;
	if(*head == NULL || (*head)->next  == NULL)
		return;
	tail = *head;
	while(tail->next != NULL)
		tail = tail->next;
	tail->next = *head;
	*head = (*head)->next;
	tail->next->next = NULL;
}

void rotate_a(t_stack **head)
{
	rotate_cw(head);
	ft_putstr("ra\n");
}

void rotate_b(t_stack **head)
{
	rotate_cw(head);
	ft_putstr("rb\n");
}

void rotate_ab(t_stack **stack_a, t_stack **stack_b)
{
	rotate_cw(stack_a);
	rotate_cw(stack_b);
	ft_putstr("rr\n");
}