/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 22:45:30 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/12/10 17:14:49 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"
# include <stdbool.h>

typedef struct s_lst
{
	int				value;
	int				index;
	struct s_lst	*next;
	struct s_lst	*prev;
}					t_lst;

typedef struct s_stack
{
	t_lst			*head;
	t_lst			*tail;
	int				nodes;
}					t_stack;

// bubble_sort.c
void				bubble_sort(int *arr, int size);
int					*copy_into_sorted(int *arr, int size);
bool				is_sorted(int *unordered, int size);
int					*get_nums(int nums_count, char **argv);

// butterfly.c
void				find_max_and_push_b(t_lst *lst, t_stack *stack_a, int size);
void				find_max_and_push_a(t_lst *lst, t_stack *stack_b, int size);
void				sort_stack(t_stack *st_a, t_stack *st_b);
void				make_butterfly(t_stack *st_a, t_stack *st_b, int chunk);
void				butterfly_algo(t_stack *st_a, t_stack *st_b, int size);
// check_args.c
void				check_duplicates(int *unordered, int size);
void				check_num1(char *num, char **temp);
void				check_num(char *num, char **temp, int *nums_count);
int					get_nums_count(char **argv);
int					check_args(int argc, char **argv);

//	free.c
void				ft_free(int *unordered, int *sorted, char *sms);
void				free_matrix(char **matrix, int size);
void				free_and_exit(char **matrix, int size, char *sms);
void				free_list_and_exit(t_stack *stack, int **arrays, int i);
void				free_stacks_and_arrays(t_stack *st_a, t_stack *st_b,
						int *a1, int *a2);

// make_stack.c
int					find_index(int *arr, int value, int size);
t_lst				*make_lst(t_stack *stack, int *arrays[], int size, int i);
void				make_stack_a(t_stack *stack, int *unordered, int *sorted,
						int size);

// sortings.c
void				double_sort(int *unordered, int *sorted);
void				triple_sort(t_stack *stack_a);
void				fourple_sort(t_stack *stack_a, t_stack *stack_b, int size);
void				fiveple_sort(t_stack *stack_a, t_stack *stack_b, int size);
void				forbidden_sorting(int size, t_stack *stack_a,
						t_stack *stack_b);

// utils.c
void				init_stack(t_stack *st_b, int **sorted);
void				error_message(char *str);
int					get_matrix_size(char **matrix);
int					generate_chunk(int size);
// stack_actions.c
void				swap_stack(t_stack *stack, char *action);
void				rotate_stack(t_stack *stack, char *action);
void				reverse_rotate_stack(t_stack *stack, char *action);
void				push_stack(t_stack *from, t_stack *to, char *action);
void				push_stack_2(t_stack *from, char *action);

#endif