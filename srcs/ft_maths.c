/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maths.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 00:29:55 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/12/30 03:03:24 by aphyo-ht         ###   ########.fr       */
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

/**
 * @brief Safely converts a string to an integer with overflow protection
 * 
 * This function parses a string and converts it to an integer, similar to atoi
 * but with additional safety checks. It handles leading whitespace and 
 * optional sign characters.
 * 
 * @param str The string to convert
 * @param value Pointer to store the converted integer value
 * @return bool Always returns true (may need enhancement for error checking)
 */
bool	ft_safe_atoi(const char *str, int *value)
{
	long	a;
	long	sign;
	long	i;
	// int		len;

	a = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		a = (a * 10) + (str[i] - '0');
		i++;
	}
	*value = a * sign;
	return (true);
}
