/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 00:04:56 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/12/25 00:06:33 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INITS_H
#define INITS_H

#include "push_swap.h"

	t_stack *init_stack(void);
	t_node	*init_node(int value);
	t_stack	*init_stack_from_arr(int *arr, int arr_len);
	t_stack *init_stack_from_args(int argc, char **argv);
#endif