/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_primitives.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 23:15:01 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/12/24 23:35:32 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_PRIMITIVES_H
# define STACK_PRIMITIVES_H

#include "push_swap.h"

bool	push(t_stack *stack, t_node *node);
void	push_end(t_stack *stack, t_node *node);
t_node	*pop(t_stack *stack);
t_node	*pop_end(t_stack *stack);

#endif