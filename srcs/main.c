/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 12:26:51 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/12/12 13:49:24 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int main(int argc, char **argv)
{
	t_stack *stack;
	t_node	*node;
	int		i;

	int arr[] = {1,2,3,4,5,6,7,8};
	stack = init_stack(arr, 8);

	head_to_tail(stack);
	tail_to_head(stack);
	swap(stack, "sa");
	head_to_tail(stack);
	tail_to_head(stack);
	rotate(stack, "ra");
	head_to_tail(stack);
	tail_to_head(stack);

	return (0);
}