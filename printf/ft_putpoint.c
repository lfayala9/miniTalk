/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpoint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layala-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 12:54:58 by layala-s          #+#    #+#             */
/*   Updated: 2024/04/18 12:55:00 by layala-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_puthex_big(unsigned long long int nb, char *base)
{
	int				len;

	len = 0;
	if (nb >= 16)
		len += ft_puthex_big(nb / 16, base);
	len += ft_putchar(base[nb % 16]);
	return (len);
}

int	ft_putpoint(void *pointer)
{
	int						len;
	unsigned long long int	nb;
	char					*base;

	len = 0;
	nb = (unsigned long long int)pointer;
	base = "0123456789abcdef";
	len = ft_putstr("0x");
	if (nb >= 16)
		len += ft_puthex_big(nb / 16, base);
	len += ft_putchar(base[nb % 16]);
	return (len);
}
