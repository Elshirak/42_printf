/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selbakya <selbakya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:30:21 by selbakya          #+#    #+#             */
/*   Updated: 2023/01/26 21:20:54 by selbakya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t number_of_elements, size_t size_of_element)
{
	void	*ptr;

	if (number_of_elements * size_of_element > __INT_MAX__ \
			|| number_of_elements == SIZE_MAX || size_of_element == SIZE_MAX)
		return (NULL);
	ptr = malloc(number_of_elements * size_of_element);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, number_of_elements * size_of_element);
	return (ptr);
}
