/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller-@student.42sp.org.br <ekeller-@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 16:06:52 by ekeller-@st       #+#    #+#             */
/*   Updated: 2025/04/06 17:27:06 by ekeller-@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int signum)
{
	write(1, "signal received\n", 17);
}


int	main(int argc, char **av)
{
	printf("PID: %i\n", getpid());	//use ft_printf
	signal(SIGUSR1, handler);
	while (42)
	{
			
	}
}