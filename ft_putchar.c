/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachtata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 15:40:30 by yachtata          #+#    #+#             */
/*   Updated: 2023/11/15 12:33:06 by yachtata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

char	ft_putchar(unsigned char c, int *len)
{
	int	result;

	result = write(1, &c, 1);
	if (result == -1)
		return (-1);
	(*len)++;
	return (1);
}
