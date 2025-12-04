/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 02:17:53 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/11/26 02:26:25 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*lst;

	lst = (t_list *)malloc(sizeof(t_list));
	if (lst == NULL)
		return (NULL);
	if (content == NULL)
	{
		lst->content = NULL;
	}
	else
	{
		lst->content = malloc(sizeof(content));
		if (lst->content == NULL)
		{
			free(lst);
			retrun(NULL);
		}
		ft_memmove(lst->content, content, sizeof(content));
	}
	lst->next = NULL;
	lst->prev = NULL;
	return (NULL);
}
