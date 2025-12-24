/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 23:20:38 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/12/24 23:38:28 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stack_aux.h"
#include "stack_primitives.h"

// second is  NULL if only one stack swap
void	swap_command(t_stack *first, t_stack *second, char *command)
{
	swap(first);
	if (second)
		swap(second);
	ft_printf("%s\n", command);
}

void	push_command(t_stack *from, t_stack *to, char *command)
{
	t_node	*node;

	node = pop(from);
	push(to, node);
	ft_printf("%s\n", command);
}

void	rotate_command(t_stack *first, t_stack *second, char *command)
{
	rotate(first);
	if (second)
		rotate(second);
	ft_printf("%s\n", command);
}
void	reverse_rotate_command(t_stack *first, t_stack *second, char *command)
{
	reverse_rotate(first);
	if (second)
		reverse_rotate(second);
	ft_printf("%s\n", command);
}