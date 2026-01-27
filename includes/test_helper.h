/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_helper.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 00:29:36 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/12/30 03:53:04 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_HELPER_H
# define TEST_HELPER_H

# include "push_swap.h"

void	print_stack(t_stack *stack, char *message);
void	head_to_tail(t_stack *stack);
void	tail_to_head(t_stack *stack);
#endif