#include "../include/minitalk.h"

void	server_responce(int sig)
{
	ft_printf("message received. sig: %i\n", sig);
}

void	encode_char(int server_pid, int num)
{
	if (num % 2 == 0)
		kill(server_pid, SIGUSR1);
	else
		kill(server_pid, SIGUSR2);
}

void	send_message(int server_pid, char *message)
{
	while (*message)
		encode_char(server_pid, *message);
	ft_printf("%i, %s\npausing for responce\n", server_pid, message);
	pause();
}

int	main(int argc, char **argv)
{
	int server_pid;

	if (argc != 3)
		return (0);
	else
	{
		server_pid = ft_atoi(argv[1]);
		ft_printf("%i\n", server_pid);
		if (ft_strncmp(argv[1], ft_itoa(server_pid), ft_strlen(argv[1])))
			return (0);
		signal(SIGUSR1, server_responce);
		send_message(server_pid, argv[2]);
		sleep(1);
	}
}