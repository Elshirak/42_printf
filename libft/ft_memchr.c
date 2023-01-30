/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selbakya <selbakya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 22:40:42 by selbakya          #+#    #+#             */
/*   Updated: 2023/01/26 21:46:15 by selbakya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *smth, int symbol, size_t len)
{
	unsigned char	*ptr;
	size_t			iter;

	iter = 0;
	ptr = (unsigned char *)smth;
	while (iter != len && ptr[iter] != (unsigned char)symbol)
		iter++;
	if (iter == len)
		return (NULL);
	return ((void *)(ptr + iter));
}
