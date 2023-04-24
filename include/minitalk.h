/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 00:56:55 by jalves-c          #+#    #+#             */
/*   Updated: 2023/04/24 01:52:25 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# define SHORT_SLEEP_TIME 100
# define MEDIUM_SLEEP_TIME 500
# define LONG_SLEEP_TIME 1000

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
