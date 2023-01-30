/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selbakya <selbakya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 21:23:28 by selbakya          #+#    #+#             */
/*   Updated: 2023/01/26 22:14:10 by selbakya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int symb)
{
	size_t	len;

	len = ft_strlen(s);
	while (len != (size_t) -1)
	{
		if (s[len] == (unsigned char)symb)
			return ((char *)&s[len]);
		len--;
	}
	return (NULL);
}
