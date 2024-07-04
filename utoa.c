/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:11:38 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/07/04 10:54:04 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	get_str_size(unsigned int n)
{
	size_t	len;

	len = 2;
	while (n >= 10)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(unsigned int n)
{
	char			*out;
	unsigned int	abs;
	size_t			len;

	len = get_str_size(n);
	out = malloc(len);
	if (!out)
		return (NULL);
	out[--len] = '\0';
	while (n >= 10)
	{
		out[--len] = '0' + (n % 10);
		n /= 10;
	}
	out[--len] = '0' + (n % 10);
	return (out);
}
