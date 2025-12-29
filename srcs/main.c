/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 00:23:49 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/12/30 03:50:27 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "inits.h"
#include "test_helper.h"
#include "stack_aux.h"
#include "turk.h"

/**
 * @brief Main entry point for the push_swap program
 * 
 * Initializes two stacks (A and B) from command line arguments and performs
 * the Turk sort algorithm to sort the numbers. Stack A is populated from
 * the command line arguments, and stack B starts empty.
 * 
 * @param argc Number of command line arguments
 * @param argv Array of command line argument strings containing numbers to sort
 * @return int Program exit status (handled by exit calls in functions)
 */
int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = init_stack_from_args(argc, argv);
	stack_b = init_stack();
	if (stack_b)
	{
		turk_sort(stack_a, stack_b);
		stack_free(stack_b);
	}
	stack_free(stack_a);
}
