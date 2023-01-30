/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selbakya <selbakya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:58:28 by selbakya          #+#    #+#             */
/*   Updated: 2023/01/27 20:32:17 by selbakya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	leng_dest;
	size_t	leng_src;
	size_t	ls;
	size_t	j;

	if ((!dest || !src) && !size)
		return (0);
	leng_dest = ft_strlen(dest);
	leng_src = ft_strlen(src);
	if (size == 0 || size <= leng_dest)
		return (leng_src + size);
	ls = leng_dest;
	j = 0;
	while (j < size - leng_dest - 1 && src[j] != '\0')
	{
		dest[ls] = src[j];
		++j;
		++ls;
	}
	dest[ls] = '\0';
	return (leng_dest + leng_src);
}
