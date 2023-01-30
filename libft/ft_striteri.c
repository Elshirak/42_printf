/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selbakya <selbakya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 12:33:58 by selbakya          #+#    #+#             */
/*   Updated: 2023/01/26 22:00:53 by selbakya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	iterator;

	if (!s || !f)
		return ;
	iterator = 0;
	while (s[iterator])
	{
		f(iterator, s + iterator);
		iterator++;
	}
	return ;
}
