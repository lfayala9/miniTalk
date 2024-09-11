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

volatile sig_atomic_t conf_signal;

static void	check_conf(void)
{
	while(conf_signal != 1)
		usleep(100);
}

static void	send_str(pid_t pid, char *str)
{
	int	bit;
	int	i;
	
	i = 0;
	while (str[i])
	{
		bit = 8;
		while (bit--)
		{
			conf_signal = 0;
			if (str[i] & (1 << bit))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			check_conf();
		}
		i++;
	}
}
void	conf_handler(int sig)
{
	if (sig == SIGUSR1)
		conf_signal = 1;
	else if (sig == SIGUSR2)
		exit(EXIT_SUCCESS);
}
int	main(int ac, char **av)
{
	int	pid;
	struct sigaction	handler;

	if (ac != 3)
	{
		write(2, "Usage 👉 ./client <PID> <message>\n", 30);
		return (1);
	}
	handler.sa_handler = conf_handler;
	sigaction(SIGUSR1, &handler, NULL);
	sigaction(SIGUSR2, &handler, NULL);
	pid = ft_atoi(av[1]);
	send_str(pid, av[2]);
	return (0);
}