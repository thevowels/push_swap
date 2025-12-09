/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 01:44:18 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/12/10 01:51:53 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	double_sort(int *unordered, int *sorted)
{
	ft_putstr("sa\n");
	ft_free(unordered, sorted, "");
}

void	triple_sort(t_stack *stack_a)
{
	int	arr[3];

	arr[0] = stack_a->head->index;
	arr[1] = stack_a->head->next->index;
	arr[2] = stack_a->tail->index;
	if (arr[0] == 0 && arr[1] == 2)
	{
		reverse_rotate_stack(stack_a, "rra");
		swap_stack(stack_a, "sa");
	}
	else if (arr[0] == 0 && arr[1] == 1)
		return ;
	else if (arr[0] == 1 && arr[1] == 0)
		swap_stack(stack_a, "sa");
	else if (arr[0] == 1 && arr[1] == 2)
		reverse_rotate_stack(stack_a, "rra");
	else if (arr[0] == 2 && arr[1] == 0)
		rotate_stack(stack_a, "ra");
	else if (arr[0] == 2 && arr[1] == 1)
	{
		swap_stack(stack_a, "sa");
		reverse_rotate_stack(stack_a, "rra");
	}
}

// void	fourple_sort(t_stack *stack_a, t_stack *stack_b, int size)
// {
// 	t_lst *lst;
// 	lst = stack_a->head;
	
// 	find_max_and_
// }