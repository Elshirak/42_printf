/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selbakya <selbakya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:03:11 by selbakya          #+#    #+#             */
/*   Updated: 2023/02/24 16:14:55 by selbakya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
size_t	ft_strlen(const char *str);
void	ft_number(int num, int *len);
void	ft_unsigned(unsigned int num, int *len);
void	ft_hexadec(unsigned int hex, char c, int *len);
int		ft_putchar(char c);
void	ft_pointer(unsigned long long p, int *len);
void	ft_putchar1(char c, int fd);

#endif
