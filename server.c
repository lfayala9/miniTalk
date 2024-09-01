/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layala-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 17:25:39 by layala-s          #+#    #+#             */
/*   Updated: 2024/07/25 17:25:41 by layala-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_handler(int signal)
{
	if (signal == SIGUSR1)
		ft_printf("1\n");
	if (signal == SIGUSR2)
		ft_printf("0\n");
}

int	main(void)
{
	struct sigaction	action;
	pid_t				pid;

	pid = getpid();
	action.sa_handler = sig_handler;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	ft_printf("The server PID is:🥲	 --> [%d]\n", pid);
	while (1)
		pause();
	return (0);
}
