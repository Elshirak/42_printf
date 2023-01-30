/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selbakya <selbakya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:36:04 by selbakya          #+#    #+#             */
/*   Updated: 2023/01/23 20:44:03 by selbakya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char		*to;
	const unsigned char	*from;
	size_t				i;

	to = (unsigned char *)dest;
	from = (const unsigned char *)src;
	if (!len || from == to)
		return (dest);
	i = 0;
	while (i < len)
	{
		if (to > from)
			to[len - i - 1] = from[len - i - 1];
		else
			to[i] = from[i];
		i++;
	}
	return (dest);
}
