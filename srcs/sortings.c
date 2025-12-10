/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 01:44:18 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/12/10 20:02:46 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	double_sort(int *unordered, int *sorted)
{
	ft_putstr("sa\n");
	ft_free(unordered, sorted, "");
}

// void	triple_sort(t_stack *stack_a)
// {
// 	ft_putstr("triple sort called");
// 	int	arr[3];

// 	arr[0] = stack_a->head->index;
// 	arr[1] = stack_a->head->next->index;
// 	arr[2] = stack_a->tail->index;
// 	if (arr[0] == 0 && arr[1] == 2)
// 	{
// 		reverse_rotate_stack(stack_a, "rra");
// 		swap_stack(stack_a, "sa");
// 	}
// 	else if (arr[0] == 0 && arr[1] == 1)
// 		return ;
// 	else if (arr[0] == 1 && arr[1] == 0)
// 		swap_stack(stack_a, "sa");
// 	else if (arr[0] == 1 && arr[1] == 2)
// 		reverse_rotate_stack(stack_a, "rra");
// 	else if (arr[0] == 2 && arr[1] == 0)
// 		rotate_stack(stack_a, "ra");
// 	else if (arr[0] == 2 && arr[1] == 1)
// 	{
// 		swap_stack(stack_a, "sa");
// 		reverse_rotate_stack(stack_a, "rra");
// 	}
// }
#include "stdio.h"
void	triple_sort(t_stack *stack_a)
{
	int	arr[3];

	ft_putstr("triple sort working");

	arr[0] = stack_a->head->index;
	arr[1] = stack_a->head->next->index;
	arr[2] = stack_a->head->next->next->index;
	printf("%d , %d, %d \n", arr[0], arr[1], arr[2]);

	if (arr[0] == 0 && arr[1] == 2)
	{
		ft_putstr("first condition rra and sa\n");
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


void fourple_sort(t_stack *stack_a, t_stack *stack_b, int size)
{
	t_lst *lst;
	lst = stack_a->head;
	find_max_and_push_b(lst, stack_a, size);
	push_stack(stack_a, stack_b, "pb");
	triple_sort(stack_a);
	push_stack(stack_b, stack_a, "pa");
	rotate_stack(stack_a, "ra");
}

void fiveple_sort(t_stack *stack_a, t_stack *stack_b, int size)
{
	t_lst *lst;
	
	lst = stack_a->head;
	find_max_and_push_b(lst, stack_a, size);
	push_stack(stack_a, stack_b, "pb");
	lst = stack_a->head;
	find_max_and_push_b(lst, stack_a, size -1);
	push_stack(stack_a, stack_b, "pb");
	triple_sort(stack_a);
	push_stack(stack_b,stack_a, "pa");
	rotate_stack(stack_a,"ra");
	push_stack(stack_b, stack_a, "pa");
	rotate_stack(stack_a, "ra");
}

void forbidden_sorting(int size, t_stack *stack_a, t_stack *stack_b)
{
	ft_putstr("forbidden sorting\n");
	if(size == 3)
		triple_sort(stack_a);
	else if(size == 4)
		fourple_sort(stack_a, stack_b, size);
	else
		fiveple_sort(stack_a, stack_b, size);
}