/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 20:53:54 by jalves-c          #+#    #+#             */
/*   Updated: 2023/04/24 00:45:57 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	positive_signal_received(int sig)
{
	(void)sig;
	ft_printf("\033[0;32mMessage received by the Server!\n\033[0m");
}

void	encode_and_send_char(pid_t server_pid, int sleep_time, int character)
{
	int	index;

	index = 8;
	while (index--)
	{
		if (character & (1 << index))
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		usleep(sleep_time);
	}
}

void	send_message(pid_t server_pid, const char *message)
{
	int	sleep_time;

	if (ft_strlen(message) <= 100)
		sleep_time = SHORT_SLEEP_TIME;
	else
		sleep_time = LONG_SLEEP_TIME;
	while (*message)
		encode_and_send_char(server_pid, sleep_time, *message++);
	encode_and_send_char(server_pid, sleep_time, '\0');
}

int	arguments_check(t_args *args, int argc, char **argv)
{
	if (argc != 3)
	{
		ft_printf("\033[0;31mError: ./client [PID] [MESSAGE]\n\033[0m");
		return (1);
	}
	args->server_pid = ft_atoi(argv[1]);
	if (kill(args->server_pid, 0) == -1)
	{
		ft_printf("\033[0;31mPID %d is Invalid\n\033[0m", args->server_pid);
		return (1);
	}
	else if (!ft_isprint(*argv[2]) || !ft_isdigit(*argv[1]))
	{
		ft_printf("\033[0;31mInvalid CLI arguments\n\033[0m");
		return (1);
	}
	else
		return (0);
}

int	main(int argc, char **argv)
{
	t_args	args;

	signal(SIGUSR1, positive_signal_received);
	if (arguments_check(&args, argc, argv))
		return (0);
	send_message(args.server_pid, argv[2]);
	return (0);
}