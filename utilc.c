/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selbakya <selbakya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 21:49:10 by selbakya          #+#    #+#             */
/*   Updated: 2023/02/15 22:10:09 by selbakya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putnbr_hex(unsigned int numeric, char f_symb)
{
	char	*base;
	size_t	printed;

	if (f_symb == "x")
		base = "0123456789abcdef";
	else if (f_symb == "X")
		base = "0123456789ABCDEF";
	printed = 0;
	if (numeric > 16)
		ft_putnbr_base(numeric / 16, f_symb);
	++printed;
	ft_putchar_fd(base[numeric % 16], 1);
	return (printed);
}

size_t	ft_print_ptr(unsigned long long numeric)
{
	size_t	count;

	count = 0;
	count += write(1, "0x", 2);
	count += ft_putnbr_hex(numeric, 'x');
	return (count);
}