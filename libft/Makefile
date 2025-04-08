# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ekeller-@student.42sp.org.br <ekeller-@    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/26 15:14:14 by ekeller-@st       #+#    #+#              #
#    Updated: 2025/04/07 14:38:02 by ekeller-@st      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = \
ft_putnbr.c \
ft_printf.c \
ft_atoi.c \
ft_strlen.c \

CC = cc

FLAGS = -Wall -Wextra -Werror

OBJECTS = $(SRC:%.c=%.o)

INCLUDES = 	libft.h

RM = rm -f

all: $(NAME)

$(NAME): $(OBJECTS)

%.o:%.c $(INCLUDES)
	${CC} ${FLAGS} -c $< -o $@
	ar rc $(NAME) $@

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY:	all clean fclean re bonus