/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 17:35:51 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/12/04 18:02:28 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

int	check_doubles(char **argv)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = count_arg(argv);
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if(ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_nbr(char *argv)
{
	int	i;

	i = 0;
	if (argv[i] == '-')
		i++;
	while (argv[i])
	{
		if (!ft_isdigit(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

void	check_input(int argc, char **argv)
{
	int i;
	long tmp;
	char **tmp_arr;

	i = 0;
	if (argc == 2)
		tmp_arr = ft_split(argv[1], ' ');
	else
		tmp_arr = argv + 1;
	while (tmp_arr[i])
	{
		tmp = ft_atoi(tmp_arr[i]);
		if (tmp < INT_MIN || tmp > INT_MAX)
			error_msg("ERROR");
		if (check_doubles(tmp_arr))
			error_msg("ERROR");
		if (!check_nbr(tmp_arr[i]))
			error_msg("ERROR");
		i++;
	}
	/*
		TODO: Free tmp_arr;
	*/
}