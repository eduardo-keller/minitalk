/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller-@student.42sp.org.br <ekeller-@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 16:29:09 by ekeller-@st       #+#    #+#             */
/*   Updated: 2025/04/07 18:30:07 by ekeller-@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

char	*ft_strjoin_letter(char *str, char c);
void	ft_receive(int signal, siginfo_t *info, void *unused);
char	*init_str(char *str);

//client
void	send_message(int pid, char c);
void	handle_sig(int sig);

#endif