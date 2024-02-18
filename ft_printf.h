/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachtata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:59:47 by yachtata          #+#    #+#             */
/*   Updated: 2023/11/16 12:46:51 by yachtata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define LOWER_HEX "0123456789abcdef"
# define UPPER_HEX "0123456789ABCDEF"

int		int_to_base(unsigned long number, const char *base, int *len);
int		ft_printf(const char *format, ...);
int		ft_putstr(char *str, int *len);
int		ft_putnbr(long long nb, int *len);
char	ft_putchar(unsigned char c, int *len);
int		ft_print_add(void *str, int *len);
int		ft_putnbr_unsigned(unsigned int nb, int *len);

#endif
