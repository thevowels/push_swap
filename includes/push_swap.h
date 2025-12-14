/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 22:45:30 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/12/14 22:49:42 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"
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
	t_node			*count;
}					t_stack;

// printf
int					ft_printf(const char *str, ...);

// errors
void				error_exit(void);

// init
t_stack				*get_stack(void);
t_node				*get_node(int val);
t_node				*find_last_node(t_stack *stack);
t_stack				*init_stack(int *arr, int arr_len);

// stack_operations.c
void				push_stack(t_stack *stack, t_node *node);
t_node				*pop_stack(t_stack *stack);
void				pop_push(t_stack *from, t_stack *to, char *command);

void				swap(t_stack *stack, char *command);
void				rotate(t_stack *stack, char *command);
void				reverse_rotate(t_stack *stack, char *command);

// arg_control
t_stack				*get_stack_from_args(char **argv);
// test
void				print_stack(t_stack *stack, char *message);
void				head_to_tail(t_stack *stack);
void				tail_to_head(t_stack *stack);

#endif