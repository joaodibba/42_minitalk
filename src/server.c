
#include "../include/minitalk.h"
#include <sys/time.h>
#include <stdio.h>

t_process	g_process;

void	decode_and_print_char(int sig, siginfo_t *info, void *context)
{
	struct timeval start, end;
    gettimeofday(&start, NULL);

	(void)context;
	if (sig == SIGUSR1)
		g_process.current_char |= (1 << (7 - g_process.bit_count));
	g_process.bit_count++;
	if (g_process.bit_count == 8)
	{
		if (g_process.current_char == 0) 
		{
			kill(info->si_pid, SIGUSR1);
			ft_printf("\n");
			gettimeofday(&end, NULL);
   	 		double time_taken = (end.tv_sec - start.tv_sec) * 1.0 + (end.tv_usec - start.tv_usec) / 1000000.0;
			printf("Time taken: %f seconds\n", time_taken);
		}
		ft_printf("%c", g_process.current_char);
		g_process.current_char = 0;
		g_process.bit_count = 0;
	}
}

int	main(void)
{
	struct sigaction act;

	act.sa_sigaction = decode_and_print_char;
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);

	g_process.bit_count = 0;
	g_process.current_char = 0;
	g_process.is_pid = 1;
	g_process.client_pid = 0;
	ft_printf("Server PID: %d\n", getpid());
	while (1)
		sleep(1);
}