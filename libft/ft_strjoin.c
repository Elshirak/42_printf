/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selbakya <selbakya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:08:20 by selbakya          #+#    #+#             */
/*   Updated: 2023/01/26 22:02:34 by selbakya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_result_string;
	char	*ptr_result;
	char	*result;

	if (!s1 || !s2)
		return (NULL);
	len_result_string = ft_strlen(s1) + ft_strlen(s2) + 1;
	ptr_result = (char *) malloc(len_result_string * sizeof(char));
	if (!ptr_result)
		return (NULL);
	result = ptr_result;
	while (*s1 != '\0')
		*ptr_result++ = *s1++;
	while (*s2 != '\0')
		*ptr_result++ = *s2++;
	*ptr_result = '\0';
	return (result);
}
