/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selbakya <selbakya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 21:29:19 by selbakya          #+#    #+#             */
/*   Updated: 2023/02/07 19:50:12 by selbakya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putnbr_fd(int n)
{
	size_t	i;
	char	*ptr_str;

	i = 0;
	ptr_str = ft_itoa(n);
	i = ft_strlen(ptr_str);
	ft_putstr_fd(ptr_str, 1);
	free(ptr_str);
	return (i);
}
