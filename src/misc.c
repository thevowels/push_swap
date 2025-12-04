/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 17:50:58 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/12/04 17:59:35 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_msg(char *str)
{
	int i;

	i = 0;
	ft_putstr_fd(str, 1);
	write(1, "\n", 1);
	exit(0);
}

int sorted(t_stack **head)
{
	t_stack *tmp;
	
	tmp = *head;
	while( tmp && tmp->next)
	{
		if(tmp->index > tmp->next->index)
			return (0);
		tmp = tmp->next;
	}
	return (1);

}
void free_stack(t_stack **head)
{
	t_stack *tmp;
	while(*head)
	{
		tmp = *head;
		*head = (*head)->next;
		free(tmp);
	}
}

int count_arg(char **argv)
{
	int i;
	i = 0;
	while(argv[i])
		i++;
	return (i);
}