
#include "../include/minitalk.h"

t_process	g_process;

void	decode_and_print_char(int sig)
{
	if (sig == SIGUSR1)
		g_process.current_char |= (1 << (7 - g_process.bit_count));
	g_process.bit_count++;
	if (g_process.bit_count == 8)
	{
		if (g_process.current_char == 0) 
			ft_printf("\n");
		ft_printf("%c", g_process.current_char);
		g_process.current_char = 0;
		g_process.bit_count = 0;
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
	ft_printf("Server PID: %d\n", getpid());
	while (1)
		sleep(1);
}
