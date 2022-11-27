# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/30 21:22:26 by sounchoi          #+#    #+#              #
#    Updated: 2022/11/18 17:20:12 by sounchoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = gnl.a
SRCS = get_next_line_utils.c \
get_next_line.c

OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = -src
RM = rm -rf

.c.o :
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $@ $?

all : $(NAME)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
