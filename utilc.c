/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selbakya <selbakya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 21:49:10 by selbakya          #+#    #+#             */
/*   Updated: 2023/02/25 18:36:31 by selbakya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *str, int *length)
{
	if (!str)
	{
		*length += write(1, "(null)", 6);
		return ;
	}
	*length += write(1, str, ft_strlen(str));
}

void	ft_pointer(unsigned long long numeric, int *length)
{
	write(1, "0x", 2);
	ft_hex_print(numeric, 'x', length);
	*length += 2;
}

void	ft_number(int numeric, int *length)
{
	long	num;

	num = numeric;
	if (num < 0)
	{
		*length += ft_putchar('-');
		num = num * -1;
	}
	if (num > 9)
	{
		ft_number(num / 10, length);
		ft_number(num % 10, length);
	}
	else
		*length += ft_putchar(num + 48);
}

void	ft_unsigned(unsigned int num, int *length)
{
	if (num > 9)
	{
		ft_unsigned(num / 10, length);
		ft_unsigned(num % 10, length);
	}
	else
		*length += ft_putchar(num + 48);
}

void	ft_hex_print(unsigned long long numeric, char f_symb, int *length)
{
	char	*base;
	char	hex_out[13];
	int		ind;

	ind = 0;
	if (f_symb == 'x')
		base = "0123456789abcdef";
	else if (f_symb == 'X')
		base = "0123456789ABCDEF";
	if (numeric == 0)
		*length += ft_putchar('0');
	while (numeric != 0)
	{
		hex_out[ind] = base[numeric % 16];
		numeric = numeric / 16;
		++ind;
	}
	while (ind--)
		*length += ft_putchar(hex_out[ind]);
}
