/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset32.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 16:47:57 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/08/06 11:11:56 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include <stdint.h>

void	*ft_memset32(void *ptr, int c, size_t n)
{
	size_t		i;
	uint32_t	*my_ptr;

	if (!ptr)
		return (NULL);
	i = 0;
	my_ptr = ptr;
	while (i < n)
	{
		my_ptr[i++] = c;
	}
	return (ptr);
}
