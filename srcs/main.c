/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 00:23:49 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/02/01 03:29:04 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aux.h"
#include "inits.h"
#include "push_swap.h"
#include "stack_aux.h"
#include "test_helper.h"
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
	if (stack_a->count == 3)
		aux_sort(stack_a);
	stack_b = init_stack();
	if (stack_b)
	{
		turk_sort(stack_a, stack_b);
		stack_free(stack_b);
	}
	stack_free(stack_a);
}
