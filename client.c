/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layala-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:50:42 by layala-s          #+#    #+#             */
/*   Updated: 2024/08/27 14:50:45 by layala-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	g_conf_signal;

static void	check_conf(void)
{
	while (g_conf_signal != 1)
		usleep(100);
}

static void	init(pid_t pid)
{
	kill(pid, SIGUSR1);
	usleep(100);
}

static void	send_str(pid_t pid, char *str)
{
	int	bit;
	int	i;

	init(pid);
	i = 0;
	while (str[i])
	{
		bit = 8;
		while (bit--)
		{
			g_conf_signal = 0;
			if (str[i] & (1 << bit))
			{
				if (kill(pid, SIGUSR1) == -1)
					exit(EXIT_FAILURE);
			}
			else
			{
				if (kill(pid, SIGUSR2) == -1)
					exit(EXIT_FAILURE);
			}
			check_conf();
		}
		i++;
	}
}

static void	conf_handler(int signal)
{
	if (signal == SIGUSR1)
		g_conf_signal = 1;
	else if (signal == SIGUSR2)
		exit(EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
	pid_t				pid;
	struct sigaction	handler;

	if (ac != 3)
	{
		ft_printf("INSTRUCTIONS 👉./client [PID] [MESSAGE]");
		return (1);
	}
	handler.sa_handler = conf_handler;
	handler.sa_flags = 0;
	sigemptyset(&handler.sa_mask);
	sigaction(SIGUSR1, &handler, NULL);
	sigaction(SIGUSR2, &handler, NULL);
	pid = ft_atoi(av[1]);
	send_str(pid, av[2]);
	ft_printf("Message sent succesfully!\n");
	return (0);
}
