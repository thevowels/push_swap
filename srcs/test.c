/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 00:23:49 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/12/25 00:39:52 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"
#include "inits.h"
#include "test_helper.h"

int main(void)
{
	t_stack *stack;
	int arr[] = {1,2,3,4,5,6};

	stack = init_stack_from_arr(arr,6);
	head_to_tail(stack);
}