
#include "../include/minitalk.h"

void encode_and_send_char(pid_t server_pid, int c)
{
    int i;

    i = 8;
    while (i--)
    {
        if (c & (1 << i))
            kill(server_pid, SIGUSR1);
        else
            kill(server_pid, SIGUSR2);
        usleep(500);
    }
}

void	send_message(pid_t server_pid, char *message)
{
	while (*message)
		encode_and_send_char(server_pid, *message++);
	encode_and_send_char(server_pid, *message);
}

void	server_response(int sig)
{
	(void)sig;
	ft_printf("Message received by the Server!\n");
}

int	main(int argc, char **argv)
{
	pid_t	server_pid;

	signal(SIGUSR1, server_response);
	if (argc != 3)
		return (0);

	server_pid = ft_atoi(argv[1]);

	if (server_pid != ft_atoi(argv[1]))
		return (0);
	send_message(server_pid, argv[2]);
	return (0);
}

