/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 00:37:04 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/12/30 03:53:11 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TURK_H
# define TURK_H

# include "push_swap.h"

t_node	*find_target(t_stack *stack_a, t_node *current, t_basic *basics);
void	move_back(t_stack *stack_a, t_stack *stack_b);
bool	is_sorted(t_stack *stack_a);
void	turk_sort(t_stack *stack_a, t_stack *stack_b);
#endif