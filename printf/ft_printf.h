/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layala-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 12:59:08 by layala-s          #+#    #+#             */
/*   Updated: 2024/04/15 12:59:10 by layala-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H 
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putpoint(void *pointer);
int	ft_putnbr(int nb);
int	ft_putuns(unsigned int nb);
int	ft_puthex(unsigned int nb, char c);
int	ft_printf(char const *s, ...);

#endif