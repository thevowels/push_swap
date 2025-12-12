/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 12:26:51 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/12/12 13:12:13 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int main(int argc, char **argv)
{
	t_stack *stack;
	t_node	*node;

	int arr[] = {1,2,3,4,5,6,7,8};
	stack = init_stack(arr, 8);
	
	node = stack->head;
	if(stack->head)
	{
		ft_printf("Head: %p %d\n", stack->head, stack->head->value);
		ft_printf("Tail: %p %d\n", stack->tail, stack->tail->value);	
	}
	
	int i = 0;
	while(node)
	{
		ft_printf("Index : %d is address: %p , value: %d\n", i, node, node->value);
		node = node->next;
		i++;
	}
	
	return (0);
}