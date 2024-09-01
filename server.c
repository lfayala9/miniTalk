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

// void	sig_handler(int signal)
// {
// 	if (signal == SIGUSR1)
// 		ft_printf("patata %d\n", signal);
// 	if (signal == SIGUSR2)
// 		ft_printf("pititi %d\n", signal);
// }

// int	main(void)
// {
// 	struct sigaction	action;
// 	pid_t				pid;

// 	pid = getpid();
// 	action.sa_handler = sig_handler;
// 	sigaction(SIGUSR1, &action, NULL);
// 	sigaction(SIGUSR2, &action, NULL);
// 	ft_printf("The server PID is:🥲	 --> [%d]\n", pid);
// 	while (1)
// 		pause();
// 	return (0);
// }

#define MAX_LEN 1024

char buffer[MAX_LEN];
int bit_count = 0;
int char_index = 0;

void handle_sigusr1(int sig)
{
    (void)sig;
    buffer[char_index] |= (1 << (7 - bit_count));
    bit_count++;
    if (bit_count == 8)
    {
        bit_count = 0;
        char_index++;
        if (char_index == MAX_LEN - 1)
        {
            buffer[char_index] = '\0';
            printf("Received string: %s\n", buffer);
            char_index = 0;
        }
    }
}

void handle_sigusr2(int sig)
{
    (void)sig;
    bit_count++;
    if (bit_count == 8)
    {
        bit_count = 0;
        char_index++;
        if (char_index == MAX_LEN - 1)
        {
            buffer[char_index] = '\0';
            printf("Received string: %s\n", buffer);
            char_index = 0;
        }
    }
}

int main(void)
{
    struct sigaction sa1, sa2;

    sa1.sa_handler = handle_sigusr1;
    sa1.sa_flags = 0;
    sigemptyset(&sa1.sa_mask);
    sigaction(SIGUSR1, &sa1, NULL);

    sa2.sa_handler = handle_sigusr2;
    sa2.sa_flags = 0;
    sigemptyset(&sa2.sa_mask);
    sigaction(SIGUSR2, &sa2, NULL);

    printf("Server PID: %d\n", getpid());

    while (1)
    {
        pause(); // Espera señales
    }

    return 0;
}