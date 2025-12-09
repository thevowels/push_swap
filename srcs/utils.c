/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 19:20:09 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/12/10 00:19:53 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	error_message(char *str)
{
	write(2, str, ft_strlen(str));
	exit(EXIT_FAILURE);
}

int	get_matrix_size(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
		i++;
	return (i + 1);
}

int	generate_chunk(int size)
{
	int	chunk;

	chunk = 1;
	if (size < 50)
		chunk = 3 + (size - 6) / 7;
	else if (size >= 50 && size < 100)
		chunk = 10 + (size - 50) / 8;
	else if (size >= 100 && size < 350)
		chunk = 18 + (size - 100) / 9;
	else if (size >= 350 && size <= 500)
		chunk = 27 + (size - 350) / 15;
	else if (size > 500)
		chunk = 37 + (size - 500) / 20;
	return (chunk);
}
