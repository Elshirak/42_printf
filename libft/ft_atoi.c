/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selbakya <selbakya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:32:22 by selbakya          #+#    #+#             */
/*   Updated: 2023/01/28 15:01:17 by selbakya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	size_t	result;
	int		sign;

	result = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		++str;
	if (*str == '-')
		sign *= -1;
	if (*str == '+' || *str == '-')
		++str;
	while ((*str >= '0' && *str <= '9') && *str != '\0')
	{
		result = result * 10 + *str - '0';
		++str;
	}
	return (sign * result);
}
