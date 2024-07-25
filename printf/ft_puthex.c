/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layala-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:55:28 by layala-s          #+#    #+#             */
/*   Updated: 2024/04/17 14:55:31 by layala-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int nb, char c)
{
	int				len;
	char			*base;

	len = 0;
	base = NULL;
	if (c == 'x')
		base = "0123456789abcdef";
	else if (c == 'X')
		base = "0123456789ABCDEF";
	if (nb >= 16)
		len += ft_puthex(nb / 16, c);
	len += ft_putchar(base[nb % 16]);
	return (len);
}
