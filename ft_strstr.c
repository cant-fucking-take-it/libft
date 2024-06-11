/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 18:32:46 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/06/11 14:50:18 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

char	*ft_strstr(const char *big, const char *little, size_t len)
{
	size_t	found_index;
	char	*my_big;
	char	*my_little;

	my_big = (char *)big;
	my_little = (char *)little;
	found_index = 0;
	if (*my_big == *my_little && *my_big == '\0')
	{
		return (my_big);
	}
	while (*my_big != '\0' && len-- > 0)
	{
		while (my_big[found_index] == my_little[found_index]
			&& my_little[found_index] != '\0')
		{
			found_index++;
		}
		if (my_little[found_index] == '\0')
		{
			return (my_big);
		}
		found_index = 0;
		my_big++;
	}
	return (0);
}
