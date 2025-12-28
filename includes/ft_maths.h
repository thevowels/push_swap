/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maths.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 00:30:26 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/12/29 04:33:01 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATHS_H
# define FT_MATHS_H
# include <stdbool.h>

int		ft_min(int a, int b);
int		ft_max(int a, int b);
bool	ft_safe_atoi(const char *str, int *value);
#endif