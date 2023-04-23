/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 00:03:48 by jalves-c          #+#    #+#             */
/*   Updated: 2023/04/24 00:07:40 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	send_message_recieved_signal(int sig, siginfo_t *info)
{
	(void)sig;
	kill(info->si_pid, SIGUSR1);
}

void	message_handler(int sig, siginfo_t *info, void *context)
{
	static t_process	process;

	(void)context;
	if (sig == SIGUSR1)
		process.current_char |= (1 << (7 - process.bit_count));
	process.bit_count++;
	if (process.bit_count == 8)
	{
		if (process.current_char == 0)
		{
			send_message_recieved_signal(sig, info);
			ft_printf("\n");
		}
		ft_printf("%c", process.current_char);
		process.current_char = 0;
		process.bit_count = 0;
	}
}

int	main(void)
{
	struct sigaction	act;

	act.sa_sigaction = message_handler;
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	ft_printf("\033[0;32mServer PID: \033[0m%d\n", getpid());
	while (1)
		sleep(1);
}
