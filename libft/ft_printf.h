/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fliraud- <fliraud-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 12:47:43 by fliraud-          #+#    #+#             */
/*   Updated: 2026/03/03 13:50:41 by fliraud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>

void	ft_putchar(int c, int *count);
void	ft_putstr(char *s, int *count);
void	ft_putnbr(int n, int *count);
void	ft_putnbr_base(int num, const char *base, int *count);
void	ft_putnbr_base_ul(unsigned long n, const char *base, int *count);
void	ft_putnbu(unsigned int n, const char *base, int *count);
void	ft_putmem(void *s, int *count);
void	ft_putdec(float n, int *count);
void	ft_read(char c, va_list va, int *count);
int		ft_printf(char const *format, ...);
int		ft_intlen(int n);
int		ft_istrlen(const char *s);

#endif