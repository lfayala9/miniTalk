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

void	sig_handler(int signal, siginfo_t *info, void *context)
{
	static int	bit_count = 0;
	static char	character = 0;

	(void)context;
	if (signal == SIGUSR1 && bit_count == 0 && character == 0)
	{
		write(1, "\n", 1);
		return;
	}
	if (signal == SIGUSR1)
		character |= (1 << (7 - bit_count));
	bit_count++;
	if (bit_count == 8)
	{
		write(1, &character, 1);
		bit_count = 0;
		character = 0;
	}
	if (kill(info->si_pid, SIGUSR1) == -1)
		exit(EXIT_FAILURE);
}

int	main(void)
{
	struct sigaction	action;
	pid_t				pid;

	pid = getpid();
	action.sa_sigaction = sig_handler;
	action.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	ft_printf("The server PID is:🥲	 --> [%d]\n", pid);
	while (1)
		pause();
	return (0);
}
