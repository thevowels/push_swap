/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 00:23:49 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/02/01 03:29:50 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inits.h"
#include "push_swap.h"
#include "test_helper.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack	*stack_a;

	stack_a = init_stack_from_args(argc, argv);
	head_to_tail(stack_a);
}
