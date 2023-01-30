/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selbakya <selbakya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 20:50:27 by selbakya          #+#    #+#             */
/*   Updated: 2023/01/26 21:58:05 by selbakya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *pointer_str, int symbol)
{
	unsigned char	c;

	c = (unsigned char)symbol;
	if (symbol == 0)
		return ((char *)(pointer_str + ft_strlen(pointer_str)));
	while (*pointer_str != 0)
	{
		if (*pointer_str == c)
			return ((char *)pointer_str);
		pointer_str++;
	}
	return (NULL);
}
