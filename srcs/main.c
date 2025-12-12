/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 12:26:51 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/12/12 13:00:37 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
int main(int argc, char **argv)
{
	t_stack *stack;
	
	int arr[] = {1,2,3,4,5,6,7,8};
	stack = init_stack(arr, 8);
	ft_printf("%p\n", stack);
	return (0);
}