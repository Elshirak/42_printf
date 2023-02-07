/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selbakya <selbakya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:03:11 by selbakya          #+#    #+#             */
/*   Updated: 2023/02/07 17:26:02 by selbakya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *, ...);
size_t	ft_putnbr(int numeric);
size_t	ft_putnbr_base(unsigned int numeric, int base, char f_symb);
size_t	ft_print_ptr(unsigned long long numeric);

#endif