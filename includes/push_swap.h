/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 22:45:30 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/12/30 03:52:30 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"
# include "ft_maths.h"
# include <stdbool.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node			*head;
	t_node			*tail;
	int				count;
}					t_stack;

// mix 1 for a_up b_down
// mix 2 for a_down b_up
typedef struct s_cost_calc
{
	int				same_up;
	int				same_down;
	int				mix_1;
	int				mix_2;
	int				cheapest_move;
	int				cheapest_cost;
}					t_cost_calc;

typedef struct s_basic
{
	int				a_up;
	int				a_down;
	int				b_up;
	int				b_down;
	int				index;
	int				a_index;
	t_cost_calc		costs;
}					t_basic;

/*
move
0 => same_up
1 => mix_1
2 => mix_2
3 => same_down
*/
typedef struct s_cheapest
{
	int				cost;
	int				move;
	int				a_index;
	int				b_index;
	t_node			*a_node;
	t_node			*b_node;

}					t_cheapest;
// printf
int					ft_printf(const char *str, ...);

// errors
void				error_exit(void);

#endif