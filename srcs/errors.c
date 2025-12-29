/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 18:02:08 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/12/30 03:35:00 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

/**
 * @brief Prints "Error" to stderr and exits the program with failure status
 *
 * This function is called when an error condition is detected in the program.
 * It writes "Error\n" to file descriptor 2 (stderr) and terminates the program
 * with EXIT_FAILURE status code.
 */
void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
