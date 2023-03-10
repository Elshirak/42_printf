/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selbakya <selbakya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:43:22 by selbakya          #+#    #+#             */
/*   Updated: 2023/02/25 18:24:00 by selbakya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_read_flag(const char f_symb, va_list arg_list)
{
	int	length;

	length = 0;
	if (f_symb == 'c')
		length += ft_putchar(va_arg(arg_list, int));
	else if (f_symb == 's')
		ft_putstr(va_arg(arg_list, char *), &length);
	else if (f_symb == '%')
		length += ft_putchar('%');
	else if (f_symb == 'd' || f_symb == 'i')
		ft_number(va_arg(arg_list, int), &length);
	else if (f_symb == 'u')
		ft_unsigned(va_arg(arg_list, unsigned int), &length);
	else if (f_symb == 'p')
		ft_pointer(va_arg(arg_list, unsigned long long), &length);
	else if (f_symb == 'x' || f_symb == 'X')
		ft_hex_print(va_arg(arg_list, unsigned int), f_symb, &length);
	return (length);
}

int	ft_printf(const char *str, ...)
{
	int		len;
	size_t	index;
	va_list	arg_list;

	index = 0;
	len = 0;
	va_start(arg_list, str);
	while (str[index] && index < ft_strlen(str))
	{
		if (str[index] == '%')
		{
			++index;
			len += ft_read_flag(str[index], arg_list);
		}
		else
			len += ft_putchar(str[index]);
		++index;
	}
	va_end(arg_list);
	return (len);
}
