/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 18:29:32 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/12/05 05:49:31 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_ccw(t_stack **head)
{
	t_stack	*prev_tail;
	t_stack	*new_tail;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	prev_tail = *head;
	while (prev_tail->next != NULL)
	{
		new_tail = prev_tail;
		prev_tail = prev_tail->next;
	}
	prev_tail->next = *head;
	new_tail->next = NULL;
	*head = prev_tail;
}

void	r_rotate_a(t_stack **head)
{
	rotate_ccw(head);
	ft_putstr("rra\n");
}

void	r_rotate_b(t_stack **head)
{
	rotate_ccw(head);
	ft_putstr("rrb\n");
}

void	r_rotate_ab(t_stack **stack_a, t_stack **stack_b)
{
	rotate_ccw(stack_a);
	rotate_ccw(stack_b);
	ft_putstr("rrr\n");
}