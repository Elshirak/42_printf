/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selbakya <selbakya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 01:41:04 by selbakya          #+#    #+#             */
/*   Updated: 2023/01/26 21:48:22 by selbakya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *array1, const void *array2, size_t len)
{
	unsigned char	*arr1;
	unsigned char	*arr2;
	size_t			iterable;

	iterable = 0;
	arr1 = (unsigned char *)array1;
	arr2 = (unsigned char *)array2;
	if (!len)
		return (0);
	while (++iterable < len && *arr1 == *arr2)
	{
		++arr1;
		++arr2;
	}
	return ((int)(*arr1 - *arr2));
}
