/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachtata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:40:10 by yachtata          #+#    #+#             */
/*   Updated: 2023/11/16 12:44:52 by yachtata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

int	int_to_base(unsigned long number, const char *base, int *len)
{
	char	converted[33];
	int		index;
	int		i;
	long	len_base;
	char	*result;

	i = 0;
	index = 0;
	len_base = ft_strlen(base);
	while ((long)number >= len_base)
	{
		converted[index++] = base[number % len_base];
		number /= len_base;
	}
	converted[index] = base[number];
	result = (char *)malloc((index + 2) * sizeof(char));
	if (!result)
		return (0);
	while (index >= 0)
		result[i++] = converted[index--];
	result[i] = '\0';
	len_base = ft_putstr(result, len);
	free(result);
	return (len_base);
}
