#ifndef MINITALK_H
# define MINITALK_H

# include "../libft/libft.h"

# include <unistd.h>
# include <signal.h>

void	send_message(int server_pid, char *message);
void	encode_char(int server_pid, int num);
void	decode_char(int sig);
void	server_responce(int sig);

#endif
