/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller-@student.42sp.org.br <ekeller-@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 16:06:56 by ekeller-@st       #+#    #+#             */
/*   Updated: 2025/04/07 18:28:55 by ekeller-@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

//0 = false. volatile tells the compiler keep
//checking the variable 
static volatile int	g_message_received = 0;

void	send_message(int pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		g_message_received = 0;
		if ((c >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (g_message_received == 0)
			;
		i--;
	}
}

void	handle_sig(int sig)
{
	if (sig == SIGUSR2)
		ft_printf("Message received by the server\n");
	g_message_received = 1;
}

int	main(int argc, char **av)
{
	int		pid;
	char	*message;

	if (argc == 3)
	{
		pid = ft_atoi(av[1]);
		message = av[2];
		signal(SIGUSR1, handle_sig);
		signal(SIGUSR2, handle_sig);
		while (*message)
		{
			send_message(pid, *message);
			message++;
		}
		send_message(pid, '\0');
	}
	else
		ft_printf("Error: wrong number of arguments\n");
	return (0);
}
