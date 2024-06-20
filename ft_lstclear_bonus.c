/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:37:21 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/06/20 19:54:37 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*curr;
	t_list	*prev;

	curr = *lst;
	while (curr->next)
	{
		prev = curr;
		curr = curr->next;
		del(prev->content);
		free(prev);
	}
	del(curr);
	free(curr);
	*lst = NULL;
}