/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 03:15:25 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/12/30 03:53:41 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COSTS_H
# define COSTS_H

# include "push_swap.h"

t_node		*find_smallest_larger(t_stack *stack_a, t_node *current,
				t_basic *basics);
t_node		*find_smallest(t_stack *stack_a, t_basic *basics);
void		calc_a_cheapest(t_stack *stack_a, t_node *current, t_basic *basics);
void		get_basic_costs(t_stack *stack_a, t_stack *stack_b, t_node *current,
				t_basic *basics);
t_cheapest	calculate_cheapest_node(t_stack *stack_a, t_stack *stack_b,
				t_basic *basics);
#endif