/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_commands.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 23:38:49 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/12/24 23:40:31 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_COMMANDS_H
# define STACK_COMMANDS_H

#include "push_swap.h"

void	swap_command(t_stack *first, t_stack *second, char *command);
void	push_command(t_stack *from, t_stack *to, char *command);
void	rotate_command(t_stack *first, t_stack *second, char *command);
void	reverse_rotate_command(t_stack *first, t_stack *second, char *command);

#endif