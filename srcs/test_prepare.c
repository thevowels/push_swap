/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_prepare.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 00:02:52 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/12/15 03:28:26 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"
#include <stdio.h>
int main(int argc, char **argv)
{

	t_stack *stack_a;
	t_node	*node;
	int		i;

	int arr[] = {8,5,6,3,1,2};
	stack_a= init_stack(arr, 6);
	do_sort(stack_a);
}