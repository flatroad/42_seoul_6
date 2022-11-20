# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: younkim <younkim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/01 05:09:09 by younkim           #+#    #+#              #
#    Updated: 2022/07/04 02:46:27 by younkim          ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = gcc
CFLAGS = -Wextra -Werror -Wall -c

SRCS := ft_split.c \
	ft_utils.c \
	check_map.c \
	mlx_img_utils.c \
	key_moves.c \
	so_long.c
OBJS := $(SRCS:.c=.o)
RM = rm -f

all : $(NAME)

clean : 
	make -C ./mlx clean
	$(RM) $(OBJS)

fclean :
	make clean
	$(RM) $(NAME)

re :
	make fclean
	make all

$(NAME) : $(OBJS)
	make -C ./mlx
	gcc -L ./mlx -lmlx -framework OpenGL -framework AppKit $^ -o so_long

%.o : %.c
	$(CC) $(CFLAGS) $?
