
#include "../include/minitalk.h"

void	encode_and_send_char(pid_t server_pid, int sleep_time, int c)
{
	int	i;

	i = 8;
	while (i--)
	{
		if (c & (1 << i))
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		usleep(sleep_time);
	}
}

void	send_message(pid_t server_pid, char *message)
{
	int	sleep_time;

	if (ft_strlen(message) <= 100)
		sleep_time = 100;
	else
		sleep_time = 500;
	while (*message)
		encode_and_send_char(server_pid, sleep_time, *message++);
	encode_and_send_char(server_pid, sleep_time, *message);
}

void	server_response(int sig)
{
	(void)sig;
	ft_printf("\033[0;32mMessage received by the Server!\n\033[0m");
}

int	main(int argc, char **argv)
{
	pid_t	server_pid;

	signal(SIGUSR1, server_response);
	if (argc != 3)
		return (0);

	server_pid = ft_atoi(argv[1]);

	if (ft_strlen(ft_itoa(server_pid)) < ft_strlen(argv[1]))
		return (0);
	send_message(server_pid, argv[2]);
	return (0);
}

