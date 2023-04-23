
#ifndef MINITALK_H
# define MINITALK_H

# define SHORT_SLEEP_TIME 100
# define LONG_SLEEP_TIME 500

# include "../libft/libft.h"
# include <unistd.h>
# include <signal.h>

typedef struct s_process
{
	int		bit_count;
	char	current_char;
}	t_process;

typedef struct s_args
{
	pid_t	server_pid;
	char	*message;
}	t_args;

#endif
