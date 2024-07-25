/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layala-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:11:53 by layala-s          #+#    #+#             */
/*   Updated: 2024/04/15 13:11:54 by layala-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	param_type(char c, va_list param)
{
	if (c == 'c')
		return (ft_putchar(va_arg(param, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(param, char *)));
	else if (c == 'u')
		return (ft_putuns(va_arg(param, unsigned int)));
	else if (c == 'p')
		return (ft_putpoint(va_arg(param, void *)));
	else if (c == '%')
		return (ft_putchar('%'));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(param, int)));
	else if (c == 'x' || c == 'X')
		return (ft_puthex(va_arg(param, unsigned int), c));
	return (-1);
}

int	ft_printf(char const *s, ...)
{
	va_list	params;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(params, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			len += param_type(s[i + 1], params);
			i++;
		}
		else
			len += ft_putchar(s[i]);
		i++;
	}
	va_end(params);
	return (len);
}
