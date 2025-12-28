/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 00:36:39 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/12/29 05:14:51 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_maths.h"
#include "push_swap.h"
#include "stack_commands.h"
#include "turk.h"

void	move_to_b(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_a && stack_a->count > 2)
		push_command(stack_a, stack_b, "pb");
}
t_node	*find_smallest_larger(t_stack *stack_a, t_node *current,
		t_basic *basics)
{
	t_node	*target;
	t_node	*temp;
	int		index;

	target = NULL;
	temp = stack_a->head;
	index = 0;
	while (temp)
	{
		if (temp->value > current->value)
		{
			if (!target || temp->value < target->value)
			{
				target = temp;
				basics->a_index = index;
			}
		}
		temp = temp->next;
		index++;
	}
	return (target);
}

t_node	*find_smallest(t_stack *stack_a, t_basic *basics)
{
	t_node	*target;
	t_node	*temp;
	int		index;

	target = stack_a->head;
	temp = stack_a->head;
	index = 0;
	basics->a_index = 0;
	while (temp)
	{
		if (temp->value < target->value)
		{
			target = temp;
			basics->a_index = index;
		}
		temp = temp->next;
		index++;
	}
	return (target);
}

// find the smallest larger
t_node	*find_target(t_stack *stack_a, t_node *current, t_basic *basics)
{
	t_node	*target;

	if (!stack_a || !stack_a->head || !current)
		return (NULL);
	target = find_smallest_larger(stack_a, current, basics);
	if (!target)
		target = find_smallest(stack_a, basics);
	return (target);
}

void	calc_a_cheapest(t_stack *stack_a, t_node *current, t_basic *basics)
{
	t_node	*target;

	target = find_target(stack_a, current, basics);
	if (!target || !stack_a)
		return ;
	basics->a_up = basics->a_index;
	basics->a_down = stack_a->count - basics->a_index;
}

void	get_basic_costs(t_stack *stack_a, t_stack *stack_b, t_node *current,
		t_basic *basics)
{
	calc_a_cheapest(stack_a, current, basics);
	basics->b_up = basics->index;
	basics->b_down = stack_b->count - basics->index;
	basics->costs.same_up = ft_max(basics->a_up, basics->b_up);
	basics->costs.same_down = ft_max(basics->a_down, basics->b_down);
	basics->costs.mix_1 = basics->a_up + basics->b_down;
	basics->costs.mix_2 = basics->a_down + basics->b_up;
	basics->costs.cheapest_cost = basics->costs.mix_1;
	basics->costs.cheapest_move = 1;
	if (basics->costs.mix_2 < basics->costs.cheapest_cost)
	{
		basics->costs.cheapest_cost = basics->costs.mix_2;
		basics->costs.cheapest_move = 2;
	}
	if (basics->costs.same_up <= basics->costs.cheapest_cost)
	{
		basics->costs.cheapest_cost = basics->costs.same_up;
		basics->costs.cheapest_move = 0;
	}
	if (basics->costs.same_down < basics->costs.cheapest_cost)
	{
		basics->costs.cheapest_cost = basics->costs.same_down;
		basics->costs.cheapest_move = 3;
	}
}

