#include "../include/minitalk.h"


void	decode_char(int sig)
{
	if (sig == SIGUSR1)
		ft_printf("received: SIGUSR1\n");
	else if (sig == SIGUSR2)
		ft_printf("received: SIGUSR2\n");
}

int main(void)
{
	signal(SIGUSR1, decode_char);
	signal(SIGUSR2, decode_char);

	ft_printf("Process PID: %d\n", (size_t)getpid());
	pause();
	kill();
}