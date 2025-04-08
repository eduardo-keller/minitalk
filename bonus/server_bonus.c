/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller-@student.42sp.org.br <ekeller-@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 16:06:52 by ekeller-@st       #+#    #+#             */
/*   Updated: 2025/04/07 18:23:18 by ekeller-@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_receive(int signal, siginfo_t *info, void *unused)
{
	static char	c;
	static char	*str;
	static int	bit_count;

	unused = NULL;
	if (bit_count < 8 && signal == SIGUSR1)
		c = c | (1 << (7 - bit_count));
	bit_count++;
	if (!str)
		str = init_str(str);
	if (bit_count == 8)
	{
		str = ft_strjoin_letter(str, c);
		if (c == '\0')
		{
			ft_printf("%s\n", str);
			free(str);
			str = NULL;
			kill(info->si_pid, SIGUSR2);
		}
		bit_count = 0;
		c = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	signal;

	ft_printf("PID: %i\n", getpid());
	signal.sa_sigaction = ft_receive;
	signal.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &signal, NULL);
	sigaction(SIGUSR2, &signal, NULL);
	while (42)
		pause();
	return (0);
}

char	*ft_strjoin_letter(char *str, char c)
{
	char	*new_str;
	int		i;

	i = 0;
	if (!str)
	{
		new_str = malloc(2);
		if (!new_str)
			return (NULL);
		new_str[0] = c;
		new_str[1] = '\0';
		return (new_str);
	}
	new_str = malloc(ft_strlen(str) + 2);
	if (!new_str)
		return (NULL);
	while (str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	free(str);
	new_str[i++] = c;
	new_str[i] = '\0';
	return (new_str);
}

char	*init_str(char *str)
{
	str = malloc(1);
	str[0] = '\0';
	return (str);
}
