/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selbakya <selbakya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 02:01:13 by selbakya          #+#    #+#             */
/*   Updated: 2023/01/27 15:24:28 by selbakya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	str_length;
	unsigned int	itera;

	if (!*needle)
		return ((char *)haystack);
	if (!len)
		return (0);
	str_length = 0;
	while (haystack[str_length] != '\0' && (size_t)str_length < len)
	{
		if (haystack[str_length] == needle[0])
		{
			itera = 1;
			while (needle[itera] != '\0' && haystack[str_length + itera] == \
			needle[itera] && (size_t)(str_length + itera) < len)
				++itera;
			if (needle[itera] == '\0')
				return ((char *)&haystack[str_length]);
		}
		++str_length;
	}
	return (NULL);
}
