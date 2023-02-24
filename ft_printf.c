/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selbakya <selbakya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:43:22 by selbakya          #+#    #+#             */
/*   Updated: 2023/02/24 16:12:46 by selbakya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar1(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr(char *str, int *length)
{
	if (!str)
	{
		*length += write(1, "(null)", 6);
		return ;
	}
	*length += write(1, str, ft_strlen(str));
}

int	ft_check(const char f_symb, va_list arg_list)
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
	else if (f_symb == 'x')
		ft_hexadec(va_arg(arg_list, unsigned int), 'x', &length);
	else if (f_symb == 'X')
		ft_hexadec(va_arg(arg_list, unsigned int), 'X', &length);
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
			len += ft_check(str[index], arg_list);
		}
		else
			len += ft_putchar(str[index]);
		++index;
	}
	va_end(arg_list);
	return (len);
}
