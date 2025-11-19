/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   example_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 22:41:35 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/11/19 23:09:50 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	T_stack *front;
	T_stack *end;
	T_stack *current;
	int i;

	i = 0;

	front = malloc(sizeof(T_stack));
	front->value = 42;
	front->v_val = 1;
	front->next = NULL;
	front->prev = NULL;

	end = front;
	current = front;

	while(i < 10)
	{
		T_stack *new;
		new = malloc(sizeof(T_stack));
		new->value= (i * 10);
		new->v_val= (i);
		new->prev = current;
		current->next = new;

		current = new;
		i++;
	}

	current = front;
	
	while(1)
	{
		printf("Value %d\n", current->value);
		printf("V Val: %d\n", current->v_val);
		printf("Previous : %p\n", current->prev);
		printf("Next	 : %p\n", current->next);
		if(current->next != NULL)
			current = current->next;
		else
			break;
	}

	printf("************* Finish ************\n");
}