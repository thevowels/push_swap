/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 22:33:18 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/12/14 22:48:28 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// TOdo check errors when the input is not integer or exceed the limits.

t_stack *get_stack_from_args(char **argv)
{	
	t_stack *stack_a;
	t_node	*node;
	
	stack_a = get_stack();
	while(*argv)
	{
		node = get_node(ft_atoi(*argv));
		push_stack(stack_a, node);
		argv++;
	}
	return stack_a;
}