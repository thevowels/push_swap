/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 22:45:30 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/12/12 11:42:18 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define EXIT_SUCCESS 0
# define EXIT_MALLOC_FAILURE 1
# define EXIT_INVALID_INT_INPUT 2
# define EXIT_DUPLICATES 3

# include <stdbool.h> // bool
# include <limits.h> // INT_MAX, etc.
# include <stddef.h>

typedef struct s_stacks
{
	size_t	size_a;
	size_t	size_b;
	int		*stack_a;
	int		*stack_b;
	size_t	*target_a;
	size_t	*target_b;
	int		*cost;
	int		*rr;
	int		*rrr;
}	t_stacks;

#endif