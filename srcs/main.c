/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 00:23:49 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/12/29 05:07:11 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"
#include "inits.h"
#include "test_helper.h"
#include "stack_aux.h"
#include "turk.h"
int main(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack *stack_b;
	// t_stack *stack_b;

	stack_a = init_stack_from_args(argc, argv);	
	stack_b = init_stack();
	
	if(true)
	{
		turk_sort(stack_a, stack_b);
	}
	else
	{
	}
}	