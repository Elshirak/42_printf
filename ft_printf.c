/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selbakya <selbakya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:43:22 by selbakya          #+#    #+#             */
/*   Updated: 2023/02/15 22:03:32 by selbakya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

size_t	ft_get_format(char f_symb, va_list arg_list)
{
	size_t	printed_characters;

	printed_characters = 0;
	if (f_symb == 'c')
		printed_characters += write(1, va_arg(arg_list, int), 1);
	else if (f_symb == 's')
		printed_characters += ft_putstr_fd(va_arg(arg_list, char *), 1);
	else if (f_symb == 'p')
		printed_characters += ft_print_ptr(va_arg(arg_list, unsigned long long)); 
	else if (f_symb == 'd' || f_symb == 'i')
		printed_characters += ft_putnbr(va_arg(arg_list, int));
	else if (f_symb == 'u')
		printed_characters += ft_putnbr_u(va_arg(arg_list, unsigned int));
	else if (f_symb == 'x' || f_symb == 'X')
		printed_characters += ft_putnbr_hex(va_arg(arg_list, unsigned int), f_symb);
	else if (f_symb == '%')
		printed_characters += write(1, &"%", 1);
	return (printed_characters);
}

int	ft_printf(const char *str, ...)
{
	size_t	length_str;
	va_list	arg_list;

	if (!str)
		return (0);
	length_str = 0;
	va_start(arg_list, str);
	while (str[length_str])
	{
		if (str[length_str] == '%')
			length_str += ft_get_format(str[length_str + 1], arg_list);
		else
			length_str += write(1, &str[length_str], 1);
		++length_str;
	}
	va_end(arg_list);
	return (length_str);
}