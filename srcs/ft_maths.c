/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maths.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 00:29:55 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/01/27 20:11:32 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Returns the minimum of two integers
 *
 * @param a First integer
 * @param b Second integer
 * @return int The smaller of the two values
 */
int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

/**
 * @brief Returns the maximum of two integers
 *
 * @param a First integer
 * @param b Second integer
 * @return int The larger of the two values
 */
int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}
bool	check_str(const char *str)
{
	while (*str)
	{
		if (!(*str == ' ' || *str == '\n' || *str == '\t' || *str == '\v'
				|| *str == '\f' || *str == '\r' || *str == '+' || *str == '-'
				|| ft_isdigit(*str)))
			return (false);
		str++;
	}
	return (true);
}
int	ft_isdigit(int i)
{
	return ((unsigned)i - '0' < 10);
}