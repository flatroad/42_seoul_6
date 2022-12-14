# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/18 13:49:19 by sounchoi          #+#    #+#              #
#    Updated: 2022/12/15 06:31:15 by sounchoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				=	cc
CFLAG			=	-Wall -Wextra -Werror
CFILES			=	check_factor_utils.c \
					check_factor.c \
					main.c \
					error_handle.c \
					philo_bonus.c \
					init_data.c \
					free_box.c \
					start_game.c \
					start_game_state.c \
					start_game_utils.c

NAME			= 	philo_bouns
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
