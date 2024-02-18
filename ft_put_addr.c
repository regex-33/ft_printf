/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_addr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachtata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:00:01 by yachtata          #+#    #+#             */
/*   Updated: 2023/11/18 11:37:23 by yachtata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	hex_helper(char *str, int *len, int boool)
{
	int	i;

	i = 0;
	if (boool)
	{
		while (str[i] == '0' && str[i] != '\0')
			i++;
	}
	if (ft_putstr("0x", len) == -1)
		return (-1);
	if (ft_putstr(&str[i], len) == -1)
		return (-1);
	return (1);
}

int	int_len(uintmax_t nbr)
{
	int	i;

	i = 0;
	while (nbr >= 10)
	{
		i++;
		nbr /= 10;
	}
	i++;
	return (i);
}

static int	ft_hex_upperr(uintmax_t nbr, int *len)
{
	uintmax_t	temp;
	int			i;
	char		*saver;
	int			boool;

	boool = 1;
	if (!nbr)
		boool = 0;
	temp = nbr;
	i = int_len(temp);
	saver = (char *)malloc(sizeof(char) * i + 1);
	if (!saver)
		return (0);
	saver[i] = '\0';
	while (i--)
	{
		saver[i] = LOWER_HEX[nbr % 16];
		nbr /= 16;
	}
	i = hex_helper(saver, len, boool);
	free(saver);
	return (i);
}

int	ft_print_add(void *str, int *len)
{
	int	result;

	result = ft_hex_upperr((uintmax_t)str, len);
	if (!result || result == -1)
		return (-1);
	return (1);
}
