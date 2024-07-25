/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuns.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layala-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:14:42 by layala-s          #+#    #+#             */
/*   Updated: 2024/04/18 13:14:47 by layala-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putuns(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb >= 10)
	{
		len += ft_putuns(nb / 10);
		len += ft_putuns(nb % 10);
	}
	else
		len += ft_putchar(nb + 48);
	return (len);
}
