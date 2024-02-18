/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putUnsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachtata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:42:01 by yachtata          #+#    #+#             */
/*   Updated: 2023/12/03 13:40:02 by yachtata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_unsigned(unsigned int nb, int *len)
{
	if (nb > 9)
		ft_putnbr_unsigned(nb / 10, len);
	if (ft_putchar(nb % 10 + '0', len) == -1)
		return (-1);
	return (1);
}
