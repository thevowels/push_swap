/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 22:45:30 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/12/10 00:26:25 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include "../libft/includes/libft.h"

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
}	t_stack;

// utils.c
void				error_message(char *str);
int					get_matrix_size(char **matrix);
int	generate_chunk(int size);


//	free.c
void	ft_free(int *unordered, int *sorted, char *sms);
void	free_matrix(char **matrix, int size);
void	free_and_exit(matrix,size);
void	free_list_and_exit(t_stack *stack, int **arrays, int i);
void	free_stacks_and_arrays(t_stack *st_a, t_stack *st_b, int *a1, int *a2);

// bubble_sort.c
void	bubble_sort(int *arr, int*size);
int		*copy_into_sorted(int *arr, int size);
bool	is_sorted(int	*unordered, int size);
int		*get_nums(int nums_count, char **argv);

#endif