
#include "../include/minitalk.h"

t_bits	g_process;

/*The send_back_response function is responsible for sending a signal
 to the client that the message has been received successfully.
  It sends the SIGUSR1 signal to the client process using the kill function.*/

void	send_back_response(void)
{
	kill(g_process.client_pid, SIGUSR1);
	ft_printf("OK\n");
}

/* The decode_and_print_char function is called whenever the server receives
 a signal from the client. It decodes the signal and prints the result.
 If the signal is SIGUSR1, it means that a bit is set to 1, and the function
 sets the corresponding bit in either the client PID or the current character being decoded,
 depending on the value of the is_pid flag in the g_process struct. If the signal is SIGUSR2,
 it means that a bit is set to 0, and the function does nothing except increment the bit count.
 Once 8 bits have been received, the function either prints the client PID or the decoded character,
 depending on the value of the is_pid flag, and resets the bit count and current character.*/
void	decode_and_print_char(int sig)
{
	if (sig == SIGUSR1)
	{
		if (g_process.is_pid)
			g_process.client_pid |= (1 << g_process.bit_count);
		else
			g_process.current_char |= (1 << g_process.bit_count);
	}
	g_process.bit_count++;
	ft_printf("SIGUSR1: %i | bit_count: %i\n", (sig == SIGUSR1), g_process.bit_count);
	if (g_process.bit_count == 8)
	{
		if (g_process.is_pid)
		{
			g_process.is_pid = 0;
			ft_printf("Client pid: %i\n", g_process.client_pid);
		}
		else
		{
			if (!g_process.current_char)
				send_back_response();
			else
				ft_printf("char: %c | %i\n", g_process.current_char, g_process.current_char);
			g_process.current_char = 0;
		}
		g_process.bit_count = 0;
	}
}

/* The main function initializes the g_process struct and sets up
 the signal handlers for SIGUSR1 and SIGUSR2.
 It then enters an infinite loop and waits for signals to arrive.*/
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
