/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selbakya <selbakya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:03:11 by selbakya          #+#    #+#             */
/*   Updated: 2023/02/25 18:43:32 by selbakya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
int		ft_putchar(char c);
void	ft_number(int num, int *len);
void	ft_unsigned(unsigned int num, int *len);
void	ft_hex_print(unsigned long long hex, char c, int *len);
void	ft_pointer(unsigned long long p, int *len);
void	ft_putstr(char *str, int *length);
size_t	ft_strlen(const char *str);

#endif
