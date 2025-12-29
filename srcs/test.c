/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 00:23:49 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/12/30 03:14:17 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"
#include "inits.h"
#include "test_helper.h"
#include "turk.h"
#include <stdio.h>

/**
 * @brief Test function for debugging and validating the push_swap implementation
 * 
 * This is a test main function used for development and debugging purposes.
 * It creates a predefined stack with test values and runs the Turk sort algorithm
 * to verify the sorting functionality. Contains commented code for step-by-step
 * debugging of the move_to_b and move_back operations.
 * 
 * @return int Program exit status (0 on success)
 */
int main(void)
{
    t_stack *stack;
    t_stack *stack_b;
    int arr[] = {1,8,9,7,3};
    
    stack = init_stack_from_arr(arr,5);
    stack_b = init_stack();
    
    // head_to_tail(stack);
    
    // printf("\nAfter move_to_b:\n");
    // move_to_b(stack, stack_b);
    // printf("Stack A:\n");
    // head_to_tail(stack);
    // printf("Stack B:\n");
    // head_to_tail(stack_b);
    
    // printf("\nAfter move_back:\n");
    // move_back(stack, stack_b);
    // head_to_tail(stack);
    turk_sort(stack, stack_b);
	// printf("Done sorting==========\n");
	// head_to_tail(stack);
    return (0);
}