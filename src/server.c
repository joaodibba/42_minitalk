
#include "../include/minitalk.h"

t_bits	g_process;

void	send_back_responce(void)
{
	kill(g_process.client_pid, SIGUSR1);
	ft_printf("OK\n");
}

void	decode_and_print_char(int sig)
{
	if (sig == SIGUSR1)
		g_process.current_char |= (1 << g_process.bit_count);
	g_process.bit_count++;
	ft_printf("SIGUSR1: %i | bit_count: %i\n", (sig == SIGUSR1), g_process.bit_count);
	if (g_process.bit_count == 8)
	{
		if (g_process.is_pid)
		{
			g_process.client_pid = (int)g_process.current_char;
			g_process.is_pid = 0;
			ft_printf("Client pid: %i", g_process.client_pid);
		}
		else
		{
			ft_printf("current char: %c\n", g_process.current_char);
			g_process.bit_count = 0;
			if (!g_process.current_char)
				send_back_responce();
			g_process.current_char = 0;
		}
	}
}

int	main(void)
{
	signal(SIGUSR1, decode_and_print_char);
	signal(SIGUSR2, decode_and_print_char);

	g_process.bit_count = 0;
	g_process.current_char = 0;
	g_process.is_pid = 1;
	g_process.client_pid = 0;

	ft_printf("Server PID: %d\n", (size_t)getpid());
	while (1)
		sleep(1);
}
