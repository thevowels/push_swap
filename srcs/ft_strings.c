/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strings.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 04:00:40 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/12/30 05:02:34 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

/**
 * @brief Counts the number of words in a string
 *
 * Counts words separated by whitespace characters (space, newline, tab,
 * vertical tab, form feed, carriage return). A word is defined as a 
 * sequence of non-whitespace characters.
 *
 * @param str The string to count words in
 * @return int The number of words found, or 0 if str is NULL
 */
int	count_words(char *str)
{
	int word_flag;
	int word_count;

	word_count = 0;
	word_flag = 0;
	if (!str)
		return (0);
	while (*str)
	{
		if (word_flag && (*str == ' ' || *str == '\n' || *str == '\t'
				|| *str == '\v' || *str == '\f' || *str == '\r'))
			word_flag = 0;
		if (!word_flag && !(*str == ' ' || *str == '\n' || *str == '\t'
				|| *str == '\v' || *str == '\f' || *str == '\r'))
		{
			word_count += 1;
			word_flag = 1;
		}
		str++;
	}
	return word_count;
}

/**
 * @brief Finds the pointer to the next word in a string
 *
 * Advances past the current word and any following whitespace to find
 * the beginning of the next word. Whitespace characters include space,
 * newline, tab, vertical tab, form feed, and carriage return.
 *
 * @param str Pointer to the current position in the string
 * @return char* Pointer to the start of the next word,
 *               or NULL if no more words exist or str is NULL
 */
char *next_word(char *str)
{
	if(!str)
		return (NULL);
	while (*str && (*str == ' ' || *str == '\n' || *str == '\t'
		|| *str == '\v' || *str == '\f' || *str == '\r'))
		str++;
	if(!*str)
		return (NULL);
	while (*str && !(*str == ' ' || *str == '\n' || *str == '\t'
		|| *str == '\v' || *str == '\f' || *str == '\r'))
		str++;
	if(!*str)
		return (NULL);
	while (*str && (*str == ' ' || *str == '\n' || *str == '\t'
		|| *str == '\v' || *str == '\f' || *str == '\r'))
		str++;
	if(!*str)
		return (NULL);
	return (str);
}
