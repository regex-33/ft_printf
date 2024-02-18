/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachtata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 14:09:14 by yachtata          #+#    #+#             */
/*   Updated: 2023/11/18 11:33:53 by yachtata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_putstr(char *str, int *len)
{
	int	i;
	int	write_result;

	i = 0;
	if (!str)
	{
		if (ft_putstr("(null)", len) == -1)
			return (-1);
		return (1);
	}
	while (str[i] != '\0')
	{
		write_result = write(1, &str[i], 1);
		if (write_result == -1)
			return (-1);
		++i;
		(*len)++;
	}
	return (1);
}
