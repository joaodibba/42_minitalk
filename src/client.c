
#include "../include/minitalk.h"

void	server_responce(int sig)
{
	ft_printf("message received. sig: %i\n", sig);
}

void	encode_and_send_char(pid_t server_pid, int c)
{
	int	i;

	ft_printf("the num: %i\n", c);
	i = 1;
	while (i <= 8)
	{
		if (c & (1 << i))
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		i--;
		usleep(100);
	}
}

void	send_message(pid_t server_pid, char *message)
{
	while (*message)
		encode_and_send_char(server_pid, *message++);
	encode_and_send_char(server_pid, *message);
	ft_printf("Waiting for server responce\n");
	pause();
}

int	main(int argc, char **argv)
{
	pid_t	server_pid;
	pid_t	client_pid;

	client_pid = getpid();
	if (argc != 3)
		return (0);
	ft_printf("Client PID: %d\n", client_pid);
	server_pid = ft_atoi(argv[1]);
	ft_printf("Server %d\n", server_pid);
	if (ft_strncmp(argv[1], ft_itoa(server_pid), ft_strlen(argv[1])))
		return (0);
	signal(SIGUSR1, server_responce);
	encode_and_send_char(server_pid, client_pid);
	send_message(server_pid, argv[2]);
	return (0);
}