t_cheapest	calculate_cheapest_node(t_stack *stack_a, t_stack *stack_b,
		t_basic *basics)
{
	t_node		*current;
	t_cheapest	cheapest;

	current = stack_b->head;
	basics->index = 0;
	cheapest.cost = -1;
	if (!stack_b || !stack_b->head)
	{
		cheapest.cost = -1;
		return (cheapest);
	}
	while (current)
	{
		get_basic_costs(stack_a, stack_b, current, basics);
		if (cheapest.cost == -1 || basics->costs.cheapest_cost < cheapest.cost)
		{
			cheapest.cost = basics->costs.cheapest_cost;
			cheapest.move = basics->costs.cheapest_move;
			// cheapest.a_node
			cheapest.b_node = current;
			cheapest.a_index = basics->a_index;
			cheapest.b_index = basics->index;
		}
		current = current->next;
		basics->index++;
	}
	return (cheapest);
}
void	do_op_up(t_stack *stack_a, t_stack *stack_b,
		t_cheapest *cheapest)
{
	int	i;

	i = 0;
	while (i < ft_min(cheapest->b_index, cheapest->a_index))
	{
		rotate_command(stack_a, stack_b, "rr");
		i++;
	}
	if (cheapest->b_index > cheapest->a_index)
	{
		while (i < cheapest->b_index)
		{
			rotate_command(stack_b, NULL, "rb");
			i++;
		}
	}
	else
		while (i < cheapest->a_index)
		{
			rotate_command(stack_a, NULL, "ra");
			i++;
		}
}
void	do_op_down(t_stack *stack_a, t_stack *stack_b,
		t_cheapest *cheapest)
{
	int	i;
	int	a_down;
	int	b_down;

	a_down = stack_a->count - cheapest->a_index;
	b_down = stack_b->count - cheapest->b_index;
	i = 0;
	while (i++ <= ft_min(a_down, b_down))
		reverse_rotate_command(stack_a, stack_b, "rrr");
	if (a_down > b_down)
	{
		while (i < a_down)
		{
			reverse_rotate_command(stack_a, NULL, "rra");
			i++;
		}
	}
	else
		while (i < b_down)
		{
			reverse_rotate_command(stack_b, NULL, "rrb");
			i++;
		}
}
void	do_op_a_up_b_down(t_stack *stack_a, t_stack *stack_b, t_cheapest *cheapest)
{
	int	i;
	int	b_down;
	b_down = stack_b->count - cheapest->b_index;
	i = 0;
	while (i < cheapest->a_index)
	{
		rotate_command(stack_a, NULL, "ra");
		i++;
	}
	i = 0;
	while (i < b_down)
	{
		reverse_rotate_command(stack_b, NULL, "rrb");
		i++;
	}
}
void	do_op_a_down_b_up(t_stack *stack_a, t_stack *stack_b, t_cheapest *cheapest)
{
	int	i;
	int	a_down;

	a_down = stack_a->count - cheapest->a_index;
	i = 0;
	while (i < a_down)
	{
		reverse_rotate_command(stack_a, NULL, "rra");
		i++;
	}
	i = 0;
	while (i < cheapest->b_index)
	{
		rotate_command(stack_b, NULL, "rb");
		i++;
	}
}

void	move_back(t_stack *stack_a, t_stack *stack_b)
{
	t_basic		basics;
	t_cheapest	cheapest;

	while (stack_b->head)
	{
		cheapest = calculate_cheapest_node(stack_a, stack_b, &basics);
		if (cheapest.cost == -1)
			break ;
		if (cheapest.move == 0)
			do_op_up(stack_a, stack_b, &cheapest);
		else if (cheapest.move == 1)
			do_op_a_up_b_down(stack_a, stack_b, &cheapest);
		else if (cheapest.move == 2)
			do_op_a_down_b_up(stack_a, stack_b, &cheapest);
		else if (cheapest.move == 3)
			do_op_down(stack_a, stack_b, &cheapest);
		push_command(stack_b, stack_a, "pa");
	}
}

bool is_sorted(t_stack *stack_a)
{
	t_node *node;
	node = stack_a->head;
	while(node->next)
	{
		if(node->next->value < node->value)
			return (false);
		node = node->next;
	}
	return (true);
}

/**
 * @brief
 * @param stack_a
 * @param stack_b
 *
 * 1. move two nodes if the stack is not sorted.
 * 2. move the cheapest node to stack_b to be in descending order.
 * 3. loop until there is only two left in stack a.
 * 4. move everything back to stack_a in ascending order.
 */

void	turk_sort(t_stack *stack_a, t_stack *stack_b)
{
	t_basic	basics;
	int		i;

	i = 0;
	if (!stack_a || stack_a->count <= 1 || is_sorted(stack_a))
		return ;
	move_to_b(stack_a, stack_b);
	move_back(stack_a, stack_b);
	find_smallest(stack_a, &basics);
	if (basics.a_index < stack_a->count - basics.a_index)
	{
		while (i++ < basics.a_index)
		{
			rotate_command(stack_a, NULL, "ra");
		}
	}
	else
	{
		while (i++ < stack_a->count - basics.a_index)
		{
			reverse_rotate_command(stack_a, NULL, "rra");
		}
	}
}
