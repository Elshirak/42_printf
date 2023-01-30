/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selbakya <selbakya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:52:06 by selbakya          #+#    #+#             */
/*   Updated: 2023/01/28 15:14:13 by selbakya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	unsigned char	*dest_1;
	unsigned char	*src_1;

	dest_1 = (unsigned char *)dest;
	src_1 = (unsigned char *)src;
	if (!len || dest == src)
		return (dest);
	while (len--)
	{
		*dest_1++ = *src_1++;
	}
	return (dest);
}
