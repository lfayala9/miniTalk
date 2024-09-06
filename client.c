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

static void	send_str(pid_t pid, char *str)
{
	int	bit;
	int	i;
	
	kill(pid, SIGUSR1);
	usleep(10);
	i = 0;
	while (str[i])
	{
		bit = 8;
		while (bit--)
		{
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
			usleep(10);
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac != 3)
	{
		write(2, "Usage 👉 ./client <PID> <message>\n", 30);
		return (1);
	}
	pid = ft_atoi(av[1]);
	send_str(pid, av[2]);
	return (0);
}