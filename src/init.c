/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 18:03:10 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/12/04 18:20:34 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_index(t_stack *head, int link_size)
{
	t_stack	*biggest;
	t_stack	*tmp;

	while (link_size-- > 0)
	{
		biggest = NULL;
		tmp = head;
		while (tmp)
		{
			if (!tmp->index && (biggest == NULL || tmp->value > biggest->value))
				biggest = tmp;
			tmp = tmp->next;
		}
		if(biggest)
			biggest->index = link_size;
	}
}

t_stack	*init_list(int argc, char **argv)
{
	t_stack *stack_a;
	char **tmp;
	int i;

	stack_a = NULL;
	i = 0;
	if (argc == 2)
		tmp = ft_split(argv[i], ' ');
	else
	{
		i = 1;
		tmp = argv;
	}
	while (tmp[i])
	{
		insert_at_tail(&stack_a, ft_atoi(tmp[i]));
		i++;
	}
	if (argc == 2)
		ft_sarr_free(tmp);
	return (stack_a);
}