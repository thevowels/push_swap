/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soort_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 06:01:49 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/12/05 06:04:01 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>
int find_biggest(t_stack *head)
{
	int big;
	t_stack *tmp;

	big = INT_MIN;
	tmp = head;
	while(*tmp)
	{
		if(tmp->index > big)
			big = tmp->index;
		tmp = tmp->next;
	}
	return (big);
}

int find_bits(int biggest_nbr)
{
	int max_bits;
	max_bits = 0;
	while(biggest_nbr > 0)
	{
		biggest_nbr >>= 1;
		max_bits++;
	}
	return (max_bits);
}