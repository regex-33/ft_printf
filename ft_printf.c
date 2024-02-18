/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachtata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:58:58 by yachtata          #+#    #+#             */
/*   Updated: 2023/12/03 13:39:32 by yachtata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	checker_flags(char c)
{
	char	*str;
	int		i;

	i = 0;
	str = "idupscxX";
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	printf_helper(va_list list, char c, int *len)
{
	int	result;

	result = 0;
	if (c == 'd' || c == 'i')
		result = ft_putnbr(va_arg(list, int), len);
	else if (c == 'c')
		result = ft_putchar(va_arg(list, int), len);
	else if (c == 's')
		result = ft_putstr(va_arg(list, char *), len);
	else if (c == 'p')
		result = ft_print_add(va_arg(list, char *), len);
	else if (c == 'u')
		result = ft_putnbr_unsigned(va_arg(list, int), len);
	else if (c == 'X')
		result = int_to_base(va_arg(list, unsigned int),
				UPPER_HEX, len);
	else if (c == 'x')
		result = int_to_base(va_arg(list, unsigned int),
				LOWER_HEX, len);
	return (result);
}

int	handle_format_specifier(const char *format, int *i, int *len, va_list list)
{
	int	result;

	result = 1;
	result = printf_helper(list, format[*i + 1], len);
	(*i)++;
	return (result);
}

int	handle_percent(const char *format, int *i, int *len)
{
	if (format[*i] == '%' && format[*i + 1] == '%')
	{
		(*i)++;
		return (ft_putchar(format[*i], len));
	}
	else
		return (ft_putchar(format[*i], len));
}

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	list;
	int		len;
	int		result;

	i = 0;
	len = 0;
	va_start(list, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%' && checker_flags(format[i + 1]))
			result = handle_format_specifier(format, &i, &len, list);
		else
			result = handle_percent(format, &i, &len);
		if (result == -1 || result == 0)
		{
			va_end(list);
			return (-1);
		}
		i++;
	}
	va_end(list);
	return (len);
}
