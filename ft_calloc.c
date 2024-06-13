/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:48:18 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/06/13 18:50:22 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total;

	total = nmemb * size;
	if (total / nmemb == size)
		return (malloc(nmemb * size));
	return (NULL);
}