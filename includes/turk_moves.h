/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_moves.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 03:22:48 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/12/30 03:53:07 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TURK_MOVES_H
# define TURK_MOVES_H

# include "push_swap.h"

void	move_to_b(t_stack *stack_a, t_stack *stack_b);
void	do_op_up(t_stack *stack_a, t_stack *stack_b, t_cheapest *cheapest);
void	do_op_down(t_stack *stack_a, t_stack *stack_b, t_cheapest *cheapest);
void	do_op_a_up_b_down(t_stack *stack_a, t_stack *stack_b,
			t_cheapest *cheapest);
void	do_op_a_down_b_up(t_stack *stack_a, t_stack *stack_b,
			t_cheapest *cheapest);
#endif