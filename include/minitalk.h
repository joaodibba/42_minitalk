
#ifndef MINITALK_H
# define MINITALK_H

# include "../libft/libft.h"

# include <unistd.h>
# include <signal.h>

typedef struct s_bits
{
	int		is_pid;
	int		bit_count;
	pid_t	client_pid;
	char	current_char;
}	t_bits;

void	send_message(pid_t server_pid, char *message);
void	encode_and_send_char(pid_t server_pid, int c);
void	decode_and_print_char(int sig);
void	server_responce(int sig);
void	send_back_responce(void);

#endif
