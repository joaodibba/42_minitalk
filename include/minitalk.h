
#ifndef MINITALK_H
# define MINITALK_H

# include "../libft/libft.h"

# include <unistd.h>
# include <signal.h>

typedef struct s_process
{
    pid_t   client_pid;
    int     is_pid;
    int		bit_count;
    char 	current_char;
}	t_process;

void	encode_and_send_char(pid_t server_pid, int sleep_time, int c);

#endif
