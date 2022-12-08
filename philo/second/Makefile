# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/18 13:49:19 by sounchoi          #+#    #+#              #
#    Updated: 2022/12/08 08:45:35 by sounchoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				=	cc
CFLAG			=	-Wall
CFILES			=	check_factor_utils.c \
					check_factor.c \
					main.c \
					error_handle.c \
					philo.c

NAME			= 	philo
OBJS			=	$(CFILES:.c=.o)


$(NAME): $(OBJS)
	$(CC) $(CFLAG) $(OBJS) -o $@

%.o: %.c
	$(CC) $(CFLAG) -c $? -o $@

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean:
	make clean
	rm -f $(NAME)

re:
	make fclean
	make all

.PHONY: all clean fclean re bonus
