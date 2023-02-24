/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selbakya <selbakya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 21:49:10 by selbakya          #+#    #+#             */
/*   Updated: 2023/02/24 16:12:40 by selbakya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pointer(unsigned long long numeric, int *length)
{
	char	*base;
	char	p1[25];
	int		i;

	*length += ft_putchar('0');
	*length += ft_putchar('x');
	i = 0;
	base = "0123456789abcdef";
	if (numeric == 0)
		*length += ft_putchar('0');
	while (numeric != 0)
	{
		p1[i] = base[numeric % 16];
		numeric = numeric / 16;
		++i;
	}
	while (i--)
		*length += ft_putchar(p1[i]);
}

void	ft_number(int num, int *len)
{
	long	n;

	n = num;
	if (n < 0)
	{
		*len += ft_putchar('-');
		n = n * -1;
	}
	if (n > 9)
	{
		ft_number(n / 10, len);
		ft_number(n % 10, len);
	}
	else
		*len += ft_putchar(n + 48);
}

void	ft_unsigned(unsigned int num, int *len)
{
	if (num > 9)
	{
		ft_unsigned(num / 10, len);
		ft_unsigned(num % 10, len);
	}
	else
		*len += ft_putchar(num + 48);
}

void	ft_putnbr_fd(int num, int fd)
{
	long	number;

	number = num;
	if (number < 0)
	{
		ft_putchar1('-', fd);
		number = -number;
	}
	if (number > 9)
	{
		ft_putnbr_fd(number / 10, fd);
		ft_putnbr_fd(number % 10, fd);
	}
	else
		ft_putchar1(number + 48, fd);
}

void	ft_hexadec(unsigned int numeric, char f_symb, int *length)
{
	char	*base;
	char	hex1[13];
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
		hex1[ind] = base[numeric % 16];
		numeric = numeric / 16;
		++ind;
	}
	while (ind--)
		*length += ft_putchar(hex1[ind]);
}
